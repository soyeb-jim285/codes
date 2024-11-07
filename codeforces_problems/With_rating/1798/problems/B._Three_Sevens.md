<h1 style='text-align: center;'> B. Three Sevens</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lottery "Three Sevens" was held for $m$ days. On day $i$, $n_i$ people with the numbers $a_{i, 1}, \ldots, a_{i, n_i}$ participated in the lottery.

It is known that in each of the $m$ days, only one winner was selected from the lottery participants. The lottery winner on day $i$ was not allowed to participate in the lottery in the days from $i+1$ to $m$.

Unfortunately, the information about the lottery winners has been lost. You need to find any possible list of lottery winners on days from $1$ to $m$ or determine that no solution exists.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 50\,000$). The description of the test cases follows.

The first line of each test case contains a single integer $m$ ($1 \le m \le 50\,000$) — the number of days in which the lottery was held.

Next, for each $i$ from $1$ to $m$, follows a two-line block of data.

The first line of each block contains a single integer $n_i$ ($1 \le n_i \le 50\,000$) — the number of lottery participants on day $i$.

The second line of the block contains integers $a_{i, 1}, \ldots, a_{i, n_i}$ ($1 \le a_{i, j} \le 50\,000$) — lottery participants on day $i$. It is guaranteed that all the numbers $a_{i, 1}, \ldots, a_{i, n_i}$ are pairwise distinct.

It is guaranteed that the sum of $n_i$ over all blocks of all test cases does not exceed $50\,000$.

### Output

For each test case, if there is no solution, print a single integer $-1$.

Otherwise, print $m$ integers $p_1, p_2, \ldots, p_m$ ($1 \le p_i \le 50\,000$) — lottery winners on days from $1$ to $m$. If there are multiple solutions, print any of them.

## Example

### Input


```text
3341 2 4 832 9 121 4221 222 1441 2 3 4111413
```
### Output

```text

8 2 1 
-1
2 1 4 3 

```
## Note

In the first test case, one of the answers is $[8, 2, 1]$ since the participant with the number $8$ participated on day $1$, but did not participate on days $2$ and $3$; the participant with the number $2$ participated on day $2$, but did not participate on day $3$; and the participant with the number $1$ participated on day $3$. 
## Note

 that this is not the only possible answer, for example, $[8, 9, 4]$ is also a correct answer.

In the second test case, both lottery participants participated on both days, so any possible lottery winner on the day $1$ must have participated on the day $2$, which is not allowed. Thus, there is no correct answer.

In the third test case, only one participant participated on days $2$, $3$, $4$, and on day $1$ there is only one participant who did not participate in the lottery on days $2, 3, 4$ — participant $2$, which means $[2, 1, 4, 3]$ is the only correct answer to this test case.



#### Tags 

#1000 #OK #brute_force #data_structures #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_860_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
