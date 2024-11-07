<h1 style='text-align: center;'> E. Generate a String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

zscoder wants to generate an input file for some programming competition problem.

His input is a string consisting of *n* letters 'a'. He is too lazy to write a generator so he will manually generate the input in a text editor.

Initially, the text editor is empty. It takes him *x* seconds to insert or delete a letter 'a' from the text file and *y* seconds to copy the contents of the entire text file, and duplicate it.

zscoder wants to find the minimum amount of time needed for him to create the input file of exactly *n* letters 'a'. Help him to determine the amount of time needed to generate the input.

## Input

The only line contains three integers *n*, *x* and *y* (1 ≤ *n* ≤ 107, 1 ≤ *x*, *y* ≤ 109) — the number of letters 'a' in the input file and the parameters from the problem statement.

## Output

Print the only integer *t* — the minimum amount of time needed to generate the input file.

## Examples

## Input


```
8 1 1  

```
## Output


```
4  

```
## Input


```
8 1 10  

```
## Output


```
8  

```


#### tags 

#2000 #dfs_and_similar #dp 