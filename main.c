#include "display.h"

int main(void){
	int hours,minutes,seconds;
	scanf("%d:%d:%d",&hours,&minutes,&seconds);
	open_display();
	while(hours && minutes && seconds){
		display_time(hours,minutes,seconds);
		scanf("%d:%d:%d",&hours,&minutes,&seconds);
	}
	close_display();
	return 0;
}
