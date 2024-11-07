<h1 style='text-align: center;'> J. Japanese Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Joseph really likes the culture of Japan. Last year he learned Japanese traditional clothes and visual arts and now he is trying to find out the secret of the Japanese game called Nonogram.

In the one-dimensional version of the game, there is a row of $n$ empty cells, some of which are to be filled with a pen. There is a description of a solution called a profile — a sequence of positive integers denoting the lengths of consecutive sets of filled cells. For example, the profile of $[4, 3, 1]$ means that there are sets of four, three, and one filled cell, in that order, with at least one empty cell between successive sets.

 ![](images/7a2ec6eef2a8990ca87369275e00ff3d727142b6.png)A suitable solution for $n = 12$ and $p = [4, 3, 1]$. 

 ![](images/576966c8c448e6c57711c7c8c48b57ee891143df.png)A wrong solution: the first four filled cells should be consecutive. 

 ![](images/fcabfef8f4c2e5ea68b94a6ec84ba5d3930b38f0.png)A wrong solution: there should be at least one empty cell before the last filled cell. 

Joseph found out that for some numbers $n$ and profiles $p$ there are lots of ways to fill the cells to satisfy the profile. Now he is in the process of solving a nonogram consisting of $n$ cells and a profile $p$. He has already created a mask of $p$ — he has filled all the cells that must be filled in every solution of the nonogram.

 ![](images/e9defc82c67384b93c6d14f4cc99554ea8f3adf6.png)The mask for $n = 12$ and $p = [4, 3, 1]$: all the filled cells above are filled in every solution. 

After a break, he lost the source profile $p$. He only has $n$ and the mask $m$. Help Joseph find any profile $p'$ with the mask $m$ or say that there is no such profile and Joseph has made a mistake.

## Input

The only line contains a string $m$ — the mask of the source profile $p$. The length of $m$ is $n$ ($1 \le n \le 100\,000$). The string $m$ consists of symbols # and _ — denoting filled and empty cells respectively.

## Output

If there is no profile with the mask $m$, output the number $-1$. Otherwise, on the first line, output an integer $k$ — the number of integers in the profile $p'$. On the second line, output $k$ integers of the profile $p'$.

## Examples

## Input


```

__#_____

```
## Output


```

2
3 2 

```
## Input


```

_#

```
## Output


```

-1

```
## Input


```

___

```
## Output


```

0


```


#### tags 

#2700 #constructive_algorithms #math 