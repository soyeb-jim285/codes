<h1 style='text-align: center;'> D. Good Trip</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ children in a class, $m$ pairs among them are friends. The $i$-th pair who are friends have a friendship value of $f_i$. 

The teacher has to go for $k$ excursions, and for each of the excursions she chooses a pair of children randomly, equiprobably and independently. If a pair of children who are friends is chosen, their friendship value increases by $1$ for all subsequent excursions (the teacher can choose a pair of children more than once). The friendship value of a pair who are not friends is considered $0$, and it does not change for subsequent excursions. 

Find the expected value of the sum of friendship values of all $k$ pairs chosen for the excursions (at the time of being chosen). It can be shown that this answer can always be expressed as a fraction $\dfrac{p}{q}$ where $p$ and $q$ are coprime integers. Calculate $p\cdot q^{-1} \bmod (10^9+7)$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 5 \cdot 10^4$). Description of the test cases follows.

The first line of each test case contains $3$ integers $n$, $m$ and $k$ ($2 \le n \le 10^5$, $0 \le m \le \min \Big(10^5$, $ \frac{n(n-1)}{2} \Big)$, $1 \le k \le 2 \cdot 10^5$) — the number of children, pairs of friends and excursions respectively.

The next $m$ lines contain three integers each — $a_i$, $b_i$, $f_i$ — the indices of the pair of children who are friends and their friendship value. ($a_i \neq b_i$, $1 \le a_i,b_i \le n$, $1 \le f_i \le 10^9$). It is guaranteed that all pairs of friends are distinct.

It is guaranteed that the sum of $n$ and sum $m$ over all test cases does not exceed $10^5$ and the sum of $k$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print one integer — the answer to the problem.

## Example

## Input


```

4100 0 242 1 101 2 13 1 22 1 15 2 41 2 253 2 24
```
## Output


```

0
55
777777784
40000020

```
## Note

For the first test case, there are no pairs of friends, so the friendship value of all pairs is $0$ and stays $0$ for subsequent rounds, hence the friendship value for all excursions is $0$.

For the second test case, there is only one pair possible $(1, 2)$ and its friendship value is initially $1$, so each turn they are picked and their friendship value increases by $1$. Therefore, the total sum is $1+2+3+\ldots+10 = 55$.

For the third test case, the final answer is $\frac{7}{9} = 777\,777\,784\bmod (10^9+7)$.



#### tags 

#1900 #combinatorics #dp #math #probabilities 