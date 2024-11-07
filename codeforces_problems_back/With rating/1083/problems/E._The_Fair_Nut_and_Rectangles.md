<h1 style='text-align: center;'> E. The Fair Nut and Rectangles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Fair Nut got stacked in planar world. He should solve this task to get out.

You are given $n$ rectangles with vertexes in $(0, 0)$, $(x_i, 0)$, $(x_i, y_i)$, $(0, y_i)$. For each rectangle, you are also given a number $a_i$. Choose some of them that the area of union minus sum of $a_i$ of the chosen ones is maximum.

It is guaranteed that there are no nested rectangles.

Nut has no idea how to find the answer, so he asked for your help.

## Input

The first line contains one integer $n$ ($1 \leq n \leq 10^6$) — the number of rectangles.

Each of the next $n$ lines contains three integers $x_i$, $y_i$ and $a_i$ ($1 \leq x_i, y_i \leq 10^9$, $0 \leq a_i \leq x_i \cdot y_i$).

It is guaranteed that there are no nested rectangles.

## Output

In a single line print the answer to the problem — the maximum value which you can achieve.

## Examples

## Input


```

3
4 4 8
1 5 0
5 2 10

```
## Output


```

9
```
## Input


```

4
6 2 4
1 6 2
2 4 3
5 3 8

```
## Output


```

10
```
## Note

In the first example, the right answer can be achieved by choosing the first and the second rectangles.

In the second example, the right answer can also be achieved by choosing the first and the second rectangles.



#### tags 

#2400 #data_structures #dp #geometry 