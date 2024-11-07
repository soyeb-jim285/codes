<h1 style='text-align: center;'> D. Sasha and a Walk in the City</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha wants to take a walk with his girlfriend in the city. The city consists of $n$ intersections, numbered from $1$ to $n$. Some of them are connected by roads, and from any intersection, there is exactly one simple path$^{\dagger}$ to any other intersection. In other words, the intersections and the roads between them form a tree.

Some of the intersections are considered dangerous. Since it is unsafe to walk alone in the city, Sasha does not want to visit three or more dangerous intersections during the walk.

Sasha calls a set of intersections good if the following condition is satisfied:

* If in the city only the intersections contained in this set are dangerous, then any simple path in the city contains no more than two dangerous intersections.

However, Sasha does not know which intersections are dangerous, so he is interested in the number of different good sets of intersections in the city. Since this number can be very large, output it modulo $998\,244\,353$.

$^{\dagger}$A simple path is a path that passes through each intersection at most once.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \leq 3 \cdot 10^5$) — the number of intersections in the city.

The next $(n - 1)$ lines describe the roads. The $i$-th line contains two integers $u_i$ and $v_i$ ($1 \leq u_i, v_i \leq n$, $u_i \ne v_i$) — the numbers of the intersections connected by the $i$-th road.

It is guaranteed that these roads form a tree.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, output a single integer — the number of good sets of intersections modulo $998\,244\,353$.

## Example

### Input


```text
431 33 243 42 33 151 23 45 12 341 22 33 4
```
### Output

```text

7
12
16
11

```
## Note

In the first test case, there are $2^3 = 8$ sets of intersections. All of them are good, except for the set $\{1, 2, 3\}$, because if intersections $1, 2$, and $3$ are dangerous, then the simple path $1 - 2 - 3$ contains $3$ dangerous intersections. Thus, there are $7$ good sets.

In the second test case, there are $2^4 = 16$ sets of intersections. Among them, the sets $\{1, 2, 3, 4\}$, $\{1, 2, 3\}$, $\{1, 3, 4\}$, $\{2, 3, 4\}$ are not good. Thus, there are a total of $12$ good sets. The city layout is shown below:

 ![](images/6099716106eb21a756456f73670fc0f51b161ac2.png) 

#### Tags 

#1900 #NOT OK #combinatorics #dp #math #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_926_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
