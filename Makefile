##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC		=		src/my_sokoban.c	\
				src/set_map.c		\
				src/moves.c			\
				src/errors.c		\
				src/end.c

NAME	=		my_sokoban

GCC		= 		@gcc -o $(NAME) $(SRC) -g3 -Llib/my/. -lmy -lncurses

PROJECT	=		Sokoban

SPACES	=		$(shell expr '$(PROJECT)' : '.*')

all:
	@printf "\x1B[1;33mWelcome to $(PROJECT) Project !\x1B[1;0m"
	@sleep 0.5

ifeq ($(shell test -f lib/my/libmy.a ; echo $$?), 1)
	@printf "\x1B[1;34m\rCompiling my lib       %$(SPACES)c\x1B[1;0m" ' '
	@make -sC ./lib/my/
else
	@printf "\x1B[1;31m\rLib already exist      %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.5
endif

	@printf "\x1B[1;34m\rCompiling Sources Files%$(SPACES)c\x1B[1;0m" ' '
	$(GCC)

	@rm -rf $(NAME).dSYM
	@printf "\x1B[1;32m\rCompilation terminated%$(SPACES)c\n\x1B[1;0m" ' '


clean:
	@rm -f $(OBJ)
	@rm -rf $(NAME).dSYM


fclean: clean
	@printf "\x1B[1;31mCleaning...\n\x1B[1;0m"
	rm -f $(NAME) lib/my/libmy.a


re:		fclean
	@printf "\x1B[1;33mRecompiling...\n\x1B[1;0m"
	@make -sC ./lib/my/
	$(GCC)
	@rm -rf $(NAME).dSYM


auteur:
	echo "Lucas GOIFFON" > Auteur
