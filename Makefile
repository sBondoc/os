DIR_SRC := src
DIR_INC := inc
DIR_OBJ := obj
DIR_BIN := bin
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
DFLAGS := -g -DDEBUG
APP := app
SRC_MAIN := src/main.c

CFLAGS += -I"$(DIR_INC)"
FLAGS := $(CFLAGS) -pthread
DIR_BUILD = $(DIR_OBJ) $(DIR_BIN)
EXEC := $(DIR_BIN)/$(APP)

SRC := $(shell find -regex ".*$(DIR_SRC)\/.*\.c")
SRC := $(subst ./,,$(SRC))
SRC := $(subst $(SRC_MAIN),,$(SRC))
OBJ := $(patsubst $(DIR_SRC)%.c,$(DIR_OBJ)%.o,$(SRC))

.phony: all debug run rundbg test clean
all: $(EXEC)
run: $(EXEC)
	./$<
debug: FLAGS += $(DFLAGS)
debug: $(EXEC)_debug
rundbg: FLAGS += $(DFLAGS)
rundbg: $(EXEC)_debug
clean: force
	rm -rf $(DIR_BUILD)
test:
	@echo "$(OBJ)"
force:
$(EXEC) $(EXEC)_debug: $(SRC_MAIN) $(OBJ) | $(DIR_BIN)
	$(CC) $(FLAGS) -o $@ $^
$(DIR_BUILD):
	mkdir $@
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	$(CC) $(FLAGS) -c -o $@ $<
