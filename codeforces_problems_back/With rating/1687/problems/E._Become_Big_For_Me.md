<h1 style='text-align: center;'> E. Become Big For Me</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Come, let's build a world where even the weak are not forgotten!—Kijin Seija, Double Dealing CharactersShinmyoumaru has a mallet that can turn objects bigger or smaller. She is testing it out on a sequence $a$ and a number $v$ whose initial value is $1$. She wants to make $v = \gcd\limits_{i\ne j}\{a_i\cdot a_j\}$ by no more than $10^5$ operations ($\gcd\limits_{i\ne j}\{a_i\cdot a_j\}$ denotes the $\gcd$ of all products of two distinct elements of the sequence $a$). 

In each operation, she picks a subsequence $b$ of $a$, and does one of the followings: 

* Enlarge: $v = v \cdot \mathrm{lcm}(b)$
* Reduce: $v = \frac{v}{\mathrm{lcm}(b)}$

## Note

 that she does not need to guarantee that $v$ is an integer, that is, $v$ does not need to be a multiple of $\mathrm{lcm}(b)$ when performing Reduce.

Moreover, she wants to guarantee that the total length of $b$ chosen over the operations does not exceed $10^6$. Fine a possible operation sequence for her. You don't need to minimize anything.

## Input

The first line contains a single integer $n$ ($2\leq n\leq 10^5$) — the size of sequence $a$.

The second line contains $n$ integers $a_1,a_2,\cdots,a_n$ ($1\leq a_i\leq 10^6$) — the sequence $a$.

It can be shown that the answer exists.

## Output

The first line contains a non-negative integer $k$ ($0\leq k\leq 10^5$) — the number of operations.

The following $k$ lines contains several integers. For each line, the first two integers $f$ ($f\in\{0,1\}$) and $p$ ($1\le p\le n$) stand for the option you choose ($0$ for Enlarge and $1$ for Reduce) and the length of $b$. The other $p$ integers of the line $i_1,i_2,\ldots,i_p$ ($1\le i_1<i_2<\ldots<i_p\le n$) represents the indexes of the subsequence. Formally, $b_j=a_{i_j}$.

## Examples

## Input


```

3
6 10 15

```
## Output


```

1
0 3 1 2 3

```
## Input


```

4
2 4 8 16

```
## Output


```

2
0 1 4
1 1 1

```
## Note

Test case 1:

$\gcd\limits_{i\ne j}\{a_i\cdot a_j\}=\gcd\{60,90,150\}=30$.

Perform $v = v\cdot \operatorname{lcm}\{a_1,a_2,a_3\}=30$.

Test case 2:

$\gcd\limits_{i\ne j}\{a_i\cdot a_j\}=8$.

Perform $v = v\cdot \operatorname{lcm}\{a_4\}=16$.

Perform $v = \frac{v}{\operatorname{lcm}\{a_1\}}=8$.



#### tags 

#3500 #combinatorics #constructive_algorithms #greedy #math #number_theory 