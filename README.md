Group project : 0x16. C - Simple Shell

Requirements to be respect :
General :

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc,
using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
- Write a README with the description of your project
- You should have an AUTHORS file at the root of your repository, listing all individuals having
contributed content to the repository. Format, see Docker

Github :

here should be one project repository per group. If you and your partner have a repository with
the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator.

Copyright - Plagiarism :

You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
You are not allowed to publish any content of this project.
Any form of plagiarism is strictly forbidden and will result in removal from the program.

tasks :
mandatory :

0. Betty would be proud
Write a beautiful code that passes the Betty checks
1. Simple shell 0.1
Write a UNIX command line interpreter.

Your Shell should:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to :
use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
2. Simple shell 0.2
Handle command lines with arguments
3. Simple shell 0.3
Handle the PATH
fork must not be called if the command doesn’t exist
4. Simple shell 0.4
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
5. Simple shell 1.0
Implement the env built-in, that prints the current environment

advanced :

6. Simple shell 0.1.1
Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
7. Simple shell 0.2.1
You are not allowed to use strtok
8. Simple shell 0.4.1
handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell
9. setenv, unsetenv
Implement the setenv and unsetenv builtin commands
setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure
10. cd
Implement the builtin command cd:
Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory
11. ;
Handle the commands separator ;
12. && and ||
Handle the && and || shell logical operators
13. alias
Implement the alias builtin command
Usage: alias [name[='value'] ...]
alias: Prints a list of all aliases, one per line, in the form name='value'
alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
alias name='value' [...]: Defines an alias for each name whose value is given.
If name is already an alias, replaces its value with value
14. Variables
Handle variables replacement
Handle the $? variable
Handle the $$ variable
15. Comments
Handle comments (#)
16. File as input
Usage: simple_shell [filename]
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from stdin
