NAME			=	bureaucrat3

DIR_SRCS		=	sources

DIR_OBJS		=	objects

SRCS_NAMES		=	Bureaucrat.cpp \
					AForm.cpp \
					Intern.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp \
					main.cpp

SRCS			=	${addprefix ${DIR_SRCS}/, ${SRCS_NAMES}}
OBJS			=	${addprefix ${DIR_OBJS}/, ${OBJS_NAMES}}

OBJS_NAMES		=	${SRCS_NAMES:.cpp=.o}

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
CDFLAGS			=	-MM -MT
INCLUDES		=	-Iincludes
DEFINES			=
RM				=	rm -rf

_OK				= [\033[32mOK\033[0m]

all:			${NAME}

${NAME}:		${DIR_OBJS} ${OBJS}
				${CC} ${CFLAGS} ${DEFINES} ${OBJS} -o ${NAME}
				@echo "$(_OK) $(NAME) compiled"


${OBJS} :		${DIR_OBJS}/%.o : ${DIR_SRCS}/%.cpp
				${CC} ${CFLAGS} ${DEFINES} ${INCLUDES} -c $< -o $@
				${CC} ${CFLAGS} ${DEFINES} ${INCLUDES} -MM -MT $@ $< -MF ${DIR_OBJS}/$*.d

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}

bonus:			DEFINES = -D BONUS=1
bonus:			${NAME}

clean:
			${RM} ${DIR_OBJS} *_shrubbery

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
