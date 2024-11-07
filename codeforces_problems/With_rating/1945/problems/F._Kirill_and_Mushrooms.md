<h1 style='text-align: center;'> F. Kirill and Mushrooms</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As soon as everyone in the camp fell asleep, Kirill sneaked out of the tent and went to the Wise Oak to gather mushrooms.

It is known that there are $n$ mushrooms growing under the Oak, each of which has magic power $v_i$. Kirill really wants to make a magical elixir of maximum strength from the mushrooms.

The strength of the elixir is equal to the product of the number of mushrooms in it and the minimum magic power among these mushrooms. To prepare the elixir, Kirill will sequentially pick one mushroom growing under the Oak. Kirill can gather mushrooms in any order.

However, it's not that simple. The Wise Oak informed Kirill of a permutation of numbers $p$ from $1$ to $n$. If Kirill picks only $k$ mushrooms, then the magic power of all mushrooms with indices $p_1, p_2, \dots, p_{k - 1}$ will become $0$. Kirill will not use mushrooms with zero magic power to prepare the elixir.

Your task is to help Kirill gather mushrooms in such a way that he can brew the elixir of maximum possible strength. However, Kirill is a little scared to stay near the oak for too long, so out of all the suitable options for gathering mushrooms, he asks you to find the one with the minimum number of mushrooms.

A permutation of length $n$ is an array consisting of $n$ different integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears in the array twice) and $[1,3,4]$ is also not a permutation ($n=3$, but $4$ appears in the array).

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 200\,000$) — the number of mushrooms.

The second line contains an array $v$ of size $n$ ($1\le v_i \le 10^9$) — the magic powers of the mushrooms.

The third line contains a permutation $p$ of numbers from $1$ to $n$.

It is guaranteed that the sum of the values of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output two integers separated by a space — the maximum strength of the elixir that can be brewed and the minimum number of mushrooms that Kirill needs to use for this.

## Example

### Input


```text
639 8 143 2 151 2 3 4 51 2 3 4 561 2 3 4 5 66 5 4 3 2 151 4 6 10 102 1 4 5 342 2 5 54 2 3 151 2 9 10 101 4 2 3 5
```
### Output

```text

16 2
9 3
8 2
20 2
5 1
20 2

```
## Note

In the first example, you need to take the mushrooms with indices $1$ and $2$, so the strength of the elixir is equal to $2 \cdot \min(a_1, a_2) = 2 \cdot \min(9, 8) = 2 \cdot 8 = 16$. 
## Note

 that the magic power of the mushroom with index $3$ after picking two mushrooms will become $0$.



#### Tags 

#1900 #NOT OK #data_structures #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_935_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
