<h1 style='text-align: center;'> F. Jee, You See?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

During their training for the ICPC competitions, team "Jee You See" stumbled upon a very basic counting problem. After many "Wrong answer" verdicts, they finally decided to give up and destroy turn-off the PC. Now they want your help in up-solving the problem.

You are given 4 integers $n$, $l$, $r$, and $z$. Count the number of arrays $a$ of length $n$ containing non-negative integers such that:

* $l\le a_1+a_2+\ldots+a_n\le r$, and
* $a_1\oplus a_2 \oplus \ldots\oplus a_n=z$, where $\oplus$ denotes the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation.

Since the answer can be large, print it modulo $10^9+7$.

## Input

The only line contains four integers $n$, $l$, $r$, $z$ ($1 \le n \le 1000$, $1\le l\le r\le 10^{18}$, $1\le z\le 10^{18}$).

## Output

Print the number of arrays $a$ satisfying all requirements modulo $10^9+7$.

## Examples

## Input


```

3 1 5 1

```
## Output


```

13

```
## Input


```

4 1 3 2

```
## Output


```

4

```
## Input


```

2 1 100000 15629

```
## Output


```

49152

```
## Input


```

100 56 89 66

```
## Output


```

981727503

```
## Note

The following arrays satisfy the conditions for the first sample:

* $[1, 0, 0]$;
* $[0, 1, 0]$;
* $[3, 2, 0]$;
* $[2, 3, 0]$;
* $[0, 0, 1]$;
* $[1, 1, 1]$;
* $[2, 2, 1]$;
* $[3, 0, 2]$;
* $[2, 1, 2]$;
* $[1, 2, 2]$;
* $[0, 3, 2]$;
* $[2, 0, 3]$;
* $[0, 2, 3]$.

The following arrays satisfy the conditions for the second sample:

* $[2, 0, 0, 0]$;
* $[0, 2, 0, 0]$;
* $[0, 0, 2, 0]$;
* $[0, 0, 0, 2]$.


#### tags 

#2400 #bitmasks #combinatorics #dp 