#ifndef TEXT_TETRIS_H
#define TEXT_TETRIS_H

#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

class  TEXT_print
{
public:
    TEXT_print();
    bool Load_text( const std::string text , SDL_Renderer* renderer);
    void show();
    void setdes(int x, int y);
    void set_font(int x) {  size_font = x; }
protected:
    SDL_Rect des;
    SDL_Renderer* renderer;
    SDL_Texture* IMG;
    TTF_Font* font;
    int size_font;
};
#endif // TEXT_TETRIS_H
