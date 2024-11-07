<h1 style='text-align: center;'> G. Another Wine Tasting Event</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After the first successful edition, Gabriella has been asked to organize a second wine tasting event. There will be $2n - 1$ bottles of wine arranged in a row, each of which is either red wine or white wine.

This time, Gabriella has already chosen the type and order of all the bottles. The types of the wines are represented by a string $s$ of length $2n - 1$. For each $1 \le i \le 2n - 1$, it holds that $s_i = \texttt{R}$ if the $i$-th bottle is red wine, and $s_i = \texttt{W}$ if the $i$-th bottle is white wine.

Exactly $n$ critics have been invited to attend. The critics are numbered from $1$ to $n$. Just like last year, each critic $j$ wants to taste an interval of wines, that is, the bottles at positions $a_j, \, a_j + 1, \, \dots, \, b_j$ for some $1 \le a_j \le b_j \le 2n - 1$. Moreover, they have the following additional requirements:

* each of them wants to taste at least $n$ wines, that is, it must hold that $b_j - a_j + 1 \ge n$;
* no two critics must taste exactly the same wines, that is, if $j \ne k$ it must hold that $a_j \ne a_k$ or $b_j \ne b_k$.

Gabriella knows that, since the event is held in a coastal region of Italy, critics are especially interested in the white wines, and don't care much about the red ones. (Indeed, white wine is perfect to accompany seafood.) Thus, to ensure fairness, she would like that all critics taste the same number of white wines.

Help Gabriella find an integer $x$ (with $0 \le x \le 2n - 1$) such that there exists a valid assignment of intervals to critics where each critic tastes exactly $x$ white wines. It can be proved that at least one such $x$ always exists.

## Input

The first line contains the integer $n$ ($1 \le n \le 10^6$) — where $2n - 1$ is the number of bottles, and $n$ is the number of critics.

The second line contains a string $s$ of length $2n - 1$ that represents the arrangement of the wines — the $i$-th character of $s$ ($1 \le i \le 2n - 1$) is $\texttt{R}$ for a red wine and $\texttt{W}$ for a white wine.

## Output

Print an integer $x$ — the number of white wines that each critic will taste.

It can be proved that at least one solution exists. If multiple solutions exist, any of them will be accepted.

## Examples

## Input


```

5
RWWRRRWWW

```
## Output


```

2

```
## Input


```

1
R

```
## Output


```

0

```
## Note

In the first sample, there are $5$ critics and $2 \cdot 5 - 1 = 9$ bottles of wine. A possible set of intervals that makes each critic taste $2$ white wines is the following: $[2, 6],$ $[1, 6],$ $[4, 8],$ $[1, 5],$ $[3, 7]$. ## Note

 that all intervals contain at least $5$ bottles.

In the second sample, there is $1$ critic and $2 \cdot 1 - 1 = 1$ bottle of wine. The only possible interval is $[1, 1]$, which gives $x = 0$.



#### tags 

#2100 #combinatorics #constructive_algorithms #math #strings 