<h1 style='text-align: center;'> D. Fun</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Counting is Fun!— satyam343Given two integers $n$ and $x$, find the number of triplets ($a,b,c$) of positive integers such that $ab + ac + bc \le n$ and $a + b + c \le x$. 

## Note

 that order matters (e.g. ($1, 1, 2$) and ($1, 2, 1$) are treated as different) and $a$, $b$, $c$ must be strictly greater than $0$.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$)  — the number of test cases.

Each test case contains two integers $n$ and $x$ ($1 \leq n,x \leq 10^6$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$ and that the sum of $x$ over all test cases does not exceed $10^6$.

### Output

### Output

 a single integer — the number of triplets ($a,b,c$) of positive integers such that $ab + ac + bc \le n$ and $a + b + c \le x$.

## Example

### Input


```text
47 410 57 1000900000 400000
```
### Output

```text

4
10
7
1768016938

```
## Note

In the first test case, the triplets are ($1, 1, 1$), ($1, 1, 2$), ($1, 2, 1$), and ($2, 1, 1$).

In the second test case, the triplets are ($1, 1, 1$), ($1, 1, 2$), ($1, 1, 3$), ($1, 2, 1$), ($1, 2, 2$), ($1, 3, 1$), ($2, 1, 1$), ($2, 1, 2$), ($2, 2, 1$), and ($3, 1, 1$).



#### Tags 

#NOT OK #binary_search #brute_force #combinatorics #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_962_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial 2 (en)](../blogs/Video_Tutorial_2_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
