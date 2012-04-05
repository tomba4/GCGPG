#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>

#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent
{
    public:
        CApp();
        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnExit();
        void OnLoop();
        void OnRender();
        void OnCleanup();
        void Reset();
        void SetCell(int ID, int Type);
        void OnLButtonDown(int mX, int mY);
    protected:
    private:
        bool Running;
        SDL_Surface* Surf_Display;
        SDL_Surface* Surf_Grid;
        SDL_Surface* Surf_X;
        SDL_Surface* Surf_O;
        int Grid[9];
        int CurrentPlayer;

        enum
        {
            GRID_TYPE_NONE = 0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };
};

#endif // CAPP_H
