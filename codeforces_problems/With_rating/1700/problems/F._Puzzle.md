<h1 style='text-align: center;'> F. Puzzle</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pupils Alice and Ibragim are best friends. It's Ibragim's birthday soon, so Alice decided to gift him a new puzzle. The puzzle can be represented as a matrix with $2$ rows and $n$ columns, every element of which is either $0$ or $1$. In one move you can swap two values in neighboring cells.

More formally, let's number rows $1$ to $2$ from top to bottom, and columns $1$ to $n$ from left to right. Also, let's denote a cell in row $x$ and column $y$ as $(x, y)$. We consider cells $(x_1, y_1)$ and $(x_2, y_2)$ neighboring if $|x_1 - x_2| + |y_1 - y_2| = 1$.

Alice doesn't like the way in which the cells are currently arranged, so she came up with her own arrangement, with which she wants to gift the puzzle to Ibragim. Since you are her smartest friend, she asked you to help her find the minimal possible number of operations in which she can get the desired arrangement. Find this number, or determine that it's not possible to get the new arrangement.

#### Input

The first line contains an integer $n$ ($1 \leq n \leq 200\,000$) — the number of columns in the puzzle.

Following two lines describe the current arrangement on the puzzle. Each line contains $n$ integers, every one of which is either $0$ or $1$.

The last two lines describe Alice's desired arrangement in the same format.

#### Output

If it is possible to get the desired arrangement, print the minimal possible number of steps, otherwise print $-1$.

## Examples

#### Input


```text
5
0 1 0 1 0
1 1 0 0 1
1 0 1 0 1
0 0 1 1 0
```
#### Output


```text
5
```
#### Input


```text
3
1 0 0
0 0 0
0 0 0
0 0 0
```
#### Output


```text
-1
```
## Note

In the first example the following sequence of swaps will suffice: 

* $(2, 1), (1, 1)$,
* $(1, 2), (1, 3)$,
* $(2, 2), (2, 3)$,
* $(1, 4), (1, 5)$,
* $(2, 5), (2, 4)$.

It can be shown that $5$ is the minimal possible answer in this case.

In the second example no matter what swaps you do, you won't get the desired arrangement, so the answer is $-1$.



#### Tags 

#2600 #NOT OK #constructive_algorithms #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_802_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
