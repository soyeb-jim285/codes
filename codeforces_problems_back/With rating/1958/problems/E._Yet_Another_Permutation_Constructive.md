<h1 style='text-align: center;'> E. Yet Another Permutation Constructive</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Suppose you have a permutation $p$ of $n$ integers — an array where each element is an integer from $1$ to $n$, and every integer from $1$ to $n$ appears exactly once.

In one operation, you remove every element of this permutation which is less than at least one of its neighbors. For example, when you apply the operation to $[3, 1, 2, 5, 4]$, you get $[3, 5]$. If you apply an operation again, you get $[5]$.

It's easy to see that after applying a finite number of operations, you get an array consisting of a single integer $n$.

You are given two integers $n$ and $k$. Find a permutation of $n$ integers such that it becomes an array consisting of a single element $n$ after exactly $k$ operations (and not earlier).

## Input

The first line contains one integer $t$ ($1 \le t \le 2000$) — the number of test cases.

Each test case consists of one line containing two integers $n$ and $k$ ($2 \le n \le 100$; $1 \le k \le n - 1$).

## Output

For each test case, print the answer as follows:

* if a permutation of size $n$ which becomes an array consisting of a single element $n$ after exactly $k$ operations does not exist, print $-1$;
* otherwise, print $n$ distinct integers from $1$ to $n$ — the requested permutation. If there are multiple such permutations, print any of them.
## Example

## Input


```

45 25 42 13 2
```
## Output


```

3 1 2 5 4
-1
1 2
2 1 3

```


#### tags 

#1900 #*special #constructive_algorithms 