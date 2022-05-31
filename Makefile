NAME	=	so_long
CC		= 	clang
CFLAGS	= 	-Wall -Werror -Wextra -I.
MLX		= 	libmlx_Darwin.a
SRCS_PATH	=	./srcs
MLX_PATH	=	./mlx
GNL_PATH	=	./gnl

SRCS_FILES	=	$(shell find ./srcs -type f -name "*.c")
GNL_FILES	=	$(shell find ./gnl -type f -name "*.c")
MLXFLAG		= 	-lmlx -framework OpenGL -framework AppKit
SRCS		=	$(SRCS_FILES)
SRCS_OBJS	=	$(SRCS:.c=.o)
GNL			=	$(GNL_FILES)
GNL_OBJS	=	$(GNL:.c=.o)
MLXMAKE		=	$(MAKE) -C $(MLX_PATH)

all	:	$(NAME)

$(NAME)	:	$(SRCS_OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) $(GNL_OBJS) $(MLXFLAG) -o $(NAME)

mlx	:
	$(MLXMAKE)

clean	:
	$(MAKE) clean -C $(MLX_PATH)
	$(RM) $(SRCS_OBJS)
	$(RM) $(GNL_OBJS)

fclean	:	clean
	$(RM) $(MLX_PATH)/libmlx_Darwin.a
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean mlx re