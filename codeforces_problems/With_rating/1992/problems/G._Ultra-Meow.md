<h1 style='text-align: center;'> G. Ultra-Meow</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

K1o0n gave you an array $a$ of length $n$, consisting of numbers $1, 2, \ldots, n$. Accept it? Of course! But what to do with it? Of course, calculate $\text{MEOW}(a)$.

Let $\text{MEX}(S, k)$ be the $k$-th positive (strictly greater than zero) integer in ascending order that is not present in the set $S$. Denote $\text{MEOW}(a)$ as the sum of $\text{MEX}(b, |b| + 1)$, over all distinct subsets $b$ of the array $a$.

## Example

s of $\text{MEX}(S, k)$ values for sets: 

* $\text{MEX}(\{3,2\}, 1) = 1$, because $1$ is the first positive integer not present in the set;
* $\text{MEX}(\{4,2,1\}, 2) = 5$, because the first two positive integers not present in the set are $3$ and $5$;
* $\text{MEX}(\{\}, 4) = 4$, because there are no numbers in the empty set, so the first $4$ positive integers not present in it are $1, 2, 3, 4$.
### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

In a single line of each test case, an integer $n$ ($1 \le n \le 5000$) is entered, the size of the array of gifted numbers.

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $25 \cdot 10^6$.

### Output

For each test case, output a single number — $\text{MEOW}(a)$. Since it may be very large, output it modulo $10^9 + 7$.

## Example

### Input


```text
523499951
```
### Output

```text

12
31
354226409
184
4

```


#### Tags 

#2000 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_957_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Shayan's Video Tutorial (en)](../blogs/Shayan's_Video_Tutorial_(en).md)
