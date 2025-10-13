/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Creattyed: 2025/10/10 21:58:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 18:21:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/raycast_tty.hpp"

int	main(void)
{
	Term		tty;
	const char	*raw_map[] = {SAMPLE_MAP};
	Map			map((const int8_t **)raw_map);

	map.print();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	while (tty.is_active() == true)
	{
		commands(tty, map);
		tty.clear();
		debug_print("Starting render\n");
		raycast(tty, map);
		tty.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(tty.FRAME_RATE));
	}
	std::cout << "\033[9999;9999H";
	return (0);
}
