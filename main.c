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
