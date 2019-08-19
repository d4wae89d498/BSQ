main:
	make fclean && make norme && cc -Werror -Wall -Wextra includes/*.h  sources/*.c  && mv a.out bsq && make run
sanitize:
	cc -Werror -Wall -Wextra -g3 -fsanitize=address includes/*.h  sources/*.c && mv a.out bsq
fclean:
	rm -rf *.out && rm -rf includes/*.gch  && rm -rf a.out.dSYM/
norme:
	norminette -R CheckForbiddenSourceHeader includes/ sources/
run:
	./bsq
