#define WIDTH 640
#define HEIGHT 480
struct color { unsigned char r, g, b; };
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_drawhline(struct color c, int x1, int x2, int y);
void img_drawvline(struct color c, int x, int y1, int y2);
void img_fillcircle(struct color c, double x, double y, double r);
void img_rectangle(struct color c, int x1, int y1, int x2, int y2);
void img_fillrect(struct color c, int x1, int y1, int x2, int y2);
void img_filltri(struct color c, int x1, int y1);
void img_filltri2(struct color c, int x1, int y1);
void img_filltri_forhp(struct color c, int x1, int y1);
void img_filltri_forhp2(struct color c, int x1, int y1);
void img_framy(struct color c, int x1, int y1);
void img_rectangle_forhp(int x1, int y1, int x2, int y2);
void img_hp_gage(int x1, int y1, int hp);
void img_hp_frame1(int x1, int y1);
void img_hp_frame2(int x1, int y1);
void img_hp_framy(int x, int y, int hp);
void img_hp_mickey(int x, int y, int hp);
void flash(int n);
void f_mov_framy(int i);
void HP(int x, int y);
void framy_c(int x, int y);
void mickey_c(int x, int y);
