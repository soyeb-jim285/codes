<h1 style='text-align: center;'> F. Traveling in Berland</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ cities in Berland, arranged in a circle and numbered from $1$ to $n$ in clockwise order.

You want to travel all over Berland, starting in some city, visiting all the other cities and returning to the starting city. Unfortunately, you can only drive along the Berland Ring Highway, which connects all $n$ cities. The road was designed by a very titled and respectable minister, so it is one-directional — it can only be traversed clockwise, only from the city $i$ to the city $(i \bmod n) + 1$ (i.e. from $1$ to $2$, from $2$ in $3$, ..., from $n$ to $1$).

The fuel tank of your car holds up to $k$ liters of fuel. To drive from the $i$-th city to the next one, $a_i$ liters of fuel are needed (and are consumed in the process).

Every city has a fuel station; a liter of fuel in the $i$-th city costs $b_i$ burles. Refueling between cities is not allowed; if fuel has run out between cities, then your journey is considered incomplete.

For each city, calculate the minimum cost of the journey if you start and finish it in that city.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($3 \le n \le 2 \cdot 10^5$; $1 \le k \le 10^9$) — the number of cities and the volume of fuel tank, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le k$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 2$).

The sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print $n$ integers, where the $i$-th of them is equal to the minimum cost of the journey if you start and finish in the $i$-th city.

## Example

### Input


```text
43 53 4 41 2 25 71 3 2 5 12 1 1 1 24 31 2 1 32 2 2 23 22 2 21 2 1
```
### Output

```text

17 19 17 
13 12 12 12 14 
14 14 14 14 
8 8 8 

```


#### Tags 

#2500 #NOT OK #binary_search #data_structures #graphs #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
