<h1 style='text-align: center;'> E. The Ultimate LIS Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It turns out that this is exactly the $100$-th problem of mine that appears in some programming competition. So it has to be special! And what can be more special than another problem about LIS...

You are given a permutation $p_1, p_2, \ldots, p_{2n+1}$ of integers from $1$ to $2n+1$. You will have to process $q$ updates, where the $i$-th update consists in swapping $p_{u_i}, p_{v_i}$.

After each update, find any cyclic shift of $p$ with $LIS \le n$, or determine that there is no such shift. (Refer to the output section for details).

Here $LIS(a)$ denotes the length of [longest strictly increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) of $a$.

Hacks are disabled in this problem. Don't ask why.

### Input

The first line of the input contains two integers $n, q$ ($2 \le n \le 10^5$, $1 \le q \le 10^5$).

The second line of the input contains $2n+1$ integers $p_1, p_2, \ldots, p_{2n+1}$ ($1 \le p_i \le 2n+1$, all $p_i$ are distinct)  — the elements of $p$.

The $i$-th of the next $q$ lines contains two integers $u_i, v_i$ ($1 \le u_i, v_i \le 2n+1$, $u_i \neq v_i$)  — indicating that you have to swap elements $p_{u_i}, p_{v_i}$ in the $i$-th update.

### Output

After each update, output any $k$ $(0 \le k \le 2n)$, such that the length of the longest increasing subsequence of $(p_{k+1}, p_{k+2}, \ldots, p_{2n+1}, p_1, \ldots, p_k)$ doesn't exceed $n$, or $-1$, if there is no such $k$.

## Example

### Input


```text
2 6
1 2 3 4 5
1 5
1 5
4 5
5 4
1 4
2 5
```
### Output


```text
-1
-1
2
-1
4
0
```
## Note

After the first update, our permutation becomes $(5, 2, 3, 4, 1)$. We can show that all its cyclic shifts have $LIS \ge 3$.

After the second update, our permutation becomes $(1, 2, 3, 4, 5)$. We can show that all its cyclic shifts have $LIS \ge 3$.

After the third update, our permutation becomes $(1, 2, 3, 5, 4)$. Its shift by $2$ is $(3, 5, 4, 1, 2)$, and its $LIS = 2$.

After the fourth update, our permutation becomes $(1, 2, 3, 4, 5)$. We can show that all its cyclic shifts have $LIS \ge 3$.

After the fifth update, our permutation becomes $(4, 2, 3, 1, 5)$. Its shift by $4$ is $(5, 4, 2, 3, 1)$, and its $LIS = 2$.

After the fifth update, our permutation becomes $(4, 5, 3, 1, 2)$. Its shift by $0$ is $(4, 5, 3, 1, 2)$, and its $LIS = 2$.



#### Tags 

#3500 #NOT OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_794_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
