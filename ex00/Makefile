# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:17:59 by kangkim           #+#    #+#              #
#    Updated: 2022/04/04 16:39:48 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror
CXXDEBUGFLAGS = -fsanitize=address -fsanitize=undefined

NAME = main
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

debug : CXXFLAGS += $(CXXDEBUGFLAGS)
debug : re

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all debug clean fclean re