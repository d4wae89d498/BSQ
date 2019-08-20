# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fdumas <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/20 16:13:12 by fdumas       #+#   ##    ##    #+#        #
#    Updated: 2019/08/20 17:34:06 by fdumas      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC&FLAGS = cc -Wall -Wextra -Werror
N&FLAGS = norminette -R CheckForbiddenSourceHeader
EXEC = bsq
OEXEC = a.out
M = make
R&FLAGS = rm -rf

all:
	$(M) fclean && $(M) norme && $(CC&FLAGS) includes/*.h  sources/*.c  && mv $(OEXEC) $(EXEC) && $(M) run

sanitize:
	$(CC&FLAGS) -g3 -fsanitize=address includes/*.h  sources/*.c && mv $(OEXEC) $(EXEC)

fclean:
	$(R&FLAGS) *.out && $(R&FLAGS) includes/*.gch  && $(R&FLAGS) a.out.dSYM/

norme:
	$(N&FLAGS) includes/ sources/

run:
	./$(EXEC)
