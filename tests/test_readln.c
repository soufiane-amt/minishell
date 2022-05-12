#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <editline/readline.h>
#include <unistd.h>
int main()
{
    char *cmd;
    while (1)
    {
        cmd = readline(">");
        add_history(cmd);
        if (access(cmd, W_OK) == 0)
            printf("%s\n",cmd);         // print the path if exists
    }
    return 0;
}
