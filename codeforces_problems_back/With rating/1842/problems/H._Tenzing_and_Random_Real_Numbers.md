<h1 style='text-align: center;'> H. Tenzing and Random Real Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

There are $n$ uniform random real variables between 0 and 1, inclusive, which are denoted as $x_1, x_2, \ldots, x_n$.

Tenzing has $m$ conditions. Each condition has the form of $x_i+x_j\le 1$ or $x_i+x_j\ge 1$.

Tenzing wants to know the probability that all the conditions are satisfied, modulo $998~244~353$.

Formally, let $M = 998~244~353$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. ## Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output the integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

## Input

The first line contains two integers $n$ and $m$ ($1\le n\le 20$, $0\le m\le n^2+n$).

Then following $m$ lines of input contains three integers $t$, $i$ and $j$ ($t \in \{0,1\}$, $1\le i\le j\le n$).

* If $t=0$, the condition is $x_i+x_j\le 1$.
* If $t=1$, the condition is $x_i+x_j\ge 1$.

It is guaranteed that all conditions are pairwise distinct.

## Output

## Output

 the probability that all the conditions are satisfied, modulo $M = 998~244~353$.

## Examples

## Input


```

3 2
0 1 2
1 3 3

```
## Output


```

748683265

```
## Input


```

3 3
0 1 2
0 1 3
0 2 3

```
## Output


```

748683265

```
## Input


```

3 4
0 1 2
0 1 3
1 2 3
1 2 2

```
## Output


```

935854081

```
## Input


```

4 4
0 1 2
0 3 4
1 1 3
1 2 4

```
## Output


```

0

```
## Input


```

8 12
0 1 2
0 2 3
1 3 4
0 1 4
0 5 6
0 6 7
1 7 8
0 5 8
1 3 7
1 3 8
1 4 7
1 4 8

```
## Output


```

997687297

```
## Note

In the first test case, the conditions are $x_1+x_2 \le 1$ and $x_3+x_3\ge 1$, and the probability that each condition is satisfied is $\frac 12$, so the probability that they are both satisfied is $\frac 12\cdot \frac 12=\frac 14$, modulo $998~244~353$ is equal to $748683265$.

In the second test case, the answer is $\frac 14$.

In the third test case, the answer is $\frac 1{16}$.

In the fourth test case, the sum of all variables must equal $2$, so the probability is $0$.



#### tags 

#3000 #bitmasks #dp #graphs #math #probabilities 