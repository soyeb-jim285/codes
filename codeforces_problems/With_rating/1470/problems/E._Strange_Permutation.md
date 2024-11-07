<h1 style='text-align: center;'> E. Strange Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice had a permutation $p_1, p_2, \ldots, p_n$. Unfortunately, the permutation looked very boring, so she decided to change it and choose some non-overlapping subranges of this permutation and reverse them. The cost of reversing a single subrange $[l, r]$ (elements from position $l$ to position $r$, inclusive) is equal to $r - l$, and the cost of the operation is the sum of costs of reversing individual subranges. Alice had an integer $c$ in mind, so she only considered operations that cost no more than $c$.

Then she got really bored, and decided to write down all the permutations that she could possibly obtain by performing exactly one operation on the initial permutation. Of course, Alice is very smart, so she wrote down each obtainable permutation exactly once (no matter in how many ways it can be obtained), and of course the list was sorted lexicographically.

Now Bob would like to ask Alice some questions about her list. Each question is in the following form: what is the $i$-th number in the $j$-th permutation that Alice wrote down? Since Alice is too bored to answer these questions, she asked you to help her out.

#### Input

The first line contains a single integer $t$ ($1 \leq t \leq 30$) — the number of test cases.

The first line of each test case contains three integers $n$, $c$, $q$ ($1 \leq n \leq 3 \cdot 10^4$, $1 \leq c \leq 4$, $1 \leq q \leq 3 \cdot 10^5$) — the length of the permutation, the maximum cost of the operation, and the number of queries.

The next line of each test case contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \leq p_i \leq n$, $p_i \neq p_j$ if $i \neq j$), describing the initial permutation.

The following $q$ lines describe the queries. Each of them contains two integers $i$ and $j$ ($1 \leq i \leq n$, $1 \leq j \leq 10^{18}$), denoting parameters of this query.

It is guaranteed that the sum of values $n$ over all test cases does not exceed $3 \cdot 10^5$, and the sum of values $q$ over all test cases does not exceed $3 \cdot 10^5$.

#### Output

For each query output the answer for this query, or $-1$ if $j$-th permutation does not exist in her list.

## Examples

#### Input


```text
2
3 1 9
1 2 3
1 1
2 1
3 1
1 2
2 2
3 2
1 3
2 3
3 3
6 4 4
6 5 4 3 1 2
1 1
3 14
1 59
2 6
```
#### Output


```text
1
2
3
1
3
2
2
1
3
1
4
-1
5
```
#### Input


```text
1
12 4 2
1 2 3 4 5 6 7 8 9 10 11 12
2 20
2 21
```
#### Output


```text
2
2
```
## Note

In the first test case, Alice wrote down the following permutations: $[1, 2, 3]$, $[1, 3, 2]$, $[2, 1, 3]$.

## Note

 that, for a permutation $[3, 2, 1]$ Alice would have to reverse the whole array, and it would cost her $2$, which is greater than the specified value $c=1$. The other two permutations can not be obtained by performing exactly one operation described in the problem statement.



#### Tags 

#3200 #NOT OK #binary_search #combinatorics #data_structures #dp #graphs #implementation #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_694_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Разбор](../blogs/Разбор.md)
