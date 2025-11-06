.PHONY: all clean

BUILD_DIR := build

all:
	cmake -S . -B $(BUILD_DIR) -G "Unix Makefiles"
	cmake --build $(BUILD_DIR)

clean:
	rm -rf build

