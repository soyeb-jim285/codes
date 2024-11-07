<h1 style='text-align: center;'> D. Turtle Tenacity: Continual Mods</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a_1, a_2, \ldots, a_n$, determine whether it is possible to rearrange its elements into $b_1, b_2, \ldots, b_n$, such that $b_1 \bmod b_2 \bmod \ldots \bmod b_n \neq 0$.

Here $x \bmod y$ denotes the remainder from dividing $x$ by $y$. Also, the modulo operations are calculated from left to right. That is, $x \bmod y \bmod z = (x \bmod y) \bmod z$. For example, $2024 \bmod 1000 \bmod 8 = (2024 \bmod 1000) \bmod 8 = 24 \bmod 8 = 0$.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output "YES" if it is possible, "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
861 2 3 4 5 653 3 3 3 332 2 351 1 2 3 731 2 231 1 265 2 10 10 10 243 6 9 3
```
### Output

```text

YES
NO
YES
NO
YES
NO
YES
NO

```
## Note

In the first test case, rearranging the array into $b = [1, 2, 3, 4, 5, 6]$ (doing nothing) would result in $1 \bmod 2 \bmod 3 \bmod 4 \bmod 5 \bmod 6 = 1$. Hence it is possible to achieve the goal.

In the second test case, the array $b$ must be equal to $[3, 3, 3, 3, 3]$, which would result in $3 \bmod 3 \bmod 3 \bmod 3 \bmod 3 = 0$. Hence it is impossible to achieve the goal.

In the third test case, rearranging the array into $b = [3, 2, 2]$ would result in $3 \bmod 2 \bmod 2 = 1$. Hence it is possible to achieve the goal.



#### Tags 

#1200 #NOT OK #constructive_algorithms #greedy #math #number_theory #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_929_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
