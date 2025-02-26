/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 14:34:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static int	other_messages(int error);
static int	other_messages2(int error);
static int	other_messages3(int error);

/*
	Error messages are definied in z_data.h, in enum e_error.

	Error ER_BAD_ARGC shows a part of the original project text.
*/
int	error(int error)
{
	reset_memory();
	if (error == ER_BAD_ARGC)
	{
		fd_printf(2, "Error\n");
		fd_printf(2, "Your program should be executed as:\n");
		fd_printf(2, "./pipex file1 cmd1 cmd2 file2\n\n");
		fd_printf(2, "It must take 4 arguments:\n");
		fd_printf(2, "• file1 and file2 are file names.\n");
		fd_printf(2, "• cmd1 and cmd2 are shell commands.\n\n");
		fd_printf(2, "It must behave like this shell command:");
		fd_printf(2, "$> < file1 cmd1 | cmd2 > file2\n\n");
		fd_printf(2, "Examples:\n");
		fd_printf(2, "$> ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
		fd_printf(2, "Equivalent to: < infile ls -l | wc -l > outfile\n\n");
		fd_printf(2, "$> ./pipex infile \"grep a1\" \"wc -w\" outfile\n");
		fd_printf(2, "Equivalent to: < infile grep a1 | wc -w > outfile\n");
		return (ER_BAD_ARGC);
	}
	return (other_messages(error));
}

static int	other_messages(int error)
{
	if (error == ER_MALLOC)
	{
		fd_printf(2, "Error\nMalloc failure.\n");
		return (ER_MALLOC);
	}
	if (error == ER_PARSING)
	{
		fd_printf(2, "Error\nGeneric error while parsing.\n");
		return (ER_PARSING);
	}
	if (error == ER_NOPATH)
	{
		fd_printf(2, "Error\nThe PATH string was not found in env.\n");
		return (ER_NOPATH);
	}
	if (error == ER_CMD_NOTFOUND)
	{
		fd_printf(2, "Error\nCommand not found.\n");
		return (ER_CMD_NOTFOUND);
	}
	return (other_messages2(error));
}

static int	other_messages2(int error)
{
	if (error == ER_FORK_FAILED)
	{
		fd_printf(2, "Error\nFork failed.\n");
	}
	if (error == ER_EXECVE_FAILED)
	{
		fd_printf(2, "Error\nExecve failed.\n");
		return (ER_EXECVE_FAILED);
	}
	if (error == ER_OPEN_FAILED)
	{
		fd_printf(2, "Error\nOpen failed.\n");
		return (ER_OPEN_FAILED);
	}
	if (error == ER_DUP_FAILED)
	{
		fd_printf(2, "Error\nDup failed.\n");
		return (ER_DUP_FAILED);
	}
	if (error == ER_WAIT_FAILED)
	{
		fd_printf(2, "Error\nWait failed.\n");
		return (ER_WAIT_FAILED);
	}
	return (other_messages3(error));
}

static int	other_messages3(int error)
{
	if (error == ER_PIPE_FAILED)
	{
		fd_printf(2, "Error\nPipe failed.\n");
		return (ER_PIPE_FAILED);
	}
	if (error == ER_NO_CODED)
	{
		fd_printf(2, "Error\nMissing part of code.\n");
		return (ER_NO_CODED);
	}
	return (fd_printf(2, "Generic error %d\n", error));
}
