<h1 style='text-align: center;'> F. Tree Recovery</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Fishingprince loves trees. A tree is a connected undirected graph without cycles.

Fishingprince has a tree of $n$ vertices. The vertices are numbered $1$ through $n$. Let $d(x,y)$ denote the shortest distance on the tree from vertex $x$ to vertex $y$, assuming that the length of each edge is $1$.

However, the tree was lost in an accident. Fortunately, Fishingprince still remembers some information about the tree. More specifically, for every triple of integers $x,y,z$ ($1\le x<y\le n$, $1\le z\le n$) he remembers whether $d(x,z)=d(y,z)$ or not.

Help him recover the structure of the tree, or report that no tree satisfying the constraints exists.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 200$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($2\le n\le 100$) — the number of vertices in the tree.

Then $n-1$ lines follow. The $i$-th line of these $n-1$ lines contains $n-i$ strings of length $n$ consisting of 0 and 1. If the $k$-th character in the $j$-th string of the $i$-th line is 0, it means that $d(i,k)\ne d(i+j,k)$; if the $k$-th character in the $j$-th string of the $i$-th line is 1, it means that $d(i,k)=d(i+j,k)$.

It is guaranteed that in one input file,

* there are at most $2$ test cases that have $n>50$;
* there are at most $5$ test cases that have $n>20$.
### Output

For each test case:

* if no answer exists, output No;
* otherwise, on the first line output Yes. Then output $n-1$ lines. Each line should contain two integers $x,y$ ($1\le x,y\le n$), denoting an edge between vertices $x$ and $y$ of the tree. If there are multiple solutions, print any.

When printing Yes and No, you can print each letter in any case (upper or lower).

## Example

### Input


```text
52002103001 0000003001 010000500000 01001 00000 0110000000 10000 0000000000 1101000000
```
### Output

```text

Yes
1 2
No
Yes
1 3
2 3
No
Yes
1 2
1 4
2 3
2 5

```


#### Tags 

#2600 #NOT OK #brute_force #constructive_algorithms #dfs_and_similar #dsu #graphs #trees 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_21.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
