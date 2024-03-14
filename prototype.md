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

# 	**Extra**
##	1. Why `< file1.txt cat` instead of `file1.txt > cat` ?
This is the result:
```
	$> file1.txt > wc -w
	bash: ./file1.txt: Permission denied
```