#CC Core

CC := cc
CCFLAGS := -Wall -Wextra -Werror

BUILD_DIR := build/
INCLUDES_DIR := includes/
BIN_DIR := bin/
LIB_DIR := lib/


# 42 Tester Library
NAME_LIB:= lib42Tester.a
FILES_LIB := main.c

SRCS_LIB := $(addprefix $(LIB_DIR), $(FILES_LIB))
OBJS_LIB := $(SRCS_LIB:$(LIB_DIR)%.c=$(BUILD_DIR)$(LIB_DIR)%.o)


# 42 Tester Binary
NAME_BIN := 42Tester
FILES_BIN := main.c

SRCS_BIN := $(addprefix $(BIN_DIR), $(FILES_BIN))
OBJS_BIN := $(SRCS_BIN:$(BIN_DIR)%.c=$(BUILD_DIR)$(BIN_DIR)%.o)

# Compilation

ALL: $(NAME_LIB) $(NAME_BIN)

$(NAME_LIB): $(OBJS_LIB)
	ar rcs -o $(NAME_LIB) $(OBJS_LIB)

$(BUILD_DIR)$(LIB_DIR)%.o: $(SRC_DIR)$(LIB_DIR)%.c
	$(CC) $(CCFLAGS) $< -o $@ -g -c -I.


$(NAME_BIN): $(OBJS_BIN)
	$(CC) $(CCFLAGS) $(OBJS_BIN) -o $(NAME_BIN) -g  -I.
	
$(BUILD_DIR)$(BIN_DIR)%.o: $(SRC_DIR)$(BIN_DIR)%.c
	$(CC) $(CCFLAGS) $< -o $@ -g -c  -I.

clean: 
	rm $(OBJS) -rf

fclean: clean
	rm $(NAME_LIB) $(NAME_BIN)

re: fclean ALL clean