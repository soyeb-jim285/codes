<h1 style='text-align: center;'> B. Binary String Constructing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $a$, $b$ and $x$. Your task is to construct a binary string $s$ of length $n = a + b$ such that there are exactly $a$ zeroes, exactly $b$ ones and exactly $x$ indices $i$ (where $1 \le i < n$) such that $s_i \ne s_{i + 1}$. It is guaranteed that the answer always exists.

For example, for the string "01010" there are four indices $i$ such that $1 \le i < n$ and $s_i \ne s_{i + 1}$ ($i = 1, 2, 3, 4$). For the string "111001" there are two such indices $i$ ($i = 3, 5$).

Recall that binary string is a non-empty sequence of characters where each character is either 0 or 1.

##### Input

The first line of the input contains three integers $a$, $b$ and $x$ ($1 \le a, b \le 100, 1 \le x < a + b)$.

##### Output

Print only one string $s$, where $s$ is any binary string satisfying conditions described above. It is guaranteed that the answer always exists.

## Examples

##### Input


```text
2 2 1  

```
##### Output


```text
1100  

```
##### Input


```text
3 3 3  

```
##### Output


```text
101100  

```
##### Input


```text
5 3 6  

```
##### Output


```text
01010100  

```
## Note

All possible answers for the first example: 

* 1100;
* 0011.

All possible answers for the second example: 

* 110100;
* 101100;
* 110010;
* 100110;
* 011001;
* 001101;
* 010011;
* 001011.


#### Tags 

#1300 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_494_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
