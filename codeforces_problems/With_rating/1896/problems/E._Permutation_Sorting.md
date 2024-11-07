<h1 style='text-align: center;'> E. Permutation Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation$^\dagger$ $a$ of size $n$. We call an index $i$ good if $a_i=i$ is satisfied. After each second, we rotate all indices that are not good to the right by one position. Formally,

* Let $s_1,s_2,\ldots,s_k$ be the indices of $a$ that are not good in increasing order. That is, $s_j < s_{j+1}$ and if index $i$ is not good, then there exists $j$ such that $s_j=i$.
* For each $i$ from $1$ to $k$, we assign $a_{s_{(i \% k+1)}} := a_{s_i}$ all at once.

For each $i$ from $1$ to $n$, find the first time that index $i$ becomes good.

 $^\dagger$ A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^6$) — the size of permutation $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the elements of permutation $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output a single line containing $n$ integers where the $i$-th integer represents the first time that index $i$ becomes good.

## Example

### Input


```text
253 2 4 1 562 1 4 6 5 3
```
### Output

```text

1 0 1 1 0 
2 1 2 1 0 1 

```
## Note

In the first test case, $2$ and $5$ are already in the correct position so indices $2$ and $5$ become good at $0$ second. After $1$ second, a cyclic shift will be done with $s=[1, 3, 4]$, resulting in array $a=[1, 2, 3, 4, 5]$. Notice that indices $1$, $3$ and $4$ become good at $1$ second.

In the second test case, $5$ is already in the correct position, so index $5$ becomes good at $0$ second. After $1$ second, a cyclic shift will be done with $s=[1, 2, 3, 4, 6]$, resulting in array $a=[3, 2, 1, 4, 5, 6]$. Notice that indices $2$, $4$ and $6$ become good at $1$ second. After $2$ seconds, a cyclic shift will be done with $s=[1, 3]$, resulting in array $a=[1, 2, 3, 4, 5, 6]$. Notice that indices $1$ and $3$ become good at $2$ second.



#### Tags 

#2100 #NOT OK #data_structures #sortings 

## Blogs
- [All Contest Problems](../CodeTON_Round_7_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
