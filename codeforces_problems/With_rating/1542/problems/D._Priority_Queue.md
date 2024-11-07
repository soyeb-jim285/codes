<h1 style='text-align: center;'> D. Priority Queue</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a sequence $A$, where its elements are either in the form + x or -, where $x$ is an integer.

For such a sequence $S$ where its elements are either in the form + x or -, define $f(S)$ as follows:

* iterate through $S$'s elements from the first one to the last one, and maintain a multiset $T$ as you iterate through it.
* for each element, if it's in the form + x, add $x$ to $T$; otherwise, erase the smallest element from $T$ (if $T$ is empty, do nothing).
* after iterating through all $S$'s elements, compute the sum of all elements in $T$. $f(S)$ is defined as the sum.

The sequence $b$ is a subsequence of the sequence $a$ if $b$ can be derived from $a$ by removing zero or more elements without changing the order of the remaining elements. For all $A$'s subsequences $B$, compute the sum of $f(B)$, modulo $998\,244\,353$.

#### Input

The first line contains an integer $n$ ($1\leq n\leq 500$) — the length of $A$.

Each of the next $n$ lines begins with an operator + or -. If the operator is +, then it's followed by an integer $x$ ($1\le x<998\,244\,353$). The $i$-th line of those $n$ lines describes the $i$-th element in $A$.

#### Output

Print one integer, which is the answer to the problem, modulo $998\,244\,353$.

## Examples

#### Input


```text
4
-
+ 1
+ 2
-
```
#### Output


```text
16
```
#### Input

```text

15
+ 2432543
-
+ 4567886
+ 65638788
-
+ 578943
-
-
+ 62356680
-
+ 711111
-
+ 998244352
-
-

```
#### Output


```text

750759115
```
## Note

In the first example, the following are all possible pairs of $B$ and $f(B)$:

* $B=$ {}, $f(B)=0$.
* $B=$ {-}, $f(B)=0$.
* $B=$ {+ 1, -}, $f(B)=0$.
* $B=$ {-, + 1, -}, $f(B)=0$.
* $B=$ {+ 2, -}, $f(B)=0$.
* $B=$ {-, + 2, -}, $f(B)=0$.
* $B=$ {-}, $f(B)=0$.
* $B=$ {-, -}, $f(B)=0$.
* $B=$ {+ 1, + 2}, $f(B)=3$.
* $B=$ {+ 1, + 2, -}, $f(B)=2$.
* $B=$ {-, + 1, + 2}, $f(B)=3$.
* $B=$ {-, + 1, + 2, -}, $f(B)=2$.
* $B=$ {-, + 1}, $f(B)=1$.
* $B=$ {+ 1}, $f(B)=1$.
* $B=$ {-, + 2}, $f(B)=2$.
* $B=$ {+ 2}, $f(B)=2$.

The sum of these values is $16$.



#### Tags 

#2200 #NOT OK #combinatorics #dp #implementation #math #ternary_search 

## Blogs
- [All Contest Problems](../Codeforces_Round_729_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
