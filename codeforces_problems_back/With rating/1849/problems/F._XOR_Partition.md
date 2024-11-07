<h1 style='text-align: center;'> F. XOR Partition</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For a set of integers $S$, let's define its cost as the minimum value of $x \oplus y$ among all pairs of different integers from the set (here, $\oplus$ denotes bitwise XOR). If there are less than two elements in the set, its cost is equal to $2^{30}$.

You are given a set of integers $\{a_1, a_2, \dots, a_n\}$. You have to partition it into two sets $S_1$ and $S_2$ in such a way that every element of the given set belongs to exactly one of these two sets. The value of the partition is the minimum among the costs of $S_1$ and $S_2$.

Find the partition with the maximum possible value.

## Input

The first line contains $n$ ($2 \le n \le 200000$) — the number of elements in the set.

The second line contains $n$ distinct integers $a_1$, $a_2$, ..., $a_n$ ($0 \le a_i < 2^{30}$) — the elements of the set.

## Output

Print a string $n$ characters 0 and/or 1 describing the partition as follows: the $i$-th character should be 0 if the element $a_i$ belongs to $S_1$, otherwise, that character should be 1.

If there are multiple optimal answers, print any of them.

## Examples

## Input


```
5  
42 13 1337 37 152  

```
## Output


```
10001  

```
## Input


```
4  
1 2 3 4  

```
## Output


```
1100  

```
## Input


```
2  
1 2  

```
## Output


```
10  

```
## Input


```
8  
7 6 5 4 3 2 1 0  

```
## Output


```
10010110  

```


#### tags 

#2700 #binary_search #bitmasks #data_structures #divide_and_conquer #greedy #trees 