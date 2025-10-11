/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Term.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:22:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/11 01:22:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_HPP
# define TERM_HPP

# define KEYS "wdsa"

# include "../../includes/raycast_tty.hpp"

class Term
{
private:
	char	map[10][10];

	//SECTION - input
	std::map<int8_t, u_int64_t>	_key_binding;
	std::mutex					_mutex_input;
	std::thread					_thread_input;
	u_int64_t					_input;

	int32_t		_term_x;
	int32_t		_term_y;
	int32_t		_column;
	int32_t		_height;

	enum e_term_input: u_int64_t
	{
		KEY_W = 	1 << 0,
		KEY_D = 	1 << 1,
		KEY_S = 	1 << 2,
		KEY_A = 	1 << 3,
		KEY_END =	1 << 4,
		INPUT_END = 1 << 63,
	};
	void	randomize_height(void);
	void	_init_keys(void);
	void	_init_input(void);
	void	_init_tty_size(void);
	void	_input_reader(void);
public:
	//canonic form
	Term();
	~Term();
	Term(const Term &other);
	Term	&operator=(const Term &other);

	//SECTION - class functions
	void	render(void) const;
	void	clear(void) const;

	//SECTION - testing
	void		test_column(void);
	void		test_screen(void);
	void		test_input(void);
	u_int64_t	get_input(void);
	void		set_input(const u_int64_t &other);
};

#endif