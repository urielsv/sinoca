CFLAGS = -Wall -lncurses
C_FILES = game.c main.c ui.c

.PHONY: all clean
.DEFAULT: all

all: sinoca

sinoca: $(SRCS)
		gcc $(CFLAGS)

clean:
		-rf -f sinoca
