#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>

#include "CSurface.h"

class CApp
{
    public:
        CApp();
        int OnExecute();
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnCleanup();
    protected:
    private:
        bool Running;
        SDL_Surface* Surf_Display;
        SDL_Surface* Surf_Test;
};

#endif // CAPP_H
