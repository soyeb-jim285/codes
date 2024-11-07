<h1 style='text-align: center;'> F. Swimmers in the Pool</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a pool of length $l$ where $n$ swimmers plan to swim. People start swimming at the same time (at the time moment $0$), but you can assume that they take different lanes, so they don't interfere with each other.

Each person swims along the following route: they start at point $0$ and swim to point $l$ with constant speed (which is equal to $v_i$ units per second for the $i$-th swimmer). After reaching the point $l$, the swimmer instantly (in negligible time) turns back and starts swimming to the point $0$ with the same constant speed. After returning to the point $0$, the swimmer starts swimming to the point $l$, and so on.

Let's say that some real moment of time is a meeting moment if there are at least two swimmers that are in the same point of the pool at that moment of time (that point may be $0$ or $l$ as well as any other real point inside the pool).

The pool will be open for $t$ seconds. You have to calculate the number of meeting moments while the pool is open. Since the answer may be very large, print it modulo $10^9 + 7$.

## Input

The first line contains two integers $l$ and $t$ ($1 \le l, t \le 10^9$) — the length of the pool and the duration of the process (in seconds).

The second line contains the single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of swimmers.

The third line contains $n$ integers $v_1, v_2, \dots, v_n$ ($1 \le v_i \le 2 \cdot 10^5$), where $v_i$ is the speed of the $i$-th swimmer. All $v_i$ are pairwise distinct.

## Output

Print one integer — the number of meeting moments (including moment $t$ if needed and excluding moment $0$), taken modulo $10^9 + 7$.

## Examples

## Input


```

9 18
2
1 2

```
## Output


```

3

```
## Input


```

12 13
3
4 2 6

```
## Output


```

10

```
## Input


```

1 1000000000
3
100000 150000 200000

```
## Output


```

997200007

```
## Note

In the first example, there are three meeting moments:

* moment $6$, during which both swimmers are in the point $6$;
* moment $12$, during which both swimmers are in the point $6$;
* and moment $18$, during which both swimmers are in the point $0$.


#### tags 

#2800 #dp #fft #math #number_theory 