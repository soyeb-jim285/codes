<h1 style='text-align: center;'> C. Vasya and Multisets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has a multiset $s$ consisting of $n$ integer numbers. Vasya calls some number $x$ nice if it appears in the multiset exactly once. For example, multiset $\{1, 1, 2, 3, 3, 3, 4\}$ contains nice numbers $2$ and $4$.

Vasya wants to split multiset $s$ into two multisets $a$ and $b$ (one of which may be empty) in such a way that the quantity of nice numbers in multiset $a$ would be the same as the quantity of nice numbers in multiset $b$ (the quantity of numbers to appear exactly once in multiset $a$ and the quantity of numbers to appear exactly once in multiset $b$).

## Input

The first line contains a single integer $n~(2 \le n \le 100)$.

The second line contains $n$ integers $s_1, s_2, \dots s_n~(1 \le s_i \le 100)$ — the multiset $s$.

## Output

If there exists no split of $s$ to satisfy the given requirements, then print "NO" in the first line.

Otherwise print "YES" in the first line.

The second line should contain a string, consisting of $n$ characters. $i$-th character should be equal to 'A' if the $i$-th element of multiset $s$ goes to multiset $a$ and 'B' if if the $i$-th element of multiset $s$ goes to multiset $b$. Elements are numbered from $1$ to $n$ in the order they are given in the input.

If there exist multiple solutions, then print any of them.

## Examples

## Input


```
4  
3 5 7 1  

```
## Output


```
YES  
BABA  

```
## Input


```
3  
3 5 1  

```
## Output


```
NO  

```


#### tags 

#1500 #brute_force #dp #greedy #implementation #math 