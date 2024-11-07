<h1 style='text-align: center;'> C. Train Maintenance</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Kawasiro Nitori is excellent in engineering. Thus she has been appointed to help maintain trains.

There are $n$ models of trains, and Nitori's department will only have at most one train of each model at any moment. In the beginning, there are no trains, at each of the following $m$ days, one train will be added, or one train will be removed. When a train of model $i$ is added at day $t$, it works for $x_i$ days (day $t$ inclusive), then it is in maintenance for $y_i$ days, then in work for $x_i$ days again, and so on until it is removed.

In order to make management easier, Nitori wants you to help her calculate how many trains are in maintenance in each day.

On a day a train is removed, it is not counted as in maintenance.

## Input

The first line contains two integers $n$, $m$ ($1 \le n,m \le 2 \cdot 10^5$).

The $i$-th of the next $n$ lines contains two integers $x_i,y_i$ ($1 \le x_i,y_i \le 10^9$).

Each of the next $m$ lines contains two integers $op$, $k$ ($1 \le k \le n$, $op = 1$ or $op = 2$). If $op=1$, it means this day's a train of model $k$ is added, otherwise the train of model $k$ is removed. It is guaranteed that when a train of model $x$ is added, there is no train of the same model in the department, and when a train of model $x$ is removed, there is such a train in the department.

## Output

Print $m$ lines, The $i$-th of these lines contains one integers, denoting the number of trains in maintenance in the $i$-th day.

## Examples

## Input


```

3 4
10 15
12 10
1 1
1 3
1 1
2 1
2 3

```
## Output


```

0
1
0
0

```
## Input


```

5 4
1 1
10000000 100000000
998244353 1
2 1
1 2
1 5
2 5
1 5
1 1

```
## Output


```

0
0
0
1

```
## Note

Consider the first example:

The first day: Nitori adds a train of model $3$. Only a train of model $3$ is running and no train is in maintenance.

The second day: Nitori adds a train of model $1$. A train of model $1$ is running and a train of model $3$ is in maintenance.

The third day: Nitori removes a train of model $1$. The situation is the same as the first day.

The fourth day: Nitori removes a train of model $3$. There are no trains at all.



#### tags 

#2200 #brute_force #data_structures #implementation 