<h1 style='text-align: center;'> D. Jumping Through Segments</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is designing a level for a game. The level consists of $n$ segments on the number line, where the $i$-th segment starts at the point with coordinate $l_i$ and ends at the point with coordinate $r_i$.

The player starts the level at the point with coordinate $0$. In one move, they can move to any point that is within a distance of no more than $k$. After their $i$-th move, the player must land within the $i$-th segment, that is, at a coordinate $x$ such that $l_i \le x \le r_i$. This means:

* After the first move, they must be inside the first segment (from $l_1$ to $r_1$);
* After the second move, they must be inside the second segment (from $l_2$ to $r_2$);
* ...
* After the $n$-th move, they must be inside the $n$-th segment (from $l_n$ to $r_n$).

The level is considered completed if the player reaches the $n$-th segment, following the rules described above. After some thought, Polycarp realized that it is impossible to complete the level with some values of $k$.

Polycarp does not want the level to be too easy, so he asks you to determine the minimum integer $k$ with which it is possible to complete the level.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$)—the number of test cases. Descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$)—the number of segments in the level.

The following $n$ lines.

The $i$-th line contain two integers $l_i$ and $r_i$ ($0 \le l_i \le r_i \le 10^9$)—the boundaries of the $i$-th segment. Segments may intersect.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer—the minimum value of $k$ with which it is possible to complete the level.

## Example

## Input


```

451 53 45 68 100 130 20 10 333 810 186 11410 200 515 172 2
```
## Output


```

7
0
5
13

```
## Note

In the third example, the player can make the following moves:

* Move from point $0$ to point $5$ ($3 \le 5 \le 8$);
* Move from point $5$ to point $10$ ($10 \le 10 \le 18$);
* Move from point $10$ to point $7$ ($6 \le 7 \le 11$).

## Note

 that for the last move, the player could have chosen not to move and still complete the level.



#### tags 

#1400 #binary_search #constructive_algorithms 