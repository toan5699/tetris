#include "core.h"
#include <string>
#include <SDL.h>
#include "TetrisOBJECT.h"
#include<stdlib.h>

using namespace std;

Tetris::Tetris()
{
    rect_.h = BLOCK_SIZE;
    rect_.w = BLOCK_SIZE;
    rect_.x = 0;
    rect_.y = 0;
    x_val = 0;
    y_val = 0;
    is_rotate = false;
}

Tetris::~Tetris()
{

}

void Tetris::create()
{
    color = rand()%6+1;
    id_shape = rand()%7;
    int ran_slot = rand()%9;
    for (int i=0;i<4;i++)
    {
        now_status[i].x = shape[id_shape][i] % 2 + ran_slot;
        now_status[i].y = shape[id_shape][i] / 2 + 2;
    }
}

void Tetris::show(SDL_Renderer* renderer)
{
    for (int i=0;i<4;i++)
    {
        SDL_Rect rect_temp;
        rect_.x = now_status[i].x * BLOCK_SIZE;
        rect_.y = now_status[i].y * BLOCK_SIZE;
        SDL_RenderCopy(renderer,color_block[color],NULL,&rect_);
    }
}

void Tetris::handle_key(SDL_Event e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
            case SDLK_UP: if (id_shape !=5) is_rotate=true; break;
            case SDLK_LEFT: x_val--; break;
            case SDLK_RIGHT: x_val++; break;
            case SDLK_s: y_val++; break;
        }
    }
}

void Tetris::handle_move(int broad[BROAD_HEIGHT][BROAD_WIDTH])
{
    point future_status[4];
    point center = now_status[1];
    for (int i=0;i<4;i++)
    {
        future_status[i] = now_status[i];
        if (is_rotate == true)
        {
        int x = now_status[i].y-center.y;
        int y = now_status[i].x-center.x;
        future_status[i].x = center.x - x;
        future_status[i].y = center.y + y;
        }
        future_status[i].x += x_val;
        future_status[i].y += y_val;
    }
    if (check(future_status,broad))
        for (int i=0;i<4;i++) now_status[i] = future_status[i];
    is_rotate = false;
    x_val = 0;
    y_val = 0;
}

void Tetris::set_broad(int broad[BROAD_HEIGHT][BROAD_WIDTH])
{
    static int i=0;
    i++;
    point future_status[4];
    if (i>SPEED_COUNT)
    {
         for (int i=0;i<4;i++)
         {
            future_status[i] = now_status[i];
            future_status[i].y++;
         }
        if (check(future_status,broad))
            for (int i=0;i<4;i++) now_status[i] = future_status[i];
        else
        {
            for (int i=0;i<4;i++) broad[now_status[i].y][now_status[i].x]=color;
            create();
        }
        i = 0;
    }
}


