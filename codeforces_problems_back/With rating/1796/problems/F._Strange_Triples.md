<h1 style='text-align: center;'> F. Strange Triples</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a triple of positive integers ($a, b, n$) strange if the equality $\frac{an}{nb} = \frac{a}{b}$ holds, where $an$ is the concatenation of $a$ and $n$ and $nb$ is the concatenation of $n$ and $b$. For the purpose of concatenation, the integers are considered without leading zeroes.

For example, if $a = 1$, $b = 5$ and $n = 9$, then the triple is strange, because $\frac{19}{95} = \frac{1}{5}$. But $a = 7$, $b = 3$ and $n = 11$ is not strange, because $\frac{711}{113} \ne \frac{7}{3}$.

You are given three integers $A$, $B$ and $N$. Calculate the number of strange triples $(a, b, n$), such that $1 \le a < A$, $1 \le b < B$ and $1 \le n < N$.

## Input

The only line contains three integers $A$, $B$ and $N$ ($1 \le A, B \le 10^5$; $1 \le N \le 10^9$).

## Output

Print one integer — the number of strange triples $(a, b, n$) such that $1 \le a < A$, $1 \le b < B$ and $1 \le n < N$.

## Examples

## Input


```

5 6 10

```
## Output


```

7

```
## Input


```

10 10 100

```
## Output


```

29

```
## Input


```

1 10 25

```
## Output


```

0

```
## Input


```

4242 6969 133333337

```
## Output


```

19536

```
## Input


```

94841 47471 581818184

```
## Output


```

98715

```
## Note

In the first example, there are $7$ strange triples: $(1, 1, 1$), ($1, 4, 6$), ($1, 5, 9$), ($2, 2, 2$), ($2, 5, 6$), ($3, 3, 3$) and ($4, 4, 4$).



#### tags 

#2900 #brute_force #math #number_theory 