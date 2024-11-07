<h1 style='text-align: center;'> D. Make It Round</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Inflation has occurred in Berlandia, so the store needs to change the price of goods.

The current price of good $n$ is given. It is allowed to increase the price of the good by $k$ times, with $1 \le k \le m$, k is an integer. ## Output

 the roundest possible new price of the good. That is, the one that has the maximum number of zeros at the end.

For example, the number 481000 is more round than the number 1000010 (three zeros at the end of 481000 and only one at the end of 1000010).

If there are several possible variants, output the one in which the new price is maximal.

If it is impossible to get a rounder price, output $n \cdot m$ (that is, the maximum possible price).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) —the number of test cases in the test.

Each test case consists of one line.

This line contains two integers: $n$ and $m$ ($1 \le n, m \le 10^9$). Where $n$ is the old price of the good, and the number $m$ means that you can increase the price $n$ no more than $m$ times.

## Output

For each test case, output on a separate line the roundest integer of the form $n \cdot k$ ($1 \le k \le m$, $k$ — an integer).

If there are several possible variants, output the one in which the new price (value $n \cdot k$) is maximal.

If it is impossible to get a more rounded price, output $n \cdot m$ (that is, the maximum possible price).

## Example

## Input


```

106 115 4313 54 1610050 123452 64 3025 102 811 7
```
## Output


```

60
200
65
60
120600000
10
100
200
100
7

```
## Note

In the first case $n = 6$, $m = 11$. We cannot get a number with two zeros or more at the end, because we need to increase the price $50$ times, but $50 > m = 11$. The maximum price multiple of $10$ would be $6 \cdot 10 = 60$.

In the second case $n = 5$, $m = 43$. The maximum price multiple of $100$ would be $5 \cdot 40 = 200$.

In the third case, $n = 13$, $m = 5$. All possible new prices will not end in $0$, then you should output $n \cdot m = 65$.

In the fourth case, you should increase the price $15$ times.

In the fifth case, increase the price $12000$ times.



#### tags 

#1400 #brute_force #number_theory 