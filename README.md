#	 **How should the program behave ?**
### `./pipex file1.txt "cat" "wc -l" file2.txt`
 needs to behave like
### `< file1.txt cat | wc -l > file2.txt`

##	 **Breakdown**
> **1.** Read the contents from `file1.txt`
- `< file1.txt` redirects the contents of `file1.txt` to the `standard input (stdin)`

> **2.** Run `cat` with the contents from step 1
- Note: Not all commands take input from `stdin`

> **3.** Write the output of `cat` to `| (pipe)`
- instead of writing the output to `stdout`, the output is written to `|`

> **4.** `wc -l` reads its input from `|`
- the ouput of `cat` is connected to the input of `wc -l` via `|`

> **5.** Redirect the output of `wc -l` to `file2.txt`


# 	**Things to know before starting**
## 0. Commands are scattered throughout different places
Not all commands are found in `/bin/`, there are some in `/usr/bin/` and in other places. Luckily, the `PATH` environment variable has specified a set of directories where executable programs are located.
Type the following in the shell to get the variable:
```
$> env | grep 'PATH='
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```
The directories are separated by a colon(`:`)

## 1. Commands that take input from stdin
1. `cat`: Concatenates and prints files. If no file is specified, or if the file is -, it reads from stdin.

2. `grep`: Searches for a pattern in the input. It can read from stdin.

3. `sort`: Sorts lines in text. It can read from stdin.

4. `awk`: A versatile programming language for working with text. It can read from stdin.

5. `sed`: A stream editor for filtering and transforming text. It can read from stdin.

6. `wc`: Counts lines, words, and characters. It can read from stdin.

7. `cut`: Removes sections from each line of files. It can read from stdin.

8. `paste`: Merges lines of files. It can read from stdin.

9. `tr`: Translates or deletes characters. It can read from stdin.

10. `uniq`: Reports or omits repeated lines. It can read from stdin.

##	2. Why `< file1.txt cat` instead of `file1.txt > cat` ?
This is the result:
```
$> file1.txt > wc -w
bash: ./file1.txt: Permission denied
```

## 3. Shell built-in commands
 > `type <command>`

By using the `type` command, we can see if the `command` is a `shell built-in`, a file in the `PATH`, an `alias`, a `function`, or a `keyword`

```
$> type cd
cd is a shell builtin

$> type ls
ls is aliased to `ls --color=auto'

$> type python
python is /usr/bin/python
```

# **Prototype**
### `./pipex file1 cmd1 cmd2 file2`
### `./pipex infile "ls -l" "wc -l" outfile`

## **Step 0: Input parsing**
Since `argv[2]` & `argv[3]` are the commands with their `command line options`/`flags`, it is important to parse the string before proceeding:
1. use `ft_split` with the `space character` as a delimter so the command and its options can be separated and stored for later operations

Moreover, since `execve()` only takes the absolute path of the command as its argument, we have to find out where is the command located:

2. make sure to add `char *envp[]` to your `main()`'s arguments:
>`int main(int argc, char *argv[], char *envp[])`

`envp` is a parameter that represents the environment variables

There are a lot of variables stored in `envp` but only the `PATH` variable is needed.

3.  so, use `ft_strncmp` to find the string `"PATH="` while looping through `envp`
4.  use `ft_split` with `:` as the delimiter to seperate out each paths
5.  append `/<cmd>`(replace with the actual command) to each path

## **Step 1: Input validation**
1. check if `argc` is `5`
2. use `access` to check if `argv[1]` is a present file
3. check if `argv[2]` & `argv[3]` are valid shell commands using the `access` command

## **Step 2: Open `file1` & redirect to `stdin`**
Since most shell commands that take input can read from `stdin`, by using `dup2()` we can effectively links the `fd` obtained from `open()` to `stdin`.

## **Step 3: Create a `pipe1` for inter-process communication**
`pipe` takes a an int array with 2 elements `int pipe1[2]` as its parameter. `pipe1[1]` will be the end that we can write input into, while`pipe1[0]` will be the end that we can read the output from. Paired with `dup2`, we are able to do some pretty fascinating read/write operations.

## **Step 4: Fork a child process to run `cmd1`**
Something worth to note is that although `fork` creates a copy of the parent process, but the child process start its execution from the point where `fork` is called.

## **Step 4.1: Use `wait` to halt the execution of the parent process**
This should halt the execution of the parent process until the child process finish its execution, thus concurrency is avoided.

## **Step 4.2: Redirecting output of `cmd1` to the pipe's write end**
In the child process, use `dup2` to redirect `stdout` to `pipe1[1](input end of the pipe)`, thus the output of `cmd1` is written into `pipe1[1]`

## **Step 4.3: Call `execve` to execute `cmd1`**
If `cmd1` takes input from `stdin` the contents of `file1` that we have been redirected to `stdin` will be used here.

After the child process finished, the parent process continues its execution.

## **Step 5: Open `file2`**
When calling `open`, `O_CREAT | O_WRONLY | O_TRUNC` should be passed as the second argument (`int __oflag`). The following is what each flag does:

1. `O_CREAT`: This flag means that if the file does not exist, it will be created.

2. `O_WRONLY`: This flag means that the file is opened for writing only.

3. `O_TRUNC`: This flag means that if the file already exists and is a regular file, it will be truncated to length 0. If the file is successfully opened, any data that it previously contained is discarded.

And the third argument will be `0644`. This is a file permission mode used when opening a file using `open`.

Let's break down `0644`:

1. The leading `0` indicates that the number is in octal format.
2. The first digit, `0`, represents the special permissions. In this case, it is set to `0`, which means no special permissions are set.
3. The second digit, `6`, represents the owner's permissions. `6` in octal corresponds to `110` in binary, which means the owner has read and write permissions.
4. The third digit, `4`, represents the group's permissions. `4` in octal corresponds to `100` in binary, which means the group has read-only permissions.
5. The fourth digit, `4`, represents the permissions for others (everyone else). `4` in octal corresponds to `100` in binary, which means others have read-only permissions


So, in this case, `0644` sets the file permissions to read and write for the owner, and read-only for the group and others.

We will name the file descriptor of `file2` `fd2`.

## **Step 6: Fork another child process to run `cmd2`**
Use `wait` again to halt the execution of the parent process until the child process finish executing.

## **Step 6.1: Redirect the pipe's output end to `stdin`**
> `dup2(pipe1[0], 0)`

Since `cmd2` might also take input from `stdin`, we will redirect the output end of pipe1(`pipe1[0]`) to `stdin`.

## **Step 6.2: Redirect `stdout` to `fd2`**
> `dups(1, fd2)`

Since the project requires the final output of the program to be written into `file2`,
`stdout` is redirected to `fd2`.

## **Step 6.3: Execute `cmd2`**
This will be the same as `Step 4.3`.

## **Step 7: Clean up**
At last, release and free all `file descriptors` and `allocated memory`.
