# Options to pass to the C compiler
# (Add more options here to use Address Sanitizer, etc.)
CFLAGS = -std=c99 -O2 -Wall -pedantic -g

# List of programs to build
TARGETS = seminar05

# Default rule, built if you just say "make"
all: $(TARGETS)

# Build a program
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Remove built programs and temporary files
clean:
	rm -f $(TARGETS) *~
