#include "display.h" 

#define WHITE 0xFFFF
 

int open_display(void){
	pi_framebuffer_t *fb=getFrameBuffer();
    	sense_fb_bitmap_t *bm=fb->bitmap;
	return 0;
}

void display_time(int hours, int minutes, int seconds){

}

void display_colons(void){
	sense_fb_bitmap_t *bm;
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

void display_hours(int hours){

}

void display_minutes(int minutes){

}

void display_seconds(int seconds){

}

void close_display(void){

}

