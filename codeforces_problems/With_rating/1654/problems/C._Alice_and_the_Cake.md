<h1 style='text-align: center;'> C. Alice and the Cake</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice has a cake, and she is going to cut it. She will perform the following operation $n-1$ times: choose a piece of the cake (initially, the cake is all one piece) with weight $w\ge 2$ and cut it into two smaller pieces of weight $\lfloor\frac{w}{2}\rfloor$ and $\lceil\frac{w}{2}\rceil$ ($\lfloor x \rfloor$ and $\lceil x \rceil$ denote [floor and ceiling functions](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions), respectively).

After cutting the cake in $n$ pieces, she will line up these $n$ pieces on a table in an arbitrary order. Let $a_i$ be the weight of the $i$-th piece in the line.

You are given the array $a$. Determine whether there exists an initial weight and sequence of operations which results in $a$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print a single line: print YES if the array $a$ could have resulted from Alice's operations, otherwise print NO.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

## Example

### Input


```text
1413272869 5412985214736 98521473732 3 132 3 361 1 1 1 1 16100 100 100 100 100 1008100 100 100 100 100 100 100 10082 16 1 8 64 1 4 32101 2 4 7 1 1 1 1 7 2107 1 1 1 3 1 3 3 2 3101 4 4 1 1 1 3 3 3 1102 3 2 2 1 2 2 2 2 24999999999 999999999 999999999 999999999
```
### Output

```text

YES
NO
YES
YES
NO
YES
NO
YES
YES
YES
YES
NO
NO
YES

```
## Note

In the first test case, it's possible to get the array $a$ by performing $0$ operations on a cake with weight $327$.

In the second test case, it's not possible to get the array $a$.

In the third test case, it's possible to get the array $a$ by performing $1$ operation on a cake with weight $1\,970\,429\,473$: 

* Cut it in half, so that the weights are $[985\,214\,736, 985\,214\,737]$.

 
## Note

 that the starting weight can be greater than $10^9$.In the fourth test case, it's possible to get the array $a$ by performing $2$ operations on a cake with weight $6$:

* Cut it in half, so that the weights are $[3,3]$.
* Cut one of the two pieces with weight $3$, so that the new weights are $[1, 2, 3]$ which is equivalent to $[2, 3, 1]$ up to reordering.


#### Tags 

#1400 #NOT OK #data_structures #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_778_(Div._1_+_Div._2,_based_on_Technocup_2022_Final_Round).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
