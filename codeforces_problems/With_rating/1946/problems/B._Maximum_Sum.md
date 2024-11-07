<h1 style='text-align: center;'> B. Maximum Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of $n$ integers.

You perform exactly $k$ operations on it. In one operation, you select any contiguous subarray of the array $a$ (possibly empty) and insert the sum of this subarray anywhere in the array.

Your task is to find the maximum possible sum of the array after $k$ such operations.

As this number can be very large, output the answer modulo $10^9 + 7$.

Reminder: the remainder of a number $x$ modulo $p$ is the smallest non-negative $y$ such that there exists an integer $q$ and $x = p \cdot q + y$.

### Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n, k \le 2 \cdot 10^5$) — the length of the array $a$ and the number of operations, respectively.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — the array $a$ itself.

It is guaranteed that the sum of the values of $n$ and $k$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test, output a single integer — the maximum sum of the array that can be obtained after $k$ operations modulo $10^9 + 7$.

## Example

### Input


```text
122 2-4 -73 32 2 81 775 14 -2 8 -12 97 48 14 -9 6 0 -1 37 1005 3 -8 12 -5 -9 36 1000-1000000000 -1000000000 -1000000000 -1000000000 -1000000000 -10000000002 11000000000 85 40 0 0 0 06 1048973 757292 58277 -38574 27475 9999847 1-1000 1000 -1000 1000 -1000 1000 -100010 10050408293874 -3498597 7374783 295774930 -48574034 26623784 498754833 -294875830 283045804 85938045
```
### Output

```text

999999996
96
896
17
351
716455332
42
2
0
897909241
0
416571966

```
## Note

In the first test case, it is advantageous to take an empty subarray of the array twice and insert the sum of the empty subarray (zero) anywhere, then the sum of the resulting array will be $(-4) + (-7) + 0 + 0 = -11$, modulo $10^9 + 7$ this is $999\,999\,996$.

In the second test case, it is advantageous to take the sum of the entire array three times and place it anywhere in the array, then one of the possible sequences of actions: [$2, 2, 8$] $\rightarrow$ [$2, 2, 8, 12$] $\rightarrow$ [$2, 2, 8, 12, 24$] $\rightarrow$ [$2, 2, 8, 12, 24, 48$], the sum of the final array is $2 + 2 + 8 + 12 + 24 + 48 = 96$.

In the fourth test case, it is advantageous to take a subarray of the array consisting of the first three numbers (i.e. consisting of the numbers $4, -2$ and $8$) and insert its sum at the beginning of the array, thereby obtaining the array [$10, 4, -2, 8, -12, 9$], the sum of this array is $17$.

In the seventh test case, it will always be advantageous for us to take an empty subarray of the array. In this case, the sum of the resulting array will not differ from the sum of the original. The answer will be the sum of the original array, taken modulo — $42$, because $(-6 \cdot (10^9 + 7) + 42 = -6\,000\,000\,000)$.



#### Tags 

#1100 #NOT OK #dp #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_936_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
