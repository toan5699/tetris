#ifndef TETRISOBJECT_H_INCLUDED
#define TETRISOBJECT_H_INCLUDED

#include <SDL.h>

class Tetris
{
private:
    SDL_Rect rect_;
    int color;
    int id_shape;
    point now_status[4];
    int x_val;
    int y_val;
    bool is_rotate;
public:
    Tetris();
    ~Tetris();
    void create();
    void handle_key(SDL_Event e);
    void handle_move(int broad[BROAD_HEIGHT][BROAD_WIDTH]);
    void show(SDL_Renderer* renderer);
    void set_broad(int broad[BROAD_HEIGHT][BROAD_WIDTH]);

};

#endif // TETRISOBJECT_H_INCLUDED
