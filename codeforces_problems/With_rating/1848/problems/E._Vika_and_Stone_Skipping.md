<h1 style='text-align: center;'> E. Vika and Stone Skipping</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Vika's hometown, Vladivostok, there is a beautiful sea.

Often you can see kids skimming stones. This is the process of throwing a stone into the sea at a small angle, causing it to fly far and bounce several times off the water surface.

Vika has skimmed stones many times and knows that if you throw a stone from the shore perpendicular to the coastline with a force of $f$, it will first touch the water at a distance of $f$ from the shore, then bounce off and touch the water again at a distance of $f - 1$ from the previous point of contact. The stone will continue to fly in a straight line, reducing the distances between the points where it touches the water, until it falls into the sea.

Formally, the points at which the stone touches the water surface will have the following coordinates: $f$, $f + (f - 1)$, $f + (f - 1) + (f - 2)$, ... , $f + (f - 1) + (f - 2) + \ldots + 1$ (assuming that $0$ is the coordinate of the shoreline).

Once, while walking along the embankment of Vladivostok in the evening, Vika saw a group of guys skipping stones across the sea, launching them from the same point with different forces.

She became interested in what is the maximum number of guys who can launch a stone with their force $f_i$, so that all $f_i$ are different positive integers, and all $n$ stones touched the water at the point with the coordinate $x$ (assuming that $0$ is the coordinate of the shoreline).

After thinking a little, Vika answered her question. After that, she began to analyze how the answer to her question would change if she multiplied the coordinate $x$ by some positive integers $x_1$, $x_2$, ... , $x_q$, which she picked for analysis.

Vika finds it difficult to cope with such analysis on her own, so she turned to you for help.

Formally, Vika is interested in the answer to her question for the coordinates $X_1 = x \cdot x_1$, $X_2 = X_1 \cdot x_2$, ... , $X_q = X_{q-1} \cdot x_q$. Since the answer for such coordinates can be quite large, find it modulo $M$. It is guaranteed that $M$ is prime.

##### Input

The first line of the input contains three integers $x$ ($1 \le x \le 10^9$), $q$ ($1 \le q \le 10^5$) and $M$ ($100 \le M \le 2 \cdot 10^9$) — the initial coordinate for which Vika answered the question on her own, the number of integers $x_i$ by which Vika will multiply the initial coordinate and prime module $M$.

The second line of the input contains $q$ integers $x_1, x_2, x_3, \ldots, x_q$ ($1 \le x_i \le 10^6$) — the integers described in the statement.

##### Output

##### Output

 $q$ integers, where the $i$-th number corresponds to the answer to Vika's question for the coordinate $X_i$. 
##### Output

 all the answers modulo $M$.

## Examples

##### Input


```text
1 2 179
2 3
```
##### Output


```text
1
2
```
##### Input


```text
7 5 998244353
2 13 1 44 179
```
##### Output


```text
2
4
4
8
16
```
##### Input


```text
1000000000 10 179
58989 49494 8799 9794 97414 141241 552545 145555 548959 774175
```
##### Output


```text
120
4
16
64
111
43
150
85
161
95
```
## Note

In the first sample, to make the stone touch the water at a point with coordinate $2$, it needs to be thrown with a force of $2$. To make the stone touch the water at a point with coordinate $2 \cdot 3 = 6$, it needs to be thrown with a force of $3$ or $6$.

In the second sample, you can skim a stone with a force of $5$ or $14$ to make it touch the water at a point with coordinate $7 \cdot 2 = 14$. For the coordinate $14 \cdot 13 = 182$, there are $4$ possible forces: $20$, $29$, $47$, $182$.



#### Tags 

#2600 #NOT OK #brute_force #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_885_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
