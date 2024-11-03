
LINUX_CFLAGS = -Wall -Werror -Wextra -include oeuf/oeuf.h
OUTPUT = sas
CC = gcc



all: 
	make setup
	make linux

setup:
	if [ ! -d ./oeuf ]; then \
		git clone https://github.com/asqel/oeuf.git oeuf; \
	else \
		git -C oeuf pull; \
	fi
	make -C oeuf linux


linux:
	$(CC) main.c $$(find src -name "*.c") oeuf/out/liboe.a $(LINUX_CFLAGS) -o $(OUTPUT)


profan:
	olivine build.olv


clea:
	rm sas