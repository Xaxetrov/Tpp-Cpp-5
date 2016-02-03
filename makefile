CC = g++
CFLAGS = -Wall -std=c++11
LDFLAGS =

SRC = $(wildcard src/*.cpp)
OBJS = $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
OUT = B3133

all : $(OUT)

$(OUT) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm $(OBJS)
cleaner : clean
	@rm $(OUT)
