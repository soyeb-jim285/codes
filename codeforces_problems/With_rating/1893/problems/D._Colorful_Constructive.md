<h1 style='text-align: center;'> D. Colorful Constructive</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You have $n$ colored cubes, the $i$-th cube has color $a_i$.

You need to distribute all the cubes on shelves. There are a total of $m$ shelves, the $i$-th shelf can hold $s_i$ cubes. Also, $s_1 + s_2 + \ldots + s_m = n$.

Suppose on a shelf of size $k$ there are cubes of colors $c_1, c_2, \ldots, c_k$, in this order. Then we define the colorfulness of the shelf as the minimum distance between two different cubes of the same color on the shelf. If all the cubes on the shelf have different colors, then the colorfulness is considered to be equal to the size of the shelf, that is, the number $k$.

More formally, the colorfulness of $c_1, c_2, \ldots, c_k$ is defined as follows:

* If all the colors $c_1, c_2, \ldots, c_k$ are different, the colorfulness is considered to be $k$.
* Otherwise, the colorfulness is considered to be the smallest integer $x \geq 1$ such that there exists an index $i$ $(1 \le i \le k - x)$ such that $c_i = c_{i+x}$.

For each shelf, you are given the minimum required colorfulness, that is, you are given numbers $d_1, d_2, \ldots, d_m$, which mean that shelf $i$ must have a colorfulness $\geq d_i$ for all $i$.

Distribute the available cubes among the shelves to ensure the required colorfulness, or report that it is impossible.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 10^4)$ — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n, m$ $(1 \leq m \leq n \leq 2 \cdot 10^5)$ — the number of cubes and the number of shelves to distribute them to.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ $(1 \leq a_i \leq n)$ — the colors of the cubes.

The third line of each test case contains $m$ integers $s_1, s_2, \ldots, s_m$ $(1 \leq s_i \leq n)$ — the sizes of the shelves. It's guaranteed, that $s_1 + \ldots + s_m = n$.

The fourth line of each test case contains $m$ integers $d_1, d_2, \ldots, d_m$ $(1 \leq d_i \leq s_i)$ — the minimum required colorfulness of the shelves.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, if it is impossible to distribute the cubes on the shelves satisfying all the requirements, output a single number $-1$. Otherwise, output $m$ lines, where the $i$-th line should contain $s_i$ numbers representing the colors of the cubes on the $i$-th shelf, in the appropriate order.

## Example

### Input


```text
610 31 1 1 1 2 2 2 3 3 46 2 24 1 18 27 7 7 7 8 8 8 84 42 25 15 4 3 2 1537 31 2 2 2 2 3 41 2 41 2 412 76 6 6 6 6 6 6 6 6 7 8 92 2 2 2 2 1 11 2 2 2 1 1 120 211 20 15 6 8 18 12 16 8 20 10 12 3 12 20 11 15 8 17 178 123 5
```
### Output

```text

1 3 4 2 1 3 
1 1 
2 2 
8 7 8 7 
8 7 8 7 
2 4 5 3 1 
-1
6 6 
7 6 
8 6 
9 6 
6 6 
6 
6 
12 17 20 15 8 20 16 11 
15 20 17 12 10 8 3 18 12 11 8 6 

```


#### Tags 

#2600 #NOT OK #constructive_algorithms #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_908_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
