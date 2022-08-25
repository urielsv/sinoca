EXEC = sinoca
CFLAGS = -Wall -lncurses
C_FILES = sinoca.c main.c ui.c

.PHONY: all clean
.DEFAULT: all

all: sinoca

sinoca: 
		gcc $(C_FILES) $(CFLAGS) -o sinoca

clean:
		-rm -f sinoca
