<h1 style='text-align: center;'> B. Best Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's define the value of the permutation $p$ of $n$ integers $1$, $2$, ..., $n$ (a permutation is an array where each element from $1$ to $n$ occurs exactly once) as follows:

* initially, an integer variable $x$ is equal to $0$;
* if $x < p_1$, then add $p_1$ to $x$ (set $x = x + p_1$), otherwise assign $0$ to $x$;
* if $x < p_2$, then add $p_2$ to $x$ (set $x = x + p_2$), otherwise assign $0$ to $x$;
* ...
* if $x < p_n$, then add $p_n$ to $x$ (set $x = x + p_n$), otherwise assign $0$ to $x$;
* the value of the permutation is $x$ at the end of this process.

For example, for $p = [4, 5, 1, 2, 3, 6]$, the value of $x$ changes as follows: $0, 4, 9, 0, 2, 5, 11$, so the value of the permutation is $11$.

You are given an integer $n$. Find a permutation $p$ of size $n$ with the maximum possible value among all permutations of size $n$. If there are several such permutations, you can print any of them.

### Input

The first line contains one integer $t$ ($1 \le t \le 97$) — the number of test cases.

The only line of each test case contains one integer $n$ ($4 \le n \le 100$).

### Output

For each test case, print $n$ integers — the permutation $p$ of size $n$ with the maximum possible value among all permutations of size $n$.

## Example

### Input


```text
3456
```
### Output

```text

2 1 3 4
1 2 3 4 5
4 5 1 2 3 6
```


#### Tags 

#800 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_135_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
