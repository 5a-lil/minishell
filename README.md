# minishell

This mini-bash executable handles the majority of **Bash POSIX features** like **multi-pipes**, **redirections**, **env management** etc...
To launch the minishell do:
```
$ make
```
then just launch the binary:
```
$ ./minishell
```
There are also implementations of some bash commands remade for scratch named builtins:
- echo with -n option
- cd
- pwd
- export
- unset
- env
- exit
Also some minishell features:
- ctrl-C, ctrl-D and ctrl-\ handling
- environment variables management
- $? special value featured
- multi-pipes
- redirections (>, >>, < and <<)
- closed single and closed double quotes handling

Have fun now ! 🔥
