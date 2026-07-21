#pragma once
// ufak deneyler için ekledim
//#define APIENTRY __cdecl
//#define WINGDIAPI

void swl_CreateWindow(const char* t, int w, int h);
void*swl_GetWindowPtr();
void swl_CloseWindow();
void swl_SendQuitEvent();
void swl_Mainloop(int(*loop)(float));
int  swl_IsKeyDown(int y);
int  swl_IsKeyPressed(int y);
int  swl_IsKeyReleased(int y);
void swl_GetMousePos(int* x, int* y);
void swl_GL_CreateContext();
void swl_GL_DestroyContext();
void swl_GL_SwapBuffers();
void*swl_GL_GetProcAddress(const char* proc);
