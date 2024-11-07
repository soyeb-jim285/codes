<h1 style='text-align: center;'> B. GCD Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider the array $a$ composed of all the integers in the range $[l, r]$. For example, if $l = 3$ and $r = 7$, then $a = [3, 4, 5, 6, 7]$.

Given $l$, $r$, and $k$, is it possible for $\gcd(a)$ to be greater than $1$ after doing the following operation at most $k$ times? 

* Choose $2$ numbers from $a$.
* Permanently remove one occurrence of each of them from the array.
* Insert their product back into $a$.

$\gcd(b)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of the integers in $b$.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of test cases follows.

The input for each test case consists of a single line containing $3$ non-negative integers $l$, $r$, and $k$ ($1 \leq l \leq r \leq 10^9, \enspace 0 \leq k \leq r - l$).

### Output

For each test case, print "YES" if it is possible to have the GCD of the corresponding array greater than $1$ by performing at most $k$ operations, and "NO" otherwise (case insensitive).

## Example

### Input


```text
91 1 03 5 113 13 04 4 03 7 44 10 32 4 01 7 31 5 3
```
### Output

```text

NO
NO
YES
YES
YES
YES
NO
NO
YES

```
## Note

For the first test case, $a = [1]$, so the answer is "NO", since the only element in the array is $1$.

For the second test case the array is $a = [3, 4, 5]$ and we have $1$ operation. After the first operation the array can change to: $[3, 20]$, $[4, 15]$ or $[5, 12]$ all of which having their greatest common divisor equal to $1$ so the answer is "NO".

For the third test case, $a = [13]$, so the answer is "YES", since the only element in the array is $13$.

For the fourth test case, $a = [4]$, so the answer is "YES", since the only element in the array is $4$.



#### Tags 

#800 #NOT OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_767_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
