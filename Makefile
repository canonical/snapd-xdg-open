.PHONY: all clean

all: snappy-url-helper.c
	gcc -o snappy-url-helper snappy-url-helper.c `pkg-config --cflags --libs gio-2.0`

clean:
	rm snappy-url-helper
