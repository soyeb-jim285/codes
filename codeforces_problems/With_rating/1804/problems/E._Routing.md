<h1 style='text-align: center;'> E. Routing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ada operates a network that consists of $n$ servers and $m$ direct connections between them. Each direct connection between a pair of distinct servers allows bidirectional transmission of information between these two servers. Ada knows that these $m$ direct connections allow to directly or indirectly transmit information between any two servers in this network. We say that server $v$ is a neighbor of server $u$ if there exists a direct connection between these two servers.

Ada needs to configure her network's WRP (Weird Routing Protocol). For each server $u$ she needs to select exactly one of its neighbors as an auxiliary server $a(u)$. After all $a(u)$ are set, routing works as follows. Suppose server $u$ wants to find a path to server $v$ (different from $u$). 

1. Server $u$ checks all of its direct connections to other servers. If it sees a direct connection with server $v$, it knows the path and the process terminates.
2. If the path was not found at the first step, server $u$ asks its auxiliary server $a(u)$ to find the path.
3. Auxiliary server $a(u)$ follows this process starting from the first step.
4. After $a(u)$ finds the path, it returns it to $u$. Then server $u$ constructs the resulting path as the direct connection between $u$ and $a(u)$ plus the path from $a(u)$ to $v$.

As you can see, this procedure either produces a correct path and finishes or keeps running forever. Thus, it is critically important for Ada to configure her network's WRP properly.

Your goal is to assign an auxiliary server $a(u)$ for each server $u$ in the given network. Your assignment should make it possible to construct a path from any server $u$ to any other server $v$ using the aforementioned procedure. Or you should report that such an assignment doesn't exist.

###### Input

The first line of the input contains two integers $n$ and $m$ ($2 \leq n \leq 20$, $n - 1 \leq m \leq \frac{n \cdot (n - 1)}{2}$) — the number of servers and the number of direct connections in the given network.

Then follow $m$ lines containing two integers $u_i$ and $v_i$ ($1 \leq u_i, v_i \leq n$, $u_i \ne v_i$) each, the $i$-th line describes the $i$-th direct connection.

It is guaranteed that there is no more than one direct connection between any two servers. It is guaranteed that there is a direct or indirect route (consisting only of the given direct connections) between any two servers.

###### Output

If there is no way to assign an auxiliary server $a(u)$ for each server $u$ in such a way that WRP will be able to find a path from any server $u$ to any other server $v$, print "No" in the only line of the output.

Otherwise, print "Yes" in the first line of the output. In the second line of the output print $n$ integers, the $i$-th of these integers should be equal to $a(i)$ – the index of the auxiliary server for server $i$. Do not forget that there must be a direct connection between server $i$ and server $a(i)$.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Examples

###### Input


```text
6 7
1 2
2 3
3 1
4 5
5 6
4 6
2 5
```
###### Output


```text
Yes
2 5 2 5 2 5
```
###### Input


```text
3 2
1 2
2 3
```
###### Output


```text
Yes
2 1 2
```
###### Input


```text
4 4
1 3
2 3
4 1
4 2
```
###### Output


```text
Yes
3 3 1 1
```
###### Input


```text
6 5
1 2
2 3
3 4
4 5
5 6
```
###### Output


```text
No
```


#### Tags 

#2400 #NOT OK #bitmasks #brute_force #dfs_and_similar #dp #graphs 

## Blogs
- [All Contest Problems](../Nebius_Welcome_Round_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
