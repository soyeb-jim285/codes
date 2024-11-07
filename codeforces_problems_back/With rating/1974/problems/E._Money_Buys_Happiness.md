<h1 style='text-align: center;'> E. Money Buys Happiness</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Being a physicist, Charlie likes to plan his life in simple and precise terms. 

For the next $m$ months, starting with no money, Charlie will work hard and earn $x$ pounds per month. For the $i$-th month $(1 \le i \le m)$, there'll be a single opportunity of paying cost $c_i$ pounds to obtain happiness $h_i$.

Borrowing is not allowed. Money earned in the $i$-th month can only be spent in a later $j$-th month ($j>i$).

Since physicists don't code, help Charlie find the maximum obtainable sum of happiness.

## Input

The first line of input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains two integers, $m$ and $x$ ($1 \le m \le 50$, $1 \le x \le 10^8$) — the total number of months and the monthly salary.

The $i$-th of the following $m$ lines contains two integers, $c_i$ and $h_i$ ($0 \le c_i \le 10^8$, $1 \le h_i \le 10^3$) — the cost and happiness on offer for the $i$-th month. ## Note

 that some happiness may be free ($c_i=0$ for some $i$'s).

It is guaranteed that the sum of $\sum_i h_i$ over all test cases does not exceed $10^5$.

## Output

For each test case, print a single integer, the maximum sum of happiness Charlie could obtain.

## Example

## Input


```

71 101 52 800 10200 1003 10070 100100 200150 1505 83 15 33 41 55 32 51 52 15 32 52 44 15 13 45 22 11 23 53 23 2
```
## Output


```

0
10
200
15
1
9
9

```
## Note

In the first test case, Charlie only gets paid at the end of the month, so is unable to afford anything.

In the second test case, Charlie obtains the free happiness in the first month.

In the third test case, it's optimal for Charlie to buy happiness in the second month. Even with money left at the end, Charlie could not go back in time to obtain the happiness on offer in the first month.



#### tags 

#1800 #dp 