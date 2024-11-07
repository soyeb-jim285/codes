<h1 style='text-align: center;'> F. Divide, XOR, and Conquer</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$.

In one operation you split the array into two parts: a non-empty prefix and a non-empty suffix. The value of each part is the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all elements in it. Next, discard the part with the smaller value. If both parts have equal values, you can choose which one to discard. Replace the array with the remaining part.

The operations are being performed until the length of the array becomes $1$. For each $i$ ($1 \le i \le n$), determine whether it is possible to achieve the state when only the $i$-th element (with respect to the original numbering) remains.

Formally, you have two numbers $l$ and $r$, initially $l = 1$ and $r = n$. The current state of the array is $[a_l, a_{l+1}, \ldots, a_r]$.

As long as $l < r$, you apply the following operation: 

* Choose an arbitrary $k$ from the set $\{l, l + 1, \ldots, r - 1\}$. Denote $x = a_l \oplus a_{l + 1} \oplus \ldots \oplus a_k$ and $y = a_{k + 1} \oplus a_{k + 2} \oplus \ldots \oplus a_{r}$, where $\oplus$ denotes the bitwise XOR operation.
* If $x < y$, set $l = k + 1$.
* If $x > y$, set $r = k$.
* If $x = y$, either set $l = k + 1$, or set $r = k$.

For each $i$ ($1 \le i \le n$), determine whether it is possible to achieve $l = r = i$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1 \le n \le 10\,000$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{60}$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10\,000$.

### Output

For each test case, output a single string of length $n$ where the $i$-th element is equal to 1 if it is possible to achieve $l = r = i$ and is equal to 0 otherwise.

## Example

### Input


```text
663 2 1 3 7 451 1 1 1 1101 2 4 8 4 1 2 3 4 550 0 0 0 051 2 3 0 11100500
```
### Output

```text

111111
10101
0001000000
11111
11001
1

```
## Note

In the first test case, it is possible to achieve $l = r = i$ for any $i$ from $1$ to $n$:

* for $i=1$: $[1; 6] \rightarrow [1; 4] \rightarrow [1; 1]$;
* for $i=2$: $[1; 6] \rightarrow [1; 3] \rightarrow [2; 3] \rightarrow [2; 2]$;
* for $i=3$: $[1; 6] \rightarrow [1; 3] \rightarrow [3; 3]$;
* for $i=4$: $[1; 6] \rightarrow [1; 4] \rightarrow [4; 4]$;
* for $i=5$: $[1; 6] \rightarrow [5; 6] \rightarrow [5; 5]$;
* for $i=6$: $[1; 6] \rightarrow [6; 6]$.

Let's take a closer look at $i = 2$. Initially $l = 1$, $r = 6$. 

1. We can choose $k = 3$ and set $r = k = 3$ since $(3 \oplus 2 \oplus 1) = 0 \ge 0 = (3 \oplus 7 \oplus 4)$;
2. Next, we can choose $k = 1$ and set $l = k + 1 = 2$ since $3 \le 3 = (2 \oplus 1)$;
3. Finally, we can choose $k = 2$ and set $r = k = 2$ since $2 \ge 1$.


#### Tags 

#2600 #NOT OK #bitmasks #dp #math 

## Blogs
- [All Contest Problems](../Pinely_Round_2_(Div._1_+_Div._2).md)
- [Pinely Round 2](../blogs/Pinely_Round_2.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
