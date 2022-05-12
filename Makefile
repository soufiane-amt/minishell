# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 18:59:26 by samajat           #+#    #+#              #
#    Updated: 2022/05/11 18:11:45 by eelmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

READ= -L /goinfre/$(USER)/.brew/opt/readline/lib -lreadline

RL_INCLUDE = -I /goinfre/$(USER)/.brew/opt/readline/include

CMD_SRC = ft_echo exec_rebuilt is_rebuilt_cmd ft_pwd ft_env ft_export ft_unset ft_cd

DATA_SRC = free_data collect_data

M_SRC =  ft_prompt main

CTL_SRC = ctl

P_SRC =get_token get_cmd_data get_spliter_data redirection_handler

U_SRC = ft_strcmp ft_strlen ft_split ft_strdup ft_substr  ft_strchr ft_utils_env_exp ft_strcpy ft_strjoin \
		   ft_strlcpy ft_strtrim\
        ft_putnbr_fd ft_putstr_fd _char
                        
E_SRC        =        build_cmd exec_cmd_ln execute\

all_lst = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstlast ft_lstnew ft_lstsize\
			ft_lst_contain 



SRC = $(addsuffix .c, $(addprefix srcs/cmd/, $(CMD_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/main/, $(M_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/utils/, $(U_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/data_managment/, $(DATA_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/ctl/, $(CTL_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/exec_cmd/, $(E_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/ft_lst/, $(all_lst)))\
	  $(addsuffix .c, $(addprefix srcs/parsing/, $(P_SRC))) \
	  

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< $(RL_INCLUDE) -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mCleaning libft..."
	@echo "\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all
