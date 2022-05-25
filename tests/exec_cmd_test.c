/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:19:40 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 20:03:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <string.h>

typedef struct data
{
	int		id;
	int		**pipes;
	char	*path;
	char	**all_paths;
	char	*mypath;
	char	**cmd;
	int		last_pipe;
	int		pipes_nbr;
	int		infile;
	int		outfile;
	char	**argv;
	char	**env;
	int		argc;
	int		is_here_doc;
	int		pipe_arr_included;
}   t_data;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (len > ft_strlen(s) + 1)
		len = ft_strlen(s);
	substr = (char *) malloc (sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
	}
	substr[j] = 0;
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

static void	tt_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (str_tab[j]);
		j++;
	}
	free(str_tab);
}

static int	totalwords(char *str, char c)
{
	int		result;
	size_t	i;
	int		a;

	result = 0;
	i = 0;
	a = 0;
	while (str && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			a = 1;
		}
		if (a)
			result++;
		a = 0;
	}
	return (result);
}

static char	*fill(char c, char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	s = (char *) malloc (sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

static void	split(char **f_s, char c, int size, char *str)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		while (*str && *str == c)
			str++;
		f_s[i] = fill(c, str);
		if (!f_s[i])
		{
			tt_free (f_s, i);
			return ;
		}
		while (*str && *str != c)
			str++;
	}
	f_s[size] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**f_s;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	str = (char *)s;
	f_s = (char **) malloc (sizeof(char *) * (totalwords((char *)s, c) + 1));
	if (!f_s)
		return (NULL);
	split(f_s, c, totalwords((char *)s, c), str);
	return (f_s);
}


char	*extract_paths(char **env)
{
	int		i;
	char	*line;
	int		path_length;

	i = 0;
	while (env[i])
	{
		line = ft_substr (env[i], 0, 4);
		path_length = ft_strlen (env[i]);
		if (!memcmp (line, "PATH", 4))
		{
			free (line);
			return (ft_substr(env[i], 5, path_length));
		}
		free (line);
		i++;
	}
	return (NULL);
}

void	generate_paths(char **env)
{
	int		i;
	char	*str;

	g_data.path = extract_paths (env);
	g_data.all_paths = ft_split (g_data.path, ':');
	free(g_data.path);
	i = 1;
	while (g_data.all_paths[++i])
	{
		str = g_data.all_paths[i];
		g_data.all_paths[i] = ft_strjoin (str, "/");
		free(str);
	}
}
void	exec_cmd(char *command, char **env)
{
	int	i;

    generate_paths(data, env);
	i = 0;
	g_data. cmd = ft_split (command, ' ');
	while (g_data.all_paths[i])
	{
		g_data.mypath = ft_strjoin (g_data.all_paths[i], g_data.cmd[0]);
		execve (g_data.mypath, g_data.cmd, g_data.env);
		i++;
	}
}
int main (int   argc, char **argv, char **env)
{
    t_data data;

    exec_cmd(&data, argv[1], env);
}