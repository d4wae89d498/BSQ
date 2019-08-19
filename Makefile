main:
	cc -Werror -Wall -Wextra includes/*.h  sources/*.c  && mv a.out bsq
sanitize:
	cc -Werror -Wall -Wextra -g3 -fsanitize=address includes/*.h  sources/*.c && mv a.out bsq
fclean:
	rm -rf *.out && rm -rf includes/*.gch  && rm -rf a.out.dSYM/
norme:
	norminette -R CheckForbiddenSourceHeader includes/ sources/ && make main
