<h1 style='text-align: center;'> G. Cycle Palindrome</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We say that a sequence of $n$ integers $a_1, a_2, \ldots, a_n$ is a palindrome if for all $1 \leq i \leq n$, $a_i = a_{n-i+1}$. You are given a sequence of $n$ integers $a_1, a_2, \ldots, a_n$ and you have to find, if it exists, a cycle permutation $\sigma$ so that the sequence $a_{\sigma(1)}, a_{\sigma(2)}, \ldots, a_{\sigma(n)}$ is a palindrome. 

A permutation of $1, 2, \ldots, n$ is a bijective function from $\{1, 2, \ldots, n\}$ to $\{1, 2, \ldots, n\}$. We say that a permutation $\sigma$ is a cycle permutation if $1, \sigma(1), \sigma^2(1), \ldots, \sigma^{n-1}(1)$ are pairwise different numbers. Here $\sigma^m(1)$ denotes $\underbrace{\sigma(\sigma(\ldots \sigma}_{m \text{ times}}(1) \ldots))$.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 3 \cdot 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2 \cdot 10^5$) — the size of the sequence.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \leq a_i \leq n$).

The sum of $n$ for all test cases is at most $2 \cdot 10^5$.

### Output

For each test case, output one line with YES if a cycle permutation exists, otherwise output one line with NO.

If the answer is YES, output one additional line with $n$ integers $\sigma(1), \sigma(2), \ldots, \sigma(n)$, the permutation. If there is more than one permutation, you may print any.

## Example

### Input


```text
3
4
1 2 2 1
3
1 2 1
7
1 3 3 3 1 2 2
```
### Output


```text
YES
3 1 4 2 
NO
YES
5 3 7 2 6 4 1 
```


#### Tags 

#3200 #NOT OK #constructive_algorithms #graphs #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_1_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
