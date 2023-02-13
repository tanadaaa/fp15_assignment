#!/bin/zsh
gcc anim.c animate_test.c character.c effect.c img.c && ./a.out && convert -delay 5 ppmfile/img*.ppm animate1.gif