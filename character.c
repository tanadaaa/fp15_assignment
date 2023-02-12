#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];


void HP(int x, int y){
    struct color black = { 0, 0, 0 };
    int arr[8][18] = {{1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1},
                      {1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1},
                      {1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1},
                      {1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,1,1},
                      {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
                      {1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0},
                      {1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0}};
    int i,j;
    for(i = 0;i < 8;i++){
        for(j = 0;j < 18;j++){
            if(arr[i][j])img_putpixel(black,x+j,y-i);
        }
    }
}


void img_framy(struct color c, int x1, int y1) {
    img_rectangle(c, x1+40, y1, x1+120, y1-40); // 胴体
    img_rectangle(c, x1+15, y1+25, x1+50, y1-10); // 顔
    img_rectangle(c, x1, y1, x1+22, y1-10); // 鼻
    img_fillrect(c, x1, y1, x1+8, y1-3); // 鼻の先
    img_rectangle(c, x1+8, y1+35, x1+20, y1+19); // 左耳
    img_rectangle(c, x1+44, y1+35, x1+56, y1+19); // 右耳
    img_rectangle(c, x1+117, y1+3, x1+135, y1-5); // しっぽ
    img_rectangle(c, x1+45, y1-48, x1+55, y1-71); // 左前脚
    img_rectangle(c, x1+62, y1-45, x1+72, y1-68); // 右前脚
    img_rectangle(c, x1+87, y1-48, x1+97, y1-71); // 左後脚
    img_rectangle(c, x1+108, y1-45, x1+118, y1-68); // 右後脚
    img_fillcircle(c, x1+23, y1+10, 1); // 左目
    img_fillcircle(c, x1+35, y1+10, 1); // 右目
}