<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://stackedit.io/style.css" />
</head>

<body class="stackedit">
  <div class="stackedit__html"><h1 id="c---simple-shell"># C - Simple Shell</h1>
<p><img src="https://i.ibb.co/k90MFrD/ST-14.png" alt="Project for Holberton School MiniShell"></p>
<h2 id="background-context">Background Context</h2>
<p>Write a simple UNIX command interpreter.</p>
<h2 id="resources">Resources</h2>
<p>Read or watch:</p>
<ul>
<li><a href="https://en.wikipedia.org/wiki/Unix_shell">Unix Shell</a></li>
<li><a href="https://en.wikipedia.org/wiki/Unix_shell">Thompson shell</a></li>
<li><a href="https://en.wikipedia.org/wiki/Ken_Thompson">Ken Thompson</a></li>
<li><a href="https://www.google.com">Everything you need to know to start coding your own shell concept page</a></li>
</ul>
<p>man or help:</p>
<ul>
<li><code>sh</code> (Run sh as well)</li>
</ul>
<h2 id="learning-objectives">Learning Objectives</h2>
<p>At the end of this project, you are expected to be able to <a href="https://fs.blog/feynman-learning-technique/">explain to anyone</a>, without the help of Google</p>
<h2 id="general">General</h2>
<ul>
<li>Who designed and implemented the original Unix operating system</li>
<li>Who wrote the first version of the UNIX shell</li>
<li>Who invented the B programming language (the direct predecessor to the C programming language)</li>
<li>Who is Ken Thompson</li>
<li>How does a shell work</li>
<li>What is a pid and a ppid</li>
<li>How to manipulate the environment of the current process</li>
<li>What is the difference between a function and a system call</li>
<li>How to create processes</li>
<li>What are the three prototypes of main</li>
<li>How does the shell use the PATH to find the programs</li>
<li>How to execute another program with the execve system call</li>
<li>How to suspend the execution of a process until one of its children terminates</li>
<li>What is EOF / “end-of-file”?</li>
</ul>
<h1 id="requirements">Requirements</h1>
<h2 id="general-1">General</h2>
<ul>
<li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using <code>gcc</code>, using the options <code>-Wall -Werror -Wextra -pedantic -std=gnu89</code></li>
<li>All your files should end with a new line</li>
<li>A <code>README.md</code> file, at the root of the folder of the project is mandatory</li>
<li>Your code should use the <code>Betty</code> style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl">betty-doc.pl</a></li>
<li>Your shell should not have any memory leaks</li>
<li>No more than 5 functions per file</li>
<li>All your header files should be include guarded</li>
<li>Use system calls only when you need to (why?)</li>
</ul>
<h2 id="list-of-allowed-functions-and-system-calls">#List of allowed functions and system calls</h2>
<ul>
<li><code>access</code> (man 2 access)</li>
<li><code>chdir</code> (man 2 chdir)</li>
<li><code>close</code> (man 2 close)</li>
<li><code>closedir</code> (man 3 closedir)</li>
<li><code>execve</code> (man 2 execve)</li>
<li><code>exit</code> (man 3 exit)</li>
<li><code>_exit</code> (man 2 _exit)</li>
<li><code>fork</code> (man 2 fork)</li>
<li><code>free</code> (man 3 free)</li>
<li><code>getcwd</code> (man 3 getcwd)</li>
<li><code>getline</code> (man 3 getline)</li>
<li><code>getpid</code> (man 2 getpid)</li>
<li><code>isatty</code> (man 3 isatty)</li>
<li><code>kill</code> (man 2 kill)</li>
<li><code>malloc</code> (man 3 malloc)</li>
<li><code>open</code> (man 2 open)</li>
<li><code>opendir</code> (man 3 opendir)</li>
<li><code>perror</code> (man 3 perror)</li>
<li><code>read</code> (man 2 read)</li>
<li><code>readdir</code> (man 3 readdir)</li>
<li><code>signal</code> (man 2 signal)</li>
<li><code>stat</code> (__xstat) (man 2 stat)</li>
<li><code>lstat</code> (__lxstat) (man 2 lstat)</li>
<li><code>fstat</code> (__fxstat) (man 2 fstat)</li>
<li><code>strtok</code> (man 3 strtok)</li>
<li><code>wait</code> (man 2 wait)</li>
<li><code>waitpid</code> (man 2 waitpid)</li>
<li><code>wait3</code> (man 2 wait3)</li>
<li><code>wait4</code> (man 2 wait4)</li>
<li><code>write</code> (man 2 write)</li>
</ul>
<h2 id="compilation">Compilation</h2>
<p>Your shell will be compiled this way:</p>
<pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
</code></pre>
<h2 id="commands">Commands</h2>
<p>At minimum, this shell handles the following commands to display file contents on the command line:<br>
<code>cat</code> :Concatenates the file and gives output on standard output.<br>
<code>less</code>: View files instead of opening the file. Allows backward and forward movement.<br>
This shell handles the following file and directory manipulation commands:<br>
<code>mkdir</code>: Creates a directory and accepts directory name as next parameter.<br>
<code>rm</code> and <code>rm -r</code>: Used to delete files and directories.<br>
<code>touch</code>: Creates a file or updates a file.<br>
And the following basic command line navigation commands:<br>
<code>ls</code>: Displays list of all files and folders in the current directory.<br>
<code>cd</code>: Changes the directory.<br>
<code>du</code>: Shows disk usage.<br>
<code>pwd</code>: Shows the present working directory.<br>
<code>man</code> + <code>cmd</code>: Shows the manual entry for any given command.<br>
<code>exit</code>: Quits the simple_shell program.</p>
<h2 id="output">Output</h2>
<ul>
<li>Unless specified otherwise, your program <strong>must have the exact same output</strong> as <code>sh (/bin/sh)</code> as well as the exact same error output.</li>
<li>The only difference is when you print an error, the name of the program must be equivalent to your <code>argv[0]</code> (See below)</li>
</ul>
<p>Example of error with sh:</p>
<pre><code>$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
</code></pre>
<p>Same error with your program hsh :</p>
<pre><code>$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
</code></pre>
<h2 id="testing">Testing</h2>
<p>Your shell should work like this in interactive mode:</p>
<pre><code>$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
</code></pre>
<p>But also in non-interactive mode :</p>
<pre><code>$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
</code></pre>
</div>
</body>

</html>
