/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:17:06 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 01:32:31 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//Header//
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <editline/readline.h>
# include <stddef.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <termios.h>

//SPECIAL CHARACTERS
# define PIPE       0x00000007c
//Redirection input / output
# define INPUT_RE     0x00000003c
# define OUTPUT_RE    0x000000005

// 
# define NO_PRNTESIS 
//
# define TRUE       1
# define FALSE      0

//
# define NINPUT     33
# define HEREDOC    66

//Write file Mode
# define O_APPEND        0x0008
# define O_TRUNC         0x0400

//Linked list types
# define CHAR 10
# define INT 20

// Random values
# define PIPEFAIL 100

//Error messages
# define MEMORY_LACK "the memory you try to malloc is not available,	\
	please free up some space and try again!"

# define CMD_NOT_FOUND  "minishell: command not found: "

# define PERMISSION_DENIED "minishell: permission denied: "

# define SYNTAX_ERROR "minishell: syntax error near unexpected token  "

# define FD_ERROR "failed to open file."

# define TOO_MANY_ARGS "too many arguments."

# define OTHER_ERR "ERROR!"

# define NO_F_OR_D "No such file or directory!"

//file not found error
//Global variable

typedef struct s_env
{
	char			*variable;
	char			*value;
	struct s_env	*next;
}		t_env;

////Create a linked list 
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

typedef struct s_status
{
	char	*status;
	int		*exit_code;
}	t_status;

//structures
typedef struct s_data
{
	char		**env;
	char		*input;
	char		*path;
	char		**all_paths;
	char		*mypath;
	int			i;
	int			j;
	int			l;
	int			e;
	int			c;
	int			call_nbr;
	int			process_nbr;
	t_list		*fds;
	int			input_piped;
	int			spliter_sucess;
	t_status	status;
	t_env		*enver;
	int			error_status;
	int			exit_the_program;
	int			is_running;
}	t_data;

typedef struct s_std
{
	int		fd;
	int		mode;
}	t_std;

////s_cmd aims to content the cmmand and its components 
//.e.g options directories files
typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
	t_list	*in_redirect_f;
	t_list	*out_redirect_f;
	t_list	*heredoc_delimits;
	char	*cmd_str;
	char	**f_cmd;
	t_list	*ex_elements;
	t_std	input;
	t_std	output;
}	t_cmd;

t_data	g_data;

//the next structor will be used only in case of multicommands
typedef struct s_spliter
{
	int		spec_char;
	t_cmd	*prev_cmd;
	t_cmd	*next_cmd;
	int		pipe[2];
	int		*all_fd;
}	t_spliter;

//it takes the hole command input and split it to commands
typedef struct s_token
{
	t_spliter		*sep;
	struct s_token	*next;
}	t_token;
//One global variable

//Test
void			display_file(int fd);

//Data funcs
void			ft_collect_data(void);

//builtin funcs
void			ft_cd(t_cmd *cmd);
void			ft_echo(t_cmd *cmd);
void			ft_env(t_cmd *cmd, int is);
void			ft_exit(void);
void			ft_export(t_cmd *cmd);
char			*ft_pwd(void);
void			ft_unset(t_cmd *cmd);
void			exec_built_cmd(t_cmd *cmd, int result);
int				is_built_cmd(t_cmd *cmd);

//utils
int				ft_strlen(const char *str);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
void			display_file(int fd);
int				ft_override_spaces(char *s, int *i);
void			add_string(char **str, char *added);
char			*ft_strchr(char const *str, int c);
int				ft_contain(char *str, char *to_look_for);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_is_redi(char c);
int				ft_is_quote(char c);
int				ft_ispace(char c);
int				ft_is_redirection(char *str);
char			*ft_itoa(int n);
int				ft_is_redi_str(char *s);

