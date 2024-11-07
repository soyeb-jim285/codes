<h1 style='text-align: center;'> G. GCD Festival</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mr. Chanek has an array $a$ of $n$ integers. The prettiness value of $a$ is denoted as:

$$\sum_{i=1}^{n} {\sum_{j=1}^{n} {\gcd(a_i, a_j) \cdot \gcd(i, j)}}$$

where $\gcd(x, y)$ denotes the greatest common divisor (GCD) of integers $x$ and $y$.

In other words, the prettiness value of an array $a$ is the total sum of $\gcd(a_i, a_j) \cdot \gcd(i, j)$ for all pairs $(i, j)$.

Help Mr. Chanek find the prettiness value of $a$, and output the result modulo $10^9 + 7$!

### Input

The first line contains an integer $n$ ($2 \leq n \leq 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^5$).

### Output

### Output

 an integer denoting the prettiness value of $a$ modulo $10^9 + 7$.

## Example

### Input


```text
5
3 6 2 1 4
```
### Output


```text
77
```


#### Tags 

#2200 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../COMPFEST_13_-_Finals_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [COMPFEST 13 — Editorial (en)](../blogs/COMPFEST_13_—_Editorial_(en).md)
