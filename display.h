#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sense.h"
#include <linux/input.h>
#include <stddef.h>


//joystick
void set_current_hours(int);
void free_fb(void);
void change_time(void);
void callbackFunc(unsigned int code);
void dim_pixels(void);

//clock
int open_display(void);
void display_time(int, int, int);
void display_colons(void);
void display_hours(int);
void display_minutes(int);
void display_seconds(int);
void close_display(void);

