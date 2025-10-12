/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:45:08 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 18:09:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Term.hpp"

#ifdef _WIN32

void	Term::_input_read(void)
{
	this->_buffer_input[0] = _getch();
	this->_input_size = 1;
}

#elif defined(__linux__) || defined(__APPLE__)

void	Term::_input_read(void)
{
	this->_input_size = read(STDIN_FILENO, this->_buffer_input, READ_SIZE - 1);
}

/*
tcgetattr(int fd, struct termios *termios_p)
Legge le impostazioni correnti del terminale.
fd di solito è STDIN_FILENO.

tcsetattr(int fd, int optional_actions, const struct termios *termios_p)
Imposta nuove modalità.
optional_actions può essere:
TCSANOW → subito.
TCSADRAIN → dopo che tutti i caratteri già in buffer sono scritti.
TCSAFLUSH → subito, scarta input non letto.

struct termios
Ha diversi campi, i più importanti:
c_lflag → flags locali (ICANON, ECHO, ISIG…)
c_iflag → input flags (es. ignora CR)
c_oflag → output flags
c_cc → array di caratteri di controllo (CTRL-C, CTRL-D, ecc.)

c_lflag (Local flags)

| Flag     | Significato                                    | Effetto pratico                                                                                   |
| -------- | ---------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| `ICANON` | Modalità canonica                              | Se attivo, l’input è bufferizzato fino a INVIO. Se disattivo (`~ICANON`), `read()` torna subito.  |
| `ECHO`   | Echo dell’input                                | Se attivo, i caratteri digitati vengono mostrati. Se disattivo, no (utile per password o giochi). |
| `ECHOE`  | Cancella visivamente i caratteri con backspace | Se disattivo, il backspace non “cancella” nulla a schermo.                                        |
| `ECHOK`  | Echo del carattere `KILL` (CTRL+U)             | Stampa un newline dopo il kill della riga.                                                        |
| `ISIG`   | Interpreta segnali (CTRL+C, CTRL+Z)            | Se disattivo, il terminale non invia SIGINT/SIGTSTP.                                              |
| `IEXTEN` | Estensioni POSIX extra                         | Gestisce cose tipo CTRL+V per escaping.                                                           |
| `TOSTOP` | Blocca output dei job secondari                | Non serve quasi mai.                                                                              |

c_iflag (Input flags)

| Flag     | Significato                            | Effetto pratico                                |
| -------- | -------------------------------------- | ---------------------------------------------- |
| `IGNBRK` | Ignora il carattere “break”            |                                                |
| `BRKINT` | Genera SIGINT su break                 |                                                |
| `IGNPAR` | Ignora caratteri con errore di parità  |                                                |
| `PARMRK` | Marca i caratteri con errore di parità |                                                |
| `INPCK`  | Abilita controllo parità               |                                                |
| `ISTRIP` | Toglie il bit 8 (forza ASCII 7 bit)    |                                                |
| `INLCR`  | Converte NL in CR                      |                                                |
| `IGNCR`  | Ignora CR (carriage return)            |                                                |
| `ICRNL`  | Converte CR in NL                      | Serve per rendere “invio” uguale a newline.    |
| `IXON`   | Abilita XON/XOFF (CTRL+S/CTRL+Q)       | Disabilitalo per evitare freeze del terminale. |

c_oflag (output flags)

| Flag                       | Significato              | Effetto pratico                                              |
| -------------------------- | ------------------------ | ------------------------------------------------------------ |
| `OPOST`                    | Post-process output      | Se disattivo, niente conversione di newline (`\n` → `\r\n`). |
| `ONLCR`                    | Converte NL in CR+NL     | Attivo di default per stampare bene nei terminali.           |
| `OCRNL`, `ONOCR`, `ONLRET` | Altri controlli su CR/NL | Poca utilità oggi.                                           |

c_cflag (control flags)

| Flag               | Significato                       |
| ------------------ | --------------------------------- |
| `CS8`              | 8 bit per carattere               |
| `CLOCAL`           | Ignora modem control lines        |
| `CREAD`            | Abilita la ricezione di caratteri |
| `PARENB`, `PARODD` | Parità abilitata / dispari        |
| `CSTOPB`           | 2 bit di stop invece di 1         |

c_cc (control characters)

| Indice   | Costante | Default   | Significato                                                             |
| -------- | -------- | --------- | ----------------------------------------------------------------------- |
| `VINTR`  | CTRL+C   | `^C`      | Interrompe il processo (SIGINT)                                         |
| `VQUIT`  | CTRL+\   | `^\`      | SIGQUIT                                                                 |
| `VERASE` | CTRL+H   | backspace | Cancella un carattere                                                   |
| `VKILL`  | CTRL+U   | `^U`      | Cancella l’intera riga                                                  |
| `VEOF`   | CTRL+D   | `^D`      | Fine input (EOF)                                                        |
| `VTIME`  | -        | 0         | Timeout in decimi di secondo per `read()` (solo non canonico)           |
| `VMIN`   | -        | 1         | Numero minimo di caratteri per far tornare `read()` (solo non canonico) |

*/
void	Term::_init_tty_settings(void)
{
#if defined(__linux__) || defined(__APPLE__)
	termios	newt;

	tcgetattr(STDIN_FILENO, &this->_oldt);
	newt = this->_oldt;
	newt.c_lflag &= ~(ECHO | ICANON);
	newt.c_cc[VTIME] = 0.16;
	newt.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

/*
| Costante     | Significato                                                 | Struttura associata |
| ------------ | ----------------------------------------------------------- | ------------------- |
| `TIOCGWINSZ` | Ottiene la dimensione della finestra                        | `struct winsize`    |
| `TIOCSWINSZ` | Imposta la dimensione (raro da usare)                       | `struct winsize`    |
| `TIOCGETA`   | Ottiene le impostazioni termios (equivalente a `tcgetattr`) | `struct termios`    |
| `TIOCSETA`   | Imposta le impostazioni (equivalente a `tcsetattr`)         | `struct termios`    |
| `TIOCGPGRP`  | Ottiene il process group associato al terminale             | `pid_t`             |
| `TIOCSPGRP`  | Imposta il process group                                    | `pid_t`             |
*/
void	Term::_update_tty_size(void)
{
	this->_term_x = 80;
	this->_term_y = 60;

#if defined(__linux__) || defined(__APPLE__)
	struct winsize	w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1)
	{
		this->_term_x = w.ws_col;
		this->_term_y = w.ws_row;
	}
#elif defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    this->_term_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    this->_term_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#endif
}

#endif