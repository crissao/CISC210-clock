#include "sense.h"
#include "display.h"
#include <linux/input.h>
#include <stdio.h>

pi_framebuffer_t *fb = NULL;


void allocate_fb(void) {
    if(fb==NULL) { 
        fb=getFrameBuffer();
    }
}



void callbackFunc(unsigned int code,int hours);


void callbackFunc(unsigned int code, int hours) {
	if(code == KEY_UP || code == KEY_DOWN || code == KEY_RIGHT || code == KEY_LEFT) {
     		count += 1;	    
    }
}

void change_time (void);
