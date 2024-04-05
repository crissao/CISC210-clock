#include "display.h" 

#define WHITE 0xFFFF
 
pi_framebuffer_t *fb;
sense_fb_bitmap_t *bm;

int open_display(void){
	fb=getFrameBuffer();
    bm=fb->bitmap;
	return 0;
}

void display_time(int hours, int minutes, int seconds){
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
	
}

void display_minutes(int minutes){

}

void display_seconds(int seconds){

}

void close_display(void){

}

