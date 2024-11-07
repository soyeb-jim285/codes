<h1 style='text-align: center;'> B. Maximum Strength</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fedya is playing a new game called "The Legend of Link", in which one of the character's abilities is to combine two materials into one weapon. Each material has its own strength, which can be represented by a positive integer $x$. The strength of the resulting weapon is determined as the sum of the absolute differences of the digits in the decimal representation of the integers at each position.

Formally, let the first material have strength $X = \overline{x_{1}x_{2} \ldots x_{n}}$, and the second material have strength $Y = \overline{y_{1}y_{2} \ldots y_{n}}$. Then the strength of the weapon is calculated as $|x_{1} - y_{1}| + |x_{2} - y_{2}| + \ldots + |x_{n} - y_{n}|$. If the integers have different lengths, then the shorter integer is padded with leading zeros.

Fedya has an unlimited supply of materials with all possible strengths from $L$ to $R$, inclusive. Help him find the maximum possible strength of the weapon he can obtain.

An integer $C = \overline{c_{1}c_{2} \ldots c_{k}}$ is defined as an integer obtained by sequentially writing the digits $c_1, c_2, \ldots, c_k$ from left to right, i.e. $10^{k-1} \cdot c_1 + 10^{k-2} \cdot c_2 + \ldots + c_k$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains two integers $L$ and $R$ ($1 \le L \le R < 10^{100}$) — the decimal representation of the integers representing the minimum and maximum strength of the materials that Fedya has. It is guaranteed that the integers $L$ and $R$ do not contain leading zeros.

## Note

 that the input data may not fit into standard $32$-bit or $64$-bit integer data types.

### Output

For each test case print one integer — the maximum possible strength of the weapon that Fedya can obtain from the given materials.

## Example

### Input


```text
653 57179 23913 37132228 13222854943329752812629795 5515758193968886336688 1914
```
### Output

```text

4
19
11
0
163
28

```
## Note

In the first test case, the weapon made from materials with strengths $53$ and $57$ will have the maximum possible strength: $|5 - 5| + |3 - 7| = 4$.

In the second test case, the maximum strength is achieved with materials with strengths $190$ and $209$: $|1 - 2| + |9 - 0| + |0 - 9| = 19$.

In the fourth test case, there is only one valid strength, so the answer is $0$.

In the sixth test case, the maximum strength is achieved with materials with strengths $1909$ and $90$: $|1 - 0| + |9 - 0| + |0 - 9| + |9 - 0| = 28$. 
## Note

 that the shorter integer was padded with leading zeros.



#### Tags 

#1000 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_879_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
