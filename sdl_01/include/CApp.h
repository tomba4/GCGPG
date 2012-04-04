#ifndef CAPP_H
#define CAPP_H

#include <SDL/SDL.h>

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
};

#endif // CAPP_H
