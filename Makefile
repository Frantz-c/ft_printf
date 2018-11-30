NAME = TEST
CC = gcc -g -Wall -Wextra# -Werror 
FILES = b_specifier.o\
c_specifier.o\
diu_specifier.o\
ft_isdigit.o\
ft_printf.o\
ft_strlen.o\
ft_strnlen.o\
get_sign.o\
integer_print.o\
main_test.o\
o_specifier.o\
printf_options.o\
s_specifier.o\
get_specifier.o\
xp_specifier.o\
ft_strncpy.o\
ft_strcpy.o\
ft_memcpy.o\
ft_memrcpy.o\
ft_memset.o\
ft_strcat.o\
ft_ltoa.o\
ft_strchr.o\
w_specifier.o\
v_specifier.o\
ft_strncmp.o\
ft_memmove.o\
n_left_zero.o\
is_nan.o\
y_specifier.o\
lf_specifier.o\
lf_specifier_functions.o\
numeric_str_op.o\
ft_ten_pow.o\
ulong128.o\
f_specifier.o

all: $(NAME)

$(NAME): $(FILES)
	@$(CC) -o $@ $^

.c.o:
	@$(CC) -c $<

clean:
	@/bin/rm -f $(FILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

allc: all clean
