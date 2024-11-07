<h1 style='text-align: center;'> D. Valiant's New Map</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Game studio "DbZ Games" wants to introduce another map in their popular game "Valiant". This time, the map named "Panvel" will be based on the city of Mumbai.

Mumbai can be represented as $n \times m$ cellular grid. Each cell $(i, j)$ ($1 \le i \le n$; $1 \le j \le m$) of the grid is occupied by a cuboid building of height $a_{i,j}$.

This time, DbZ Games want to make a map that has perfect vertical gameplay. That's why they want to choose an $l \times l$ square inside Mumbai, such that each building inside the square has a height of at least $l$.

Can you help DbZ Games find such a square of the maximum possible size $l$?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 1000$). Description of the test cases follows.

The first line of each test case contains two positive integers $n$ and $m$ ($1 \le n \le m$; $1 \leq n \cdot m \leq 10^6$).

The $i$-th of next $n$ lines contains $m$ integers $a_{i,1}, a_{i,2}, \dots, a_{i,m}$ ($1 \leq a_{i,j} \leq 10^6$) — heights of buildings on the $i$-th row.

It's guaranteed that the sum of $n \cdot m$ over all test cases doesn't exceed $10^6$.

### Output

For each test case, print the maximum side length $l$ of the square DbZ Games can choose.

## Example

### Input


```text
42 22 34 51 31 2 32 34 4 32 1 45 61 9 4 6 5 810 9 5 8 11 624 42 32 8 11 123 1 9 69 13 313 22 60 12 14 17
```
### Output

```text

2
1
1
3

```
## Note

In the first test case, we can choose the square of side $l = 2$ (i. e. the whole grid) since the heights of all buildings are greater than or equal to $2$.

In the second test case, we can only choose the side as $1$, so the answer is $1$.

In the third test case, there are no squares of size $2$ that have all buildings of height at least $2$, so the answer is $1$. 



#### Tags 

#1700 #NOT OK #binary_search #brute_force #data_structures #dp #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_841_(Div._2)_and_Divide_by_Zero_2022.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
