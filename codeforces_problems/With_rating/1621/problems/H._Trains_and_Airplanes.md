<h1 style='text-align: center;'> H. Trains and Airplanes</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Railway network of one city consists of $n$ stations connected by $n-1$ roads. These stations and roads forms a tree. Station $1$ is a city center. For each road you know the time trains spend to pass this road. You can assume that trains don't spend time on stops. Let's define $dist(v)$ as the time that trains spend to get from the station $v$ to the station $1$.

This railway network is splitted into zones named by first $k$ capital latin letters. The zone of the $i$-th station is $z_i$. City center is in the zone A. For all other stations it is guaranteed that the first station on the road from this station to the city center is either in the same zone or in the zone with lexicographically smaller name. Any road is completely owned by the zone of the most distant end from the city center.

Tourist will arrive at the airport soon and then he will go to the city center. Here's how the trip from station $v$ to station $1$ happends: 

* At the moment $0$, tourist enters the train that follows directly from the station $v$ to the station $1$. The trip will last for $dist(v)$ minutes.
* Tourist can buy tickets for any subset of zones at any moment. Ticket for zone $i$ costs $pass_i$ euro.
* Every $T$ minutes since the start of the trip (that is, at the moments $T, 2T, \ldots$) the control system will scan tourist. If at the moment of scan tourist is in the zone $i$ without zone $i$ ticket, he should pay $fine_i$ euro. Formally, the zone of tourist is determined in the following way:
	+ If tourist is at the station $1$, then he already at the city center so he shouldn't pay fine.
	+ If tourist is at the station $u \neq 1$, then he is in the zone $z_u$.
	+ If tourist is moving from the station $x$ to the station $y$ that are directly connected by road, then he is in the zone $z_x$. 
## Note

, that tourist can pay fine multiple times in the same zone.

Tourist always selects such way to buy tickets and pay fines that minimizes the total cost of trip. Let $f(v)$ be such cost for station $v$.

Unfortunately, tourist doesn't know the current values of $pass_i$ and $fine_i$ for different zones and he has forgot the location of the airport. He will ask you queries of $3$ types:

* $1$ $i$ $c$ — the cost of ticket in zone $i$ has changed. Now $pass_i$ is $c$.
* $2$ $i$ $c$ — the cost of fine in zone $i$ has changed. Now $fine_i$ is $c$.
* $3$ $u$ — solve the following problem for current values of $pass$ and $fine$:
	+ You are given the station $u$. Consider all the stations $v$ that satisfy the following conditions:
		- $z_v = z_u$
		- The station $u$ is on the path from the station $v$ to the station $1$. Find the value of $\min(f(v))$ over all such stations $v$ with the following assumption: tourist has the ticket for the zone of station $z_u$.
### Input

The first line contains the single integer $n$ ($2 \leq n \leq 2 \cdot 10^5$) — the number of stations.

Each of the next $n - 1$ lines contains three integers $v_i$, $u_i$, $t_i$ ($1 \leq v_i, u_i \leq n, 1 \leq t_i \leq 10^9$) — the ends of the $i$-th road and the time it takes a train to pass this road. It is guaranteed that this roads forms a tree.

The next line contains the single integer $k$ ($1 \leq k \leq 26$) — the number of zones.

The next line contains $n$ symbols $z_1z_2 \ldots z_n$ — $z_i$ is the name of the zone of the $i$-th station. It is guaranteed that the conditions from the second paragraph are satisfied.

The next line contains $k$ integers $pass_1$, $pass_2$, $\ldots$, $pass_k$ ($1 \leq pass_i \leq 10^9$) — initial costs of tickets.

The next line contains $k$ integers $fine_1$, $fine_2$, $\ldots$, $fine_k$ ($1 \leq fine_i \leq 10^9$) — initial fines.

The next line contains the single integer $T$ ($1 \leq T \leq 10^9$) — the time gap between scans of control system.

The next line contains the single integer $q$ ($1 \leq q \leq 2 \cdot 10^5$) — the number of queries.

Next $q$ lines contains queries as described in the statement. It is guaranteed that in the queries of the first and the second type $i$ is a correct name of the zone (one of the first $k$ capital latin letters) and $1 \leq c \leq 10^9$, and in the queries of the third type $1 \leq u \leq n$.

### Output

For each query of the third type print the answer to it.

## Example

### Input


```text
8
1 2 7
2 3 4
2 4 3
4 5 1
5 6 6
4 7 10
6 8 6
4
AABABBDB
11 12 10 42
16 15 15 30
4
6
3 2
1 A 10
3 3
2 A 3
3 7
3 6
```
### Output


```text
0
10
6
6
```
## Note

## Note

, that the fine can be cheaper than the pass.

 ![](images/4ab3919d8b1770894a43b03b4881c6598c667543.png) The railway network from the example. Green color is used for stations and roads of zone A, blue color is used for zone B and red color is used for zone D. The integer near each road is time that trains spend to pass it. In the first query, the airport can be located near the station $2$ or near the station $4$. During the trip, tourist will always stay in the zone A. He already has the pass for this zone so the answer is $0$.

After the second query, the cost of the pass in the zone A has become $10$.

In the third query, the airport can be located only near the station $3$. Optimal solution will be to buy the pass for zone A. During the first $3$ seconds of trip tourist will be in the zone B. Then he will move to the zone A and will be scanned there on the $4$-th and the $8$-th second of his ride. Since he have a pass for this zone, he won't pay fines.

After the forth query, the fine in the zone A has become $3$.

In the fifth query, the airport can be located only near the station $7$ and $f(7) = 6$.

In the sixth query, the airport can be located near the station $6$ or near the station $8$. Since $f(6)=9$ and $f(8)=6$ the answer is $6$.



#### Tags 

#3500 #NOT OK #dfs_and_similar #graphs #shortest_paths #trees 

## Blogs
- [All Contest Problems](../Hello_2022.md)
- [Hello 2022](../blogs/Hello_2022.md)
- [Hello 2022 Editorial (en)](../blogs/Hello_2022_Editorial_(en).md)
