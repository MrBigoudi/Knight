# Source directories
SRCDIR = src
HDRDIR = hdr
BUILDDIR = build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)
HDRS = $(wildcard $(HDRDIR)/*.h)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

# Output
TARGET=main.exe

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -g
# SDL options
LDFLAGS=-lSDL -lSDL_ttf `sdl-config --cflags --libs`


all: directories $(TARGET)

directories:
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	$(shell mv $(TARGET) $(SRCDIR)/. && cd $(SRCDIR) && ./$(TARGET) && rm $(TARGET) && cd ..)

clean:
	rm -rf $(BUILDDIR) $(TARGET)
