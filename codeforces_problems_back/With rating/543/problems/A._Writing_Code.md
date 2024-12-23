<h1 style='text-align: center;'> A. Writing Code</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Programmers working on a large project have just received a task to write exactly *m* lines of code. There are *n* programmers working on a project, the *i*-th of them makes exactly *a**i* bugs in every line of code that he writes. 

Let's call a sequence of non-negative integers *v*1, *v*2, ..., *v**n* a plan, if *v*1 + *v*2 + ... + *v**n* = *m*. The programmers follow the plan like that: in the beginning the first programmer writes the first *v*1 lines of the given task, then the second programmer writes *v*2 more lines of the given task, and so on. In the end, the last programmer writes the remaining lines of the code. Let's call a plan good, if all the written lines of the task contain at most *b* bugs in total.

Your task is to determine how many distinct good plans are there. As the number of plans can be large, print the remainder of this number modulo given positive integer *mod*.

## Input

The first line contains four integers *n*, *m*, *b*, *mod* (1 ≤ *n*, *m* ≤ 500, 0 ≤ *b* ≤ 500; 1 ≤ *mod* ≤ 109 + 7) — the number of programmers, the number of lines of code in the task, the maximum total number of bugs respectively and the modulo you should use when printing the answer.

The next line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 500) — the number of bugs per line for each programmer.

## Output

Print a single integer — the answer to the problem modulo *mod*.

## Examples

## Input


```
3 3 3 100  
1 1 1  

```
## Output


```
10  

```
## Input


```
3 6 5 1000000007  
1 2 3  

```
## Output


```
0  

```
## Input


```
3 5 6 11  
1 2 1  

```
## Output


```
0  

```


#### tags 

#1800 #dp 