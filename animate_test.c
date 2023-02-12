// animate_test --- create animation using img lib.
#include "img.h"

int main(void) {
  struct color black = { 0, 0, 0 };
  struct color white = { 255, 255, 255};
  flash(5);
  int i;
  for(i = 0;i < 80; i++){
    f_mov_framy(i);
  }
}