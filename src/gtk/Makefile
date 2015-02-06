all: gtk-hello gtk-button

gtk-hello: gtk-hello.c
	gcc gtk-hello.c -o gtk-hello `pkg-config --libs --cflags gtk+-3.0`
gtk-button: gtk-button.c
	gcc gtk-button.c -o gtk-button `pkg-config --libs --cflags gtk+-3.0`
