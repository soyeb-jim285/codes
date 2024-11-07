<h1 style='text-align: center;'> B. Permutations & Primes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$.

In this problem, the $\operatorname{MEX}$ of a collection of integers $c_1,c_2,\dots,c_k$ is defined as the smallest positive integer $x$ which does not occur in the collection $c$. 

The primality of an array $a_1,\dots,a_n$ is defined as the number of pairs $(l,r)$ such that $1 \le l \le r \le n$ and $\operatorname{MEX}(a_l,\dots,a_r)$ is a prime number. 

Find any permutation of $1,2,\dots,n$ with the maximum possible primality among all permutations of $1,2,\dots,n$. 

## Note

: 

* A prime number is a number greater than or equal to $2$ that is not divisible by any positive integer except $1$ and itself. For example, $2,5,13$ are prime numbers, but $1$ and $6$ are not prime numbers.
* A permutation of $1,2,\dots,n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The only line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ integers: a permutation of $1,2,\dots,n$ that achieves the maximum possible primality.

If there are multiple solutions, print any of them.

## Example

### Input


```text
3215
```
### Output

```text

2 1
1
5 2 1 4 3

```
## Note

In the first test case, there are $3$ pairs $(l,r)$ with $1 \le l \le r \le 2$, out of which $2$ have a prime $\operatorname{MEX}(a_l,\dots,a_r)$: 

* $(l,r) = (1,1)$: $\operatorname{MEX}(2) = 1$, which is not prime.
* $(l,r) = (1,2)$: $\operatorname{MEX}(2,1) = 3$, which is prime.
* $(l,r) = (2,2)$: $\operatorname{MEX}(1) = 2$, which is prime.

 Therefore, the primality is $2$.In the second test case, $\operatorname{MEX}(1) = 2$ is prime, so the primality is $1$.

In the third test case, the maximum possible primality is $8$.



#### Tags 

#1000 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_884_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
