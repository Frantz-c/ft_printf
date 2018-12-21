NAME=libftprintf.a

OBJECTS=call_convertion_function.o \
		call_signed.o \
		call_signed2.o \
		call_signed3.o \
		call_signed4.o \
		call_unsigned.o \
		call_unsigned2.o \
		call_unsigned3.o \
		ft_printf.o \
		get_sign.o \
		integer_print.o \
		print_string_with_options.o \
		printf_options.o \
		bv_spe/b_specifier.o \
		bv_spe/lv_specifier.o \
		bv_spe/v_specifier.o \
		diouxXp_spe/diu_specifier.o \
		diouxXp_spe/o_specifier.o \
		diouxXp_spe/xp_specifier.o \
		f_spe/f_specifier.o \
		f_spe/is_nan.o \
		f_spe/lf_specifier.o \
		f_spe/lf_specifier_functions.o \
		f_spe/numeric_str_op.o \
		f_spe/ulong128.o \
		f_spe/ulong128_assign.o \
		functions/ft_free_assign.o \
		functions/ft_isdigit.o \
		functions/ft_join.o \
		functions/ft_ltoa.o \
		functions/ft_memchr.o \
		functions/ft_memcpy.o \
		functions/ft_memmove.o \
		functions/ft_memrcpy.o \
		functions/ft_memset.o \
		functions/ft_space.o \
		functions/ft_strcat.o \
		functions/ft_strchr.o \
		functions/ft_strcmp.o \
		functions/ft_strcpy.o \
		functions/ft_strdup.o \
		functions/ft_strlen.o \
		functions/ft_strncat.o \
		functions/ft_strncmp.o \
		functions/ft_strncpy.o \
		functions/ft_strndup.o \
		functions/ft_strnlen.o \
		functions/ft_strstr.o \
		functions/ft_ten_pow.o \
		functions/get_next_line.o \
		n_spe/n_specifier.o \
		sScC_spe/c_specifier.o \
		sScC_spe/cmaj_specifier.o \
		sScC_spe/s_specifier.o \
		sScC_spe/smaj_specifier.o \
		sScC_spe/unicode_to_utf8.o \
		wW_spe/w_functions.o \
		wW_spe/w_print_member.o \
		wW_spe/w_print_member2.o \
		wW_spe/w_print_member3.o \
		wW_spe/w_specifier.o \
		wW_spe/w_specifier2.o \
		wW_spe/wmaj_format_string.o \
		wW_spe/wmaj_free.o \
		wW_spe/wmaj_functions.o \
		wW_spe/wmaj_functions2.o \
		wW_spe/wmaj_functions3.o \
		wW_spe/wmaj_functions4.o \
		wW_spe/wmaj_functions5.o \
		wW_spe/wmaj_specifier.o \
		yYZ_spe/y_print.o \
		yYZ_spe/y_specifier.o \
		yYZ_spe/ymaj_specifier.o \
		yYZ_spe/zmaj_specifier.o \

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $@ $^
	@ranlib $@

%.o: %.c
	@gcc -Wall -Wextra -Werror -O3 -c -o $@ $<

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

allc: all clean
