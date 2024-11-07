<h1 style='text-align: center;'> A. Distinct Digits</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have two integers $l$ and $r$. Find an integer $x$ which satisfies the conditions below:

* $l \le x \le r$.
* All digits of $x$ are different.

If there are multiple answers, print any of them.

#### Input

The first line contains two integers $l$ and $r$ ($1 \le l \le r \le 10^{5}$).

#### Output

If an answer exists, print any of them. Otherwise, print $-1$.

## Examples

#### Input


```text
121 130
```
#### Output


```text
123
```
#### Input


```text
98766 100000
```
#### Output


```text
-1
```
## Note

In the first example, $123$ is one of the possible answers. However, $121$ can't be the answer, because there are multiple $1$s on different digits.

In the second example, there is no valid answer.



#### Tags 

#800 #NOT OK #brute_force #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_589_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
