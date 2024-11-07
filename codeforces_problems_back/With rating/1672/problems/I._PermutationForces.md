<h1 style='text-align: center;'> I. PermutationForces</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You have a permutation $p$ of integers from $1$ to $n$.

You have a strength of $s$ and will perform the following operation some times:

* Choose an index $i$ such that $1 \leq i \leq |p|$ and $|i-p_i| \leq s$.
* For all $j$ such that $1 \leq j \leq |p|$ and $p_i<p_j$, update $p_j$ to $p_j-1$.
* Delete the $i$-th element from $p$. Formally, update $p$ to $[p_1,\ldots,p_{i-1},p_{i+1},\ldots,p_n]$.

It can be shown that no matter what $i$ you have chosen, $p$ will be a permutation of integers from $1$ to $|p|$ after all operations.

You want to be able to transform $p$ into the empty permutation. Find the minimum strength $s$ that will allow you to do so.

## Input

The first line of input contains a single integer $n$ ($1 \leq n \leq 5 \cdot 10^5$)  — the length of the permutation $p$.

The second line of input conatains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \leq p_i \leq n$)  — the elements of the permutation $p$.

It is guaranteed that all elements in $p$ are distinct.

## Output

Print the minimum strength $s$ required.

## Examples

## Input


```

3
3 2 1

```
## Output


```

1

```
## Input


```

1
1

```
## Output


```

0

```
## Input


```

10
1 8 4 3 7 10 6 5 9 2

```
## Output


```

1

```
## Note

In the first test case, the minimum $s$ required is $1$.

Here is how we can transform $p$ into the empty permutation with $s=1$: 

* In the first move, you can only choose $i=2$ as choosing any other value of $i$ will result in $|i-p_i| \leq s$ being false. With $i=2$, $p$ will be changed to $[2,1]$.
* In the second move, you choose $i=1$, then $p$ will be changed to $[1]$.
* In the third move, you choose $i=1$, then $p$ will be changed to $[~]$.

It can be shown that with $s=0$, it is impossible to transform $p$ into the empty permutation.



#### tags 

#3000 #data_structures #greedy 