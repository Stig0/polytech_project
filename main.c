#include <stdio.h> 
#include <allegro5/allegro.h> 
#include <allegro5\allegro_primitives.h> 
#include <allegro5\allegro_font.h> 
#include <allegro5\allegro_ttf.h> 
#include <allegro5/allegro_image.h> 
#include "allegro5/allegro_native_dialog.h" 

const float FPS = 60; 
const int SCREEN_W = 840; 
const int SCREEN_H = 580; 
const int BOUNCER_SIZE = 32; 
int b1(int b[20][20]); 
int b2(int b[20][20]); 
int b3(int b[20][20]); 
int b4(int b[20][20]); 
int l1(int b[20][20]); 
int m = 20; 
int main(int argc, char **argv) 
{ 
ALLEGRO_DISPLAY *display = NULL; 
ALLEGRO_EVENT_QUEUE *event_queue = NULL; 
ALLEGRO_TIMER *timer = NULL; 
ALLEGRO_BITMAP *bouncer = NULL; 
ALLEGRO_BITMAP *image = NULL; 
float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0; 
float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0; 
int imageWidth = 0; 
int imageHeight = 0; 
bool redraw = true; 
if (!al_init()) { 
fprintf(stderr, "failed to initialize allegro!\n"); 
return -1; 
} 
if (!al_init_image_addon()) { 
al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", 
NULL, ALLEGRO_MESSAGEBOX_ERROR); 
return 0; 
} 
if (!al_install_mouse()) { 
fprintf(stderr, "failed to initialize the mouse!\n"); 
return -1; 
} 

timer = al_create_timer(4.0 / FPS); 
if (!timer) { 
fprintf(stderr, "failed to create timer!\n"); 
return -1; 
} 

display = al_create_display(SCREEN_W, SCREEN_H); 
if (!display) { 
fprintf(stderr, "failed to create display!\n"); 
al_destroy_timer(timer); 
return -1; 
} 

bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE); 
if (!bouncer) { 
fprintf(stderr, "failed to create bouncer bitmap!\n"); 
al_destroy_display(display); 
al_destroy_timer(timer); 
return -1; 
} 
image = al_load_bitmap("startstepstopclean2.png"); 
image = al_load_bitmap("rules4.png"); 
image = al_load_bitmap("randomplanerrellay.png"); 



if (!image) { 
al_show_native_message_box(display, "Error", "Error", "Failed to load image!", 
NULL, ALLEGRO_MESSAGEBOX_ERROR); 
al_destroy_display(display); 
return 0; 
} 

al_draw_bitmap(image, 200, 200, 50); 
al_set_target_bitmap(bouncer); 

al_clear_to_color(al_map_rgb(255, 0, 255)); 

al_set_target_bitmap(al_get_backbuffer(display)); 

event_queue = al_create_event_queue(); 
if (!event_queue) { 
fprintf(stderr, "failed to create event_queue!\n"); 
al_destroy_bitmap(bouncer); 
al_destroy_display(display); 
al_destroy_timer(timer); 
return -1; 
} 

al_install_keyboard(); 
al_register_event_source(event_queue, al_get_display_event_source(display)); 

al_register_event_source(event_queue, al_get_timer_event_source(timer)); 

al_register_event_source(event_queue, al_get_mouse_event_source()); 
al_register_event_source(event_queue, al_get_keyboard_event_source()); 

al_init_font_addon(); // initialize the font addon 
al_init_ttf_addon();// initialize the ttf (True Type Font) addon 


al_clear_to_color(al_map_rgb(0, 0, 0)); 



al_init_primitives_addon(); 

al_flip_display(); 

al_start_timer(timer); 
int i, j, k, x, h, y = 1, n = 0, f = 0, t = 0; 
int a[100][100], b[20][20]; 

int cle=0; 
int menu=0, level=4,lev=0; 
int kol = 0, kol_max = 300,c1=0; 
int life = 0, deaf = 0; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 





image = al_load_bitmap("startstepstopclean2.png"); 
al_draw_bitmap(image, 0, 0, 0); 

image = al_load_bitmap("rules4.png"); 
al_draw_bitmap(image, 510, 80, 0); 

image = al_load_bitmap("randomplanerrellay.png"); 
al_draw_bitmap(image, 10, 520, 0); 

