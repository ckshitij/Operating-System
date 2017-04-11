# exec (system call)
+ In computing, **exec** is a functionality of an operating system that runs an executable file in the context of an already existing process, _replacing the previous executable_. This act is also referred to as an overlay. 
+ It is especially important in Unix-like systems, although exists elsewhere. As a new process is not created, the process identifier (PID) does not change, but the machine code, data, heap, and stack of the process are replaced by those of the new program.
+ The exec is available for many programming languages including compilable languages and some scripting languages. In OS command interpreters, the exec built-in command replaces the shell process with the specified program.

 - `int execl(char const *path, char const *arg0, ...);`<br>
 - `int execle(char const *path, char const *arg0, ..., char const *envp[]);`<br>
 - `int execlp(char const *file, char const *arg0, ...);`<br>
 - `int execv(char const *path, char const *argv[]);`<br>
 - `int execve(char const *path, char const *argv[], char const *envp[]);`<br>
 - `int execvp(char const *file, char const *argv[]);`<br>

# About Codes
+ There are two Codes Present in this Directory.
  - First file is **exec_parent.c** which take *array of Integer* and sort the elemnts and send it to the child process using
    **execv** function.
  - Second code **exec_child.c** accept the array and search the element using **Binary Search**.
