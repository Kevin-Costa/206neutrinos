##
## Makefile for 206neutrinos in /home/alexandre/Projects/B4/maths/206neutrinos
## 
## Made by Alexandre Vanhoutte
## Login   <alexandre@epitech.net>
## 
## Started on  Mon Apr 27 12:50:25 2015 Alexandre Vanhoutte
## Last update Tue May  5 14:11:13 2015 Alexandre Vanhoutte
##

CXX		= clang++

NAME		= 206neutrinos

RM		= rm -f

SRC		= gtk.cpp

OBJ		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):
		$(CXX) $$(pkg-config --libs --cflags gtk+-2.0) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
