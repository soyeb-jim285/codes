<h1 style='text-align: center;'> D. Phoenix and Socks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

To satisfy his love of matching socks, Phoenix has brought his $n$ socks ($n$ is even) to the sock store. Each of his socks has a color $c_i$ and is either a left sock or right sock. 

Phoenix can pay one dollar to the sock store to either: 

* recolor a sock to any color $c'$ $(1 \le c' \le n)$
* turn a left sock into a right sock
* turn a right sock into a left sock

 The sock store may perform each of these changes any number of times. ## Note

 that the color of a left sock doesn't change when it turns into a right sock, and vice versa. 

A matching pair of socks is a left and right sock with the same color. What is the minimum cost for Phoenix to make $n/2$ matching pairs? Each sock must be included in exactly one matching pair.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains three integers $n$, $l$, and $r$ ($2 \le n \le 2 \cdot 10^5$; $n$ is even; $0 \le l, r \le n$; $l+r=n$) — the total number of socks, and the number of left and right socks, respectively.

The next line contains $n$ integers $c_i$ ($1 \le c_i \le n$) — the colors of the socks. The first $l$ socks are left socks, while the next $r$ socks are right socks.

It is guaranteed that the sum of $n$ across all the test cases will not exceed $2 \cdot 10^5$.

## Output

For each test case, print one integer — the minimum cost for Phoenix to make $n/2$ matching pairs. Each sock must be included in exactly one matching pair.

## Example

## Input


```

4
6 3 3
1 2 3 2 2 2
6 2 4
1 1 2 2 2 2
6 5 1
6 5 4 3 2 1
4 0 4
4 4 4 3

```
## Output


```

2
3
5
3

```
## Note

In the first test case, Phoenix can pay $2$ dollars to: 

* recolor sock $1$ to color $2$
* recolor sock $3$ to color $2$

 There are now $3$ matching pairs. For example, pairs $(1, 4)$, $(2, 5)$, and $(3, 6)$ are matching.In the second test case, Phoenix can pay $3$ dollars to: 

* turn sock $6$ from a right sock to a left sock
* recolor sock $3$ to color $1$
* recolor sock $4$ to color $1$

 There are now $3$ matching pairs. For example, pairs $(1, 3)$, $(2, 4)$, and $(5, 6)$ are matching.

#### tags 

#1500 #greedy #sortings #two_pointers 