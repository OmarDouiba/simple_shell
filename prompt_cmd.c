#include "main.h"

/**
 * prompt_cmd - Function That prompt $ to the user
 * wating for write command. 
*/
void prompt_cmd(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        write(STDOUT_FILENO, "$ ", 2);
    }
}
