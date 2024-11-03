CC = gcc
LD = gcc

CFLAGS = -Iinclude -Ilibs/oeuf/
LDFLAGS =

DEBUG_FLAG = -g

SRC = main.c $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c) $(wildcard src/*/*/*/*.c)
BIN = $(SRC:.c=.o) libs/oeuf/out/liboe.a

OUT_DIR = build
OUT_NAME = cpsm

ifeq ($(OS),Windows_NT)
		OUT = $(OUT_DIR)/$(OUT_NAME).exe
else
	OUT = $(OUT_DIR)/$(OUT_NAME)
endif

all: $(OUT) run

build: $(OUT)

$(OUT): $(BIN)
ifeq ($(OS),Windows_NT)
	if not exist $(OUT_DIR) mkdir $(OUT_DIR)
	if not exist libs mkdir libs
else
	mkdir -p $(OUT_DIR)
	mkdir -p libs
endif
	$(LD) $(LDFLAGS) $(BIN) -o $(OUT)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

setup:
ifeq ($(OS),Windows_NT)
	if not exist $(OUT_DIR) git clone https://github.com/asqel/oeuf.git libs/oeuf
	git -C libs/oeuf pull
	make -C libs/oeuf win
else
	if [ ! -d libs/oeuf ]; then \
		git clone https://github.com/asqel/oeuf.git libs/oeuf; \
	fi
	git -C libs/oeuf pull
	make -C libs/oeuf linux
endif

run:
	./$(OUT)

add_debug_flags:
	CFLAGS += $(DEBUG_FLAG)

debug: add_debug_flags build
	valgrind $(OUT)

clean:
ifeq ($(OS),Windows_NT)
	powershell -NoProfile -Command rm -r -force $(BIN)
else
	rm -rf $(BIN)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	powershell -NoProfile -Command rm -r -force $(OUT)
else
	rm -rf $(OUT)
endif