//_char
char			*_char(char *str);
char			*ft_charjoin(char *s1, char c);
int				who_first(char *str);
int				cpy_var(char *str, char *var, char c);
int				size_var(char *str, char c);
int				is_ex12(char *str, char c);
int				really(char *str, int to, char c);
void			get_value_from_enver(char **st, char *var);
int				ft_expand(char **_last, char *str);
//main funcs
void			open_prompt(char **env);

// ctl
void			ctl(int sig);
void			signalize(void);

//ft_lst
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content, int type);
void			ft_lstprint(t_list *lst);
int				ft_lst_contain(t_list **lst, char *str);
void			ft_lstclear(t_list **lst, int free_content);
void			ft_lstdelone(t_list **lst, int free_content);

// lst env
t_env			*ft_env_last(t_env *lst);
void			ft_env_tadd_back(t_env **lst, t_env *new);
t_env			*ft_env_new(char *var, char *val);
void			ft_env_clear(t_env **lst);
int				ft_env_size(t_env *lst);

//t_token
t_token			*ft_tokenlast(t_token *lst);
int				ft_token_size(t_token *lst);
t_token			*ft_token_new(t_spliter *t_sep);
void			ft_cmd_print(t_cmd *cmd);
void			ft_token_add_back(t_token **token, t_token *new);
void			ft_tokenprint(t_token **token);
t_spliter		*ft_split_by_sep(void);
void			ft_get_token(t_token **token);
t_token			**init_token(void);
int				get_spliter_data(t_spliter *spliter, char *prev_cmd,
					char *next_cmd);

//t_cmd
void			ft_cmd_print(t_cmd *cmd);
t_cmd			*get_cmd_data(char *command);
void			open_redir_files(t_cmd *cmd);
void			build_cmd(t_cmd *cmd);
void			exec_cmd(t_cmd *cmd);
void			exec_cmd_ln(t_token **token);
int				add_path(t_cmd *cmd, char *t_command);
void			ft_extract_data(t_cmd *cmd, char *command);
void			ft_open_heredoc(t_cmd *cmd, char *delimter);
void			ft_replace_with_acctual_values(t_cmd *cmd);
void			get_cmd_out_redirct(t_cmd *cmd, t_list *temp);
void			get_cmd_in_redirct(t_cmd *cmd, t_list *temp);
void			get_cmd_redirect(t_cmd *cmd, t_list *temp);

//free
void			free_tokens(t_token **token);
void			close_fd(t_cmd *cmd, int close_all);
void			free_arr(void **arr);
void			free_cmd(t_cmd *cmd);
void			free_spliter(t_spliter *spliter, int last_token);
void			free_arr(void **arr);
void			free_t_data(void);
void			free_enver(void);

//get_next_line
char			*get_next_line(int fd);

//Error
void			print_error(char *message);
void			chstatus(char *exit_message, char *cmd, int exit_code);
void			notify_error(char *message, char *cmd);
int				check_syntax(t_cmd *cmd, char *command);
int				check_prenthesis(char *str);
char			*if_prenthesized(char *str, char **t_str);
int				input_redirection_is_valid(char *cmd);
int				output_redirection_is_valid(char *cmd);
int				check_user_input(char *str);
int				cmd_piped(void);
int				cmd_piped2(void);
//init
t_cmd			*ft_init_cmd(void);
t_token			**init_token(void);
void			ft_init_t_data(void);

//enver export
void			get_env_while_prompt( char c, char **env);
char			*get_env(char *str);
//utils expo
int				size_var_val(char *str, int x, char c);
void			cpy_var_val(char *str, char *var, char *val, char c);
int				is_id(char *var);

//extractors
int				extract_redir(t_cmd *cmd, char *str, int *i);
int				extract_quote(t_cmd *cmd, char	*str, int *i);
int				extract_norm(t_cmd *cmd, char *str, int *i);
int				ft_add_extracted_element(t_cmd *cmd, char *s);
int				is_delimter(char c, char *delimter);

#endif