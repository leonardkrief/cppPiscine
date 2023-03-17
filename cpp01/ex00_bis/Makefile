NAME			=	zombies

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	Zombie.cpp \
					randomChump.cpp \
					newZombie.cpp \
					main.cpp

SRCS			=	${addprefix ${DIR_SRCS}/, ${SRCS_NAMES}}
OBJS			=	${addprefix ${DIR_OBJS}/, ${OBJS_NAMES}}

OBJS_NAMES		=	${SRCS_NAMES:.cpp=.o}
DEPS			=	${SRCS_NAMES:.cpp=.d}

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++11
CDFLAGS			=	-MMD -MP
INCLUDE			=	-Iinclude
DEFINES			=
RM				=	rm -rf

all:			${NAME}

${NAME}:		${DIR_OBJS} ${OBJS}
				${CC} ${CFLAGS} ${DEFINES} ${OBJS} -o ${NAME}

${OBJS} :		${DIR_OBJS}/%.o : ${DIR_SRCS}/%.cpp
				${CC} ${CFLAGS} ${DEFINES} ${CDFLAGS} ${INCLUDE} -c $< -o $@

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}

bonus:			DEFINES = -D BONUS=1
bonus:			${NAME}

clean:
				${RM} ${DIR_OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

# Debug
d:				CFLAGS += -g3
d:				all
red:			fclean d

# Performance
p:				CC = gcc
p:				CFLAGS += -O3
p:				all
rep:			fclean p

-include		${DEPS}

.PHONY:			all clean fclean re
# .SILENT: