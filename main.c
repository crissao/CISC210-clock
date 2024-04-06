#include "display.h"
#define BLACK 0x0000



int main(void){
	int hours,minutes,seconds;
	scanf("%02d:%02d:%02d",&hours,&minutes,&seconds);
	open_display();
	pi_joystick_t* joystick=getJoystickDevice();
	allocate_fb();
	while(hours >=0 && hours<=23 && minutes>=0 && minutes<=59 && seconds>=0 && seconds<=59){
		display_time(hours,minutes,seconds);
		pollJoystick(joystick,callbackFunc,1000);
		scanf("%02d:%02d:%02d",&hours,&minutes,&seconds);
   		clearFrameBuffer(&pi_framebuffer_t, BLACK);
	}
	freeJoystick(joystick);
	close_display();
	return 0;
}
