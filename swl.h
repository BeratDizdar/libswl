#pragma once

void swl_CreateWindow(const char* t, int w, int h);
void*swl_GetWindowPtr();
void swl_CloseWindow();
void swl_SendQuitEvent();
void swl_Mainloop(int(*loop)(float));
int  swl_IsKeyDown(int key);