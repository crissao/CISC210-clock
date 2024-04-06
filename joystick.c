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

/* using a char as a number because it doesn't need to be large.
 * Doing it because I _can_, not because I need to */
char xPos = 7, yPos = 7;

/* Program stops when 'running' is zero */
int running=1;

void callbackFunc(unsigned int code);

/* Note that the codes don't really match any orientation of the joystick */
void callbackFunc(unsigned int code) {
    fprintf(stderr,"code: %u\t",code);
    if(code == KEY_UP || code == KEY_DOWN || code == KEY_RIGHT || code == KEY_LEFT) {
        fprintf(stderr,"up");
        if(yPos==0) {
            yPos=7;
        }else{
            yPos--;
        }
    }else if(code == KEY_ENTER) {
        fprintf(stderr,"push");
        running = 0;
    }
    fprintf(stderr,"\n");
}

