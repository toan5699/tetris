#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include<SDL.h>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 720;
const int BROAD_WIDTH = 10;
const int BROAD_HEIGHT = 18;
const int BLOCK_SIZE = 40;
const int SPEED_COUNT = 500;

enum
{
    NONE,
    RED,
    BLACK,
    YELLOW,
    PURPLE,
    GREEN,
    BLUE,
    TOTAL
};


struct point
{
    int x;
    int y;
};

const int shape[7][4] =
{
    2,4,5,7,
    1,3,5,7,
    3,5,4,6,
    3,5,4,7,
    3,5,7,6,
    2,3,4,5,
    2,3,5,7,
};

extern SDL_Texture* color_block[TOTAL];
extern SDL_Texture* back_ground;
extern SDL_Texture* back_ground2;
extern SDL_Texture* tengame;
extern SDL_Texture* bangdiem;
extern SDL_Texture* diem0;
extern SDL_Texture* diem100;
extern SDL_Texture* diem200;
extern SDL_Texture* diem300;
extern SDL_Texture* diem400;
extern SDL_Texture* diem500;
extern SDL_Texture* diem600;
extern SDL_Texture* diem700;
extern SDL_Texture* diem800;
extern SDL_Texture* diem900;
extern SDL_Texture* diem1000;

bool load_block(SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer,string path);
bool check(point* future_status, int broad[BROAD_HEIGHT][BROAD_WIDTH]);
void show_broad(SDL_Renderer* renderer,int broad[BROAD_HEIGHT][BROAD_WIDTH]);
bool check_broad(int broad[BROAD_HEIGHT][BROAD_WIDTH],int& score,bool& quit);
#endif // CORE_H_INCLUDED
