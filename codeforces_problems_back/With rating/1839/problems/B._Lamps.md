<h1 style='text-align: center;'> B. Lamps</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $n$ lamps, numbered by integers from $1$ to $n$. Each lamp $i$ has two integer parameters $a_i$ and $b_i$.

At each moment each lamp is in one of three states: it may be turned on, turned off, or broken.

Initially all lamps are turned off. In one operation you can select one lamp that is turned off and turn it on (you can't turn on broken lamps). You receive $b_i$ points for turning lamp $i$ on. The following happens after each performed operation: 

* Let's denote the number of lamps that are turned on as $x$ (broken lamps do not count). All lamps $i$ such that $a_i \le x$ simultaneously break, whether they were turned on or off.

Please note that broken lamps never count as turned on and that after a turned on lamp breaks, you still keep points received for turning it on.

You can perform an arbitrary number of operations.

Find the maximum number of points you can get.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of lamps.

Each of the next $n$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i \le n, 1 \le b_i \le 10^9$) — parameters of the $i$-th lamp.

It is guaranteed that sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, output one integer — the maximum number of points you can get.

## Example

## Input


```

442 21 61 101 1353 43 12 53 23 361 23 41 43 43 52 311 1
```
## Output


```

15
14
20
1

```
## Note

In first test case $n = 4$. One of ways to get the maximum number of points is as follows: 

* You turn lamp $4$ on and receive $b_4 = 13$ points.
* The number of lamps that are turned on is $1$, so all lamps with $a_i \le 1$ (namely lamps $2$, $3$ and $4$) break. Lamp $4$ is no longer turned on, so the number of lamps that are turned becomes $0$.
* The only lamp you can turn on is lamp $1$, as all other lamps are broken. You receive $b_1 = 2$ points for turning it on.
* The number of lamps that are turned on is $1$. As $a_1 = 2$, lamp $1$ doesn't break.

Your receive $13 + 2 = 15$ points in total. It can be shown that this is the maximum number of points you can get, so the answer for the first test case is $15$.

In the second test case, one of the ways to get the maximum number of points is as follows:

* On the first operation you turn on lamp $4$ and receive $2$ points. No lamps break after the first operation.
* On the second operation you turn on lamp $3$ and receive $5$ points. After the second operation, there are $2$ lamps turned on. As $a_3 \le 2$, lamp $3$ breaks.
* On the third operation, you turn on lamp $1$ and receive $4$ points.
* On the fourth operation, you turn on lamp $5$ and receive $3$ points. After that there are $3$ lamps turned on: lamps $1$, $4$ and $5$. Lamps $1$, $2$, $4$ and $5$ simultaneously break, because for all of them $a_i \le 3$.

You receive $2 + 5 + 4 + 3 = 14$ points in total. It can be shown that this is the maximum number of points you can get.

In the third test case, one of the ways to get the maximum number of points is as follows:

* Turn the lamp $3$ on and receive $4$ points. Lamps $1$ and $3$ break.
* Turn the lamp $2$ on and receive $4$ points.
* Turn the lamp $6$ on and receive $3$ points. Lamp $6$ breaks.
* Turn the lamp $4$ on and receive $4$ points.
* Turn the lamp $5$ on and receive $5$ points. Lamps $2$, $4$ and $5$ break.

You receive $4 + 4 + 3 + 4 + 5 = 20$ points in total. It can be shown that this is the maximum number of points you can get.



#### tags 

#1100 #greedy #sortings 