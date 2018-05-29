#include "text_tetris.h"

TEXT_print::TEXT_print()
{
    des.x = 0;
    des.y = 0;
    renderer = NULL;
    IMG = NULL;
    size_font = 30;

}
bool TEXT_print::Load_text(const std::string text , SDL_Renderer* renderer)
{
    renderer = renderer;
    SDL_Surface* surface = NULL;
    SDL_Color fg = { 136, 0, 27};
    font = TTF_OpenFont("font/showcargothic.ttf", size_font);
    surface = TTF_RenderText_Solid(font , text.c_str() , fg);

    TTF_SizeText(font , text.c_str() , &des.w , &des.h);

    IMG = SDL_CreateTextureFromSurface( renderer , surface);

    SDL_FreeSurface(surface);

    if( IMG == NULL)
    {
        cout << "error text " << SDL_GetError() << endl;
        return false;
    }
    return true;
}
void TEXT_print::show()
{
     SDL_RenderCopy(renderer, IMG , NULL , &des );
}
void TEXT_print::setdes(int x, int y)
{
    des.x = x;
    des.y = y;
}
