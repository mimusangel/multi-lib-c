NAME = libStr.a

SRC = \
	str_new.c \
	str_out.c \
	str_set.c

DIR =

# ==================================== #

FILE_EXT = c

CC = gcc
RM = /bin/rm -f
RMDIR = /bin/rm -rf
MKDIR = /bin/mkdir -p
MAKE = make --no-print-directory

# ==================================== #

CFLAGS = -Wall -Werror -Wextra -I./include -Ofast -march=native -flto

C_FILE = $(addprefix sources/, $(SRC))
O_FILE = $(addprefix obj/, $(SRC:.$(FILE_EXT)=.o))
D_FILE = $(addprefix dep/, $(SRC:.$(FILE_EXT)=.d))

.PHONY: all dircreate clean fclean re test

all: dircreate $(NAME)

dircreate:
	@$(MKDIR) obj $(addprefix obj/, $(DIR))
	@$(MKDIR) dep $(addprefix dep/, $(DIR))

$(NAME): $(O_FILE) $(D_FILE)
	ar rc $(NAME) $(O_FILE)
	ranlib $(NAME)

obj/%.o: sources/%.$(FILE_EXT)
	$(CC) -o $@ -c $< $(CFLAGS)
dep/%.d: sources/%.$(FILE_EXT)
	@set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,obj/\1.o $@ : ,g' < $@.$$$$ >> $@; \
		$(RM) $@.$$$$
clean:
	$(RM) $(O_FILE)
	$(RM) $(D_FILE)
fclean: clean
	$(RM) $(NAME)
	$(RMDIR) obj
	$(RMDIR) dep

test: all
	$(CC) -o test.out test/testStr.c -L./ -lStr -I./include

re: fclean all

-include $(D_FILE)
