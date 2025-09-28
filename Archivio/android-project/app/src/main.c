/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:00:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 11:22:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/include/header.h"

int	main1()
{
	t_data	data;
	char	**test;

	logg("start");
	data = (t_data){0};
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (printf("CRASH!!!!!"), 1);
	data.win = SDL_CreateWindow("", 0, 0, 640, 480, SDL_WINDOW_FULLSCREEN);
	if (!data.win)
	return (printf("CRASH!!!!!"), 1);
	data.rend = SDL_CreateRenderer(data.win, -1, SDL_RENDERER_ACCELERATED);
	if (!data.rend)
	return (printf("CRASH!!!!!"), 1);
	SDL_GetWindowSize(data.win, &data.wscreen, &data.hscreen);
	if (init_txtr(&data) != 0)
		return (printf("CRASH!!!!!"), 1);
	logg("app loop..");
	//app_loop(&data);
	SDL_Quit();
	free_txtr(&data);
	if (daft_init() != 0)
		return (1);
	daft_swap(ENEMIES);
	test = daft_get("RED");
	if (ft_strncmp(test[0], "3", 12) == 0 || ft_strncmp(test[0], "RED", 12) == 0)
		SDL_Delay(4000);
	daft_quit();
	return (0);
}

void	app_loop(t_data *data)
{
	int			run;
	t_touch		touch;

	touch = (t_touch){0};
	touch.text_left = sizeof(touch.text) - 1;
	run = true;
	while (run)
	{
		inputs(&touch, &run, data->wscreen, data->hscreen);
		interface(data, &touch);
		render(&touch, data);
		if (touch.text_len > 16)
			reset_buff(&touch);
		SDL_Delay(16);
	}
}

void	inputs(t_touch *touch, int *run, int wscreen, int hscreen)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION)
		{
			touch->pos[X] = (int)(event.tfinger.x * wscreen); 
			touch->pos[Y] = (int)(event.tfinger.y * hscreen);
			touch->pressure = 1;
			touch->input |= TOUCH;
		}
		else if (event.type == SDL_FINGERUP)
		{
			touch->input ^= TOUCH;
			touch->pressure = 0.4;
		}
		else if (event.type == SDL_TEXTINPUT)
		{
			strncat(touch->text, event.text.text, touch->text_left);
			touch->text_len += strlen(event.text.text);
			touch->text_left = sizeof(touch->text) - touch->text_len - 1;
			if (SDL_strstr(touch->text, "exit"))
				*run = false;
		}
	}
}

void	render(t_touch *touch, t_data *data)
{
	SDL_Rect	rect;
	SDL_Rect	box;
	const int	size = 50;
	int			color;
	int			r, g, b;

	rect.w = 50;
	rect.h = 50;
	rect.x = touch->pos[X] - (rect.w / 2);
	rect.y = touch->pos[Y] - (rect.h / 2);
	box.x = BOX_X;
	box.y = BOX_Y;
	box.w = 100;
	box.h = 100;
	if (!touch->pressure)
		touch->pressure = 1;
	r = 20 * touch->pressure;
	g = 20 * touch->pressure;
	b = 20 * touch->pressure;
	if (data->input)
	{
		r += 100;
		g += 100;
		b += 100;
	}
	SDL_SetRenderDrawColor(data->rend, 0, 0, 0, 255);
	SDL_RenderClear(data->rend);
	SDL_SetRenderDrawColor(data->rend, 10, 10, 10, 255);
	SDL_RenderFillRect(data->rend, &rect);
	SDL_RenderCopy(data->rend, data->txtr[TXTR_CURSOR], NULL, &rect);
	SDL_RenderDrawRect(data->rend, &rect);
	SDL_SetRenderDrawColor(data->rend, r, g, b, 255);
	SDL_RenderFillRect(data->rend, &box);
	//SDL_RenderDrawRect(data->rend, &box);
	SDL_RenderCopy(data->rend, data->txtr[TXTR_BOX], NULL, &box);
	SDL_RenderPresent(data->rend);
}

void	interface(t_data *data, t_touch *touch)
{
	if (touch->pos[X] < BOX_X - 5 || touch->pos[X] > BOX_X + 105)
		return (data->input = false, SDL_StopTextInput());
	if (touch->pos[Y] < BOX_Y - 5 || touch->pos[Y] > BOX_Y + 105)
		return (data->input = false, SDL_StopTextInput());
	if (data->input == false)
		SDL_StartTextInput();
	data->input = true;
}

void	reset_buff(t_touch *touch)
{
	int	i;

	i = sizeof(touch->text);
	while (--i)
		touch->text[i] = 0;
	touch->text_len = 0;
	touch->text_left = sizeof(touch->text) - 1;
}

void	test_print(char ***matr)
{
	int	i, j;

	i = 0;
	while (matr[i])
	{
		j = 0;
		while (matr[i][j])
		{
			logg(matr[i][j]);
			//printf("%s\n", matr[i][j]);
			j++;
		}
		i++;
	}
}

int	main()
{
	srand((unsigned int)time(NULL));
	
	char	***m1;

	if (daft_init())
		return (1);
	daft_swap(POKEDEX);
	m1 = daft_append("CRAZY", 200, 100);
	ft_strlcpy(m1[1][0], "FIRE", 5);
	logg("io inizio eh..");
	ft_strlcpy(m1[1][1], "FIGHT", 6);
	ft_strlcpy(m1[5][2], "GABIBBO", 8);
	ft_strlcpy(m1[6][3], "GABIBBOo", 9);
	ft_strlcpy(m1[7][4], "GABIBBOoo", 10);
	ft_strlcpy(m1[8][5], "GABIBBOooo", 11);
	ft_strlcpy(m1[9][6], "GABIBBOooo", 11);
	logg("load..");
	daft_load();
	m1 = daft_edit("CRAZY", 200, 100);
	logg("fase edit..");
	if (!m1)
		logg("fallimento..");
	ft_strlcpy(m1[1][0], "WATER", 6);
	ft_strlcpy(m1[1][1], "FIRE", 5);
	ft_strlcpy(m1[5][2], "RAYQUAZ", 8);
	ft_strlcpy(m1[6][3], "RAYQUAZo", 8);
	ft_strlcpy(m1[7][4], "RAYQUAZoo", 8);
	ft_strlcpy(m1[8][5], "RAYQUAZooo", 8);
	ft_strlcpy(m1[9][6], "RAYQUAZooo", 8);
	daft_load();
	m1 = daft_get("CRAZY");
	logg("fase get..");
	if (!m1)
		logg("fallimento..");
	test_print(m1);
	daft_quit();
	return (0);
}
