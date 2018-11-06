#!/bin/bash
GREEN = \033[0;32m
BLUE = \033[0;36m
RESET = \033[0m
RED = \033[0;31m

all:
	@echo "$(BLUE)Begin compilation of LIBFT library$(RESET)"
	@make -C libft/ fclean && make -C libft/
	@echo "$(GREEN)Compilation was successfull$(RESET)"
	@echo
	@echo "$(BLUE)Begin compilation of  get_next_line$(RESET)"
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@echo "$(GREEN)Compilation was successfull$(RESET)"
	@echo
	@echo "$(BLUE)Begin compilation of main$(RESET)"
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@echo "$(GREEN)Compilation was successfull$(RESET)"
	@echo
	@echo "$(BLUE)Begin test_gnl$(RESET)"
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
	@echo "$(GREEN)Compilation was successfull$(RESET)"
	@echo
clean:
	@echo
	@echo "$(RED)Cleaning get_next_line$(RESET)"
	@rm -rf *.o
	@rm -rf test_gnl
	@echo

fclean: clean
	@echo
	@echo "$(RED)Deep cleaning LIBFT$(RESET)"
	@make -C libft/ fclean
	@echo

re: fclean all