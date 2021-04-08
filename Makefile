##
## EPITECH PROJECT, 2021
## hub
## File description:
## Makefile
##

NAME 	=	ecs-test

SRCS  	=	main.cpp						\
			EntityManager.cpp			\
			Entity/Entity.cpp			\

OBJS	=	$(SRCS:.cpp=.o)

NBR_OF_FILES := $(words $(SRCS))

CXX	=	g++

RM	=	rm -f

MV	= 	mv -f

CPPFLAGS += -std=c++1z
CPPFLAGS += -W -Wall -Wextra -g3
CPPFLAGS += -I ./exception -I ./Entity -I ./Components -I ./Components/components

all: $(NAME)

$(NAME): $(OBJS)
		 @ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
		 @ $(CXX) -o $(NAME) $(OBJS) $(CPPFLAGS)
		 @ echo "\033[1;34mBinary : \033[1;32m$(NAME)\033[1;34m created sucesfully.\033[0m"

clean:
		@ echo "\033[3;31mRemoving: \033[0m"
		@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
		@ $(RM) $(OBJS)

fclean:	clean
		@ echo "\033[3;31m./$(NAME)\033[0m"
		@ $(RM) $(NAME)
		@ $(RM) ./../$(NAME)

re: fclean all

%.o:	%.cpp
	@ echo "\033[1;34m[ OK ]\033[0m Compiling" $<
	@ $(CXX) -o $@ -c $< $(CPPFLAGS) -fPIC

.PHONY: all clean fclean re%   