#include <iostream>
#include "core.h"
#include <string>
#include <SDL.h>

using namespace std;

SDL_Texture* color_block[TOTAL] = {NULL};
SDL_Texture* back_ground;
SDL_Texture* back_ground2;
SDL_Texture* tengame;
SDL_Texture* bangdiem;
SDL_Texture* diem0;
SDL_Texture* diem100;
SDL_Texture* diem200;
SDL_Texture* diem300;
SDL_Texture* diem400;
SDL_Texture* diem500;
SDL_Texture* diem600;
SDL_Texture* diem700;
SDL_Texture* diem800;
SDL_Texture* diem900;
SDL_Texture* diem1000;
bool load_block(SDL_Renderer* renderer)
{
    bool success = true;
    color_block[RED] = loadTexture(renderer,"red_block.bmp");
    if (color_block[RED] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    color_block[BLACK] = loadTexture(renderer,"black_block.bmp");
    if (color_block[BLACK] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    color_block[YELLOW] = loadTexture(renderer,"yellow_block.bmp");
    if (color_block[YELLOW] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    color_block[PURPLE] = loadTexture(renderer,"purple_block.bmp");
    if (color_block[PURPLE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    color_block[GREEN] = loadTexture(renderer,"green_block.bmp");
    if (color_block[GREEN] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    color_block[BLUE] = loadTexture(renderer,"blue_block.bmp");
    if (color_block[BLUE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     back_ground = loadTexture(renderer,"anhnen.bmp");
    if (back_ground == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         back_ground2 = loadTexture(renderer,"anhnen1.bmp");
    if (back_ground2 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         tengame = loadTexture(renderer,"tengame.bmp");
    if (tengame == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     bangdiem = loadTexture(renderer,"score.bmp");
    if (bangdiem == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem0 = loadTexture(renderer,"0.bmp");
    if (diem0 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem100 = loadTexture(renderer,"100.bmp");
    if (diem100 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem200 = loadTexture(renderer,"200.bmp");
    if (diem200 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem300 = loadTexture(renderer,"300.bmp");
    if (diem300 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem400 = loadTexture(renderer,"400.bmp");
    if (diem400 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem500 = loadTexture(renderer,"500.bmp");
    if (diem500 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         diem600 = loadTexture(renderer,"600.bmp");
    if (diem600 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
     diem700 = loadTexture(renderer,"700.bmp");
    if (diem700 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         diem800 = loadTexture(renderer,"800.bmp");
    if (diem800 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         diem900 = loadTexture(renderer,"900.bmp");
    if (diem900 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
         diem1000 = loadTexture(renderer,"1000.bmp");
    if (diem1000 == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    return success;
}

SDL_Texture* loadTexture(SDL_Renderer* renderer,string path)
{
    SDL_Texture* newTexture= NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image. Error: \n " << SDL_GetError();
    }
    else
    {
        //SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << path << " Error: \n" << SDL_GetError();
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}


bool check(point future_status[4], int broad[BROAD_HEIGHT][BROAD_WIDTH])
{
    bool avaiable = true;
    for (int i=0;i<4;i++)
    {
        if (future_status[i].x < 0) avaiable = false;
        if (future_status[i].x >= BROAD_WIDTH) avaiable = false;
    }
    if (avaiable == false) return false;
    for (int i=0;i<4;i++)
    {
        if (future_status[i].y < 0) return true;
    }
    for (int i=0;i<4;i++)
    {
        if (future_status[i].x<0 || future_status[i].x >= BROAD_WIDTH || future_status[i].y >= BROAD_HEIGHT)
            return false;
        else if (broad[future_status[i].y][future_status[i].x]!=0) return false;
    }
    return true;
}

void show_broad(SDL_Renderer* renderer,int broad[BROAD_HEIGHT][BROAD_WIDTH])
{
    for (int i=0;i<BROAD_HEIGHT;i++)
        for (int j=0;j<BROAD_WIDTH;j++)
        {
            SDL_Rect rect_temp;
            rect_temp.w = BLOCK_SIZE;
            rect_temp.h = BLOCK_SIZE;
            rect_temp.x = j*BLOCK_SIZE;
            rect_temp.y = i*BLOCK_SIZE;
            SDL_RenderCopy(renderer,color_block[broad[i][j]],NULL,&rect_temp);
        }
}

bool check_broad(int broad[BROAD_HEIGHT][BROAD_WIDTH],int& score,bool& quit)
{
    for (int i=0;i<BROAD_WIDTH;i++)
        if (broad[0][i] != 0) quit=true;
    for (int i=0;i<BROAD_HEIGHT;i++)
    {
        bool is_full_line = true;
        for (int j=0;j<BROAD_WIDTH;j++) if (broad[i][j]==0) is_full_line = false;
        if (is_full_line == true)
        {
            score += 100;
            for (int j=i-1;j>=0;j--)
                for (int k=0;k < BROAD_WIDTH;k++)
                {
                    broad[j+1][k] = broad[j][k];
                    broad[j][k] = 0;
                }
            i--;
        }
    }
}


