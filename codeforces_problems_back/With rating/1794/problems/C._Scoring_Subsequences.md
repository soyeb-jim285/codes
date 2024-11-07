<h1 style='text-align: center;'> C. Scoring Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The score of a sequence $[s_1, s_2, \ldots, s_d]$ is defined as $\displaystyle \frac{s_1\cdot s_2\cdot \ldots \cdot s_d}{d!}$, where $d!=1\cdot 2\cdot \ldots \cdot d$. In particular, the score of an empty sequence is $1$.

For a sequence $[s_1, s_2, \ldots, s_d]$, let $m$ be the maximum score among all its subsequences. Its cost is defined as the maximum length of a subsequence with a score of $m$.

You are given a non-decreasing sequence $[a_1, a_2, \ldots, a_n]$ of integers of length $n$. In other words, the condition $a_1 \leq a_2 \leq \ldots \leq a_n$ is satisfied. For each $k=1, 2, \ldots , n$, find the cost of the sequence $[a_1, a_2, \ldots , a_k]$. 

A sequence $x$ is a subsequence of a sequence $y$ if $x$ can be obtained from $y$ by deletion of several (possibly, zero or all) elements.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1\le n\le 10^5$) — the length of the given sequence. 

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\le a_i\leq n$) — the given sequence. It is guaranteed that its elements are in non-decreasing order.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5\cdot 10^5$.

## Output

For each test case, output $n$ integers — the costs of sequences $[a_1, a_2, \ldots , a_k]$ in ascending order of $k$.

## Example

## Input


```

331 2 321 155 5 5 5 5
```
## Output


```

1 1 2 
1 1 
1 2 3 4 5 

```
## Note

In the first test case: 

* The maximum score among the subsequences of $[1]$ is $1$. The subsequences $[1]$ and $[]$ (the empty sequence) are the only ones with this score. Thus, the cost of $[1]$ is $1$.
* The maximum score among the subsequences of $[1, 2]$ is $2$. The only subsequence with this score is $[2]$. Thus, the cost of $[1, 2]$ is $1$.
* The maximum score among the subsequences of $[1, 2, 3]$ is $3$. The subsequences $[2, 3]$ and $[3]$ are the only ones with this score. Thus, the cost of $[1, 2, 3]$ is $2$.

 Therefore, the answer to this case is $1\:\:1\:\:2$, which are the costs of $[1], [1, 2]$ and $[1, 2, 3]$ in this order.

#### tags 

#1300 #binary_search #greedy #math #two_pointers 