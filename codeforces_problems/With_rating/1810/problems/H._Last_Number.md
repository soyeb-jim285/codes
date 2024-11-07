<h1 style='text-align: center;'> H. Last Number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a multiset $S$. Initially, $S = \{1,2,3, \ldots, n\}$.

You will perform the following operation $n-1$ times.

* Choose the largest number $S_{\text{max}}$ in $S$ and the smallest number $S_{\text{min}}$ in $S$. Remove the two numbers from $S$, and add $S_{\text{max}} - S_{\text{min}}$ into $S$.

It's easy to show that there will be exactly one number left after $n-1$ operations. 
### Output

 that number.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Their description follows.

For each test case, one single line contains a single integer $n$ ($2 \le n \le 10^9$) — the initial size of the multiset $S$.

### Output

For each test case, output an integer denoting the only number left after $n-1$ operations.

## Example

### Input


```text
524715177567
```
### Output

```text

1
2
2
4
33914

```
## Note

We show how the multiset $S$ changes for $n=4$.

* Operation $1$: $S=\{1,2,3,4\}$, remove $4$, $1$, add $3$.
* Operation $2$: $S=\{2,3,3\}$, remove $3$, $2$, add $1$.
* Operation $3$: $S=\{1,3\}$, remove $3$, $1$, add $2$.
* Final: $S = \{2\}$.

Thus, the answer for $n = 4$ is $2$.



#### Tags 

#2900 #NOT OK #combinatorics #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_4_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
