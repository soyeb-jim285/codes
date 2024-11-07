<h1 style='text-align: center;'> C. Basic Diplomacy</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Aleksey has $n$ friends. He is also on a vacation right now, so he has $m$ days to play this new viral cooperative game! But since it's cooperative, Aleksey will need one teammate in each of these $m$ days.

On each of these days some friends will be available for playing, and all others will not. On each day Aleksey must choose one of his available friends to offer him playing the game (and they, of course, always agree). However, if any of them happens to be chosen strictly more than $\left\lceil\dfrac{m}{2}\right\rceil$ times, then all other friends are offended. Of course, Aleksey doesn't want to offend anyone.

Help him to choose teammates so that nobody is chosen strictly more than $\left\lceil\dfrac{m}{2}\right\rceil$ times.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1\leq n, m\leq 100\,000$) standing for the number of friends and the number of days to play, respectively.

The $i$-th of the following $m$ lines contains an integer $k_i$ ($1\leq k_i\leq n$), followed by $k_i$ distinct integers $f_{i1}$, ..., $f_{ik_i}$ ($1\leq f_{ij}\leq n$), separated by spaces — indices of available friends on the day $i$.

It is guaranteed that the sums of $n$ and $m$ over all test cases do not exceed $100\,000$. It's guaranteed that the sum of all $k_i$ over all days of all test cases doesn't exceed $200\,000$.

### Output

Print an answer for each test case. If there is no way to achieve the goal, print "NO".

Otherwise, in the first line print "YES", and in the second line print $m$ space separated integers $c_1$, ..., $c_m$. Each $c_i$ must denote the chosen friend on day $i$ (and therefore must be one of $f_{ij}$).

No value must occur more than $\left\lceil\dfrac{m}{2}\right\rceil$ times. If there is more than one possible answer, print any of them.

## Example

### Input


```text
2
4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 3
2 2
1 1
1 1
```
### Output


```text
YES
1 2 1 1 2 3 
NO
```


#### Tags 

#1600 #NOT OK #brute_force #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Технокубок_2021_-_Финал.md)
- [Tutorial](../blogs/Tutorial.md)
