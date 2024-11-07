<h1 style='text-align: center;'> C. Marco and GCD Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a dream Marco met an elderly man with a pair of black glasses. The man told him the key to immortality and then disappeared with the wind of time.

When he woke up, he only remembered that the key was a sequence of positive integers of some length *n*, but forgot the exact sequence. Let the elements of the sequence be *a*1, *a*2, ..., *a**n*. He remembered that he calculated *gcd*(*a**i*, *a**i* + 1, ..., *a**j*) for every 1 ≤ *i* ≤ *j* ≤ *n* and put it into a set *S*. *gcd* here means the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor).

## Note

 that even if a number is put into the set *S* twice or more, it only appears once in the set.

Now Marco gives you the set *S* and asks you to help him figure out the initial sequence. If there are many solutions, print any of them. It is also possible that there are no sequences that produce the set *S*, in this case print -1.

## Input

The first line contains a single integer *m* (1 ≤ *m* ≤ 1000) — the size of the set *S*.

The second line contains *m* integers *s*1, *s*2, ..., *s**m* (1 ≤ *s**i* ≤ 106) — the elements of the set *S*. It's guaranteed that the elements of the set are given in strictly increasing order, that means *s*1 < *s*2 < ... < *s**m*.

## Output

If there is no solution, print a single line containing -1.

Otherwise, in the first line print a single integer *n* denoting the length of the sequence, *n* should not exceed 4000.

In the second line print *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 106) — the sequence.

We can show that if a solution exists, then there is a solution with *n* not exceeding 4000 and *a**i* not exceeding 106.

If there are multiple solutions, print any of them.

## Examples

## Input


```
4  
2 4 6 12  

```
## Output


```
3  
4 6 12
```
## Input


```
2  
2 3  

```
## Output


```
-1  

```
## Note

In the first example 2 = *gcd*(4, 6), the other elements from the set appear in the sequence, and we can show that there are no values different from 2, 4, 6 and 12 among *gcd*(*a**i*, *a**i* + 1, ..., *a**j*) for every 1 ≤ *i* ≤ *j* ≤ *n*.



#### tags 

#1900 #constructive_algorithms #math 