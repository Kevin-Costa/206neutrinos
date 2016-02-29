##
## Makefile for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
## 
## Made by Alexandre Vanhoutte
## Login   <alexandre@epitech.net>
## 
## Started on  Thu Apr 30 17:20:15 2015 Alexandre Vanhoutte
## Last update Mon May  4 15:25:02 2015 Alexandre Vanhoutte
##

CXX		= g++

NAME		= 206neutrinos

SRC		= main.cpp \
		  neutrinos.cpp \
		  Exception.cpp

OBJ		= $(SRC:.cpp=.o)

RM		= rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
