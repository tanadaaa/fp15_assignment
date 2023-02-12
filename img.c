#include <stdio.h>
#include <stdlib.h>
#include "img.h"

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void img_clear(void) {
    int i, j;
    for(j = 0; j < HEIGHT; ++j) {
        for(i = 0; i < WIDTH; ++i) {
            buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
        }
    }
}

void img_write(void) {
    sprintf(fname, "C:/Users/Y.Taketo/github/fp15_assignment/ppmfile/img%04d.ppm", ++filecnt);
    FILE *f = fopen(fname, "wb");
    if(f == NULL) { fprintf(stderr, "can't open %s\n", fname); exit(1); }
    fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(buf, sizeof(buf), 1, f);
    fclose(f);
}

void img_putpixel(struct color c, int x, int y) {
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) { return; }
    buf[HEIGHT-y-1][x][0] = c.r;
    buf[HEIGHT-y-1][x][1] = c.g;
    buf[HEIGHT-y-1][x][2] = c.b;
}

void img_drawhline(struct color c, int x1, int x2, int y) {
    int i;
    for(i = x1; i <= x2; ++i) {
        img_putpixel(c, i, y);
    }
}

void img_drawvline(struct color c, int x, int y1, int y2) {
    int i;
    for(i = y2; i <= y1; ++i) {
        img_putpixel(c, x, i);
    }
}

void img_fillcircle(struct color c, double x, double y, double r) {
    int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
    int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
    int i, j;
    for(j = jmin; j <= jmax; ++j) {
        for(i = imin; i <= imax; ++i) {
            if((x-i)*(x-i) + (y-j)*(y-j) <= r*r) { img_putpixel(c, i, j); }
        }
    }
}

void img_rectangle(struct color c, int x1, int y1, int x2, int y2) {
    int i, j;
    for(i = x1; i <= x2; ++i) {
        img_putpixel(c, i, y1);
        img_putpixel(c, i, y2);
    }
    for(j = y2; j <= y1; ++j) {
        img_putpixel(c, x1, j);
        img_putpixel(c, x2, j);
    }
}

void img_fillrect(struct color c, int x1, int y1, int x2, int y2) {
    int i, j;
    for(i = x1; i <= x2; ++i) {
        for(j = y1; j <= y2; ++j) {
            img_putpixel(c, i, j);
        }
    }
}

void img_filltri(struct color c, int x1, int y1) {
    int i;
    for(i = 0; i <= 3; ++i) {
        img_drawvline(c, x1+i, y1+6, y1-8);
        img_drawvline(c, x1+4+i, y1+4, y1-6);
        img_drawvline(c, x1+8+i, y1+2, y1-4);
        img_drawvline(c, x1+12+i, y1, y1-2);
    }
}

void img_filltri2(struct color c, int x1, int y1) {
    int i;
    for(i = 0; i <= 3; ++i) {
        img_drawvline(c, x1-i, y1+6, y1-8);
        img_drawvline(c, x1-4-i, y1+4, y1-6);
        img_drawvline(c, x1-8-i, y1+2, y1-4);
        img_drawvline(c, x1-12-i, y1, y1-2);
    }
}

void img_filltri_forhp(struct color c, int x1, int y1) {
    struct color w = {255, 255, 255};
    img_filltri(c, x1, y1);
    img_fillrect(w, x1, y1-2, x1+16, y1-8);
}

void img_filltri_forhp2(struct color c, int x1, int y1) {
    struct color w = {255, 255, 255};
    img_filltri2(c, x1, y1);
    img_fillrect(w, x1-16, y1-2, x1, y1-8);
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
    img_fillrect(c, x1+23, y1+10, x1+24, y1+9); // 左目
    img_fillrect(c, x1+35, y1+10, x1+36, y1+9); // 右目
}

void img_rectangle_forhp(int x1, int y1, int x2, int y2) {
    int i, j;
    struct color w = {255, 255, 255};
    struct color b = {0, 0, 0};
    for(i = x1; i <= x2; ++i) {
        img_putpixel(b, i, y1);
        img_putpixel(b, i, y1-1);
        img_putpixel(b, i, y2);
        img_putpixel(b, i, y2+1);
    }
    for(j = y2; j <= y1; ++j) {
        img_putpixel(b, x1, j);
        img_putpixel(b, x1+1, j);
        img_putpixel(b, x2, j);
        img_putpixel(b, x2-1, j);
    }
    img_fillrect(w, x1, y1, x1+1, y1-1);
    img_fillrect(w, x1, y2+1, x1+1, y2);
    img_fillrect(w, x2-1, y1, x2, y1-1);
    img_fillrect(w, x2-1, y2+1, x2, y2);
}

void img_hp_gage(int x1, int y1, int hp) {
    struct color green = {0, 255, 0};
    struct color yellow = {255, 241, 0};
    struct color red = {255, 0, 0};
    int hpp = hp*2;
    if(hp >= 50) {
        img_fillrect(green, x1, y1, x1+hp*2, y1-10);
    } else if (20 <= hp && hp < 50){
        img_fillrect(yellow, x1, y1, x1+hp*2, y1-10);
    } else {
        img_fillrect(red, x1, y1, x1+hp*2, y1-10);
    }
    img_rectangle_forhp(x1, y1, x1+200, y1-10);
}

void img_hp_frame1(int x1, int y1) {
    struct color b = {0, 0, 0};
    struct color w = {255, 255, 255};
    img_drawvline(b, x1, y1, y1-30);
    img_drawvline(b, x1+1, y1, y1-30);
    img_drawhline(b, x1, x1+250, y1-29);
    img_drawhline(b, x1, x1+250, y1-30);
    img_putpixel(w, x1, y1-30);
    img_putpixel(w, x1+1, y1-30);
    img_putpixel(w, x1, y1-29);
    img_filltri_forhp(b, x1+240, y1-29);
}

void img_hp_frame2(int x1, int y1) {
    struct color b = {0, 0, 0};
    struct color w = {255, 255, 255};
    img_drawvline(b, x1, y1, y1-50);
    img_drawvline(b, x1-1, y1, y1-50);
    img_drawhline(b, x1-250, x1, y1-49);
    img_drawhline(b, x1-250, x1, y1-50);
    img_putpixel(w, x1, y1-50);
    img_putpixel(w, x1-1, y1-50);
    img_putpixel(w, x1, y1-49);
    img_filltri_forhp2(b, x1-240, y1-49);
}

void img_hp_framy(int x, int y, int hp) {
    img_hp_frame1(x, y);
    img_hp_gage(x+40, y-10, hp);
}

void img_hp_mickey(int x, int y, int hp) {
    img_hp_frame2(x, y);
    img_hp_gage(x-210, y-10, hp);
}
