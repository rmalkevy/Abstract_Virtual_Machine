# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/12/05 15:52:17 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	avm

#[--------------------------------COMPILATION---------------------------------]#

CC				=	clang++
FLAGS			=	-std=c++14 -Wall -Wextra -Werror

#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH 	= ./src/

MAIN_PATH				= $(SRC_PATH)/

GENERAL_PATH			= $(SRC_PATH)General/

ABSTRACT_VM_PATH		= $(SRC_PATH)AbstractVM/

LEXER_PATH				= $(SRC_PATH)Lexer/

PARSER_PATH				= $(SRC_PATH)Parser/

LOG_EXCEPTION_PATH		= $(SRC_PATH)LogException/

OPERAND_FACTORY_PATH	= $(SRC_PATH)OperandFactory/

TASK_MANAGER_PATH		= $(SRC_PATH)TaskManager/


MAIN			= main.cpp

GENERAL			= General.cpp

ABSTRACT_VM		= AbstractVM.cpp

LEXER			= Lexer.cpp

PARSER			= Parser.cpp

LOG_EXCEPTION	= LogException.cpp

OPERAND_FACTORY	= OperandFactory.cpp

TASK_MANAGER	= TaskManager.cpp

SRC = $(addprefix $(MAIN_PATH),$(MAIN)) \
	$(addprefix $(GENERAL_PATH),$(GENERAL)) \
	$(addprefix $(ABSTRACT_VM_PATH),$(ABSTRACT_VM)) \
	$(addprefix $(LEXER_PATH),$(LEXER)) \
	$(addprefix $(PARSER_PATH),$(PARSER)) \
	$(addprefix $(LOG_EXCEPTION_PATH),$(LOG_EXCEPTION)) \
	$(addprefix $(OPERAND_FACTORY_PATH), $(OPERAND_FACTORY)) \
	$(addprefix $(TASK_MANAGER_PATH),$(TASK_MANAGER))  \


OBJ = $(SRC:.cpp=.o)

#[-----------------------------------COLORS-----------------------------------]#

GREEN			=	\033[32m
RESET			=	\033[39m
YELLOW			=	\033[33m
RED				=	\033[31m

#[------------------------------------MAKE------------------------------------]#

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@ echo "$(GREEN)[$(NAME)]$(RESET)"

%.o:%.cpp
	@ $(CC) $(FLAGS) -c -o $@ $<
	@ printf ' $(GREEN)[add]$(RESET) $<\n'


clean:
	@ rm -f $(OBJ)
	@ echo "$(YELLOW)[clean]$(RESET)"

fclean: clean
	@ rm -f $(NAME) $(NAMELIB)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all

