#include "WindowsApplication.hpp"
#include <tchar.h>

using namespace My;

int My::WindowsApplication::Initialize()
{
    int result;
    result = BaseApplication::Initialize();

    if(result != 0)
        exit(result);
    
    // get the hinstance of the console program.
    HINSTANCE hInstance= GetModuleHandle(NULL);
    HWND hWnd;
    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("ViriyaEngine");

    // register the window class
    RegisterClassEx(&wc);

    hWnd = CreateWindowEx(0,
                          _T("ViriyaEngine"),               // name of the window class
                          m_Config.appName,                 // title of the window
                          WS_OVERLAPPEDWINDOW,              // window style
                          CW_USEDEFAULT,                    // x-position of the window
                          CW_USEDEFAULT,                    // y-position of the window
                          m_Config.screenWidth,             // width of the window
                          m_Config.screenHeight,            // height of the window
                          NULL,                             // we have no parent window, NULL
                          NULL,                             // we aren't using menus, NULL
                          hInstance,                        // application handle
                          NULL
    );

    // display window
    ShowWindow(hWnd, SW_SHOW);
    mHWnd = hWnd;

    return result;
}

void My::WindowsApplication::Finalize()
{
}

void My::WindowsApplication::Tick()
{
    MSG msg;
    if(PeekMessage(&msg, NULL, 0,0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}


LRESULT CALLBACK My::WindowsApplication::WindowProc(HWND hWnd, UINT message,WPARAM wParm, LPARAM lParm)
{
    switch(message)
    {
        case WM_PAINT:
            {

            }
            break;
        case WM_DESTROY:
            {
                PostQuitMessage(0);
                BaseApplication::m_bQuit = true;
                return 0;
            }
            break;
    }

    return DefWindowProc(hWnd, message, wParm, lParm);
}