<h1 style='text-align: center;'> B. Vaccination</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ethan runs a vaccination station to help people combat the seasonal flu. He analyses the historical data in order to develop an optimal strategy for vaccine usage.

Consider there are $n$ patients coming to the station on a particular day. The $i$-th patient comes at the moment $t_i$. We know that each of these patients can be asked to wait for no more than $w$ time moments. That means the $i$-th patient can get vaccine at moments $t_i, t_i + 1, \ldots, t_i + w$.

Vaccines come in packs, each pack consists of $k$ doses. Each patient needs exactly one dose. Packs are stored in a special fridge. After a pack is taken out of the fridge and opened, it can no longer be put back. The lifetime of the vaccine outside the fridge is $d$ moments of time. Thus, if the pack was taken out of the fridge and opened at moment $x$, its doses can be used to vaccinate patients at moments $x, x + 1, \ldots, x + d$. At moment $x + d + 1$ all the remaining unused doses of this pack are thrown away.

Assume that the vaccination station has enough staff to conduct an arbitrary number of operations at every moment of time. What is the minimum number of vaccine packs required to vaccinate all $n$ patients?

### Input

The first line of the input contains the number of test cases $t$ ($1 \leq t \leq 10^4$). Then follow $t$ descriptions of the test cases.

The first line of each test case contains four integers $n$, $k$, $d$ and $w$ ($1 \leq n, k \leq 2 \cdot 10^5$, $0 \leq d, w \leq 10^6$). They are the number of patients, the number of doses per vaccine pack, the number of moments of time the vaccine can live outside the fridge, and the number of moments of time each of the patients can wait, respectively.

The second line of each test case contains a non-decreasing sequence $t_1, t_2, \ldots, t_n$ ($0 \leq t_1 \leq t_2 \leq \ldots \leq t_n \leq 10^6$). The $i$-th element of this sequence is the moment when the $i$-th patient comes to the vaccination station.

It is guaranteed that the sum of $n$ over all test cases won't exceed $2 \cdot 10^5$.

### Output

### Output

 one integer, the minimum number of vaccine packs required to vaccinate all $n$ patients.

## Example

### Input


```text
56 3 5 31 2 3 10 11 186 4 0 03 3 3 3 3 49 10 2 20 1 2 3 4 5 6 7 83 10 3 610 20 305 5 4 40 2 4 6 8
```
### Output

```text

2
3
2
3
1

```
## Note

In the first example, the first pack can be opened at moment $1$ to vaccinate patient $1$. The vaccine is durable enough to be used at moments $2$ and $3$ for patients $2$ and $3$, respectively. Then the staff needs to ask patients $4$ and $5$ to wait for moment $13$. At moment $13$ the staff opens the second vaccine pack and serves patients $4$ and $5$. Finally, the last patient comes at moment $18$ and immediately gets the last dose of the second pack while it is still fine.

In the second example, the vaccine should be used exactly at the moment it is taken out of the fridge. Moreover, all the patients want to be served at exactly the same moment they come. That means the staff needs to open two packs at moment $3$ and use five doses on patients $1$, $2$, $3$, $4$, and $5$. There will be three doses left ouf of these two packs but they can't be used for patient $6$. When patient $6$ comes at moment $4$ the staff needs to open a new pack just to use only one dose out of it.



#### Tags 

#1000 #NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Nebius_Welcome_Round_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
