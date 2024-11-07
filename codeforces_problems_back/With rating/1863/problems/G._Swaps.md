<h1 style='text-align: center;'> G. Swaps</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$). You can perform the following operation several (possibly, zero) times:

* pick an arbitrary $i$ and perform swap$(a_i, a_{a_i})$.

How many distinct arrays is it possible to attain? ## Output

 the answer modulo $(10^9 + 7)$.

## Input

The first line contains an integer $n$ ($1 \le n \le 10^6$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1\le a_i\le n$).

## Output

## Output

 the number of attainable arrays modulo $(10^9 + 7)$.

## Examples

## Input


```

31 1 2
```
## Output


```

2

```
## Input


```

42 1 4 3
```
## Output


```

4

```
## Input


```

62 3 1 1 1 2
```
## Output


```

18

```
## Note

In the first example, the initial array is $[1, 1, 2]$. If we perform the operation with $i = 3$, we swap $a_3$ and $a_2$, obtaining $[1, 2, 1]$. One can show that there are no other attainable arrays.

In the second example, the four attainable arrays are $[2, 1, 4, 3]$, $[1, 2, 4, 3]$, $[1, 2, 3, 4]$, $[2, 1, 3, 4]$. One can show that there are no other attainable arrays.



#### tags 

#2800 #combinatorics #dp #graphs #math 