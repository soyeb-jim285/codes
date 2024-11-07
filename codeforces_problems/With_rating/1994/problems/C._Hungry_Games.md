<h1 style='text-align: center;'> C. Hungry Games</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yaroslav is playing a computer game, and at one of the levels, he encountered $n$ mushrooms arranged in a row. Each mushroom has its own level of toxicity; the $i$-th mushroom from the beginning has a toxicity level of $a_i$. Yaroslav can choose two integers $1 \le l \le r \le n$, and then his character will take turns from left to right to eat mushrooms from this subsegment one by one, i.e., the mushrooms with numbers $l, l+1, l+2, \ldots, r$.

The character has a toxicity level $g$, initially equal to $0$. The computer game is defined by the number $x$ — the maximum toxicity level at any given time. When eating a mushroom with toxicity level $k$, the following happens:

1. The toxicity level of the character is increased by $k$.
2. If $g \leq x$, the process continues; otherwise, $g$ becomes zero and the process continues.

Yaroslav became interested in how many ways there are to choose the values of $l$ and $r$ such that the final value of $g$ is not zero. Help Yaroslav find this number!

### Input

Each test consists of multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^{4}$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$, $x$ ($1 \leq n \leq 2 \cdot 10^5, 1 \le x \le 10^9$) — the number of mushrooms and the maximum toxicity level.

The second line of each test case contains $n$ numbers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single number — the number of subsegments such that the final value of $g$ will not be zero.

## Example

### Input


```text
54 21 1 1 13 21 2 31 6106 31 2 1 4 3 85 999999999999999999 999999998 1000000000 1000000000 500000000
```
### Output

```text

8
2
0
10
7

```
## Note

In the first test case, the subsegments $(1, 1)$, $(1, 2)$, $(1, 4)$, $(2, 2)$, $(2, 3)$, $(3, 3)$, $(3, 4)$ and $(4, 4)$ are suitable.

In the second test case, non-zero $g$ will remain only on the subsegments $(1, 1)$ and $(2, 2)$.

In the third test case, on the only possible subsegment, $g$ will be zero.



#### Tags 

#1600 #NOT OK #binary_search #dp #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_959_sponsored_by_NEAR_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
