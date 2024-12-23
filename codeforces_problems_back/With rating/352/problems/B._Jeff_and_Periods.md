<h1 style='text-align: center;'> B. Jeff and Periods</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Jeff got hold of an integer sequence *a*1, *a*2, ..., *a**n* of length *n*. The boy immediately decided to analyze the sequence. For that, he needs to find all values of *x*, for which these conditions hold:

* *x* occurs in sequence *a*.
* Consider all positions of numbers *x* in the sequence *a* (such *i*, that *a**i* = *x*). These numbers, sorted in the increasing order, must form an arithmetic progression.

Help Jeff, find all *x* that meet the problem conditions.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105). The next line contains integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105). The numbers are separated by spaces.

## Output

In the first line print integer *t* — the number of valid *x*. On each of the next *t* lines print two integers *x* and *p**x*, where *x* is current suitable value, *p**x* is the common difference between numbers in the progression (if *x* occurs exactly once in the sequence, *p**x* must equal 0). Print the pairs in the order of increasing *x*.

## Examples

## Input


```
1  
2  

```
## Output


```
1  
2 0  

```
## Input


```
8  
1 2 1 3 1 2 1 5  

```
## Output


```
4  
1 2  
2 4  
3 0  
5 0  

```
## Note

In the first test 2 occurs exactly once in the sequence, ergo *p*2 = 0.



#### tags 

#1300 #implementation #sortings 