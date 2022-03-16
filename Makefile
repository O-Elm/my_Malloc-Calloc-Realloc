##
## EPITECH PROJECT, 2021
## malloc
## File description:
## oelm
##


CC 		= 		gcc
RM 		= 		rm -f
TARGET_LIB 	= 		libmy_malloc.so

SRCS		=	src/my_utilities.c	\
				src/my_free.c	\
				src/my_malloc.c

OBJS 		= 		$(SRCS:.c=.o)


CFLAGS 		= 		-I./include/
CFLAGS 		+= 		-W -Wall -Wextra -fPIC
LDFLAGS      	=		-shared

all: $(TARGET_LIB) tester

$(TARGET_LIB): $(OBJS)
		 $(CC) $(OBJS) -o $(TARGET_LIB) $(LDFLAGS)
tester : main.c
		 gcc -L. -lmy_malloc main.c -Wall -Werror -o  tester

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(TARGET_LIB)

re: fclean all
	
.PHONY: all clean fclean re