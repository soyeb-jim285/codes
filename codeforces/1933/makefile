CC = g++
CFLAGS = -fsanitize=address -std=c++17 -Wall -Wextra -Wshadow -DONPC -O2
all:
%: %.cpp
	$(CC) $(CFLAGS) -o $@ $<
run: $(file)
	./$(file)
clean:
	rm -f $(filter-out Makefile, $(wildcard *))
