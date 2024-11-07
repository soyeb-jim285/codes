<h1 style='text-align: center;'> C. Weight of the System of Nested Segments</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On the number line there are $m$ points, $i$-th of which has integer coordinate $x_i$ and integer weight $w_i$. The coordinates of all points are different, and the points are numbered from $1$ to $m$.

A sequence of $n$ segments $[l_1, r_1], [l_2, r_2], \dots, [l_n, r_n]$ is called system of nested segments if for each pair $i, j$ ($1 \le i < j \le n$) the condition $l_i < l_j < r_j < r_i$ is satisfied. In other words, the second segment is strictly inside the first one, the third segment is strictly inside the second one, and so on.

For a given number $n$, find a system of nested segments such that:

* both ends of each segment are one of $m$ given points;
* the sum of the weights $2\cdot n$ of the points used as ends of the segments is minimal.

For example, let $m = 8$. The given points are marked in the picture, their weights are marked in red, their coordinates are marked in blue. Make a system of three nested segments:

* weight of the first segment: $1 + 1 = 2$
* weight of the second segment: $10 + (-1) = 9$
* weight of the third segment: $3 + (-2) = 1$
* sum of the weights of all the segments in the system: $2 + 9 + 1 = 12$

 ![](images/cda411c8d1a8e275a60e641e41a418d9668aa68c.png) System of three nested segments ## Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^4$) —the number of input test cases.

An empty line is written before each test case.

The first line of each test case contains two positive integers $n$ ($1 \le n \le 10^5$) and $m$ ($2 \cdot n \le m \le 2 \cdot 10^5$). 

The next $m$ lines contain pairs of integers $x_i$ ($-10^9 \le x_i \le 10^9$) and $w_i$ ($-10^4 \le w_i \le 10^4$) — coordinate and weight of point number $i$ ($1 \le i \le m$) respectively. All $x_i$ are different.

It is guaranteed that the sum of $m$ values over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output $n + 1$ lines: in the first of them, output the weight of the composed system, and in the next $n$ lines output exactly two numbers  — the indices of the points which are the endpoints of the $i$-th segment ($1 \le i \le n$). The order in which you output the endpoints of a segment is not important — you can output the index of the left endpoint first and then the number of the right endpoint, or the other way around.

If there are several ways to make a system of nested segments with minimal weight, output any of them.

## Example

## Input


```

3

3 8
0 10
-2 1
4 10
11 20
7 -1
9 1
2 3
5 -2

3 6
-1 2
1 3
3 -1
2 4
4 0
8 2

2 5
5 -1
3 -2
1 0
-2 0
-5 -3

```
## Output


```

12
2 6
5 1
7 8

10
1 6
5 2
3 4

-6
5 1
4 2
```
## Note

The first test case coincides with the example from the condition. It can be shown that the weight of the composed system is minimal.

The second test case has only $6$ points, so you need to use each of them to compose $3$ segments.



#### tags 

#1200 #greedy #hashing #implementation #sortings 