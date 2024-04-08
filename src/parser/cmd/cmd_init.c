// #include "minishell.h"

// t_cmd   *new_cmd()
// {
//     t_cmd   *node;

//     node = malloc(sizeof(char *));
//     node->comand = ft_calloc(1, sizeof(char *));
//     node->comand[0] = NULL;
//     node->fd_in = 0;
//     node->fd_out = 1;
//     node->next = NULL;
//     return(node);
// }

// void add_cmd(t_cmd **cmd,t_cmd *new_cmd)
// {
//     t_cmd *tmp;

//     tmp = *cmd;

//     if (!*cmd == NULL)
//         *cmd = new_cmd;
//     else
//     {
//         tmp = *cmd;
//         while (tmp->next != 0)
//             tmp = tmp->next;
//         tmp->next = new_cmd;
//     }
// }