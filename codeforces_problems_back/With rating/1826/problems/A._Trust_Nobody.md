<h1 style='text-align: center;'> A. Trust Nobody</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a group of $n$ people. Some of them might be liars, who always tell lies. Other people always tell the truth. The $i$-th person says "There are at least $l_i$ liars amongst us". Determine if what people are saying is contradictory, or if it is possible. If it is possible, output the number of liars in the group. If there are multiple possible answers, output any one of them.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$).

The second line of each test case contains $n$ integers $l_i$ ($0 \leq l_i \leq n$) — the number said by the $i$-th person.

It's guaranteed that the sum of all $n$ does not exceed $10^4$.

## Output

For each test case output a single integer. If what people are saying is contradictory, output $-1$. Otherwise, output the number of liars in the group. If there are multiple possible answers, output any one of them.

## Example

## Input


```

721 222 220 0111055 5 3 3 565 3 6 6 3 5
```
## Output


```

1
-1
0
-1
0
3
4

```
## Note

In the first example, the only possible answer is that the second person is a liar, so the answer is $1$ liar.

In the second example, it can be proven that we can't choose the liars so that all the requirements are satisfied.

In the third example, everybody tells the truth, so the answer is $0$ liars.



#### tags 

#1200 #brute_force #greedy #implementation #sortings 