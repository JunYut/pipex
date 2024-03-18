#	 **How should the program behave ?**
### `./pipex file1.txt cat wc -l file2.txt`
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


# **Prototype**
### `./pipex file1 cmd1 cmd2 file2`
## **Step 1: Input validation**
1. check if `argc` is `5`
2. use `access` to check if `argv[1]` is a present file
3. check if `argv[2]` & `argv[3]` are valid shell commands using the `which` command
4. if `argv[4]` does not exist, create it

## **Step 2: Reading contents of `file1`**
Note: these contents will be passed as arguments for `cmd1` and they might not be valid

## **Step 3: Fork a child process to run `cmd1`**
1. use `wait` to halt the execution of the parent process until the child process finishes
2. in the child process, use `dup2` to redirect `stdout` to `fd[1](input end of the pipe)`, thus the output of `cmd1` is written into `fd[1]`
3. after the child process finished, the parent process continues its execution

## **Step 4: Fork another child process to run `cmd2`**
1. from `fd[0](output end of the pipe)`, read and store the output of `cmd1` as a string
2. use `fork` to create another child process and `wait` to wait for the child process to finsish
3. in the child process, run `cmd2` with the output string of `cmd1` as its arguments
4. use `dup2` to redirect `stdout` to `file2`

## **Step 5: Clean up**
At this step, all `file descriptors(fd)` and `dynamic allocated memory` shall be released and freed.


# 	**Extras**
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