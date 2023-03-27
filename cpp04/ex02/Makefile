NAME			=	animals_2

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	Animal.cpp \
					AAnimal.cpp \
					Brain.cpp \
					Cat.cpp \
					Dog.cpp \
					main.cpp

SRCS			=	${addprefix ${DIR_SRCS}/, ${SRCS_NAMES}}
OBJS			=	${addprefix ${DIR_OBJS}/, ${OBJS_NAMES}}

OBJS_NAMES		=	${SRCS_NAMES:.cpp=.o}

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
CDFLAGS			=	-MM -MT
INCLUDE			=	-Iinclude
DEFINES			=
RM				=	rm -rf

_OK				= [\033[32mOK\033[0m]

all:			${NAME}

${NAME}:		${DIR_OBJS} ${OBJS}
				${CC} ${CFLAGS} ${DEFINES} ${OBJS} -o ${NAME}
				@echo "$(_OK) $(NAME) compiled"


${OBJS} :		${DIR_OBJS}/%.o : ${DIR_SRCS}/%.cpp
				${CC} ${CFLAGS} ${DEFINES} ${INCLUDE} -c $< -o $@
				${CC} ${CFLAGS} ${DEFINES} ${INCLUDE} -MM -MT $@ $< -MF ${DIR_OBJS}/$*.d

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}

bonus:			DEFINES = -D BONUS=1
bonus:			${NAME}

clean:
			${RM} ${DIR_OBJS}

fclean:			clean
			${RM} ${NAME}

re:				fclean all

# Compile
c:				all fclean

# Debug
d:				CFLAGS += -g3
d:				all
red:			fclean d

# No flags
n:				CFLAGS = -std=c++98
n:				all
ren:			fclean n

# Performance
p:				CC = gcc
p:				CFLAGS += -O3
p:				all
rep:			fclean p

-include        ${OBJS:.o=.d}

.PHONY:			all clean fclean re
# .SILENT:




# When this makefile compiles, it displays every actions it performs on the same line of the terminal. What happens is that it prints an action on the terminal, then clear this line, then prints the next action, etc...

# ––

# CC			= c++ -Wall -Wextra -Werror -std=c++98
# RM			= rm -rf
# NAME		= ./brains
# NAME_SHORT	= brains

# INCS_DIR	= ./includes/
# MAIN_INC	= -I$(INCS_DIR)
# INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

# SRCS_DIR 	= ./sources/
# SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

# OBJS_DIR	= ./objects/
# OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

# _COLOR		= \033[32m
# _BOLDCOLOR	= \033[32;1m
# _RESET		= \033[0m
# _CLEAR		= \033[0K\r\c
# _OK			= [\033[32mOK\033[0m]

# $(OBJS_DIR)%.o	: $(SRCS_DIR)%.cpp
# 			@mkdir -p $(OBJS_DIR)
# 			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
# 			@$(CC) $(MAIN_INC) -c $< -o $@
# 			@echo "$(_CLEAR)"

# all			: $(NAME)

# $(NAME)		: $(OBJS) $(INCS)
# 			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
# 			@echo "$(_OK) $(NAME_SHORT) compiled"

# clean		:
# 			@$(RM) $(OBJS_DIR)

# fclean		: clean
# 			@$(RM) $(NAME)

# re			: fclean all

# .PHONY		: all clean fclean re

# ––

# I would like to modify the following Makefile to do the same:

# ––

# NAME			=	animals_1

# DIR_SRCS		=	srcs

# DIR_OBJS		=	objs

# SRCS_NAMES		=	Animal.cpp \
# 					Brain.cpp \
# 					Cat.cpp \
# 					Dog.cpp \
# 					main.cpp

# SRCS			=	${addprefix ${DIR_SRCS}/, ${SRCS_NAMES}}
# OBJS			=	${addprefix ${DIR_OBJS}/, ${OBJS_NAMES}}

# OBJS_NAMES		=	${SRCS_NAMES:.cpp=.o}

# CC				=	c++
# CFLAGS			=	-Wall -Wextra -Werror -std=c++98
# CDFLAGS			=	-MM -MT
# INCLUDE			=	-Iinclude
# DEFINES			=
# RM				=	rm -rf

# _OK				= [\033[32mOK\033[0m]

# all:			${NAME}

# ${NAME}:		${DIR_OBJS} ${OBJS}
# 				${CC} ${CFLAGS} ${DEFINES} ${OBJS} -o ${NAME}
# 				@echo "$(_OK) $(NAME) compiled"


# ${OBJS} :		${DIR_OBJS}/%.o : ${DIR_SRCS}/%.cpp
# 				${CC} ${CFLAGS} ${DEFINES} ${INCLUDE} -c $< -o $@
# 				${CC} ${CFLAGS} ${DEFINES} ${INCLUDE} -MM -MT $@ $< -MF ${DIR_OBJS}/$*.d

# ${DIR_OBJS}:
# 				mkdir -p ${DIR_OBJS}

# bonus:			DEFINES = -D BONUS=1
# bonus:			${NAME}

# clean:
# 			${RM} ${DIR_OBJS}

# fclean:			clean
# 			${RM} ${NAME}

# re:				fclean all

# # Compile
# c:				all fclean

# # Debug
# d:				CFLAGS += -g3
# d:				all
# red:			fclean d

# # No flags
# n:				CFLAGS = -std=c++98
# n:				all
# ren:			fclean n

# # Performance
# p:				CC = gcc
# p:				CFLAGS += -O3
# p:				all
# rep:			fclean p

# -include        ${OBJS:.o=.d}

# .PHONY:			all clean fclean re
# # .SILENT:

# ––

# Please assist me.
# Your answer will probably be too long to print so if you see that you are about to reach your maximum characters limit, please cut your sentence a bit before. I will ask you to continue on the next prompt