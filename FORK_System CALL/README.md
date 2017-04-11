# Fork (system call)
+ In computing, particularly in the context of the Unix operating system and its workalikes, fork is an operation whereby a process creates a copy of itself. It is usually a system call, implemented in the kernel. Fork is the primary (and historically, only) method of process creation on Unix-like operating systems.
+ In multitasking operating systems, processes (running programs) need a way to create new processes, e.g. to run other programs. Fork and its variants are typically the only way of doing so in Unix-like systems. For a process to start the execution of a different program, it first forks to create a copy of itself. Then, the copy, called the "child process", calls the exec system call to overlay itself with the other program: it ceases execution of its former program in favor of the other.
# Problem Statement
+ Process control system calls: The demonstration of fork and wait system calls along with zombie and orphan states.
	 - Implement the C program in which main program accepts the integers to be sorted.
		Main program uses the fork system call to create a new process called a child process.
		Parent process sorts the integers using merge sort and waits for child process using wait
		system call to sort the integers using quick sort. Also demonstrate zombie and orphan
		states.
#How to Compile
- __gcc fork.c__
- __./a.out__
