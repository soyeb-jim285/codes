<h1 style='text-align: center;'> C. Minimum Notation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a string $s$ consisting of digits from $0$ to $9$ inclusive. You can perform the following operation any (possibly zero) number of times: 

* You can choose a position $i$ and delete a digit $d$ on the $i$-th position. Then insert the digit $\min{(d + 1, 9)}$ on any position (at the beginning, at the end or in between any two adjacent digits).

What is the lexicographically smallest string you can get by performing these operations?

A string $a$ is lexicographically smaller than a string $b$ of the same length if and only if the following holds: 

* in the first position where $a$ and $b$ differ, the string $a$ has a smaller digit than the corresponding digit in $b$.
### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the test cases follow.

Each test case consists of a single line that contains one string $s$ ($1 \le |s| \le 2 \cdot 10^5$) — the string consisting of digits. Please note that $s$ is just a string consisting of digits, so leading zeros are allowed.

It is guaranteed that the sum of lengths of $s$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

Print a single string — the minimum string that is possible to obtain.

## Example

### Input


```text
404829901314752277691991
```
### Output

```text

02599
9
01
111334567888999

```
## Note

In the first test case: 

* Delete $8$ and insert $9$ at the end of the notation. The resulting notation is $04299$.
* Delete $4$ and insert $5$ in the $3$-rd position of the notation. The resulting notation is $02599$.

Nothing needs to be done in the second and third test cases.



#### Tags 

#1200 #OK #data_structures #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_823_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
