<h1 style='text-align: center;'> E. Min-Sum-Max</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Tom is waiting for his results of Zhongkao examination. To ease the tense atmosphere, his friend, Daniel, decided to play a game with him. This game is called "Divide the Array".

The game is about the array $a$ consisting of $n$ integers. Denote $[l,r]$ as the subsegment consisting of integers $a_l,a_{l+1},\ldots,a_r$.

Tom will divide the array into contiguous subsegments $[l_1,r_1],[l_2,r_2],\ldots,[l_m,r_m]$, such that each integer is in exactly one subsegment. More formally:

* For all $1\le i\le m$, $1\le l_i\le r_i\le n$;
* $l_1=1$, $r_m=n$;
* For all $1< i\le m$, $l_i=r_{i-1}+1$.

Denote $s_{i}=\sum_{k=l_i}^{r_i} a_k$, that is, $s_i$ is the sum of integers in the $i$-th subsegment. For all $1\le i\le j\le m$, the following condition must hold:

$$ \min_{i\le k\le j} s_k \le \sum_{k=i}^j s_k \le \max_{i\le k\le j} s_k. $$

Tom believes that the more subsegments the array $a$ is divided into, the better results he will get. So he asks Daniel to find the maximum number of subsegments among all possible ways to divide the array $a$. You have to help him find it.

## Input

The first line of input contains a single integer $t$ ($1\le t\le 50$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le 300$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^9\le a_i\le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

## Output

For each test case, output a single integer — the maximum number of subsegments among all possible ways to divide the array $a$.

## Example

## Input


```

83-1 5 422023 204361 4 7 -1 5 -45-4 0 3 -18 10199824485310-4 2 5 -10 4 8 2 9 -15 77-7 3 8 -9 -2 2 44-5 5 -2 -5
```
## Output


```

2
1
3
2
1
6
5
3

```
## Note

In the first test case, Daniel can divide the array into $[-1]$ and $[5,4]$, and $s=[-1,9]$. It can be shown that for any $i=j$, the condition in the statement is already satisfied, and for $i=1,j=2$, we have $\min(-1,9)\le (-1)+9\le \max(-1,9)$.

In the second test case, if Daniel divides the array into $[2023]$ and $[2043]$, then for $i=1,j=2$ we have $2023+2043>\max(2023,2043)$, so the maximum number of subsegments is $1$.

In the third test case, the optimal way to divide the array is $[1,4,7],[-1],[5,-4]$.

In the fourth test case, the optimal to divide the array way is $[-4,0,3,-18],[10]$.

In the fifth test case, Daniel can only get one subsegment.



#### tags 

#3500 #constructive_algorithms #dp #greedy 