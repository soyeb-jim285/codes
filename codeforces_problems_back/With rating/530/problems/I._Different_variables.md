<h1 style='text-align: center;'> I. Different variables</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

*N* variables *X*1, ..., *X**N* can have positive integer values. You are given *K* constraints for these value that look like "the values of variables *X**i*1, *X**i*2, ..., *X**i**M* are different". Among all possible lists of values of these variables that satisfy these constraints select the ones which have minimum possible *max*(*X**i*). ## Output

 lexicographically least of these lists.

## Input

The first line of input contains two integers *n* and *k* (2 ≤ *N* ≤ 10, 1 ≤ *K* ≤ 100) — the number of variables and the number of constraints.

The following *K* lines contain the constraints, formatted as follows: the first number in the line *M* (2 ≤ *M* ≤ *N*) gives the number of variables in the constraint. After it follow *M* space-separated integers *i*1, ..., *i**M* — the indices of the variables used in the constraint (1 ≤ *i**j* ≤ *N*). All *i**j* in one constraint are different.

## Output

## Output

 the values of *X*1, *X*2, ..., *X**N* in a single line, separated with single spaces.

## Examples

## Input


```
2 1  
2 1 2  

```
## Output


```
1 2  

```
## Input


```
3 2  
2 1 2  
2 2 3  

```
## Output


```
1 2 1  

```


#### tags 

#2500 #*special 