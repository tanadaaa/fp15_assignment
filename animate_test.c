// animate_test --- create animation using img lib.
#include "img.h"

int main(void) {
  struct color black = { 0, 0, 0 };
  struct color white = { 255, 255, 255};
  flash(5);
  int i;
  for(i = 0;i < 40; i++){
    f_mov_framy(i);
  }
  for(i = 0; i < 35; i++) {
    img_clear();
    img_framy(black, 400, 400);
    img_hp_framy(8*i-250, 400, 100);
    img_write();
  }
  for(i = 0;i < 80;i++){
    img_clear();
    img_framy(black, 400, 400);
    img_hp_framy(30, 400, 100);
    framy_c(100, 100);
    mickey_c(100,50);
    img_hp_mickey(600, 200, 100);
    img_write();
  }
}