al_draw_filled_rectangle(10, 100, 110, 120, al_map_rgb(500, 0, 255)); 
while (1) 
{ 



cle=cle+1; 
if (cle == 10) { 
cle = 0; 
al_draw_filled_rectangle(0,120, 110, 400, al_map_rgb(0, 0, 0)); 
} 


ALLEGRO_EVENT ev; 
al_wait_for_event(event_queue, &ev); 

if (ev.type == ALLEGRO_EVENT_TIMER) { 
redraw = true;
} 
else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { 
break; 
} 
else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || 
ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) { 

bouncer_x = ev.mouse.x; 
bouncer_y = ev.mouse.y; 
} 
if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) 
{ 

if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 0 && bouncer_x < 125)) { 
f = 10; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) 
if(b[i][j]>2){ 
b[i][j] = 0; 
} 
} 
} 
else if 
((bouncer_y > 100 && bouncer_y < 120) && (bouncer_x >10 && bouncer_x < 110)) { 
if (menu == 1) menu = 0; 
else if (menu == 0) menu = 1; 

} 
else if //активация первого уровня; 

(((bouncer_y > 125 && bouncer_y < 145) && (bouncer_x > 10 && bouncer_x < 110)) && (menu == 1)) { 
al_clear_to_color(al_map_rgb(0, 0, 0)); 
menu = 0; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 
kol = 0; 
al_draw_filled_rectangle(10, 100, 110, 120, al_map_rgb(500, 0, 255)); 
image = al_load_bitmap("startstepstopclean2.png");//Перерисовка 
al_draw_bitmap(image, 0, 0, 0); 
image = al_load_bitmap("randomplanerrellay.png");//Перерисовка 
al_draw_bitmap(image, 10, 520, 0); 
al_draw_filled_rectangle(510, 80, 600, 400, al_map_rgb(0, 110, 0));//Правила 
kol_max = 6;//Максимальное число клеток 
lev = 1; 
l1(b); 
} 

else if 
((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 125 && bouncer_x < 250)) { 
f =1; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) 
if (b[i][j]>2) { 
b[i][j] = 0; 
} 
} 

} 
else if ((bouncer_y 
> 0 && bouncer_y < 80) && (bouncer_x > 250 && bouncer_x < 375)) { 
f = 3; 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) 
if (b[i][j]>2) { 
b[i][j] = 0; 
} 
} 
} 

else if ((bouncer_y > 0 && bouncer_y < 80) && (bouncer_x > 375 && bouncer_x < 500)) { 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 

} 
else if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 10 && bouncer_x < 145)) { 
srand((unsigned)time(NULL)); 
for (j = 1; j < m; j++) { 

for (i = 1; i < m; i++) { 

t = rand() % 2; 
b[i][j] = t; 
} 
} 
} 
else if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 147 && bouncer_x < 279)) { 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 
b1(b); 
} 
else if ((bouncer_y > 520 && bouncer_y < 550) && (bouncer_x > 280 && bouncer_x < 420)) { 
for (j = 0; j < m; j++) { 
for (i = 0; i < m; i++) { 
b[i][j] = 0; 
} 
} 

b2(b); 


} 




else { 

for (y = 1; y < m; y++) { 
if ((bouncer_y>93 + 20 * y)&& (bouncer_y<107 + 20 * y)) 
for (x = 1; x < m; x++) 
{ 
if ((bouncer_x>93 + 20 * x) && (bouncer_x<107 + 20 * x)) { 
if (b[x][y] == 1) { 
b[x][y] = 0; 
kol--; 

} 
else if ((b[x][y] == 0) && kol < kol_max) { 
b[x][y] = 1; 
kol++; 
} 
else if ((b[x][y] == 3) && kol < kol_max) { 
b[x][y] = 1; 
kol++; 

} 
} 

} 
} 
} 
} 

