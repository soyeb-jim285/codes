<h1 style='text-align: center;'> A. 2023</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a sequence $a$, whose product was equal to $2023$, $k$ numbers were removed, leaving a sequence $b$ of length $n$. Given the resulting sequence $b$, find any suitable sequence $a$ and output which $k$ elements were removed from it, or state that such a sequence could not have existed.

Notice that you are not guaranteed that such array exists.

### Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains two integers $n$ ($1 \le n, k \le 5$) — the size of sequence $b$ and the number of numbers removed from sequence $a$.

The second line contains $n$ integers $b_1,b_2, \ldots,b_n$ ($1 \leq b_i \leq 2023$) — the remaining sequence. The values of $b_i$ might not be divisors of $2023$.

### Output

For each test case, output "YES" if the sequence $a$ exists, and in the following line output $k$ non-negative integers that were removed from the sequence $a$. If the sequence $a$ does not exist, output "NO" in a single line.

You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

## Example

### Input


```text
72 25 23 17 17 74 21 289 1 13 17 17 171 12891 120231 31
```
### Output

```text

NO
NO
YES
7 1
YES
1
YES
7
YES
1
YES
7 17 17

```
## Note

In third test case product is equal to $289 \cdot 7 = 2023$.

In fourth test case product is already equal to $2023$.

In seventh test case product is equal to $7 \cdot 17 \cdot 17 = 2023$.



#### Tags 

#800 #OK #constructive_algorithms #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Good_Bye_2023.md)
- [Good Bye 2023](../blogs/Good_Bye_2023.md)
- [Good Bye 2023 tutorial (en)](../blogs/Good_Bye_2023_tutorial_(en).md)
