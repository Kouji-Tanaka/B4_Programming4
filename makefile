#makefile
.PHONY : clean

CC := gcc
CFLAGS := -o main.out
CPPFLAGS :=
LDFLAGS :=
LDFLIBS :=

main.out : src/main.c
	$(CC) $(CFLAGS) src/main.c -lm
	@echo "exported as \""$@"\""

clean :
	-rm main.out