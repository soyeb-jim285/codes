<h1 style='text-align: center;'> A. Maximum Cake Tastiness</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ pieces of cake on a line. The $i$-th piece of cake has weight $a_i$ ($1 \leq i \leq n$).

The tastiness of the cake is the maximum total weight of two adjacent pieces of cake (i. e., $\max(a_1+a_2,\, a_2+a_3,\, \ldots,\, a_{n-1} + a_{n})$).

You want to maximize the tastiness of the cake. You are allowed to do the following operation at most once (doing more operations would ruin the cake): 

* Choose a contiguous subsegment $a[l, r]$ of pieces of cake ($1 \leq l \leq r \leq n$), and reverse it.

The subsegment $a[l, r]$ of the array $a$ is the sequence $a_l, a_{l+1}, \dots, a_r$.

If you reverse it, the array will become $a_1, a_2, \dots, a_{l-2}, a_{l-1}, \underline{a_r}, \underline{a_{r-1}}, \underline{\dots}, \underline{a_{l+1}}, \underline{a_l}, a_{r+1}, a_{r+2}, \dots, a_{n-1}, a_n$.

For example, if the weights are initially $[5, 2, 1, 4, 7, 3]$, you can reverse the subsegment $a[2, 5]$, getting $[5, \underline{7}, \underline{4}, \underline{1}, \underline{2}, 3]$. The tastiness of the cake is now $5 + 7 = 12$ (while before the operation the tastiness was $4+7=11$).

Find the maximum tastiness of the cake after doing the operation at most once.

## Input

The first line contains a single integer $t$ ($1 \le t \le 50$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 1000$) — the number of pieces of cake.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — $a_i$ is the weight of the $i$-th piece of cake.

## Output

For each test case, print a single integer: the maximum tastiness of the cake after doing the operation at most once.

## Example

## Input


```

565 2 1 4 7 3332 78 78369 54 918999021 999021 999021 999021 999652 999021 999021 99902121000000000 1000000000
```
## Output


```

12
156
160
1998673
2000000000

```
## Note

In the first test case, after reversing the subsegment $a[2, 5]$, you get a cake with weights $[5, \underline{7}, \underline{4}, \underline{1}, \underline{2}, 3]$. The tastiness of the cake is now $\max(5+7, 7+4, 4+1, 1+2, 2+3) = 12$. This is the maximum possible tastiness of the cake one can obtain by performing the operation at most once.

In the second test case, it's optimal not to do any operation. The tastiness is $78+78 = 156$.

In the third test case, after reversing the subsegment $a[1, 2]$, you get a cake with weights $[\underline{54}, \underline{69}, 91]$. The tastiness of the cake is now $\max(54+69, 69+91) = 160$. There is no way to make the tastiness of the cake greater than $160$ by performing at most one operation.



#### tags 

#800 #brute_force #greedy #implementation #sortings 