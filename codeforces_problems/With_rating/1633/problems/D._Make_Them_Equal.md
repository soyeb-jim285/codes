<h1 style='text-align: center;'> D. Make Them Equal</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of integers $a$ of size $n$. Initially, all elements of the array are equal to $1$. You can perform the following operation: choose two integers $i$ ($1 \le i \le n$) and $x$ ($x > 0$), and then increase the value of $a_i$ by $\left\lfloor\frac{a_i}{x}\right\rfloor$ (i.e. make $a_i = a_i + \left\lfloor\frac{a_i}{x}\right\rfloor$).

After performing all operations, you will receive $c_i$ coins for all such $i$ that $a_i = b_i$.

Your task is to determine the maximum number of coins that you can receive by performing no more than $k$ operations.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 10^3; 0 \le k \le 10^6$) — the size of the array and the maximum number of operations, respectively.

The second line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^3$).

The third line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le 10^6$).

The sum of $n$ over all test cases does not exceed $10^3$.

### Output

For each test case, print one integer — the maximum number of coins that you can get by performing no more than $k$ operations.

## Example

### Input


```text
44 41 7 5 22 6 5 23 03 5 25 4 75 95 2 5 6 35 9 1 9 76 1411 4 6 2 8 1643 45 9 41 15 38
```
### Output

```text

9
0
30
167

```


#### Tags 

#1600 #NOT OK #dp #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_122_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
