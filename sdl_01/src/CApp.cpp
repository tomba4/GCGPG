#include "CApp.h"

CApp::CApp()
{
    Running = true;
    Surf_Display = NULL;
}

int CApp::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

bool CApp::OnInit()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        return false;
    }

    return true;
}

void CApp::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        Running = false;
    }
}

void CApp::OnLoop()
{

}

void CApp::OnCleanup()
{
    SDL_Quit();
}

void CApp::OnRender()
{

}

int main(int argc, char* argv[])
{
    CApp theApp;

    return theApp.OnExecute();
}
