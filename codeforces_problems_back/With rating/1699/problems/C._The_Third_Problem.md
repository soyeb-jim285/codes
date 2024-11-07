<h1 style='text-align: center;'> C. The Third Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $a_1,a_2,\ldots,a_n$ of integers from $0$ to $n - 1$. Your task is to find how many permutations $b_1,b_2,\ldots,b_n$ are similar to permutation $a$. 

Two permutations $a$ and $b$ of size $n$ are considered similar if for all intervals $[l,r]$ ($1 \le l \le r \le n$), the following condition is satisfied: $$\operatorname{MEX}([a_l,a_{l+1},\ldots,a_r])=\operatorname{MEX}([b_l,b_{l+1},\ldots,b_r]),$$ where the $\operatorname{MEX}$ of a collection of integers $c_1,c_2,\ldots,c_k$ is defined as the smallest non-negative integer $x$ which does not occur in collection $c$. For example, $\operatorname{MEX}([1,2,3,4,5])=0$, and $\operatorname{MEX}([0,1,2,4,5])=3$.

Since the total number of such permutations can be very large, you will have to print its remainder modulo $10^9+7$.

In this problem, a permutation of size $n$ is an array consisting of $n$ distinct integers from $0$ to $n-1$ in arbitrary order. For example, $[1,0,2,4,3]$ is a permutation, while $[0,1,1]$ is not, since $1$ appears twice in the array. $[0,1,3]$ is also not a permutation, since $n=3$ and there is a $3$ in the array.

## Input

Each test contains multiple test cases. The first line of input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The following lines contain the descriptions of the test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the size of permutation $a$.

The second line of each test case contains $n$ distinct integers $a_1,a_2,\ldots,a_n$ ($0 \le a_i \lt n$) — the elements of permutation $a$.

It is guaranteed that the sum of $n$ across all test cases does not exceed $10^5$.

## Output

For each test case, print a single integer, the number of permutations similar to permutation $a$, taken modulo $10^9+7$.

## Example

## Input


```

554 0 3 2 11040 1 2 361 2 4 0 5 381 3 7 2 5 0 6 4
```
## Output


```

2
1
1
4
72

```
## Note

For the first test case, the only permutations similar to $a=[4,0,3,2,1]$ are $[4,0,3,2,1]$ and $[4,0,2,3,1]$.

For the second and third test cases, the given permutations are only similar to themselves.

For the fourth test case, there are $4$ permutations similar to $a=[1,2,4,0,5,3]$: 

* $[1,2,4,0,5,3]$;
* $[1,2,5,0,4,3]$;
* $[1,4,2,0,5,3]$;
* $[1,5,2,0,4,3]$.


#### tags 

#1700 #combinatorics #constructive_algorithms #math 