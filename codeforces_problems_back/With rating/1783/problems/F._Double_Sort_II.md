<h1 style='text-align: center;'> F. Double Sort II</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two permutations $a$ and $b$, both of size $n$. A permutation of size $n$ is an array of $n$ elements, where each integer from $1$ to $n$ appears exactly once. The elements in each permutation are indexed from $1$ to $n$.

You can perform the following operation any number of times:

* choose an integer $i$ from $1$ to $n$;
* let $x$ be the integer such that $a_x = i$. Swap $a_i$ with $a_x$;
* let $y$ be the integer such that $b_y = i$. Swap $b_i$ with $b_y$.

Your goal is to make both permutations sorted in ascending order (i. e. the conditions $a_1 < a_2 < \dots < a_n$ and $b_1 < b_2 < \dots < b_n$ must be satisfied) using minimum number of operations. Note that both permutations must be sorted after you perform the sequence of operations you have chosen.

## Input

The first line contains one integer $n$ ($2 \le n \le 3000$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$; all $a_i$ are distinct).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le n$; all $b_i$ are distinct).

## Output

First, print one integer $k$ ($0 \le k \le 2n$) — the minimum number of operations required to sort both permutations. Note that it can be shown that $2n$ operations are always enough.

Then, print $k$ integers $op_1, op_2, \dots, op_k$ ($1 \le op_j \le n$), where $op_j$ is the value of $i$ you choose during the $j$-th operation.

If there are multiple answers, print any of them.

## Examples

## Input


```

5
1 3 2 4 5
2 1 3 4 5

```
## Output


```

1
2 

```
## Input


```

2
1 2
1 2

```
## Output


```

0


```
## Input


```

4
1 3 4 2
4 3 2 1

```
## Output


```

2
3 4 

```


#### tags 

#2500 #dfs_and_similar #flows #graph_matchings #graphs 