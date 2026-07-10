```c
#include"swl.h"

loop(float dt){
    if (swl_IsKeyDown(27)) swl_SendQuitEvent();
}
int main() {
    swl_CreateWindow("X",400,300);
    //void* h = swl_GetWindowPtr();
    swl_Mainloop(loop);
    swl_CloseWindow();
    return 0;
}
```
