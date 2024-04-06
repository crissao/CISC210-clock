INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: clockdisplay joystick
clockdisplay: main.o display.o
	cc -o clockdisplay main.o display.o $(LDFLAGS)

clean:
	rm -f *.o clockdisplay joystick
main.o: main.c display.h
	cc -c main.c -I ~/include
display.o: display.c display.h
	cc -c display.c -I ~/include
joystick:
	cc -o joystick joystick.c -I ~/include $(LDFLAGS)

run:
	./clock.sh && ./clockdisplay && ./joystick
