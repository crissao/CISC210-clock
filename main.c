#include "display.h"

int main(void){
	int hours,minutes,seconds;
	scanf("%02d:%02d:%02d",&hours,&minutes,&seconds);
	open_display();
	while(hours >=0 && hours<=23 && minutes>=0 && minutes<=59 && seconds>=0 && minutes<=59){
		display_time(hours,minutes,seconds);
		scanf("%02d:%02d:%02d",&hours,&minutes,&seconds);
	}
	close_display();
	return 0;
}
