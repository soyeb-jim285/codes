<h1 style='text-align: center;'> C. Product 1 Modulo N</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Now you get Baby Ehab's first words: "Given an integer $n$, find the longest subsequence of $[1,2, \ldots, n-1]$ whose product is $1$ modulo $n$." Please solve the problem.

A sequence $b$ is a subsequence of an array $a$ if $b$ can be obtained from $a$ by deleting some (possibly all) elements. The product of an empty subsequence is equal to $1$.

## Input

The only line contains the integer $n$ ($2 \le n \le 10^5$).

## Output

The first line should contain a single integer, the length of the longest subsequence.

The second line should contain the elements of the subsequence, in increasing order.

If there are multiple solutions, you can print any.

## Examples

## Input


```

5

```
## Output


```

3
1 2 3 
```
## Input


```

8

```
## Output


```

4
1 3 5 7 
```
## Note

In the first example, the product of the elements is $6$ which is congruent to $1$ modulo $5$. The only longer subsequence is $[1,2,3,4]$. Its product is $24$ which is congruent to $4$ modulo $5$. Hence, the answer is $[1,2,3]$.



#### tags 

#1600 #greedy #number_theory 