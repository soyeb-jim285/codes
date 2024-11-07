<h1 style='text-align: center;'> G. Distinctification</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Suppose you are given a sequence $S$ of $k$ pairs of integers $(a_1, b_1), (a_2, b_2), \dots, (a_k, b_k)$.

You can perform the following operations on it:

1. Choose some position $i$ and increase $a_i$ by $1$. That can be performed only if there exists at least one such position $j$ that $i \ne j$ and $a_i = a_j$. The cost of this operation is $b_i$;
2. Choose some position $i$ and decrease $a_i$ by $1$. That can be performed only if there exists at least one such position $j$ that $a_i = a_j + 1$. The cost of this operation is $-b_i$.

Each operation can be performed arbitrary number of times (possibly zero).

Let $f(S)$ be minimum possible $x$ such that there exists a sequence of operations with total cost $x$, after which all $a_i$ from $S$ are pairwise distinct. 

Now for the task itself ...

You are given a sequence $P$ consisting of $n$ pairs of integers $(a_1, b_1), (a_2, b_2), \dots, (a_n, b_n)$. All $b_i$ are pairwise distinct. Let $P_i$ be the sequence consisting of the first $i$ pairs of $P$. Your task is to calculate the values of $f(P_1), f(P_2), \dots, f(P_n)$.

## Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of pairs in sequence $P$.

Next $n$ lines contain the elements of $P$: $i$-th of the next $n$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i \le 2 \cdot 10^5$, $1 \le b_i \le n$). It is guaranteed that all values of $b_i$ are pairwise distinct.

## Output

Print $n$ integers — the $i$-th number should be equal to $f(P_i)$.

## Examples

## Input


```
5  
1 1  
3 3  
5 5  
4 2  
2 4  

```
## Output


```
0  
0  
0  
-5  
-16  

```
## Input


```
4  
2 4  
2 3  
2 2  
1 1  

```
## Output


```
0  
3  
7  
1  

```


#### tags 

#2900 #data_structures #dsu #greedy 