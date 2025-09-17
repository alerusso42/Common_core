/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:51:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/15 15:07:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

/*
# define MAP 	"111111111", \
				"100000001", \
				"100011101", \
				"100000101", \
				"1100P0001", \
				"100010001", \
				"100000001", \
				"111111111", \
				"#"

void	copy_map(term *t)
{
	int		i;
	int		j;
	char	map[10][10] = {MAP};

	i = 0;
	while (map[i][0] != '#')
	{
		j = 0;
		while (map[i][j])
		{
			t->map[i][j] = map[i][j];
			++j;
		}
		++i;
	}
}
void	print_column(term *t)
{
	int	y;
	int	stop;

	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y + (t->height / 2);
	while (y < stop && y < t->term_y)
	{
		std::cout << "\u2588";
		std::cout << "\033[1B";
		std::cout << "\033[1D";
		++y;
	}
	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y - (t->height / 2);
	while (y && y > stop)
	{
		std::cout << "\u2588";
		std::cout << "\033[1A";
		std::cout << "\033[1D";
		--y;
	}
	t->column++;
}*/
				
typedef struct term
{
	//char	map[10][10];
	int		term_x;
	int		term_y;
	int		column;
	int		height;
}term;


void	clear(void);
void	render(void);
void	print_column(term *t);

void	render(void)
{
	std::cout << std::flush;
}

void	clear(void)
{
	std::cout << "\033[H";// H: set to position to 0,0
	std::cout << "\033[0J" << std::flush;// 0J: clear from position to end
}

void	screen_size(int &x, int &y)
{
	char	s[20];
	int		i;

	x = 0, y = 0;
	std::cout << "press ENTER" << std::endl << std::flush;
	std::cout << "\033[999;999H";//set position ESC[{line};{column}H
	std::cout << "\033[6n";// print current position on std::cout
	std::cin.get(s, 19);
	i = 0;
	while (s[i] < '0' || s[i] > '9')
		++i;
	y = std::atoi(&s[i]);
	while (s[i] != ';')
		++i;
	x = std::atoi(&s[++i]);
	std::cout << "terminal size is:" << x << "," << y << std::endl;
}

void	term_column(term *t)
{
	int	y;
	int	stop;

	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y + (t->height / 2);
	while (y < stop && y < t->term_y)
	{
		std::cout << "\u2588";// u is unicode
		std::cout << "\033[1B";//goes # line below
		std::cout << "\033[1D";//goes # colums left
		++y;
	}
	y = t->term_y / 2;
	std::cout << "\033[" << t->term_y / 2 << ";" << t->column << "H";
	stop = y - (t->height / 2);
	while (y && y > stop)
	{
		std::cout << "\u2588";
		std::cout << "\033[1A";//goes # line up
		std::cout << "\033[1D";
		--y;
	}
	t->column++;
}

void	term_putstr(term *t, string s, int x, int y)
{
	(void)t;
	std::cout << "\033[" << y << ";" << x << "H" << s;
}

int	test_main(void)
{
	term	t;
	int		loops;
	
	t.column = 0;
	t.height = 0;
	screen_size(t.term_x, t.term_y);
	clear();
	render();
	loops = 12;
	while (loops--)
	{	
		std::cout << "\033[H";
		t.height = std::rand() % t.term_y;
		while (t.column < t.term_x)
			term_column(&t);
		term_putstr(&t, "@", loops, 9);
		render();
	}
	std::cout << "\033[9999;9999H";
	return (0);
}
