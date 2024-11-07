<h1 style='text-align: center;'> D. Trivial Conjecture</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$$f(n) = \left\{ \begin{array}{ll} \frac{n}{2} & n \equiv 0 \pmod{2}\\\ 3n+1 & n \equiv 1 \pmod{2}\\\ \end{array} \right.$$

Find an integer $n$ so that none of the first $k$ terms of the sequence $n, f(n), f(f(n)), f(f(f(n))), \dots$ are equal to $1$.

## Input

The only line contains an integer $k$ ($1 \leq k \leq \min(\textbf{[REDACTED]}, 10^{18})$).

## Output

## Output

 a single integer $n$ such that none of the first $k$ terms of the sequence $n, f(n), f(f(n)), f(f(f(n))), \dots$ are equal to $1$.

Integer $n$ should have at most $10^3$ digits.

## Examples

## Input


```

1

```
## Output


```

5
```
## Input


```

5

```
## Output


```

6
```
## Note

In the first test, the sequence created with $n = 5$ looks like $5, 16, 8, 4, 2, 1, 4, \dots$, and none of the first $k=1$ terms are equal to $1$.

In the second test, the sequence created with $n = 6$ looks like $6, 3, 10, 5, 16, 8, 4, \dots$, and none of the first $k=5$ terms are equal to $1$.



#### tags 

#*special #constructive_algorithms #math #number_theory 