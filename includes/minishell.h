/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:17:06 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 14:27:30 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

//Header//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <editline/readline.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#include <termios.h>

//SPECIAL CHARACTERS
# define PIPE       0x00000007c
//Redirection input / output
# define INPUT_RE     0x00000003c
# define OUTPUT_RE    0x000000005

//Write file Mode
#define O_APPEND        0x0008
#define O_TRUNC         0x0400

//data types
# define CHARp       112
# define INTp       114

//structures
typedef struct s_env
{
    char *variable;
    char *value;
    struct s_env *next;
}   t_env; // t_cmd/t_env *enver/all enverment variable

typedef struct s_data
{
    char    **env;
    char    *input;
    char	*path;
	char	**all_paths;
	char	*mypath;
	int		i;
    int		j;
    int		l;
	int     call_nbr;
    t_env   *enver;
}   t_data;

////Create a linked list to contain args and options
typedef struct s_list
{
    char            *content;
    struct s_list    *next;
}   t_list;

typedef struct s_std
{
    int     fd;
    int     mode; 
}   t_std;

////s_cmd aims to content the cmmand and its components 
//.e.g options directories files
typedef struct s_cmd
{
    char    *cmd;
    t_list  *options;
    t_list  *args;
    t_list  *in_redirect_f;
    t_list  *out_redirect_f;
    char    *cmd_str;
    char    **splited_cmd;
    char    **f_cmd;
    t_std     input;
    t_std     output;
    //always set the fd to default
}   t_cmd;

//the next structor will be used only in case of multicommands
typedef struct s_spliter
{
    int		spec_char;
    t_cmd	*Prevcmd;
    t_cmd	*Nextcmd;
    int		pipe[2];
    //execute pipe function here if you could
}   t_spliter;


//it takes the hole command input and split it to commands
typedef struct s_token
{
    t_spliter   *sep;
    struct s_token   *next;
}   t_token;


//Data funcs
void    ft_get_program_args(t_data *data, char **input);
void    ft_collect_data(t_data *data, char **env);
void    free_arr(char **arr);

//builtin funcs
void    ft_cd(t_data *data, t_cmd *cmd);
void    ft_echo(t_data *data, t_cmd *cmd);
void    ft_env(t_data *data, int is);
void    ft_exit(t_cmd *cmd, t_data *data);
void    ft_export(t_data *data, t_cmd *cmd);
char    *ft_pwd(t_data *data);
void    ft_unset(t_data *data, t_cmd *cmd);
void	exec_rebuilt_cmd(t_data *data, t_cmd *cmd);
int     is_rebuilt_cmd(t_cmd *cmd);


//utils
int     ft_strlen(const char *str);
int     ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char    *ft_cpy_until(char *str, char *delimter, int start);
char    *ft_get_word_after_c(char  *str, char c);
int     ft_contain(char  *str, char *to_look_for);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int	    ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char    *_char(char *str);
char	*ft_charjoin(char *s1, char c);
int     who_first(char *str);
int     cpy_var(char *str, char *var, char c);
int     size_var(char *str, char c)
//main funcs
int open_prompt(t_data *data, char  **env);
// ctl
void    ctl_c(int sig);

//ft_lst
t_list  *ft_lstlast(t_list *lst);
int	    ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstprint(t_list *lst);
int     ft_lst_contain(t_list **lst, char *str);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
// lst env
t_env	*ft_env_last(t_env *lst);
void	ft_env_tadd_back(t_env **lst, t_env *new);
t_env	*ft_env_new(char *var, char *val);
void	ft_env_clear(t_env **lst);

//t_token
t_token     *ft_tokenlast(t_token *lst);
int         ft_token_size(t_token *lst);
t_token     *ft_token_new(t_spliter *t_sep);
void        ft_cmd_print(t_cmd *cmd);
void        ft_token_add_back(t_token **token, t_token *new);
void        ft_tokenprint(t_token **token);
t_spliter   *ft_split_by_sep(t_data *data);
void        ft_get_token (t_data *data, t_token **token);
t_token     **init_token();
t_spliter   *ft_split_by_sep(t_data *data);
int         get_spliter_data(t_spliter *spliter, char  *prev_cmd, char *next_cmd, t_data *data);

//t_cmd
void    ft_cmd_print(t_cmd *cmd);
t_cmd   *get_cmd_data (char  *cmd_str);
void    open_redir_files(t_cmd *cmd);
void    build_cmd (t_cmd *cmd);
void    exec_cmd (t_data *data, t_cmd *cmd);
void    exec_cmd_ln(t_data *data, t_token **token);

//free
void    free_tokens (t_token *token);

//enver export
void get_env_while_prompt(t_data *data,  char c);

//utils expo
int size_var_val(char *str, int x, char c);
void cpy_var_val(char *str, char *var, char *val, char c);

#endif