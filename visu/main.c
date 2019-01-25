/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:41:50 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/12 11:23:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_init_visu(t_env *env, int *is_running)
{
	*(is_running) = 1;
	env->p.col = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("unable to initialize SDL: %s", SDL_GetError());
		return (-1);
	}
	TTF_Init();
	env->font = TTF_OpenFont("CSMS.ttf", HEIGHT / 20);
	if (!(env->win = SDL_CreateWindow("visu filler", SDL_WINDOWPOS_UNDEFINED, \
					SDL_WINDOWPOS_UNDEFINED, WIDTH * 1.5, HEIGHT * 1.5, 0)))
		return (-1);
	if (!(env->ren = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_ACCELERATED \
					| SDL_RENDERER_TARGETTEXTURE)))
		return (-1);
	if (!(env->txt = SDL_CreateTexture(env->ren, SDL_PIXELFORMAT_RGBA8888, \
					SDL_TEXTUREACCESS_TARGET, WIDTH * 1.5, HEIGHT * 1.5)))
		return (-1);
	ft_pick_color(env, 255, 255, 255);
	return (1);
}

static void	ft_init_string_and_piece(t_env *env)
{
	env->p1 = NULL;
	env->p2 = NULL;
	env->namep1 = NULL;
	env->namep2 = NULL;
	env->score = NULL;
	env->winner = NULL;
	env->p.y = -1;
	env->p.x = -1;
}

static int	ft_run_game(t_env *env, int *is_running)
{
	int		ret;

	while (SDL_PollEvent(&env->event))
		if ((ret = ft_handle_event(env)) < 1)
		{
			if (ret == 0)
				ft_print_winner(env);
			else if (ret == -1)
			{
				ft_printf("Malloc allocation failed\n");
				return (-1);
			}
			else if (ret == -2)
			{
				*(is_running) = 0;
				break ;
			}
		}
	return (1);
}

int			main(void)
{
	t_env		env;
	int			is_running;
	int			ret;

	if (ft_init_visu(&env, &is_running) == -1)
		return (-1);
	ft_init_string_and_piece(&env);
	while (is_running)
	{
		if (is_running == 1)
			if ((ret = ft_init_env(&env, &is_running)) == -1)
				return (ft_quit_all_neg(&env));
		if (is_running == 2)
		{
			if ((ret = ft_first_parsing(&env, &is_running)) == -1)
				return (ft_quit_all_neg(&env));
			ft_original_draw(&env);
		}
		else if (is_running == 3)
		{
			if ((ret = ft_run_game(&env, &is_running)) == -1)
				return (ft_quit_all_neg(&env));
		}
	}
	return (ft_quit_all(&env));
}
