<h1 style='text-align: center;'> A. Packets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $n$ coins, each of the same value of $1$.

Distribute them into packets such that any amount $x$ ($1 \leq x \leq n$) can be formed using some (possibly one or all) number of these packets.

Each packet may only be used entirely or not used at all. No packet may be used more than once in the formation of the single $x$, however it may be reused for the formation of other $x$'s.

Find the minimum number of packets in such a distribution.

#### Input

The only line contains a single integer $n$ ($1 \leq n \leq 10^9$) — the number of coins you have.

#### Output

#### Output

 a single integer — the minimum possible number of packets, satisfying the condition above.

## Examples

#### Input


```text
6  

```
#### Output


```text
3
```
#### Input


```text
2  

```
#### Output


```text
2
```
## Note

In the first example, three packets with $1$, $2$ and $3$ coins can be made to get any amount $x$ ($1\leq x\leq 6$).

* To get $1$ use the packet with $1$ coin.
* To get $2$ use the packet with $2$ coins.
* To get $3$ use the packet with $3$ coins.
* To get $4$ use packets with $1$ and $3$ coins.
* To get $5$ use packets with $2$ and $3$ coins
* To get $6$ use all packets.

In the second example, two packets with $1$ and $1$ coins can be made to get any amount $x$ ($1\leq x\leq 2$).



#### Tags 

#1300 #NOT OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Manthan,_Codefest_18_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
