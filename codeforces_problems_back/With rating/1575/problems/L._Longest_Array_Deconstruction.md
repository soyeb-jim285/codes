<h1 style='text-align: center;'> L. Longest Array Deconstruction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mr. Chanek gives you a sequence $a$ indexed from $1$ to $n$. Define $f(a)$ as the number of indices where $a_i = i$. 

You can pick an element from the current sequence and remove it, then concatenate the remaining elements together. For example, if you remove the $3$-rd element from the sequence $[4, 2, 3, 1]$, the resulting sequence will be $[4, 2, 1]$. 

You want to remove some elements from $a$ in order to maximize $f(a)$, using zero or more operations. Find the largest possible $f(a)$.

## Input

The first line contains one integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the initial length of the sequence.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 2 \cdot 10^5$) — the initial sequence $a$.

## Output

## Output

 an integer denoting the largest $f(a)$ that can be obtained by doing zero or more operations.

## Examples

## Input


```

7
2 1 4 2 5 3 7

```
## Output


```

3

```
## Input


```

4
4 2 3 1

```
## Output


```

2

```
## Note

In the first example, $f(A) = 3$ by doing the following operations.

$[2,1,\textbf{4},2,5,3,7] \rightarrow [\textbf{2},1,2,5,3,7] \rightarrow [1,2,5,3,\textbf{7}] \rightarrow [1,2,\textbf{5},3] \rightarrow [1,2,3]$

In the second example, $f(A) = 2$ and no additional operation is needed.



#### tags 

#2100 #data_structures #divide_and_conquer #dp #sortings 