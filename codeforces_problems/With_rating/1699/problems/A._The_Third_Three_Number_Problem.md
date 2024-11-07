<h1 style='text-align: center;'> A. The Third Three Number Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$. Your task is to find any three integers $a$, $b$ and $c$ ($0 \le a, b, c \le 10^9$) for which $(a\oplus b)+(b\oplus c)+(a\oplus c)=n$, or determine that there are no such integers.

Here $a \oplus b$ denotes the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of $a$ and $b$. For example, $2 \oplus 4 = 6$ and $3 \oplus 1=2$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The following lines contain the descriptions of the test cases.

The only line of each test case contains a single integer $n$ ($1 \le n \le 10^9$). 

### Output

For each test case, print any three integers $a$, $b$ and $c$ ($0 \le a, b, c \le 10^9$) for which $(a\oplus b)+(b\oplus c)+(a\oplus c)=n$. If no such integers exist, print $-1$.

## Example

### Input


```text
541122046194723326
```
### Output

```text

3 3 1
-1
2 4 6
69 420 666
12345678 87654321 100000000

```
## Note

In the first test case, $a=3$, $b=3$, $c=1$, so $(3 \oplus 3)+(3 \oplus 1) + (3 \oplus 1)=0+2+2=4$.

In the second test case, there are no solutions.

In the third test case, $(2 \oplus 4)+(4 \oplus 6) + (2 \oplus 6)=6+2+4=12$.



#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_804_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
