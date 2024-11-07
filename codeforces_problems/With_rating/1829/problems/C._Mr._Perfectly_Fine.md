<h1 style='text-align: center;'> C. Mr. Perfectly Fine</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Victor wants to become "Mr. Perfectly Fine". For that, he needs to acquire a certain set of skills. More precisely, he has $2$ skills he needs to acquire. 

Victor has $n$ books. Reading book $i$ takes him $m_i$ minutes and will give him some (possibly none) of the required two skills, represented by a binary string of length $2$.

What is the minimum amount of time required so that Victor acquires all of the two skills? 

### Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of books available.

Then $n$ lines follow. Line $i$ contains a positive integer $m_i$ ($1 \leq m_i \leq 2 \cdot 10^5$) and a binary string of length $2$, where $s_{i1} = 1$ if reading book $i$ acquires Victor skill $1$, and $s_{i1} = 0$ otherwise, and $s_{i2} = 1$ if reading book $i$ acquires Victor skill $2$, and $s_{i2} = 0$ otherwise.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, output a single integer denoting the minimum amount of minutes required for Victor to obtain both needed skills and $-1$ in case it's impossible to obtain the two skills after reading any amount of books. 

## Example

### Input


```text
642 003 104 014 0053 013 015 012 109 1015 1139 118 017 1064 016 017 018 009 011 0048 009 109 118 11
```
### Output

```text

7
5
5
9
-1
8

```
## Note

In the first test case, we can use books $2$ and $3$, with a total amount of minutes spent equal to $3 + 4 = 7$.

In the second test case, we can use the books $1$ and $4$, with a total amount of minutes spent equal to $3 + 2 = 5$.

In the third test case, we have only one option and that is reading book $1$ for a total amount of minutes spent equal to $5$.



#### Tags 

#800 #NOT OK #bitmasks #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_871_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
