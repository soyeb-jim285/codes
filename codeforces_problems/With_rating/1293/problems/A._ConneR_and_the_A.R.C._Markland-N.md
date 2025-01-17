<h1 style='text-align: center;'> A. ConneR and the A.R.C. Markland-N</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Sakuzyo - Imprinting](https://www.youtube.com/watch?v=55Ca6av1kAY)A.R.C. Markland-N is a tall building with $n$ floors numbered from $1$ to $n$. Between each two adjacent floors in the building, there is a staircase connecting them.

It's lunchtime for our sensei Colin "ConneR" Neumann Jr, and he's planning for a location to enjoy his meal.

ConneR's office is at floor $s$ of the building. On each floor (including floor $s$, of course), there is a restaurant offering meals. However, due to renovations being in progress, $k$ of the restaurants are currently closed, and as a result, ConneR can't enjoy his lunch there.

CooneR wants to reach a restaurant as quickly as possible to save time. What is the minimum number of staircases he needs to walk to reach a closest currently open restaurant.

Please answer him quickly, and you might earn his praise and even enjoy the lunch with him in the elegant Neumanns' way!

### Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases in the test. Then the descriptions of $t$ test cases follow.

The first line of a test case contains three integers $n$, $s$ and $k$ ($2 \le n \le 10^9$, $1 \le s \le n$, $1 \le k \le \min(n-1, 1000)$) — respectively the number of floors of A.R.C. Markland-N, the floor where ConneR is in, and the number of closed restaurants.

The second line of a test case contains $k$ distinct integers $a_1, a_2, \ldots, a_k$ ($1 \le a_i \le n$) — the floor numbers of the currently closed restaurants.

It is guaranteed that the sum of $k$ over all test cases does not exceed $1000$.

### Output

For each test case print a single integer — the minimum number of staircases required for ConneR to walk from the floor $s$ to a floor with an open restaurant.

## Example

### Input


```text
5
5 2 3
1 2 3
4 3 3
4 1 2
10 2 6
1 2 3 4 5 7
2 1 1
2
100 76 8
76 75 36 67 41 74 10 77
```
### Output


```text
2
0
4
0
2
```
## Note

In the first example test case, the nearest floor with an open restaurant would be the floor $4$.

In the second example test case, the floor with ConneR's office still has an open restaurant, so Sensei won't have to go anywhere.

In the third example test case, the closest open restaurant is on the $6$-th floor.



#### Tags 

#1100 #NOT OK #binary_search #brute_force #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_614_(Div._2).md)
- [Codeforces Round #614 (en)](../blogs/Codeforces_Round_614_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
