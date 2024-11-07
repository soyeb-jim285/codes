<h1 style='text-align: center;'> A. Goshtasp, Vishtasp and Eidi</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Goshtasp was known to be a good programmer in his school. One day Vishtasp, Goshtasp's friend, asked him to solve this task:

Given a positive integer *n*, you should determine whether *n* is rich.

The positive integer *x* is rich, if there exists some set of distinct numbers *a*1, *a*2, ..., *a**m* such that ![](images/e87f6ed8dbb5ba5a37fce497d51dab80d56e0fc2.png). In addition: every *a**i* should be either a prime number, or equal to 1.

Vishtasp said that he would share his Eidi 50 / 50 with Goshtasp, if he could solve the task. Eidi is money given to children for Noruz by their parents and/or relatives.

Goshtasp needs to solve this problem to get money, you need to solve it to get score!

## Input

## Input

 contains a single positive integer *n* (1 ≤ *n* ≤ 10000).

## Output

If the number is not rich print 0. Otherwise print the numbers *a*1, ..., *a**m*. If several solutions exist print the lexicographically latest solution. Answers are compared as sequences of numbers, not as strings.

For comparing two sequences *a*1, ..., *a**m* and *b*1, ..., *b**n* we first find the first index *i* such that *a**i* ≠ *b**i*, if *a**i* < *b**i* then *a* is lexicographically earlier and if *b**i* < *a**i* then *b* is lexicographically earlier. If *m* ≠ *n* we add zeroes at the end of the smaller sequence (only for the moment of comparison) and then perform the comparison.

You do not need to minimize the number of elements in sequence (i.e. *m*). You just need to print the lexicographically latest solution.

See samples to find out how to print the sequence.

## Examples

## Input


```
11  

```
## Output


```
11=11  

```
## Input


```
545  

```
## Output


```
541+3+1=545  

```


#### tags 

#1800 #*special #greedy #math 