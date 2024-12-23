<h1 style='text-align: center;'> F. Design Tutorial: Change the Goal</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are some tasks which have the following structure: you are given a model, and you can do some operations, you should use these operations to achive the goal. One way to create a new task is to use the same model and same operations, but change the goal.

Let's have a try. I have created the following task for Topcoder SRM 557 Div1-Hard: you are given *n* integers *x*1, *x*2, ..., *x**n*. You are allowed to perform the assignments (as many as you want) of the following form *x**i* ^= *x**j* (in the original task *i* and *j* must be different, but in this task we allow *i* to equal *j*). The goal is to maximize the sum of all *x**i*.

Now we just change the goal. You are also given *n* integers *y*1, *y*2, ..., *y**n*. You should make *x*1, *x*2, ..., *x**n* exactly equal to *y*1, *y*2, ..., *y**n*. In other words, for each *i* number *x**i* should be equal to *y**i*.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 10000). The second line contains *n* integers: *x*1 to *x**n* (0 ≤ *x**i* ≤ 109). The third line contains *n* integers: *y*1 to *y**n* (0 ≤ *y**i* ≤ 109).

## Output

If there is no solution, output -1.

If there is a solution, then in the first line output an integer *m* (0 ≤ *m* ≤ 1000000) – the number of assignments you need to perform. Then print *m* lines, each line should contain two integers *i* and *j* (1 ≤ *i*, *j* ≤ *n*), which denote assignment *x**i* ^= *x**j*.

If there are multiple solutions you can print any of them. We can prove that under these constraints if there exists a solution then there always exists a solution with no more than 106 operations.

## Examples

## Input


```
2  
3 5  
6 0  

```
## Output


```
2  
1 2  
2 2  

```
## Input


```
5  
0 0 0 0 0  
1 2 3 4 5  

```
## Output


```
-1  

```
## Input


```
3  
4 5 6  
1 2 3  

```
## Output


```
5  
3 1  
1 2  
2 2  
2 3  
3 1  

```
## Input


```
3  
1 2 3  
4 5 6  

```
## Output


```
-1  

```
## Note

Assignment *a* ^= *b* denotes assignment *a* = *a* ^ *b*, where operation "^" is bitwise XOR of two integers.



#### tags 

#2700 #constructive_algorithms #math #matrices 