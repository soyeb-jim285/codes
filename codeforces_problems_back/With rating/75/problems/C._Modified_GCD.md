<h1 style='text-align: center;'> C. Modified GCD</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Well, here is another math class task. In mathematics, GCD is the greatest common divisor, and it's an easy task to calculate the GCD between two positive integers.

A common divisor for two positive numbers is a number which both numbers are divisible by.

But your teacher wants to give you a harder task, in this task you have to find the greatest common divisor *d* between two integers *a* and *b* that is in a given range from *low* to *high* (inclusive), i.e. *low* ≤ *d* ≤ *high*. It is possible that there is no common divisor in the given range.

You will be given the two integers *a* and *b*, then *n* queries. Each query is a range from *low* to *high* and you have to answer each query.

## Input

The first line contains two integers *a* and *b*, the two integers as described above (1 ≤ *a*, *b* ≤ 109). The second line contains one integer *n*, the number of queries (1 ≤ *n* ≤ 104). Then *n* lines follow, each line contains one query consisting of two integers, *low* and *high* (1 ≤ *low* ≤ *high* ≤ 109).

## Output

Print *n* lines. The *i*-th of them should contain the result of the *i*-th query in the input. If there is no common divisor in the given range for any query, you should print -1 as a result for this query.

## Examples

## Input


```
9 27  
3  
1 5  
10 11  
9 11  

```
## Output


```
3  
-1  
9  

```


#### tags 

#1600 #binary_search #number_theory 