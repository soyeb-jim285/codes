<h1 style='text-align: center;'> D. The Wu</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Childan is making up a legendary story and trying to sell his forgery — a necklace with a strong sense of "Wu" to the Kasouras. But Mr. Kasoura is challenging the truth of Childan's story. So he is going to ask a few questions about Childan's so-called "personal treasure" necklace.

This "personal treasure" is a multiset $S$ of $m$ "01-strings".

A "01-string" is a string that contains $n$ characters "0" and "1". For example, if $n=4$, strings "0110", "0000", and "1110" are "01-strings", but "00110" (there are $5$ characters, not $4$) and "zero" (unallowed characters) are not.

## Note

 that the multiset $S$ can contain equal elements.

Frequently, Mr. Kasoura will provide a "01-string" $t$ and ask Childan how many strings $s$ are in the multiset $S$ such that the "Wu" value of the pair $(s, t)$ is not greater than $k$. 

Mrs. Kasoura and Mr. Kasoura think that if $s_i = t_i$ ($1\leq i\leq n$) then the "Wu" value of the character pair equals to $w_i$, otherwise $0$. The "Wu" value of the "01-string" pair is the sum of the "Wu" values of every character pair. 
## Note

 that the length of every "01-string" is equal to $n$.

For example, if $w=[4, 5, 3, 6]$, "Wu" of ("1001", "1100") is $7$ because these strings have equal characters only on the first and third positions, so $w_1+w_3=4+3=7$.

You need to help Childan to answer Mr. Kasoura's queries. That is to find the number of strings in the multiset $S$ such that the "Wu" value of the pair is not greater than $k$.

#### Input

The first line contains three integers $n$, $m$, and $q$ ($1\leq n\leq 12$, $1\leq q, m\leq 5\cdot 10^5$) — the length of the "01-strings", the size of the multiset $S$, and the number of queries.

The second line contains $n$ integers $w_1, w_2, \ldots, w_n$ ($0 \le w_i \le 100$) — the value of the $i$-th caracter.

Each of the next $m$ lines contains the "01-string" $s$ of length $n$ — the string in the multiset $S$.

Each of the next $q$ lines contains the "01-string" $t$ of length $n$ and integer $k$ ($0\leq k\leq 100$) — the query.

#### Output

For each query, print the answer for this query.

## Examples

#### Input


```text
2 4 5  
40 20  
01  
01  
10  
11  
00 20  
00 40  
11 20  
11 40  
11 60  

```
#### Output


```text
2  
4  
2  
3  
4  

```
#### Input


```text
1 2 4  
100  
0  
1  
0 0  
0 100  
1 0  
1 100  

```
#### Output


```text
1  
2  
1  
2  

```
## Note

In the first example, we can get:

"Wu" of ("01", "00") is $40$.

"Wu" of ("10", "00") is $20$.

"Wu" of ("11", "00") is $0$.

"Wu" of ("01", "11") is $20$.

"Wu" of ("10", "11") is $40$.

"Wu" of ("11", "11") is $60$.

In the first query, pairs ("11", "00") and ("10", "00") satisfy the condition since their "Wu" is not greater than $20$.

In the second query, all strings satisfy the condition.

In the third query, pairs ("01", "11") and ("01", "11") satisfy the condition. 
## Note

 that since there are two "01" strings in the multiset, the answer is $2$, not $1$.

In the fourth query, since $k$ was increased, pair ("10", "11") satisfies the condition too.

In the fifth query, since $k$ was increased, pair ("11", "11") satisfies the condition too.



#### Tags 

#1900 #NOT OK #bitmasks #brute_force #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_502_(in_memory_of_Leopoldo_Taravilse,_Div._1_+_Div._2).md)
- [announcement (en)](../blogs/announcement_(en).md)
- [Разбор (англ.) (en)](../blogs/Разбор_(англ.)_(en).md)
