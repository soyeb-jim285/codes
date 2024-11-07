<h1 style='text-align: center;'> G. Minecraft</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

After winning another Bed Wars game, Masha and Olya wanted to relax and decided to play a new game. Masha gives Olya an array $a$ of length $n$ and a number $s$. Now Olya's task is to find a non-negative number $x$ such that $\displaystyle\sum_{i=1}^{n} a_i \oplus x = s$. But she is very tired after a tight round, so please help her with this.

But this task seemed too simple to them, so they decided to make the numbers larger (up to $2^k$) and provide you with their binary representation.

### Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n, k, n \cdot k \le 2 \cdot 10^6$) — the length of the array $a$ and the length of the binary representation of all numbers.

The second line contains a string of length $k$, consisting of zeros and ones — the binary representation of the number $s$, starting from the most significant bits.

The next $n$ lines also contain strings of length $k$, consisting of zeros and ones, the $i$-th of these strings contains the binary representation of the number $a_i$, starting from the most significant bits.

It is guaranteed that the sum of the values $n \cdot k$ for all test cases does not exceed $2 \cdot 10^6$.

### Output

For each test case, output a string of length $k$ on a separate line, consisting of zeros or ones — the binary representation of any suitable number $x$ ($x \ge 0$), starting from the most significant bits, or $-1$ if such $x$ does not exist.

## Example

### Input


```text
44 501011011100011001100011112 80010100110111111100111105 40101001000000000001000116 500011101101100101010111001001110000
```
### Output

```text

01110
10011010
0010
-1

```
## Note

In the first test case, $s = 11, a = [14, 6, 12, 15]$, if $x = 14$, then $\displaystyle\sum_{i=1}^{n} a_i \oplus x = (14 \oplus 14) + (6 \oplus 14) + (12 \oplus 14) + (15 \oplus 14) = 0 + 8 + 2 + 1 = 11 = s$.

In the second test case, $s = 41, a = [191, 158]$, if $x = 154$, then $\displaystyle\sum_{i=1}^{n} a_i \oplus x = (191 \oplus 154) + (158 \oplus 154) = 37 + 4 = 41 = s$.



#### Tags 

#2600 #NOT OK #bitmasks #brute_force #dp #graphs #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_959_sponsored_by_NEAR_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
