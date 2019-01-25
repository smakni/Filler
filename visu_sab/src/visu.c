/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:33:12 by smakni            #+#    #+#             */
/*   Updated: 2019/01/23 17:51:41 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>

int main(int ac, char **av) 
{
    int posX = 100, posY = 100, width = 1000, height = 1000;
    
	SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    win = SDL_CreateWindow("FILLER", posX, posY, width, height, 0);
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

   while (1) 
   {
        SDL_Event e;
        if (SDL_PollEvent(&e)) 
		{
            if (e.type == SDL_QUIT) 
			{
                break;
            }
        }

        SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_Rect rectangle;
		rectangle.x = 0;
		rectangle.y = 0;
		rectangle.w = 10;
		rectangle.h = 10;
		SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return 0;
}
