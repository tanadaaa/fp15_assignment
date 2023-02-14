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
        img_clear();
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

double fg(double d1, double d2){
    return d1 * d2 /sqrt(25.0*25.0 + 27.0*27.0);
}

void Hyper_Beam(double x, double y, int i){
    struct color black = {0,0,0};
    struct color yellow = {255,255,0};
    struct color white = {255,255,255};
    if(i < 30){
        double id = i;
        double zsl = id*6.0*(25.0/27.0);
        img_fillcircle(black,x+i*6,y+zsl,27);
        img_fillcircle(yellow,x+i*6,y+zsl,25);
        img_fillcircle(white,x+i*6,y+zsl,23);
        if(i*6.0 >= fg(27,27)){
            double mm = i*6.0-fg(27,27);
            int j;
            for(j = 0; j <= mm; j++){
                double jd = j;
                double dsl = jd*(25.0/27.0);
                img_putpixel(black, x - fg(14,25) + 5 + j, y + fg(14,27) + dsl + 5);
                img_putpixel(black, x - fg(13,25) + 5 + j, y + fg(13,27) + dsl + 5);
                img_putpixel(black, x - fg(12,25) + 5 + j, y + fg(12,27) + dsl + 5);
                img_putpixel(black, x - fg(11,25) + 5 + j, y + fg(11,27) + dsl + 5);
                img_putpixel(yellow, x - fg(10,25) + 5 + j, y + fg(10,27) + dsl + 5);
                img_putpixel(black, x + fg(14,25) + 5 + j, y - fg(14,27) + dsl + 5);
                img_putpixel(black, x + fg(13,25) + 5 + j, y - fg(13,27) + dsl + 5);
                img_putpixel(black, x + fg(12,25) + 5 + j, y - fg(12,27) + dsl + 5);
                img_putpixel(black, x + fg(11,25) + 5 + j, y - fg(11,27) + dsl + 5);
                img_putpixel(yellow, x + fg(10,25) + 5 + j, y - fg(10,27) + dsl + 5);
            }
        }
    }
    else if(i >= 30 && i < 60){
        double mm = 30*6.0-fg(27,27);
        int j;
        for(j = 0; j <= mm; j++){
            double jd = j;
            double dsl = jd*(25.0/27.0);
            img_putpixel(black, x - fg(14,25) + 5 + j, y + fg(14,27) + dsl + 5);
            img_putpixel(black, x - fg(13,25) + 5 + j, y + fg(13,27) + dsl + 5);
            img_putpixel(black, x - fg(12,25) + 5 + j, y + fg(12,27) + dsl + 5);
            img_putpixel(black, x - fg(11,25) + 5 + j, y + fg(11,27) + dsl + 5);
            img_putpixel(yellow, x - fg(10,25) + 5 + j, y + fg(10,27) + dsl + 5);
            img_putpixel(black, x + fg(14,25) + 5 + j, y - fg(14,27) + dsl + 5);
            img_putpixel(black, x + fg(13,25) + 5 + j, y - fg(13,27) + dsl + 5);
            img_putpixel(black, x + fg(12,25) + 5 + j, y - fg(12,27) + dsl + 5);
            img_putpixel(black, x + fg(11,25) + 5 + j, y - fg(11,27) + dsl + 5);
            img_putpixel(yellow, x + fg(10,25) + 5 + j, y - fg(10,27) + dsl + 5);
        }
    }
    else{
        double mm = 30*6.0-fg(27,27);
        int j;
        for(j = 0; j <= mm; j++){
            double jd = j;
            double dsl = jd*(25.0/27.0);
            if(j > (i-60)*6.0-fg(27,27)){
                img_putpixel(black, x - fg(14,25) + 5 + j, y + fg(14,27) + dsl + 5);
                img_putpixel(black, x - fg(13,25) + 5 + j, y + fg(13,27) + dsl + 5);
                img_putpixel(black, x - fg(12,25) + 5 + j, y + fg(12,27) + dsl + 5);
                img_putpixel(black, x - fg(11,25) + 5 + j, y + fg(11,27) + dsl + 5);
                img_putpixel(yellow, x - fg(10,25) + 5 + j, y + fg(10,27) + dsl + 5);
                img_putpixel(black, x + fg(14,25) + 5 + j, y - fg(14,27) + dsl + 5);
                img_putpixel(black, x + fg(13,25) + 5 + j, y - fg(13,27) + dsl + 5);
                img_putpixel(black, x + fg(12,25) + 5 + j, y - fg(12,27) + dsl + 5);
                img_putpixel(black, x + fg(11,25) + 5 + j, y - fg(11,27) + dsl + 5);
                img_putpixel(yellow, x + fg(10,25) + 5 + j, y - fg(10,27) + dsl + 5);
            }
        }
    }
}