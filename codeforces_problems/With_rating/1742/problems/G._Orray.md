<h1 style='text-align: center;'> G. Orray</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ nonnegative integers. 

Let's define the prefix OR array $b$ as the array $b_i = a_1~\mathsf{OR}~a_2~\mathsf{OR}~\dots~\mathsf{OR}~a_i$, where $\mathsf{OR}$ represents the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR). In other words, the array $b$ is formed by computing the $\mathsf{OR}$ of every prefix of $a$.

You are asked to rearrange the elements of the array $a$ in such a way that its prefix OR array is lexicographically maximum.

An array $x$ is lexicographically greater than an array $y$ if in the first position where $x$ and $y$ differ, $x_i > y_i$.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ nonnegative integers $a_1, \ldots, a_n$ ($0 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case print $n$ integers — any rearrangement of the array $a$ that obtains the lexicographically maximum prefix OR array.

## Example

### Input


```text
541 2 4 875 1 2 3 4 5 521 10162 3 4 2 3 481 4 2 3 4 5 7 1
```
### Output

```text

8 4 2 1 
5 2 1 3 4 5 5 
101 1 
4 3 2 2 3 4 
7 1 4 2 3 4 5 1 

```


#### Tags 

#1500 #NOT OK #bitmasks #brute_force #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_827_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
