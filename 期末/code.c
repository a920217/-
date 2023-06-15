#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <Windows.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 350

typedef struct
{
    uint16_t ScreenMemoryLocation;
    uint8_t ScreenMemory[4000];
} B32Screen;

void B32Screen_Init(B32Screen *screen)
{
    screen->ScreenMemoryLocation = 0xA000;
    memset(screen->ScreenMemory, 0, sizeof(screen->ScreenMemory));
    for (int i = 0; i < 4000; i += 2)
    {
        screen->ScreenMemory[i] = 32;
        screen->ScreenMemory[i + 1] = 7;
    }
}

void B32Screen_Poke(B32Screen *screen, uint16_t address, uint8_t value)
{
    int16_t memLoc;
    try
    {
        memLoc = address - screen->ScreenMemoryLocation;
    }
    catch (...)
    {
        return;
    }
    if (memLoc < 0 || memLoc > 3999)
        return;
    screen->ScreenMemory[memLoc] = value;
}

uint8_t B32Screen_Peek(B32Screen *screen, uint16_t address)
{
    int16_t memLoc;
    try
    {
        memLoc = address - screen->ScreenMemoryLocation;
    }
    catch (...)
    {
        return 0;
    }
    if (memLoc < 0 || memLoc > 3999)
        return 0;
    return screen->ScreenMemory[memLoc];
}

void B32Screen_Draw(B32Screen *screen, HDC hdc)
{
    HFONT font = CreateFontA(8, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                             CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FIXED_PITCH | FF_DONTCARE, "Courier New");
    SelectObject(hdc, font);

    int xLoc = 0;
    int yLoc = 0;
    for (int i = 0; i < 4000; i += 2)
    {
        HBRUSH bgBrush = NULL;
        HBRUSH fgBrush = NULL;

        if ((screen->ScreenMemory[i + 1] & 112) == 112)
        {
            bgBrush = CreateSolidBrush(RGB(128, 128, 128));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 96)
        {
            bgBrush = CreateSolidBrush(RGB(128, 64, 0));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 80)
        {
            bgBrush = CreateSolidBrush(RGB(255, 0, 255));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 64)
        {
            bgBrush = CreateSolidBrush(RGB(255, 0, 0));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 48)
        {
            bgBrush = CreateSolidBrush(RGB(0, 255, 255));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 32)
        {
            bgBrush = CreateSolidBrush(RGB(0, 128, 0));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 16)
        {
            bgBrush = CreateSolidBrush(RGB(0, 0, 255));
        }
        if ((screen->ScreenMemory[i + 1] & 112) == 0)
        {
            bgBrush = CreateSolidBrush(RGB(0, 0, 0));
        }

        if ((screen->ScreenMemory[i + 1] & 7) == 0)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(128, 128, 128));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(0, 0, 0));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 1)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(176, 224, 230));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(0, 0, 255));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 2)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(144, 238, 144));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(0, 128, 0));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 3)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(224, 255, 255));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(0, 255, 255));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 4)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(255, 192, 203));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(255, 0, 0));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 5)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(255, 0, 255));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(255, 0, 255));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 6)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(255, 255, 0));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(128, 64, 0));
            }
        }
        if ((screen->ScreenMemory[i + 1] & 7) == 7)
        {
            if ((screen->ScreenMemory[i + 1] & 8) == 8)
            {
                fgBrush = CreateSolidBrush(RGB(255, 255, 255));
            }
            else
            {
                fgBrush = CreateSolidBrush(RGB(128, 128, 128));
            }
        }

        if (bgBrush == NULL)
            bgBrush = CreateSolidBrush(RGB(0, 0, 0));
        if (fgBrush == NULL)
            fgBrush = CreateSolidBrush(RGB(128, 128, 128));

        if (((xLoc % SCREEN_WIDTH) == 0) && (xLoc != 0))
        {
            yLoc += 11;
            xLoc = 0;
        }

        char s[2] = {screen->ScreenMemory[i], '\0'};
        TextOutA(hdc, xLoc, yLoc, s, 1);

        xLoc += 8;

        DeleteObject(bgBrush);
        DeleteObject(fgBrush);
    }

    DeleteObject(font);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        B32Screen screen;
        B32Screen_Init(&screen);
        B32Screen_Draw(&screen, hdc);

        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc = {sizeof(WNDCLASSEX)};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = "B32VirtualMachine";

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "RegisterClassEx failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    HWND hWnd = CreateWindowEx(0, "B32VirtualMachine", "B32 Virtual Machine", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT,
                               NULL, NULL, hInstance, NULL);

    if (!hWnd)
    {
        MessageBox(NULL, "CreateWindowEx failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
