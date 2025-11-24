CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -march=native
LDFLAGS  := $(shell pkg-config --cflags --libs libsodium)

TARGET   := password
SRC      := password.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
