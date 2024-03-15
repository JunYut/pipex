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
1. check if `argv[1]` is a present file
2. check if `argv[2]` & `argv[3]` are valid shell commands using the `which` command
3. if `argv[4]` does not exist, create it

## **Step 2: Reading contents of `file1`**

## **Step 3: Forking a child process to run `cmd1`**

## **Step 4: 


# **Commands that take input from stdin**
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


# 	**Extras**
##	1. Why `< file1.txt cat` instead of `file1.txt > cat` ?
This is the result:
```
	$> file1.txt > wc -w
	bash: ./file1.txt: Permission denied
```