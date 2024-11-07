<h1 style='text-align: center;'> G. Sum of Prefix Sums</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

We define the sum of prefix sums of an array $[s_1, s_2, \dots, s_k]$ as $s_1 + (s_1 + s_2) + (s_1 + s_2 + s_3) + \dots + (s_1 + s_2 + \dots + s_k)$.

You are given a tree consisting of $n$ vertices. Each vertex $i$ has an integer $a_i$ written on it. We define the value of the simple path from vertex $u$ to vertex $v$ as follows: consider all vertices appearing on the path from $u$ to $v$, write down all the numbers written on these vertices in the order they appear on the path, and compute the sum of prefix sums of the resulting sequence.

Your task is to calculate the maximum value over all paths in the tree.

## Input

The first line contains one integer $n$ ($2 \le n \le 150000$) — the number of vertices in the tree.

Then $n - 1$ lines follow, representing the edges of the tree. Each line contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$, $u_i \ne v_i$), denoting an edge between vertices $u_i$ and $v_i$. It is guaranteed that these edges form a tree.

The last line contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le 10^6$).

## Output

Print one integer — the maximum value over all paths in the tree.

## Example

## Input


```

4
4 2
3 2
4 1
1 3 3 7

```
## Output


```

36

```
## Note

The best path in the first example is from vertex $3$ to vertex $1$. It gives the sequence $[3, 3, 7, 1]$, and the sum of prefix sums is $36$.



#### tags 

#2700 #data_structures #divide_and_conquer #geometry #trees 