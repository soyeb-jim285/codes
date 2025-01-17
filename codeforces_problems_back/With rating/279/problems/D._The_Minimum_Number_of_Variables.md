<h1 style='text-align: center;'> D. The Minimum Number of Variables</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got a positive integer sequence *a*1, *a*2, ..., *a**n*. All numbers in the sequence are distinct. Let's fix the set of variables *b*1, *b*2, ..., *b**m*. Initially each variable *b**i* (1 ≤ *i* ≤ *m*) contains the value of zero. Consider the following sequence, consisting of *n* operations.

The first operation is assigning the value of *a*1 to some variable *b**x* (1 ≤ *x* ≤ *m*). Each of the following *n* - 1 operations is assigning to some variable *b**y* the value that is equal to the sum of values that are stored in the variables *b**i* and *b**j* (1 ≤ *i*, *j*, *y* ≤ *m*). At that, the value that is assigned on the *t*-th operation, must equal *a**t*. For each operation numbers *y*, *i*, *j* are chosen anew.

Your task is to find the minimum number of variables *m*, such that those variables can help you perform the described sequence of operations.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 23). The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**k* ≤ 109).

It is guaranteed that all numbers in the sequence are distinct.

## Output

In a single line print a single number — the minimum number of variables *m*, such that those variables can help you perform the described sequence of operations.

If you cannot perform the sequence of operations at any *m*, print -1.

## Examples

## Input


```
5  
1 2 3 6 8  

```
## Output


```
2  

```
## Input


```
3  
3 6 5  

```
## Output


```
-1  

```
## Input


```
6  
2 4 8 6 10 18  

```
## Output


```
3  

```
## Note

In the first sample, you can use two variables *b*1 and *b*2 to perform the following sequence of operations.

1. *b*1 := 1;
2. *b*2 := *b*1 + *b*1;
3. *b*1 := *b*1 + *b*2;
4. *b*1 := *b*1 + *b*1;
5. *b*1 := *b*1 + *b*2.


#### tags 

#2200 #bitmasks #dp 