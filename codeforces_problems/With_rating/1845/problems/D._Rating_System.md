<h1 style='text-align: center;'> D. Rating System</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are developing a rating system for an online game. Every time a player participates in a match, the player's rating changes depending on the results.

Initially, the player's rating is $0$. There are $n$ matches; after the $i$-th match, the rating change is equal to $a_i$ (the rating increases by $a_i$ if $a_i$ is positive, or decreases by $|a_i|$ if it's negative. There are no zeros in the sequence $a$).

The system has an additional rule: for a fixed integer $k$, if a player's rating has reached the value $k$, it will never fall below it. Formally, if a player's rating at least $k$, and a rating change would make it less than $k$, then the rating will decrease to exactly $k$.

Your task is to determine the value $k$ in such a way that the player's rating after all $n$ matches is the maximum possible (among all integer values of $k$). If there are multiple possible answers, you can print any of them.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of matches.

The second line contains $n$ integer $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$; $a_i \ne 0$) — the rating change after the $i$-th match.

The sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print one integer $m$ ($-10^{18} \le m \le 10^{18}$) — the value of $k$ such that the rating of the player will be the maximum possible when using this value. It can be shown that at least one of the optimal answers meets the constraint $-10^{18} \le m \le 10^{18}$.

## Example

### Input


```text
443 -2 1 23-1 -2 -124 275 1 -3 2 -1 -2 2
```
### Output

```text

3
0
25
6

```
## Note

In the first example, if $k=3$, then the rating changes as follows: $0 \rightarrow 3 \rightarrow 3 \rightarrow 4 \rightarrow 6$.

In the second example, if $k=0$, then the rating changes as follows: $0 \rightarrow 0 \rightarrow 0 \rightarrow 0$.

In the third example, if $k=25$, then the rating changes as follows: $0 \rightarrow 4 \rightarrow 6$.

In the fourth example, if $k=6$, then the rating changes as follows: $0 \rightarrow 5 \rightarrow 6 \rightarrow 6 \rightarrow 8 \rightarrow 7 \rightarrow 6 \rightarrow 8$.



#### Tags 

#1800 #NOT OK #binary_search #brute_force #data_structures #dp #dsu #greedy #math #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_151_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
