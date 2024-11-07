<h1 style='text-align: center;'> D. Deduction Queries</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an array $a$ of $2^{30}$ integers, indexed from $0$ to $2^{30}-1$. Initially, you know that $0 \leq a_i < 2^{30}$ ($0 \leq i < 2^{30}$), but you do not know any of the values. Your task is to process queries of two types:

* 1 l r x: You are informed that the bitwise xor of the subarray $[l, r]$ (ends inclusive) is equal to $x$. That is, $a_l \oplus a_{l+1} \oplus \ldots \oplus a_{r-1} \oplus a_r = x$, where $\oplus$ is the bitwise xor operator. In some cases, the received update contradicts past updates. In this case, you should ignore the contradicting update (the current update).
* 2 l r: You are asked to output the bitwise xor of the subarray $[l, r]$ (ends inclusive). If it is still impossible to know this value, considering all past updates, then output $-1$.

## Note

 that the queries are encoded. That is, you need to write an online solution.

#### Input

The first line contains a single integer $q$ ($1 \leq q \leq 2 \cdot 10^5$) — the number of queries.

Each of the next $q$ lines describes a query. It contains one integer $t$ ($1 \leq t \leq 2$) — the type of query.

The given queries will be encoded in the following way: let $last$ be the answer to the last query of the second type that you have answered (initially, $last = 0$). If the last answer was $-1$, set $last = 1$.

* If $t = 1$, three integers follow, $l'$, $r'$, and $x'$ ($0 \leq l', r', x' < 2^{30}$), meaning that you got an update. First, do the following: $l = l' \oplus last$, $r = r' \oplus last$, $x = x' \oplus last$ and, if $l > r$, swap $l$ and $r$.

This means you got an update that the bitwise xor of the subarray $[l, r]$ is equal to $x$ (notice that you need to ignore updates that contradict previous updates).
* If $t = 2$, two integers follow, $l'$ and $r'$ ($0 \leq l', r' < 2^{30}$), meaning that you got a query. First, do the following: $l = l' \oplus last$, $r = r' \oplus last$ and, if $l > r$, swap $l$ and $r$.

For the given query, you need to print the bitwise xor of the subarray $[l, r]$. If it is impossible to know, print $-1$. Don't forget to change the value of $last$.

It is guaranteed there will be at least one query of the second type.

#### Output

After every query of the second type, output the bitwise xor of the given subarray or $-1$ if it is still impossible to know.

## Examples

#### Input


```text
12  
2 1 2  
2 1 1073741822  
1 0 3 4  
2 0 0  
2 3 3  
2 0 3  
1 6 7 3  
2 4 4  
1 0 2 1  
2 0 0  
2 4 4  
2 0 0  

```
#### Output


```text
-1  
-1  
-1  
-1  
5  
-1  
6  
3  
5  

```
#### Input


```text
4  
1 5 5 9  
1 6 6 5  
1 6 5 10  
2 6 5  

```
#### Output


```text
12  

```
## Note

In the first example, the real queries (without being encoded) are:

* 12
* 2 1 2
* 2 0 1073741823
* 1 1 2 5
* 2 1 1
* 2 2 2
* 2 1 2
* 1 2 3 6
* 2 1 1
* 1 1 3 0
* 2 1 1
* 2 2 2
* 2 3 3
* The answers for the first two queries are $-1$ because we don't have any such information on the array initially.
* The first update tells us $a_1 \oplus a_2 = 5$. 
## Note

 that we still can't be certain about the values $a_1$ or $a_2$ independently (for example, it could be that $a_1 = 1, a_2 = 4$, and also $a_1 = 3, a_2 = 6$).
* After we receive all three updates, we have enough information to deduce $a_1, a_2, a_3$ independently.

In the second example, notice that after the first two updates we already know that $a_5 \oplus a_6 = 12$, so the third update is contradicting, and we ignore it.



#### Tags 

#2400 #NOT OK #data_structures #dsu 

## Blogs
- [All Contest Problems](../Lyft_Level_5_Challenge_2018_-_Final_Round.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
