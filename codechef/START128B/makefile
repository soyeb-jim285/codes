# runs by make run file=filename, use *tab*
# now also supports make all, make clean
CC = g++
CFLAGS = -fsanitize=address -std=c++17 -Wall -Wextra -Wshadow -DONPC -O2
all:
%: %.cpp
	$(CC) $(CFLAGS) -o "$@" "$<"
run: $(file)
	./$(file)
clean:
	find . -type f -executable -delete
