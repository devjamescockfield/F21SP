# pkg-config packages to link the program against
PKGS = sdl2

# Options to pass to the C compiler
CFLAGS = -std=c99 -O2 -Wall -pedantic -g `pkg-config --cflags $(PKGS)`

# Options to pass when linking
LDFLAGS = `pkg-config --libs $(PKGS)`

# List of programs to build
TARGETS = graphics

# Default rule, built if you just say "make"
all: $(TARGETS)

# Build a program
%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

# Remove built programs and temporary files
clean:
	rm -f $(TARGETS) *~
