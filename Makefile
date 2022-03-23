include config.mak
LIBS = `pkg-config --libs sdl2` `pkg-config --libs SDL2_image` -lm -lGL -lGLEW
SRC = src/main.c $(wildcard src/tex/**.c)

all:
	$(CC) -o sandbox $(CFLAGS) $(SRC) $(LIBS)
