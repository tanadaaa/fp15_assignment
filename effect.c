#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

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