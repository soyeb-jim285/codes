<h1 style='text-align: center;'> B. Woeful Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

I wonder, does the falling rain Forever yearn for it's disdain?Effluvium of the MindYou are given a positive integer $n$.

Find any permutation $p$ of length $n$ such that the sum $\operatorname{lcm}(1,p_1) + \operatorname{lcm}(2, p_2) + \ldots + \operatorname{lcm}(n, p_n)$ is as large as possible. 

Here $\operatorname{lcm}(x, y)$ denotes the [least common multiple (LCM)](https://en.wikipedia.org/wiki/Least_common_multiple) of integers $x$ and $y$.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1\,000$). Description of the test cases follows.

The only line for each test case contains a single integer $n$ ($1 \le n \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print $n$ integers $p_1$, $p_2$, $\ldots$, $p_n$ — the permutation with the maximum possible value of $\operatorname{lcm}(1,p_1) + \operatorname{lcm}(2, p_2) + \ldots + \operatorname{lcm}(n, p_n)$.

If there are multiple answers, print any of them.

## Example

### Input


```text
212
```
### Output

```text

1 
2 1 

```
## Note

For $n = 1$, there is only one permutation, so the answer is $[1]$.

For $n = 2$, there are two permutations: 

* $[1, 2]$ — the sum is $\operatorname{lcm}(1,1) + \operatorname{lcm}(2, 2) = 1 + 2 = 3$.
* $[2, 1]$ — the sum is $\operatorname{lcm}(1,2) + \operatorname{lcm}(2, 1) = 2 + 2 = 4$.


#### Tags 

#800 #OK #constructive_algorithms #greedy #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_813_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
