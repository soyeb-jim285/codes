<h1 style='text-align: center;'> F. Progress Monitoring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Programming teacher Dmitry Olegovich is going to propose the following task for one of his tests for students:

You are given a tree *T* with *n* vertices, specified by its adjacency matrix *a*[1... *n*, 1... *n*]. What is the output of the following pseudocode?


```
  
used[1 ... n] = {0, ..., 0};  
  
procedure dfs(v):  
    print v;  
    used[v] = 1;  
    for i = 1, 2, ..., n:  
        if (a[v][i] == 1 and used[i] == 0):  
            dfs(i);  
  
dfs(1);  

```
In order to simplify the test results checking procedure, Dmitry Olegovich decided to create a tree *T* such that the result is his favorite sequence *b*. On the other hand, Dmitry Olegovich doesn't want to provide students with same trees as input, otherwise they might cheat. That's why Dmitry Olegovich is trying to find out the number of different trees *T* such that the result of running the above pseudocode with *T* as input is exactly the sequence *b*. Can you help him?

Two trees with *n* vertices are called different if their adjacency matrices *a*1 and *a*2 are different, i. e. there exists a pair (*i*, *j*), such that 1 ≤ *i*, *j* ≤ *n* and *a*1[*i*][*j*] ≠ *a*2[*i*][*j*].

## Input

The first line contains the positive integer *n* (1 ≤ *n* ≤ 500) — the length of sequence *b*. 

The second line contains *n* positive integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ *n*). It is guaranteed that *b* is a permutation, or in other words, each of the numbers 1, 2, ..., *n* appears exactly once in the sequence *b*. Also it is guaranteed that *b*1 = 1.

## Output

## Output

 the number of trees satisfying the conditions above modulo 109 + 7.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
2  

```
## Input


```
3  
1 3 2  

```
## Output


```
1  

```


#### tags 

#2300 #dp #trees 