<h1 style='text-align: center;'> A. Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a very popular computer game. The next level consists of $n$ consecutive locations, numbered from $1$ to $n$, each of them containing either land or water. It is known that the first and last locations contain land, and for completing the level you have to move from the first location to the last. Also, if you become inside a location with water, you will die, so you can only move between locations with land.

You can jump between adjacent locations for free, as well as no more than once jump from any location with land $i$ to any location with land $i + x$, spending $x$ coins ($x \geq 0$).

Your task is to spend the minimum possible number of coins to move from the first location to the last one.

## Note

 that this is always possible since both the first and last locations are the land locations.

### Input

There are several test cases in the input data. The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains one integer $n$ ($2 \leq n \leq 100$) — the number of locations.

The second line of the test case contains a sequence of integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 1$), where $a_i = 1$ means that the $i$-th location is the location with land, and $a_i = 0$ means that the $i$-th location is the location with water. It is guaranteed that $a_1 = 1$ and $a_n = 1$.

### Output

For each test case print a single integer — the answer to the problem.

## Example

### Input


```text
321 151 0 1 0 141 0 1 1
```
### Output

```text

0
4
2

```
## Note

In the first test case, it is enough to make one free jump from the first location to the second one, which is also the last one, so the answer is $0$.

In the second test case, the only way to move from the first location to the last one is to jump between them, which will cost $4$ coins.

In the third test case, you can jump from the first location to the third for $2$ coins, and then jump to the fourth location for free, so the answer is $2$. It can be shown that this is the optimal way.



#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_775_(Div._2,_based_on_Moscow_Open_Olympiad_in_Informatics).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
