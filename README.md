# minishell

Le projet Minishell est le premier projet en binome a l'ecole 42.
Il consiste à créer un shell minimaliste en C qui peut interpréter des commandes simples.

Objectifs

Créer un shell qui peut afficher un prompt en attente d'une nouvelle commande
Posséder un historique fonctionnel
Chercher et lancer le bon exécutable en se basant sur la variable d'environnement PATH, ou sur un chemin relatif ou absolu
Ne pas utiliser plus d'une variable globale
Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule)
Gérer les single quotes (') qui doivent empêcher le shell d'interpréter les caractères spéciaux

Fonctions autorisées

Les fonctions suivantes sont autorisées pour le projet :

readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
printf, malloc, free, write
access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs.

Les built-in suivants ont été recodés : 

◦ echo et l’option -n
◦ cd uniquement avec un chemin relatif ou absolu 
◦ pwd sans aucune option
◦ export sans aucune option
◦ unset sans aucune option
◦ env sans aucune option ni argument
◦ exit sans aucune option

Les quotes non fermés ont été interpretés.

Utilisation

Pour compiler le programme, vous pouvez utiliser le Makefile fourni en tapant la commande make.

Une fois le programme compilé, vous pouvez l'exécuter en tapant ./minishell.

Conclusion

Le projet Minishell a permis de développer des compétences en programmation en C, en particulier dans la manipulation de processus et de descripteurs de fichier. Cela a également permis de mieux comprendre le fonctionnement d'un shell.
