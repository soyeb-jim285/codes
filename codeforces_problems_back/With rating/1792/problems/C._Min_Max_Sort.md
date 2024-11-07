<h1 style='text-align: center;'> C. Min Max Sort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of length $n$ (a permutation of length $n$ is an array of length $n$ in which each integer from $1$ to $n$ occurs exactly once).

You can perform the following operation any number of times (possibly zero): 

1. choose two different elements $x$ and $y$ and erase them from the permutation;
2. insert the minimum of $x$ and $y$ into the permutation in such a way that it becomes the first element;
3. insert the maximum of $x$ and $y$ into the permutation in such a way that it becomes the last element.

For example, if $p = [1, 5, 4, 2, 3]$ and we want to apply the operation to the elements $3$ and $5$, then after the first step of the operation, the permutation becomes $p = [1, 4, 2]$; and after we insert the elements, it becomes $p = [3, 1, 4, 2, 5]$.

Your task is to calculate the minimum number of operations described above to sort the permutation $p$ in ascending order (i. e. transform $p$ so that $p_1 < p_2 < \dots < p_n$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of the test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of elements in the permutation.

The second line of the test case contains $n$ distinct integers from $1$ to $n$ — the given permutation $p$.

The sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the minimum number of operations described above to sort the array $p$ in ascending order.

## Example

## Input


```

451 5 4 2 331 2 342 1 4 365 2 4 1 6 3
```
## Output


```

2
0
1
3

```
## Note

In the first example, you can proceed as follows: 

1. in the permutation $p = [1, 5, 4, 2, 3]$, let's choose the elements $4$ and $2$, then, after applying the operation, the permutation becomes $p = [2, 1, 5, 3, 4]$;
2. in the permutation $p = [2, 1, 5, 3, 4]$, let's choose the elements $1$ and $5$, then, after applying operation, the permutation becomes $p = [1, 2, 3, 4, 5]$.


#### tags 

#1500 #binary_search #brute_force #greedy #math #two_pointers 