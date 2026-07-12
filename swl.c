#include"swl.h"
#include<Windows.h>
#define SWL __declspec(dllexport)
LARGE_INTEGER f,l,c;HWND _h;BYTE k[256],pk[256];
LRESULT CALLBACK _c(HWND h,UINT m,WPARAM w,LPARAM l){
    switch (m) {case 2: PostQuitMessage(0); break;}
    return DefWindowProcA(h,m,w,l);
}
SWL void swl_CreateWindow(const char* t, int w, int h){
    WNDCLASSA c={0,_c,0,0,GetModuleHandleA(0),0,LoadCursorA(0,(LPCSTR)IDC_ARROW),0,0,"w"};
    RegisterClassA(&c);
    int _s=CW_USEDEFAULT,_style=WS_OVERLAPPEDWINDOW|WS_VISIBLE;
    _h=CreateWindowA("w",t,_style,_s,_s,w,h,0,0,c.hInstance,0);
    QueryPerformanceFrequency(&f);QueryPerformanceCounter(&l);
}
SWL void*swl_GetWindowPtr(){return (void*)_h;}
SWL void swl_CloseWindow(){DestroyWindow(_h);}
SWL void swl_SendQuitEvent(){PostQuitMessage(0);}
SWL void swl_Mainloop(int (*loop)(float)){
    for(MSG m={0};m.message!=18;){
        for(;PeekMessageW(&m,0,0,0,1)>0;){
            TranslateMessage(&m);
            DispatchMessageW(&m);
        }
        for(int i=0;i<256;i++)pk[i]=k[i];
        GetKeyboardState(k);
        QueryPerformanceCounter(&c);
        float dt=(float)(c.QuadPart-l.QuadPart)/(float)f.QuadPart;l=c;
        loop(dt);
        Sleep(1);
    }
}
SWL int swl_IsKeyDown(int y){return k[y]&128;}
SWL int swl_IsKeyPressed(int y){return (k[y]&128)&&!(pk[y]&128);}
SWL int swl_IsKeyReleased(int y){return !(k[y]&128)&&(pk[y]&128);}
SWL void swl_GetMousePos(int* x, int* y){
    POINT p; 
    GetCursorPos(&p); 
    ScreenToClient(_h, &p);
    *x = p.x; 
    *y = p.y;
}
