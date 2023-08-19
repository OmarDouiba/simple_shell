#include "main.h"

/**
 *handle_signal - Signal handler function for
 *handling the SIGINT signal (Ctrl+C).
 *When SIGINT is received, a newline
 *and prompt symbol "$ " are printed.
 * @sin: signal
 */
void handle_signal(int sin)
{
	if (sin == SIGINT)
	{
		/*Print a newline and prompt symbol*/
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
