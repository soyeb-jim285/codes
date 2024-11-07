<h1 style='text-align: center;'> B. Up the Strip</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 128 megabytes</h5>

## Note

 that the memory limit in this problem is lower than in others.

You have a vertical strip with $n$ cells, numbered consecutively from $1$ to $n$ from top to bottom.

You also have a token that is initially placed in cell $n$. You will move the token up until it arrives at cell $1$.

Let the token be in cell $x > 1$ at some moment. One shift of the token can have either of the following kinds: 

* Subtraction: you choose an integer $y$ between $1$ and $x-1$, inclusive, and move the token from cell $x$ to cell $x - y$.
* Floored division: you choose an integer $z$ between $2$ and $x$, inclusive, and move the token from cell $x$ to cell $\lfloor \frac{x}{z} \rfloor$ ($x$ divided by $z$ rounded down).

Find the number of ways to move the token from cell $n$ to cell $1$ using one or more shifts, and print it modulo $m$. ## Note

 that if there are several ways to move the token from one cell to another in one shift, all these ways are considered distinct (check example explanation for a better understanding).

## Input

The only line contains two integers $n$ and $m$ ($2 \le n \le 4 \cdot 10^6$; $10^8 < m < 10^9$; $m$ is a prime number) — the length of the strip and the modulo.

## Output

Print the number of ways to move the token from cell $n$ to cell $1$, modulo $m$.

## Examples

## Input


```

3 998244353

```
## Output


```

5

```
## Input


```

5 998244353

```
## Output


```

25

```
## Input


```

42 998244353

```
## Output


```

793019428

```
## Input


```

787788 100000007

```
## Output


```

94810539

```
## Note

In the first test, there are three ways to move the token from cell $3$ to cell $1$ in one shift: using subtraction of $y = 2$, or using division by $z = 2$ or $z = 3$.

There are also two ways to move the token from cell $3$ to cell $1$ via cell $2$: first subtract $y = 1$, and then either subtract $y = 1$ again or divide by $z = 2$.

Therefore, there are five ways in total.



#### tags 

#1900 #brute_force #dp #math #number_theory #two_pointers 