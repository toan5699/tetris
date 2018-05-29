#include <iostream>
#include <SDL.h>
#include <string>
#include <ctime>
#include "core.h"
#include "TetrisOBJECT.h"

using namespace std;

bool Init(SDL_Renderer** renderer, SDL_Window* window);
void close(SDL_Window** window,SDL_Renderer** renderer,SDL_Texture* color_block[TOTAL]);

int main(int argc, char* argv[])
{
    int broad[BROAD_HEIGHT][BROAD_WIDTH] = {0};
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    srand(time(NULL));
    SDL_Event e;
    int score=0;
    SDL_Rect full_rect;
    SDL_Rect des_rect;
    SDL_Rect dest_rect;
    SDL_Rect destt_rect;
    SDL_Rect tes_rect;
    tes_rect.x=400;
    tes_rect.y=0;
    tes_rect.h=100;
    tes_rect.w=300;
    dest_rect.x =400;
    dest_rect.y =620;
    destt_rect.x=550;
    destt_rect.y=620;
    des_rect.x = 400;
    des_rect.y = 100;
    full_rect.x = 0;
    full_rect.y = 0;
    dest_rect.h=destt_rect.h=100;
    dest_rect.w=destt_rect.w=150;
    des_rect.h=520;
    des_rect.w=300;
    full_rect.h = SCREEN_HEIGHT;
    full_rect.w = SCREEN_WIDTH;
    bool quit=false;
    if (!Init(&renderer,window))
    {
        cout << "Can't INIT Window Screen. ";
        return 0;
    }
    else
    {
        if (!load_block(renderer))
        {
            cout << "Can't load BLOCK. ";
        }
        else
        {
            Tetris tetris;
            tetris.create();
            while (!quit)
            {
                while (SDL_PollEvent(&e)!=0)
                {
                    if (e.type == SDL_QUIT) quit = true;
                    tetris.handle_key(e);
                }
                tetris.handle_move(broad);
                tetris.set_broad(broad);
                check_broad(broad,score,quit);
               // SDL_RenderFillRect(renderer,&full_rect);
                SDL_RenderCopy(renderer,back_ground,NULL,&full_rect);
                SDL_RenderCopy(renderer,back_ground2,NULL,&des_rect );
                SDL_RenderCopy(renderer,bangdiem,NULL,&dest_rect);
                SDL_RenderCopy(renderer,tengame,NULL,&tes_rect);
                if(score ==0 )
                {
                         SDL_RenderCopy(renderer,diem0,NULL,&destt_rect);
                }
                if(score == 100)
                {
                         SDL_RenderCopy(renderer,diem100,NULL,&destt_rect);
                }
                if(score == 200)
                {
                         SDL_RenderCopy(renderer,diem200,NULL,&destt_rect);
                }
                if(score == 300)
                {
                         SDL_RenderCopy(renderer,diem300,NULL,&destt_rect);
                }
                if(score == 400)
                {
                         SDL_RenderCopy(renderer,diem400,NULL,&destt_rect);
                }
                if(score == 500)
                {
                         SDL_RenderCopy(renderer,diem500,NULL,&destt_rect);
                }
                if(score == 600)
                {
                         SDL_RenderCopy(renderer,diem600,NULL,&destt_rect);
                }
                if(score == 700)
                {
                         SDL_RenderCopy(renderer,diem700,NULL,&destt_rect);
                }
                if(score == 800)
                {
                         SDL_RenderCopy(renderer,diem800,NULL,&destt_rect);
                }
                if(score == 900)
                {
                         SDL_RenderCopy(renderer,diem900,NULL,&destt_rect);
                }
                if(score == 1000)
                {
                         SDL_RenderCopy(renderer,diem1000,NULL,&destt_rect);
                }
                show_broad(renderer,broad);
                tetris.show(renderer);
                SDL_RenderPresent(renderer);
            }
        }
    }
    close(&window,&renderer,color_block);
    cout << "Your Score: " << score;
    return 0;
}

bool Init(SDL_Renderer** renderer, SDL_Window* window)
{
    bool success = true;
        if(SDL_Init(SDL_INIT_EVERYTHING )   < 0 )
    {
        cout << "error SDL" << SDL_GetError() << endl;
        return  false;
    }
    window = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,700,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if ( window == NULL )
    {
        cout << "Window could not be created. Error: \n" << SDL_GetError();
        success = false;
    }
    else
    {
        *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if (*renderer == NULL)
        {
            cout << "Renderer could not be created. Error: \n" << SDL_GetError();
            success = false;
        }
        else
        SDL_SetRenderDrawColor(*renderer,0xFF,0xFF,0xFF,0xFF);
    }
    return success;
}

void close(SDL_Window** window,SDL_Renderer** renderer,SDL_Texture* color_block[TOTAL])
{
    SDL_DestroyWindow(*window);
    SDL_DestroyRenderer(*renderer);
    for (int i=0;i<TOTAL;i++)
    {
        SDL_DestroyTexture(color_block[i]);
        color_block[i] = NULL;
    }
    *window = NULL;
    *renderer = NULL;
    SDL_Quit();
}
