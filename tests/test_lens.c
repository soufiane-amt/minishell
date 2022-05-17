#include <stdio.h>
#include <unistd.h>
#include <string.h>
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int test(char *str, int x)
{
    int i;
    
    i = 0;
    if (x == 1)
    {
        while (str[i] && str[i] != '=')
            i++;
        return (i);
    }
    return (ft_strlen(ft_strchr(str, '=')+1));
}

int main()
{
    printf("%d\n",test("var=mehdi", 1));
}