if(menu==1) 
for (j = 0; j < level;j++) 
{ 
redraw = true; 
al_draw_filled_rectangle(10, 100+25*j, 110, 120+25*j, al_map_rgb(500, 0, 255)); 
redraw = true; 
al_flip_display(); 
} 
if (lev == 1) { 
life = 0; 
c1 = 0; 
for (y = 1; y < m; y++) { 

for (x = 1; x < m; x++) 
{ 
if(b[x][y] == 1|| b[x][y] == 3)life=1; 
if (b[x][y] == 2)c1 = 1; 

} 
} 
if(life==0) 
for (y = 1; y < m; y++) { 

for (x = 1; x < m; x++) 
{ 
b[x][y] = 2; 
lev = 0; 
f = 0; 
} 
} 
else if (c1 == 0) 
for (y = 1;
y < m; y++) { 
f = 0; 
for (x = 1; x < m; x++) 
{ 
b[x][y] = 3; 
lev = 0; 
f = 0; 
} 
} 


} 
for (y = 1; y < m; y++) { 

for (x = 1; x < m; x++) 
{ 
if (b[x][y] == 1) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(0, 0, 255)); 
redraw = true; 
} 
else if (b[x][y] == 0) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(255, 255, 255)); 
} 
else if (b[x][y] == 3) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(0, 255,0)); 
} 
else if (b[x][y] == 2) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(255, 0, 2)); 
} 
} 
} 
if (ev.type == ALLEGRO_EVENT_KEY_DOWN&&f == 0) 
{ 



switch (ev.keyboard.keycode) { 

case ALLEGRO_KEY_SPACE: 
f = 1; 
} 
} 
if (f == 1) 
{ 
f = 0; 

for (j = 1; j < m; j++) { 
for (i = 1; i < m; i++) { 
if (b[i - 1][j - 1] == 1) k++; 
if (b[i][j - 1] == 1) k++; 
if (b[i + 1][j - 1] == 1) k++; 
if (b[i - 1][j] == 1) k++; 
if (b[i + 1][j] == 1) k++; 
if (b[i - 1][j + 1] == 1) k++; 
if (b[i][j + 1] == 1) k++; 
if (b[i + 1][j + 1] == 1) k++; 
if (b[i][j] == 1) 
{ 
if ((k == 2) || (k == 3)) a[i][j] = 1; 
else a[i][j] = 0; 
} 
if (b[i][j] == 0) { 
if ((k == 3)) a[i][j] = 1; 
else a[i][j] = 0; 
} 
if (b[i][j] == 2) { 
if ((k == 3)) a[i][j] = 1; 
else if (b[i][j] == 0) a[i][j] = 0; 
else a[i][j] = 2; 
} 
k = 0; 
} 
} 
for (y = 1; y < m; y++) { 
for (x = 1; x < m; x++) 
{ 
b[x][y] = a[x][y]; 
redraw = true; 
} 
} 


} 
else if (f == 3) 
{ 
f = 0; 


} 
else if (f == 10) 
{ 



if (ev.type == ALLEGRO_EVENT_KEY_DOWN) 
{ 



switch (ev.keyboard.keycode) { 

case ALLEGRO_KEY_SPACE: 
f = 0; 
break; 
default: 
continue; 
} 



} 
for (y = 1; y < m; y++) { 

for (x = 1; x < m; x++) 
{ 
if (b[x][y] == 1) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(0, 0, 255)); 
redraw = true; 
} 
else if (b[x][y] == 0) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(255, 255, 255)); 
} 
else if (b[x][y] == 3) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(0, 255, 0)); 
} 
else if (b[x][y] == 2) { 
al_draw_filled_ellipse(100 + 20 * x, 100 + 20 * y, 7, 7, al_map_rgb(255, 0, 2)); 
} 
} 
} 
for (j = 1; j < m; j++) { 
for (i = 1; i < m; i++) { 
if (b[i - 1][j - 1] == 1) k++; 
if (b[i][j - 1] == 1) k++; 
if (b[i + 1][j - 1] == 1) k++; 
if (b[i - 1][j] == 1) k++; 
if (b[i + 1][j] == 1) k++; 
if (b[i - 1][j + 1] == 1) k++; 
if (b[i][j + 1] == 1) k++; 
if (b[i + 1][j + 1] == 1) k++; 
if (b[i][j] == 1) 
{ 
if ((k == 2) || (k == 3)) a[i][j] = 1; 
else a[i][j] = 0; 
} 
if (b[i][j] == 0) { 
if ((k == 3)) a[i][j] = 1; 
else a[i][j] = 0; 
} 
if (b[i][j] == 2) { 
if ((k == 3)) a[i][j] = 1; 
else if (b[i][j] == 0) a[i][j] = 0; 
else a[i][j] = 2; 
} 
k = 0; 
} 
} 
for (y = 1; y < m; y++) { 
for (x = 1; x < m; x++) 
{ 
b[x][y] = a[x][y]; 
redraw = true; 
} 
} 






} 


al_flip_display(); 

} 
al_destroy_bitmap(bouncer); 
al_destroy_timer(timer); 
al_destroy_display(display); 
al_destroy_event_queue(event_queue); 

return 0; 
}
