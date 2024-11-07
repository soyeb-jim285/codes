<h1 style='text-align: center;'> H. Moving Walkways</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Airports often use moving walkways to help you walking big distances faster. Each such walkway has some speed that effectively increases your speed. You can stand on such a walkway and let it move you, or you could also walk and then your effective speed is your walking speed plus walkway's speed.

Limak wants to get from point $0$ to point $L$ on a straight line. There are $n$ disjoint walkways in between. The $i$-th walkway is described by two integers $x_i$ and $y_i$ and a real value $s_i$. The $i$-th walkway starts at $x_i$, ends at $y_i$ and has speed $s_i$. 

Every walkway is located inside the segment $[0, L]$ and no two walkways have positive intersection. However, they can touch by endpoints.

Limak needs to decide how to distribute his energy. For example, it might make more sense to stand somewhere (or to walk slowly) to then have a lot of energy to walk faster.

Limak's initial energy is $0$ and it must never drop below that value. At any moment, he can walk with any speed $v$ in the interval $[0, 2]$ and it will cost him $v$ energy per second, but he continuously recovers energy with speed of $1$ energy per second. So, when he walks with speed $v$, his energy increases by $(1-v)$. 
## Note

 that negative value would mean losing energy.

In particular, he can walk with speed $1$ and this won't change his energy at all, while walking with speed $0.77$ effectively gives him $0.23$ energy per second.

Limak can choose his speed arbitrarily (any real value in interval $[0, 2]$) at every moment of time (including the moments when he is located on non-integer positions). Everything is continuous (non-discrete).

What is the fastest time Limak can get from $0$ to $L$?

##### Input

The first line contains integers $n$ and $L$ ($1 \le n \le 200\,000$, $1 \le L \le 10^9$), the number of walkways and the distance to walk.

Each of the next $n$ lines contains integers $x_i$, $y_i$ and real value $s_i$ ($0 \le x_i < y_i \le L$, $0.1 \le s_i \le 10.0$). The value $s_i$ is given with at most $9$ digits after decimal point.

It's guaranteed, that no two walkways have a positive intersection. The walkways are listed from left to right. That is, $y_i \le x_{i + 1}$ for $1 \le i \le n - 1$.

##### Output

Print one real value, the fastest possible time to reach $L$. Your answer will be considered correct if its absolute or relative error won't exceed $10^{-9}$.

## Examples

##### Input


```text
1 5
0 2 2.0
```
##### Output


```text
3.000000000000
```
##### Input


```text
1 5
2 4 0.91
```
##### Output


```text
3.808900523560
```
##### Input


```text
3 1000
0 990 1.777777
995 996 1.123456789
996 1000 2.0
```
##### Output


```text
361.568848429553
```
## Note

The drawings show the first two examples. In the first one, there is a walkway from $0$ to $2$ with speed $2.0$ and Limak wants to get to point $5$. The second example has a walkway from $2$ to $4$ with speed $0.91$.

 ![](images/17fbff67d5963ecf551eb5bb2e166242f24e7554.png) In the first example, one of optimal strategies is as follows.

* Get from $0$ to $2$ by standing still on the walkway. It moves you with speed $2$ so it takes $1$ second and you save up $1$ energy.
* Get from $2$ to $4$ by walking with max speed $2$ for next $1$ second. It takes $1$ second again and the energy drops to $0$.
* Get from $4$ to $5$ by walking with speed $1$. It takes $1$ second and the energy stays constant at the value $0$.

The total time is $1 + 1 + 1 = 3$.



#### Tags 

#3300 #NOT OK #data_structures #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_584_-_Dasha_Code_Championship_-_Elimination_Round_(rated,_open_for_everyone,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
