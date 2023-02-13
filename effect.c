#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void flash(int n){
    struct color black = { 0, 0, 0 };
    int i;
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

void rolling(void){
    struct color black = { 0, 0, 0 };
    struct color white = { 255, 255, 255 };
    int i;
    for(i = 0;i < 30;i++){
        img_clear;
        int j,k;
        for(j = 0; j < WIDTH; j++){
            for(k = 0; k < HEIGHT; k++){
                img_putpixel(white,j,k);
                int xm = j - WIDTH/2 , ym = k - HEIGHT/2;
                if(i <= 30/2){
                    if (ym <= tan( (M_PI * i*3 ) / 90) * xm && ym >= 0)img_putpixel(black,j,k);
                    if (ym >= tan( (M_PI * i*3 ) / 90) * xm && ym <= 0)img_putpixel(black,j,k);
                }
                else{
                    if(xm*ym >= 0)img_putpixel(black,j,k);
                    if (ym <= tan( (M_PI * i*3 ) / 90) * xm && ym <= 0)img_putpixel(black,j,k);
                    if (ym >= tan( (M_PI * i*3 ) / 90) * xm && ym >= 0)img_putpixel(black,j,k);
                }
            }
        }
        img_write();
    }
}