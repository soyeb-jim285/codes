<h1 style='text-align: center;'> C. Another Array Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers. You are allowed to perform the following operation on it as many times as you want (0 or more times): 

* Choose $2$ indices $i$,$j$ where $1 \le i < j \le n$ and replace $a_k$ for all $i \leq k \leq j$ with $|a_i - a_j|$

Print the maximum sum of all the elements of the final array that you can obtain in such a way.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of array $a$.

It's guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print the sum of the final array.

## Example

### Input


```text
331 1 129 134 9 5
```
### Output

```text

3
16
18

```
## Note

In the first test case, it is not possible to achieve a sum $> 3$ by using these operations, therefore the maximum sum is $3$.

In the second test case, it can be shown that the maximum sum achievable is $16$. By using operation $(1,2)$ we transform the array from $[9,1]$ into $[8,8]$, thus the sum of the final array is $16$. 

In the third test case, it can be shown that it is not possible to achieve a sum $> 18$ by using these operations, therefore the maximum sum is $18$.



#### Tags 

#2000 #OK #brute_force #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_840_(Div._2)_and_Enigma_2022_-_Cybros_LNMIIT.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
