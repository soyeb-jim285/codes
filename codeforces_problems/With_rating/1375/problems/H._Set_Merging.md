<h1 style='text-align: center;'> H. Set Merging</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $a_1, a_2, \dots, a_n$ of numbers from $1$ to $n$. Also, you have $n$ sets $S_1,S_2,\dots, S_n$, where $S_i=\{a_i\}$. Lastly, you have a variable $cnt$, representing the current number of sets. Initially, $cnt = n$.

We define two kinds of functions on sets:

$f(S)=\min\limits_{u\in S} u$;

$g(S)=\max\limits_{u\in S} u$.

You can obtain a new set by merging two sets $A$ and $B$, if they satisfy $g(A)<f(B)$ (Notice that the old sets do not disappear).

Formally, you can perform the following sequence of operations:

* $cnt\gets cnt+1$;
* $S_{cnt}=S_u\cup S_v$, you are free to choose $u$ and $v$ for which $1\le u, v < cnt$ and which satisfy $g(S_u)<f(S_v)$.

You are required to obtain some specific sets.

There are $q$ requirements, each of which contains two integers $l_i$,$r_i$, which means that there must exist a set $S_{k_i}$ ($k_i$ is the ID of the set, you should determine it) which equals $\{a_u\mid l_i\leq u\leq r_i\}$, which is, the set consisting of all $a_i$ with indices between $l_i$ and $r_i$.

In the end you must ensure that $cnt\leq 2.2\times 10^6$. 
## Note

 that you don't have to minimize $cnt$. It is guaranteed that a solution under given constraints exists.

#### Input

The first line contains two integers $n,q$ $(1\leq n \leq 2^{12},1 \leq q \leq 2^{16})$  — the length of the permutation and the number of needed sets correspondently.

The next line consists of $n$ integers $a_1,a_2,\cdots, a_n$ ($1\leq a_i\leq n$, $a_i$ are pairwise distinct)  — given permutation.

$i$-th of the next $q$ lines contains two integers $l_i,r_i$ $(1\leq l_i\leq r_i\leq n)$, describing a requirement of the $i$-th set.

#### Output

It is guaranteed that a solution under given constraints exists.

The first line should contain one integer $cnt_E$ $(n\leq cnt_E\leq 2.2\times 10^6)$, representing the number of sets after all operations.

$cnt_E-n$ lines must follow, each line should contain two integers $u$, $v$ ($1\leq u, v\leq cnt'$, where $cnt'$ is the value of $cnt$ before this operation), meaning that you choose $S_u$, $S_v$ and perform a merging operation. In an operation, $g(S_u)<f(S_v)$ must be satisfied.

The last line should contain $q$ integers $k_1,k_2,\cdots,k_q$ $(1\leq k_i\leq cnt_E)$, representing that set $S_{k_i}$ is the $i$th required set.

Please notice the large amount of output.

## Examples

#### Input


```text
3 2
1 3 2
2 3
1 3
```
#### Output


```text
6
3 2
1 3
5 2
4 6 
```
#### Input

```text

2 4
2 1
1 2
1 2
1 2
1 1

```
#### Output


```text

5
2 1
2 1
2 1
5 3 3 1
```
## Note

In the first sample:

We have $S_1=\{1\},S_2=\{3\},S_3=\{2\}$ initially.

In the first operation, because $g(S_3)=2<f(S_2)=3$, we can merge $S_3,S_2$ into $S_4=\{2,3\}$.

In the second operation, because $g(S_1)=1<f(S_3)=2$, we can merge $S_1,S_3$ into $S_5=\{1,2\}$.

In the third operation, because $g(S_5)=2<f(S_2)=3$, we can merge $S_5,S_2$ into $S_6=\{1,2,3\}$.

For the first requirement, $S_4=\{2,3\}=\{a_2,a_3\}$, satisfies it, thus $k_1=4$.

For the second requirement, $S_6=\{1,2,3\}=\{a_1,a_2,a_3\}$, satisfies it, thus $k_2=6$

Notice that unused sets, identical sets, outputting the same set multiple times, and using sets that are present initially are all allowed.



#### Tags 

#3300 #NOT OK #constructive_algorithms #divide_and_conquer 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_9.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
