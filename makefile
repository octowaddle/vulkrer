COMPILER=gcc
FLAGS=-Wall -g -I include
LIBRARIES=vulkan
BINARY=vulkrer

SOURCE_DIRECTORY=source
BUILD_DIRECTORY=build
OBJECT_DIRECTORY=objects
SOURCE_FILES=$(wildcard $(SOURCE_DIRECTORY)/*.c)
OBJECT_FILES=$(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/$(OBJECT_DIRECTORY)/%.o, $(SOURCE_FILES))

all: setup $(BUILD_DIRECTORY)/$(BINARY)

setup:
	@mkdir -p $(BUILD_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)/$(OBJECT_DIRECTORY)

run: all
	@$(BUILD_DIRECTORY)/$(BINARY)

clean:
	@rm -r $(BUILD_DIRECTORY)

$(BUILD_DIRECTORY)/$(BINARY): $(OBJECT_FILES)
	@$(COMPILER) $(FLAGS) `pkg-config --cflags --libs $(LIBRARIES)` $(OBJECT_FILES) -o $@

$(BUILD_DIRECTORY)/$(OBJECT_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	@$(COMPILER) $(FLAGS) `pkg-config --cflags --libs $(LIBRARIES)` -c $< -o $@
