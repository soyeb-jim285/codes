<h1 style='text-align: center;'> G. Clubstep</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

There is an extremely hard video game that is one of Chaneka's favourite video games. One of the hardest levels in the game is called Clubstep. Clubstep consists of $n$ parts, numbered from $1$ to $n$. Chaneka has practised the level a good amount, so currently, her familiarity value with each part $i$ is $a_i$.

After this, Chaneka can do several (possibly zero) attempts on Clubstep. In each attempt, she dies on one of the $n$ parts. If an attempt dies on part $p$, that means it only successfully passes through every part $k$ for all $1 \leq k \leq p-1$ and it does not reach any part $k$ for all $p+1 \leq k \leq n$. An attempt that dies on part $p$ takes $p$ seconds.

It is known that Chaneka improves much more on the part she dies on than anything else. It is also known that during an attempt, Chaneka does not get to practise that much on the parts she does not reach. So, the effect of an attempt that dies on part $p$ is as follows: 

* Chaneka's familiarity value with part $p$ increases by $2$.
* Chaneka's familiarity value with each part $k$ for all $1 \leq k \leq p-1$ increases by $1$.

 There will be $q$ questions. For the $j$-th question, you are given three integers $l_j$, $r_j$, and $x_j$. Then, you are asked to find out the minimum time (in seconds) for Chaneka to make it such that the familiarity value for every part $p$ ($l_j \leq p \leq r_j$) is at least $x_j$.## Note

 that each question is independent, so the attempt Chaneka does on a question does not affect the familiarity values of any other questions.

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 3\cdot10^5$) — the number of parts in Clubstep.

The second line contains $n$ integers $a_1,a_2,a_3,\ldots,a_n$ ($1\leq a_i\leq10^9$) — Chaneka's familiarity value with each part.

The third line contains a single integer $q$ ($1\leq q\leq3\cdot10^5$) — the number of questions.

The $j$-th of the next $q$ lines contains three integers $l_j$, $r_j$, and $x_j$ ($1\leq l_j\leq r_j\leq n$; $1\leq x_j\leq10^9$) — the description of the $j$-th question.

## Output

## Output

 $q$ lines with an integer in each line. The integer in the $j$-th line represents the minimum time (in seconds) for Chaneka to make it such that the familiarity value for every part $p$ ($l_j \leq p \leq r_j$) is at least $x_j$.

## Example

## Input


```

5
1 3 2 1 2
3
1 5 5
2 4 5
3 3 1

```
## Output


```

15
11
0

```
## Note

For the $1$-st question, one possible strategy is to do the following: 

1. Do $1$ attempt that dies on part $1$. This takes $1$ second. The familiarity values become $[3, 3, 2, 1, 2]$.
2. Do $1$ attempt that dies on part $4$. This takes $4$ seconds. The familiarity values become $[4, 4, 3, 3, 2]$.
3. Do $2$ attempts that die on part $5$. This takes $10$ seconds. The familiarity values become $[6, 6, 5, 5, 6]$.

The total time taken (in seconds) is $1+4+10=15$.

For the $2$-nd question, one possible strategy is to do the following: 

1. Do $1$ attempt that dies on part $3$. This takes $3$ seconds. The familiarity values become $[2, 4, 4, 1, 2]$.
2. Do $2$ attempts that die on part $4$. This takes $8$ seconds. The familiarity values become $[4, 6, 6, 5, 2]$.

The total time taken (in seconds) is $3+8=11$.



#### tags 

#3500 #binary_search #brute_force #data_structures #greedy #trees 