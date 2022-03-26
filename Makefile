CC :=gcc 
CFLAGS := -c -Wall -Werror -Wextra
C_SOURCES := ft_printf.c utils.c
OBJECTS :=$(C_SOURCES:.c=.o)

all:$(OBJECTS) 

$(OBJECTS):$(C_SOURCES)
		$(CC) $^   $(CFLAGS) && ar cr libftprintf.a $(OBJECTS)
clean:
		rm -rf $(OBJECTS) && rm -rf libftprintf.a
fclean:
	rm -rf $(OBJECTS) && rm -rf libftprintf.a
re:
	make fclean 
	make all