#include <stdio.h>
#include <stdlib.h>
#include "img.h"

struct color black = { 0, 0, 0 };
    int i;

void flash(int n){
    for(i = 0; i < n; i++){
        img_clear();
        if(i >= 0 && i < n/5){img_fillrect(black, 0, 479, 639, 0);}
        if(i >= n/5 && i < n*2/5){}
        if(i >= n*2/5 && i < n*3/5){img_fillrect(black, 0, 479, 639, 0);}
        if(i >= n*3/5 && i < n*4/5){}
        if(i >= n*4/5){img_fillrect(black, 0, 479, 639, 0);}
        img_write();
    }
    
}

void f_mov_framy(int i){
    img_clear();
    img_framy(black, 680-i*7, 400);
    img_write();
}