<h1 style='text-align: center;'> B. Split Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation$^{\dagger}$ $p_1, p_2, \ldots, p_n$ of integers $1$ to $n$.

You can change the current permutation by applying the following operation several (possibly, zero) times:

* choose some $x$ ($2 \le x \le n$);
* create a new permutation by:
	+ first, writing down all elements of $p$ that are less than $x$, without changing their order;
	+ second, writing down all elements of $p$ that are greater than or equal to $x$, without changing their order;
* replace $p$ with the newly created permutation.

For example, if the permutation used to be $[6, 4, 3, 5, 2, 1]$ and you choose $x = 4$, then you will first write down $[3, 2, 1]$, then append this with $[6, 4, 5]$. So the initial permutation will be replaced by $[3, 2, 1, 6, 4, 5]$.

Find the minimum number of operations you need to achieve $p_i = i$ for $i = 1, 2, \ldots, n$. We can show that it is always possible to do so.

$^{\dagger}$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1 \le n \le 100\,000$).

The second line of each test case contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$). It is guaranteed that $p_1, p_2, \ldots, p_n$ is a permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $100\,000$.

### Output

For each test case, output the answer on a separate line.

## Example

### Input


```text
51122 166 4 3 5 2 133 1 21910 19 7 1 17 11 8 5 12 9 4 18 14 2 6 15 3 16 13
```
### Output

```text

0
1
4
1
7

```
## Note

In the first test case, $n = 1$ and $p_1 = 1$, so there is nothing left to do.

In the second test case, we can choose $x = 2$ and we immediately obtain $p_1 = 1$, $p_2 = 2$.

In the third test case, we can achieve the minimum number of operations in the following way:

1. $x = 4$: $[6, 4, 3, 5, 2, 1] \rightarrow [3, 2, 1, 6, 4, 5]$;
2. $x = 6$: $[3, 2, 1, 6, 4, 5] \rightarrow [3, 2, 1, 4, 5, 6]$;
3. $x = 3$: $[3, 2, 1, 4, 5, 6] \rightarrow [2, 1, 3, 4, 5, 6]$;
4. $x = 2$: $[2, 1, 3, 4, 5, 6] \rightarrow [1, 2, 3, 4, 5, 6]$.


#### Tags 

#1100 #OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Pinely_Round_2_(Div._1_+_Div._2).md)
- [Pinely Round 2](../blogs/Pinely_Round_2.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
