<h1 style='text-align: center;'> B. Customising the Track</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Highway 201 is the most busy street in Rockport. Traffic cars cause a lot of hindrances to races, especially when there are a lot of them. The track which passes through this highway can be divided into $n$ sub-tracks. You are given an array $a$ where $a_i$ represents the number of traffic cars in the $i$-th sub-track. You define the inconvenience of the track as $\sum\limits_{i=1}^{n} \sum\limits_{j=i+1}^{n} \lvert a_i-a_j\rvert$, where $|x|$ is the absolute value of $x$. 

You can perform the following operation any (possibly zero) number of times: choose a traffic car and move it from its current sub-track to any other sub-track.

Find the minimum inconvenience you can achieve.

### Input

The first line of input contains a single integer $t$ ($1\leq t\leq 10\,000$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1\leq n\leq 2\cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0\leq a_i\leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, print a single line containing a single integer: the minimum inconvenience you can achieve by applying the given operation any (possibly zero) number of times.

## Example

### Input


```text
3
3
1 2 3
4
0 1 1 0
10
8 3 6 11 5 2 1 7 10 4
```
### Output


```text
0
4
21
```
## Note

For the first test case, you can move a car from the $3$-rd sub-track to the $1$-st sub-track to obtain $0$ inconvenience.

For the second test case, moving any car won't decrease the inconvenience of the track.



#### Tags 

#900 #NOT OK #combinatorics #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_730_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
