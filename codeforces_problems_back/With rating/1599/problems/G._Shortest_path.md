<h1 style='text-align: center;'> G. Shortest path</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $N$ points on an infinite plane with the Cartesian coordinate system on it. $N-1$ points lay on one line, and one point isn't on that line. You are on point $K$ at the start, and the goal is to visit every point. You can move between any two points in a straight line, and you can revisit points. What is the minimum length of the path? 

## Input

The first line contains two integers: $N$ ($3 \leq N \leq 2*10^5$) - the number of points, and $K$ ($1 \leq K \leq N$) - the index of the starting point.

Each of the next $N$ lines contain two integers, $A_i$, $B_i$ ($-10^6 \leq A_i, B_i \leq 10^6$) - coordinates of the $i-th$ point.

## Output

The output contains one number - the shortest path to visit all given points starting from point $K$. The absolute difference between your solution and the main solution shouldn't exceed $10^-6$;

## Example

## Input


```

5 2
0 0
-1 1
2 -2
0 1
-2 2

```
## Output


```

7.478709
```
## Note

The shortest path consists of these moves: 

2 -> 5 

5 -> 4 

4 -> 1 

1 -> 3 

There isn't any shorter path possible.



#### tags 

#2700 #brute_force #geometry #math #shortest_paths 