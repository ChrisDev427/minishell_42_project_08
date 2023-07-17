# minishell
The Minishell project is the first group project at École 42.
It involves creating a minimalist shell in C that can interpret simple commands.

Objectives

Create a shell that can display a prompt and wait for a new command.
Implement functional command history.
Search for and execute the correct executable based on the PATH environment variable or a relative or absolute path.
Avoid using more than one global variable.
Do not interpret unclosed quotes or unrequested special characters such as backslashes () or semicolons (;).
Handle single quotes (') to prevent the shell from interpreting special characters.
Allowed Functions

The following functions are allowed for the project:

readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
printf, malloc, free, write
access, open, read, close
fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit
stat, lstat, fstat, unlink, execve
dup, dup2, pipe
opendir, readdir, closedir
strerror, perror
isatty, ttyname, ttyslot, ioctl
getenv
tcsetattr, tcgetattr
tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
The following built-in functions have been recoded:

echo with the -n option
cd only with a relative or absolute path
pwd without any options
export without any options
unset without any options
env without any options or arguments
exit without any options
Unclosed quotes have been interpreted.

Usage

To compile the program, you can use the provided Makefile by running the command make.

Once the program is compiled, you can execute it by typing ./minishell.

Conclusion

The Minishell project allowed for the development of C programming skills, particularly in process manipulation and file descriptors. It also provided a better understanding of how a shell works.
