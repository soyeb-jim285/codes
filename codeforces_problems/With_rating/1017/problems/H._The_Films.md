<h1 style='text-align: center;'> H. The Films</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In "The Man in the High Castle" world, there are $m$ different film endings. 

Abendsen owns a storage and a shelf. At first, he has $n$ ordered films on the shelf. In the $i$-th month he will do:

1. Empty the storage.
2. Put $k_i \cdot m$ films into the storage, $k_i$ films for each ending.
3. He will think about a question: if he puts all the films from the shelf into the storage, then randomly picks $n$ films (from all the films in the storage) and rearranges them on the shelf, what is the probability that sequence of endings in $[l_i, r_i]$ on the shelf will not be changed? Notice, he just thinks about this question, so the shelf will not actually be changed.

Answer all Abendsen's questions.

Let the probability be fraction $P_i$. Let's say that the total number of ways to take $n$ films from the storage for $i$-th month is $A_i$, so $P_i \cdot A_i$ is always an integer. Print for each month $P_i \cdot A_i \pmod {998244353}$.

$998244353$ is a prime number and it is equal to $119 \cdot 2^{23} + 1$.

It is guaranteed that there will be only no more than $100$ different $k$ values.

#### Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n, m, q \le 10^5$, $n+q\leq 10^5$) — the number of films on the shelf initially, the number of endings, and the number of months.

The second line contains $n$ integers $e_1, e_2, \ldots, e_n$ ($1\leq e_i\leq m$) — the ending of the $i$-th film on the shelf.

Each of the next $q$ lines contains three integers $l_i$, $r_i$, and $k_i$ ($1 \le l_i \le r_i \le n, 0 \le k_i \le 10^5$) — the $i$-th query.

It is guaranteed that there will be only no more than $100$ different $k$ values.

#### Output

Print the answer for each question in a separate line.

## Examples

#### Input


```text
6 4 4  
1 2 3 4 4 4  
1 4 0  
1 3 2  
1 4 2  
1 5 2  

```
#### Output


```text
6  
26730  
12150  
4860  

```
#### Input


```text
5 5 3  
1 2 3 4 5  
1 2 100000  
1 4 4  
3 5 5  

```
#### Output


```text
494942218  
13125  
151632  

```
## Note

In the first sample in the second query, after adding $2 \cdot m$ films into the storage, the storage will look like this: $\{1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4\}$.

There are $26730$ total ways of choosing the films so that $e_l, e_{l+1}, \ldots, e_r$ will not be changed, for example, $[1, 2, 3, 2, 2]$ and $[1, 2, 3, 4, 3]$ are such ways.

There are $2162160$ total ways of choosing the films, so you're asked to print $(\frac{26730}{2162160} \cdot 2162160) \mod 998244353 = 26730$.



#### Tags 

#3300 #NOT OK #brute_force 

## Blogs
- [All Contest Problems](../Codeforces_Round_502_(in_memory_of_Leopoldo_Taravilse,_Div._1_+_Div._2).md)
- [announcement (en)](../blogs/announcement_(en).md)
- [Разбор (англ.) (en)](../blogs/Разбор_(англ.)_(en).md)
