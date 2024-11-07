<h1 style='text-align: center;'> F. Fancy Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's call an array $a$ of $n$ non-negative integers fancy if the following conditions hold: 

* at least one from the numbers $x$, $x + 1$, ..., $x+k-1$ appears in the array;
* consecutive elements of the array differ by at most $k$ (i.e. $|a_i-a_{i-1}| \le k$ for each $i \in [2, n]$).

You are given $n$, $x$ and $k$. Your task is to calculate the number of fancy arrays of length $n$. Since the answer can be large, print it modulo $10^9+7$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 50$) — the number of test cases.

The only line of each test case contains three integers $n$, $x$ and $k$ ($1 \le n, k \le 10^9$; $0 \le x \le 40$).

### Output

For each test case, print a single integer — the number of fancy arrays of length $n$, taken modulo $10^9+7$.

## Example

### Input


```text
43 0 11 4 254 7 21000000000 40 1000000000
```
### Output

```text

9
25
582
514035484

```
## Note

In the first test case of the example, the following arrays are fancy:

* $[0, 0, 0]$;
* $[0, 0, 1]$;
* $[0, 1, 0]$;
* $[0, 1, 1]$;
* $[0, 1, 2]$;
* $[1, 0, 0]$;
* $[1, 0, 1]$;
* $[1, 1, 0]$;
* $[2, 1, 0]$.


#### Tags 

#2600 #NOT OK #combinatorics #dp #math #matrices 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_157_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
