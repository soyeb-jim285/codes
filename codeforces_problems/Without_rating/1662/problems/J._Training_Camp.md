<h1 style='text-align: center;'> J. Training Camp</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are organizing a training camp to teach algorithms to young kids. There are $n^2$ kids, organized in an $n$ by $n$ grid. Each kid is between $1$ and $n$ years old (inclusive) and any two kids who are in the same row or in the same column have different ages.

You want to select exactly $n$ kids for a programming competition, with exactly one kid from each row and one kid from each column. Moreover, kids who are not selected must be either older than both kids selected in their row and column, or younger than both kids selected in their row and column (otherwise they will complain). Notice that it is always possible to select $n$ kids satisfying these requirements (for example by selecting $n$ kids who have the same age).

During the training camp, you observed that some kids are good at programming, and the others are not. What is the maximum number of kids good at programming that you can select while satisfying all the requirements?

#### Input

The first line contains $n$ ($1 \leq n \leq 128$) — the size of the grid.

The following $n$ lines describe the ages of the kids. Specifically, the $i$-th line contains $n$ integers $a_{i,1}, \, a_{i,2}, \, \dots, \, a_{i, n}$ ($1 \le a_{i,j} \le n$) — where $a_{i,j}$ is the age of the kid in the $i$-th row and $j$-th column. It is guaranteed that two kids on the same row or column have different ages, i.e., $a_{i,j} \ne a_{i,j'}$ for any $1\le i\le n$, $1\le j < j'\le n$, and $a_{i,j} \ne a_{i',j}$ for any $1\le i < i'\le n$, $1\le j\le n$.

The following $n$ lines describe the programming skills of the kids. Specifically, the $i$-th line contains $n$ integers $c_{i,1}, \, c_{i,2}, \, \dots, \, c_{i, n}$ ($c_{i,j} \in \{0, \, 1\}$) — where $c_{i,j}=1$ if the kid in the $i$-th row and $j$-th column is good at programming and $c_{i,j}=0$ otherwise.

#### Output

Print the maximum number of kids good at programming that you can select while satisfying all the requirements.

## Examples

#### Input


```text
3
1 2 3
3 1 2
2 3 1
1 0 0
0 0 1
0 0 0
```
#### Output


```text
1
```
#### Input


```text
4
1 2 3 4
2 1 4 3
3 4 1 2
4 3 2 1
1 1 1 0
0 0 1 0
1 1 0 1
0 0 0 1
```
#### Output


```text
2
```
## Note

In the first sample, it is not possible to select the two kids good at programming (in row $1$ and column $1$, and in row $2$ and column $3$), because then you would have to select the kid in row $3$ and column $2$, and in that case two kids would complain (the one in row $1$ and column $2$, and the one in row $3$ and column $1$).

A valid selection which contains $1$ kid good at programming is achieved by choosing the $3$ kids who are $1$ year old.

In the second sample, there are $10$ valid choices of the $n$ kids that satisfy the requirements, and each of them selects exactly $2$ kids good at programming.



#### Tags 

#NOT OK #flows #graphs 

## Blogs
- [All Contest Problems](../SWERC_2021-2022_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [SWERC 2021-2022 (en)](../blogs/SWERC_2021-2022_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
