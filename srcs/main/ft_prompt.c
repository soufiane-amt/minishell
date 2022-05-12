
#include "minishell.h"


int open_prompt(char  **env)
{
    t_token  **token;

    signal(SIGINT,ctl_c);
    signal(SIGQUIT, ctl_c);
    //    get_env_while_prompt(data, '=');
    while (1)
    {
        data.input = readline("𝖒𝖎𝖓𝖎𝖘𝖍𝖊𝖑𝖑➜");
        if (!data.input)
            return (0);
        ft_collect_data(env);
        if (!*data.status.exit_code && check_user_input(data.input))
        {
            if (data.input_piped)
            {
                token = init_token();
                ft_get_token(token);
                exec_cmd_ln (token);
                // ft_tokenprint (token);
                free_tokens(token);
            }
            else if (!*data.status.exit_code)
            {
                exec_cmd_ln (token);
            }
            add_history(data.input);
        }
        if (data.status.status)
            notify_error(data.status.status, NULL);
        // exec_rebuilt_cmd(data);
        // printf ("%d\n", *data.status.exit_code);
        free_t_data();
    }
    return 0;
}