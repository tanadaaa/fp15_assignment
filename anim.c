#include <stdio.h>
#include <stdlib.h>
#include "img.h"

void f_mov_framy(int i){
    struct color black = { 0, 0, 0 };
    img_clear();
    img_framy(black, 680-i*7, 400);
    img_write();
}