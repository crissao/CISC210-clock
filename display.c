#include "display.h" 

#define BLACK 0x0000
#define WHITE 0xFFFF
#define BLUE 0x0000FF
#define GREEN 0x07E0
#define RED 0x8000
#define DIMWHITE 0xFFFF
#define DIMBLUE 0x0000FF
#define DIMGREEN 0x07E0
#define DIMRED 0x8000



pi_framebuffer_t *fb;
sense_fb_bitmap_t *bm;

int open_display(void) {
	fb=getFrameBuffer();
	bm=fb->bitmap;
	if (fb == NULL || bm->pixel[1][2] == WHITE) {
		return 0;
	}
	else {
		return 1;
	}
}

void display_time(int hours, int minutes, int seconds){
	clearFrameBuffer(fb,BLACK);
	display_colons();
    	display_hours(hours);
    	display_minutes(minutes);
    	display_seconds(seconds);
	
}

void display_colons(void){
	bm->pixel[1][2]=WHITE;
        bm->pixel[1][3]=WHITE;
	bm->pixel[2][2]=WHITE;
        bm->pixel[2][3]=WHITE;
	bm->pixel[4][2]=WHITE;
        bm->pixel[4][3]=WHITE;
	bm->pixel[5][2]=WHITE;
        bm->pixel[5][3]=WHITE;
	bm->pixel[1][5]=WHITE;
        bm->pixel[1][6]=WHITE;
	bm->pixel[2][5]=WHITE;
        bm->pixel[2][6]=WHITE;
	bm->pixel[4][5]=WHITE;
        bm->pixel[4][6]=WHITE;
	bm->pixel[5][5]=WHITE;
        bm->pixel[5][6]=WHITE;
}

void display_hours(int hours) {
	char binary[5];
	for (int i = 0; i < 5; i++) {
		binary[i] = hours%2;
		hours /= 2;
	}
	int pixel = 7;
	for (int j = 0; j < 5; j++) {
		if (binary[j] == 1) {
			bm->pixel[6][pixel]=BLUE;
		}
		pixel -= 1;
	}
}

void display_minutes(int minutes){
	char binary[6];
 	for (int i = 0; i < 6; i++) {
		binary[i] = minutes%2;
		minutes /= 2;
	}
	int pixel = 7;
	for (int j = 0; j < 6; j++) {
		if (binary[j] == 1) {
			bm->pixel[3][pixel]=GREEN;
		}
		pixel -= 1;
	}
}

void display_seconds(int seconds){
	char binary[6];
	for (int i = 0; i < 6; i++) {
		binary[i] = seconds%2;
		seconds /= 2;
	}
	int pixel = 7;
	for (int j = 0; j < 6; j++) {
		if (binary[j] == 1) {
			bm->pixel[0][pixel]=RED;
		}
		pixel -= 1;
	}
}

void close_display(void){
        clearFrameBuffer(fb,BLACK);
	sleep(1);
        freeFrameBuffer(fb);
}
/*
void callbackFunc(unsigned int code){
	if (code == KEY_UP || code == KEY_DOWN || code == KEY_LEFT || code == KEY_RIGHT){
		if (hours > 12){
			dim_pixels();
		}
		if (hours == 0 || hours == 12){
			hours = 12;
		} else {
			hours = hours%2;
		}
	}
}

void change_time(void){

}

void dim_pixels(void){
	for (int x=0; x<8; x++){
		for(int y=0; y<8; y++){
			if (bm->pixel[x][y] == WHITE){
				bm->pixel[x][y] == DIMWHITE;
			} else if (bm->pixel[x][y] == BLUE){
				bm->pixel[x][y] = DIMBLUE;
			} else if (bm->pixel[x][y] == GREEN){
				bm->pixel[x][y] = DIMGREEN;
			} else if (bm->pixel[x][y] == RED){
				bm->pixel[x][y] = DIMRED;
			}
		}
	}
}
*/
