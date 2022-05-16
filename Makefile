NAME = minishell

HEADER = minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

READ= -L /goinfre/$(USER)/.brew/opt/readline/lib -lreadline

RL_INCLUDE = -I /goinfre/$(USER)/.brew/opt/readline/include

CMD_SRC = ft_echo exec_built is_built_cmd ft_pwd ft_env ft_exit\
			ft_export ft_unset ft_cd _char _char2 _char3

DATA_SRC = free_data collect_data free_utils

M_SRC =  ft_prompt main

CTL_SRC = ctl_c

P_SRC = get_token get_cmd_data get_spliter_data redirection_handler ft_extractor ft_replace_values redirection\
		

U_SRC = ft_strcmp ft_strlen ft_split ft_strdup ft_substr  ft_strchr ft_utils_env_exp ft_strcpy ft_strjoin \
		ft_contain  ft_strlcpy\
		ft_strtrim ft_ispace extract_util ft_memcmp display_content\
		add_str  ft_putnbr_fd ft_putstr_fd\
                        
E_SRC        =        build_cmd exec_cmd_ln execute add_path ft_open_herdoc\

LST_SRC = ft_lstadd_back ft_lstadd_front ft_lstclear \
			ft_lstdelete_last ft_lstdelete_top ft_lstdelone \
			ft_lstiter ft_lstlast ft_lstnew ft_lstprint ft_lstsize\
			ft_lst_contain \

G_SRC	= get_next_line\

ERR_SRC = print_error chstatus check_syntax check_redirection check_user_input\

INIT_SRC = ft_init_cmd ft_init_token ft_init_t_data


## fill_list  
	 


SRC = $(addsuffix .c, $(addprefix srcs/cmd/, $(CMD_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/main/, $(M_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/utils/, $(U_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/data_managment/, $(DATA_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/ctl/, $(CTL_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/exec_cmd/, $(E_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/ft_lst/, $(LST_SRC)))\
	  $(addsuffix .c, $(addprefix srcs/parsing/, $(P_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/get_next_line/, $(G_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/error_handler/, $(ERR_SRC))) \
	  $(addsuffix .c, $(addprefix srcs/ft_init/, $(INIT_SRC))) \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "\033[0;32mCompiling minishell..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READ) -g
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< $(RL_INCLUDE) -o $@ -g

clean:
	@echo "\nRemoving files..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31mDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all
