# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 11:33:49 by wzouf             #+#    #+#              #
#    Updated: 2022/03/10 15:21:24 by wzouf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c \
		ft_printf.c \
		extra_function.c 

NAME1 = server
NAME2 = client
BNAME1 = server_bonus
BNAME2 = client_bonus

HEADER =	./Minitalk.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME1) $(NAME2)

$(NAME1) : ${SRCS} $(HEADER)
	$(CC) $(CFLAGS) ${SRCS}  server.c -o ${NAME1}

$(NAME2) : ${SRCS} $(HEADER)
	$(CC) $(CFLAGS) ${SRCS} client.c -o ${NAME2}

$(BNAME1) : ${SRCS} $(HEADER)
	$(CC) $(CFLAGS) ${SRCS} server.c -o ${BNAME1}
	
$(BNAME2) : ${SRCS} $(HEADER)
	$(CC) $(CFLAGS) ${SRCS} client.c -o ${BNAME2}
bonus : $(BNAME1) $(BNAME2)

clean : 
	rm -rf server
	rm -rf server_bonus
	rm -rf client
	rm -rf client_bonus

fclean : clean

re : fclean all
