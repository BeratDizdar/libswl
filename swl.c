#include"swl.h"
#include<Windows.h>
LARGE_INTEGER f,l,c;HWND _h;LRESULT CALLBACK _c(HWND h,UINT m,WPARAM w,LPARAM l){
    switch (m) {case 2: PostQuitMessage(0); break;}
    return DefWindowProcA(h,m,w,l);
}
void swl_CreateWindow(const char* t, int w, int h){
    WNDCLASSA c={0,_c,0,0,GetModuleHandleA(0),0,LoadCursorA(0,(LPCSTR)IDC_ARROW),0,0,"w"};
    RegisterClassA(&c);
    _h=CreateWindowA("w",t,WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        0x80000000,0x80000000,w,h,0,0,c.hInstance,0);
    QueryPerformanceFrequency(&f);QueryPerformanceCounter(&l);
}
void*swl_GetWindowPtr(){return (void*)_h;}
void swl_CloseWindow(){DestroyWindow(_h);}
void swl_SendQuitEvent(){PostQuitMessage(0);}
void swl_Mainloop(int (*loop)(float)){
    for(MSG m={0};m.message!=18;){
        for(;PeekMessageW(&m,0,0,0,1)>0;){
            TranslateMessage(&m);
            DispatchMessageW(&m);
        }
        QueryPerformanceCounter(&c);
        float dt=(float)(c.QuadPart-l.QuadPart)/(float)f.QuadPart;l=c;
        loop(dt);
        Sleep(1);
    }
}
int swl_IsKeyDown(int key){return GetAsyncKeyState(key);}