<h1 style='text-align: center;'> B. Watering System</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady wants to water his only flower. Unfortunately, he has a very poor watering system that was designed for $n$ flowers and so it looks like a pipe with $n$ holes. Arkady can only use the water that flows from the first hole.

Arkady can block some of the holes, and then pour $A$ liters of water into the pipe. After that, the water will flow out from the non-blocked holes proportionally to their sizes $s_1, s_2, \ldots, s_n$. In other words, if the sum of sizes of non-blocked holes is $S$, and the $i$-th hole is not blocked, $\frac{s_i \cdot A}{S}$ liters of water will flow out of it.

What is the minimum number of holes Arkady should block to make at least $B$ liters of water flow out of the first hole?

##### Input

The first line contains three integers $n$, $A$, $B$ ($1 \le n \le 100\,000$, $1 \le B \le A \le 10^4$) — the number of holes, the volume of water Arkady will pour into the system, and the volume he wants to get out of the first hole.

The second line contains $n$ integers $s_1, s_2, \ldots, s_n$ ($1 \le s_i \le 10^4$) — the sizes of the holes.

##### Output

Print a single integer — the number of holes Arkady should block.

## Examples

##### Input


```text
4 10 3  
2 2 2 2  

```
##### Output


```text
1  

```
##### Input


```text
4 80 20  
3 2 1 4  

```
##### Output


```text
0  

```
##### Input


```text
5 10 10  
1000 1 1 1 1  

```
##### Output


```text
4  

```
## Note

In the first example Arkady should block at least one hole. After that, $\frac{10 \cdot 2}{6} \approx 3.333$ liters of water will flow out of the first hole, and that suits Arkady.

In the second example even without blocking any hole, $\frac{80 \cdot 3}{10} = 24$ liters will flow out of the first hole, that is not less than $20$.

In the third example Arkady has to block all holes except the first to make all water flow out of the first hole.



#### Tags 

#1000 #NOT OK #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_477_(rated,_Div._2,_based_on_VK_Cup_2018_Round_3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
