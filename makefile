CC = gcc
CFLAGS = -W -Wall -g
LDFLAGS =

SRC = $(wildcard src/*.cpp)
OBJS = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
AOUT = B3133

all : $(AOUT)

prog : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm $(AOUT)