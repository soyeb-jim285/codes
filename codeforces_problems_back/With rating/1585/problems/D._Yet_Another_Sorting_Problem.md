<h1 style='text-align: center;'> D. Yet Another Sorting Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya has an array of integers $a_1, a_2, \ldots, a_n$. He only likes sorted arrays. Unfortunately, the given array could be arbitrary, so Petya wants to sort it.

Petya likes to challenge himself, so he wants to sort array using only $3$-cycles. More formally, in one operation he can pick $3$ pairwise distinct indices $i$, $j$, and $k$ ($1 \leq i, j, k \leq n$) and apply $i \to j \to k \to i$ cycle to the array $a$. It simultaneously places $a_i$ on position $j$, $a_j$ on position $k$, and $a_k$ on position $i$, without changing any other element.

For example, if $a$ is $[10, 50, 20, 30, 40, 60]$ and he chooses $i = 2$, $j = 1$, $k = 5$, then the array becomes $[\underline{50}, \underline{40}, 20, 30, \underline{10}, 60]$.

Petya can apply arbitrary number of $3$-cycles (possibly, zero). You are to determine if Petya can sort his array $a$, i. e. make it non-decreasing.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 5 \cdot 10^5$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 5 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, print "YES" (without quotes) if Petya can sort the array $a$ using $3$-cycles, and "NO" (without quotes) otherwise. You can print each letter in any case (upper or lower).

## Example

## Input


```

7
1
1
2
2 2
2
2 1
3
1 2 3
3
2 1 3
3
3 1 2
4
2 1 4 3

```
## Output


```

YES
YES
NO
YES
NO
YES
YES

```
## Note

In the $6$-th test case Petya can use the $3$-cycle $1 \to 3 \to 2 \to 1$ to sort the array.

In the $7$-th test case Petya can apply $1 \to 3 \to 2 \to 1$ and make $a = [1, 4, 2, 3]$. Then he can apply $2 \to 4 \to 3 \to 2$ and finally sort the array.



#### tags 

#1900 #data_structures #math 