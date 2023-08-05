CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m4 -mthumb -nostdlib
EXT = c
SRC = src
OBJ = obj
IFLAGS = -Iinclude
BINDIR = bin
PROJNAME = blinky
BINNAME = $(PROJNAME).elf
SRCS = $(wildcard $(SRC)/*.$(EXT))
OBJS = $(patsubst $(SRC)/%.$(EXT), $(OBJ)/%.o, $(SRCS))
BIN = $(BINDIR)/$(BINNAME)

DEBUGTOOL = openocd
DEBUGGER = interface/stlink.cfg
TARGET = target/stm32f4x.cfg
RESOURCE = resources
LINKER = $(RESOURCE)/STM32F4X_FLASH.ld


all: create_dirs
all: $(BIN)
all: upload

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) -T $(LINKER) -o $(BIN) -Wl,--no-warn-rwx-segments

$(OBJ)/%.o: $(SRC)/%.$(EXT)
	$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

upload:
	$(DEBUGTOOL) -f $(DEBUGGER) -f $(TARGET) -c "program $(BIN) verify reset exit"

clean:
	rm -r $(BINDIR) $(OBJ)

new: clean
new: all

create_dirs:
	@mkdir -p $(BINDIR) $(OBJ)