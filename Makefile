all	: do_configure

do_configure	:
	./configure

clean	:
	./configure clean

re	: clean all 

compile	: 
	gcc -lmlx -framework OpenGL -framework AppKit main.c \
	get_map.c map_err.c map_check.c render.c window.c \
	move_vertical.c move_horizontal.c get_next_line.c \
	get_next_line_utils.c solong_utils.c \
	keycode.c