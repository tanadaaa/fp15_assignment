#define WIDTH 640
#define HEIGHT 480
struct color { unsigned char r, g, b; };
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void img_rectangle(struct color c, int x1, int y1, int x2, int y2);
void img_fillrect(struct color c, int x1, int y1, int x2, int y2);
void img_framy(struct color c, int x1, int y1);
void flash(int n);
void f_mov_framy(int i);
void HP(int x, int y);