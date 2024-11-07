<h1 style='text-align: center;'> C. Autosynthesis</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Chaneka writes down an array $a$ of $n$ positive integer elements. Initially, all elements are not circled. In one operation, Chaneka can circle an element. It is possible to circle the same element more than once.

After doing all operations, Chaneka makes a sequence $r$ consisting of all uncircled elements of $a$ following the order of their indices.

Chaneka also makes another sequence $p$ such that its length is equal to the number of operations performed and $p_i$ is the index of the element that is circled in the $i$-th operation.

Chaneka wants to do several operations such that sequence $r$ is equal to sequence $p$. Help her achieve this, or report if it is impossible! 
## Note

 that if there are multiple solutions, you can print any of them.

#### Input

The first line contains a single integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the size of array $a$.

The second line contains $n$ integers $a_1,a_2,a_3,\ldots,a_n$ ($1\leq a_i\leq n$).

#### Output

A single line containing $-1$ if it is impossible.

Otherwise, the output consists of two lines. The first line contains an integer $z$ representing the number of operations performed. The second line contains $z$ integers, the $i$-th integer represents the index of the element circled in the $i$-th operation. If there are multiple solutions, you can print any of them.

## Examples

#### Input


```text
5
3 4 2 2 3
```
#### Output


```text
3
3 2 3
```
#### Input


```text
3
1 2 3
```
#### Output


```text
-1
```
## Note

In the first example, doing the operations like the example output gives the following results: 

* Element $a_2$ gets circled $1$ time.
* Element $a_3$ gets circled $2$ times.
* The uncircled elements (ordered by their indices) are $a_1$, $a_4$, and $a_5$. So $r=[3,2,3]$.
* $p=[3,2,3]$

Therefore, $r=p$.

In the second example, it is impossible.



#### Tags 

#2100 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_902_(Div._1,_based_on_COMPFEST_15_-_Final_Round).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
