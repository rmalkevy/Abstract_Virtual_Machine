# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/14 15:52:17 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project name (generate executable with this name)
TARGET   = avm

CC       = clang++
# compiling flags here
CFLAGS   = -std=c++14 -Wall -Wextra -Werror -I.

LINKER   = clang++
# linking flags here
LFLAGS   = -std=c++14 -Wall -Wextra -Werror -I. -lm

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = Obj
BINDIR   = Bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.hpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"