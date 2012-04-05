#include "CApp.h"

CApp::CApp()
{
    Running = true;
    Surf_Display = NULL;
    Surf_Test = NULL;
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

    if((Surf_Test = CSurface::OnLoad("img/myimage.bmp")) == NULL)
    {
        return false;
    }

    return true;
}

void CApp::OnEvent(SDL_Event* Event)
{
    CEvent::OnEvent(Event);
}

void CApp::OnLoop()
{

}

void CApp::OnCleanup()
{
    SDL_FreeSurface(Surf_Test);
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

void CApp::OnRender()
{
    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Test, 100, 100, 0, 0, 50, 50);

    SDL_Flip(Surf_Display);
}

void CApp::OnExit()
{
    Running = false;
}

int main(int argc, char* argv[])
{
    CApp theApp;

    return theApp.OnExecute();
}
