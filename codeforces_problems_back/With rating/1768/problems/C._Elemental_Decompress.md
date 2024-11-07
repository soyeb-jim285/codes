<h1 style='text-align: center;'> C. Elemental Decompress</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers.

Find two permutations$^\dagger$ $p$ and $q$ of length $n$ such that $\max(p_i,q_i)=a_i$ for all $1 \leq i \leq n$ or report that such $p$ and $q$ do not exist.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq n$) — the array $a$.

It is guaranteed that the total sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. 

## Output

For each test case, if there do not exist $p$ and $q$ that satisfy the conditions, output "NO" (without quotes).

Otherwise, output "YES" (without quotes) and then output $2$ lines. The first line should contain $n$ integers $p_1,p_2,\ldots,p_n$ and the second line should contain $n$ integers $q_1,q_2,\ldots,q_n$.

If there are multiple solutions, you may output any of them.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

31155 3 4 2 521 1
```
## Output


```

YES
1 
1 
YES
1 3 4 2 5 
5 2 3 1 4 
NO

```
## Note

In the first test case, $p=q=[1]$. It is correct since $a_1 = max(p_1,q_1) = 1$.

In the second test case, $p=[1,3,4,2,5]$ and $q=[5,2,3,1,4]$. It is correct since:

* $a_1 = \max(p_1, q_1) = \max(1, 5) = 5$,
* $a_2 = \max(p_2, q_2) = \max(3, 2) = 3$,
* $a_3 = \max(p_3, q_3) = \max(4, 3) = 4$,
* $a_4 = \max(p_4, q_4) = \max(2, 1) = 2$,
* $a_5 = \max(p_5, q_5) = \max(5, 4) = 5$.

In the third test case, one can show that no such $p$ and $q$ exist.



#### tags 

#1300 #constructive_algorithms #greedy #implementation #sortings 