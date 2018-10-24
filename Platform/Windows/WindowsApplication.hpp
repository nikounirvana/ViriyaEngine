#pragma once
#include <windows.h>
#include <windowsx.h>
#include "BaseApplication.hpp"

namespace My{
    class WindowsApplication : public BaseApplication
    {
    public:
        WindowsApplication(GfxConfiguration& config)
            :BaseApplication(config){}

        virtual int     Initialize();
        virtual void    Finalize();
        virtual void    Tick();

        static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message,
                                    WPARAM wParm, LPARAM lParm);
        inline HWND GetMainWindow(){return mHWnd;}

    private:
        HWND mHWnd;
    };
}