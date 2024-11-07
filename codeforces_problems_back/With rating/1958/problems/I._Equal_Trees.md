<h1 style='text-align: center;'> I. Equal Trees</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two rooted trees, consisting of $n$ vertices each. The vertices in the trees are numbered from $1$ to $n$, and the root is the vertex $1$.

You can perform the following operation: choose the tree and the vertex $v$ (except the root of the tree) in it; connect the child nodes of $v$ to the parent of $v$ and remove $v$ from the tree.

Let's say that two trees are equal if both of the following conditions hold: 

* the sets of remaining vertices in both trees are the same;
* for every vertex $v$ which is not deleted, its parent in the first tree is the same as its parent in the second tree.

Your task is to calculate the minimum number of aforementioned operation in order to make the trees equal.

## Input

The first line contains a single integer $n$ ($2 \le n \le 40$) — the number of vertices in the trees.

The second line contains $n-1$ integers $a_2, a_3, \dots, a_n$ ($1 \le a_i \le n$), where $a_i$ the parent of the $i$-th vertex in the first tree. Vertex $1$ is the root.

The third line contains $n-1$ integers $b_2, b_3, \dots, b_n$ ($1 \le b_i \le n$), where $b_i$ the parent of the $i$-th vertex in the second tree. Vertex $1$ is the root.

## Output

Print a single integer — the minimum number of aforementioned operation in order to make the trees equal.

## Examples

## Input


```

51 5 5 11 4 1 2
```
## Output


```

4

```
## Input


```

211
```
## Output


```

0

```
## Input


```

104 7 10 6 2 9 7 1 11 2 10 3 4 6 6 5 5
```
## Output


```

10

```


#### tags 

#3100 #*special #graphs #meet-in-the-middle 