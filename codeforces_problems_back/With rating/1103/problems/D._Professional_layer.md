<h1 style='text-align: center;'> D. Professional layer</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Cardbluff is popular sport game in Telegram. Each Cardbluff player has ever dreamed about entrance in the professional layer. There are $n$ judges now in the layer and you are trying to pass the entrance exam. You have a number $k$ — your skill in Cardbluff.

Each judge has a number $a_i$ — an indicator of uncertainty about your entrance to the professional layer and a number $e_i$ — an experience playing Cardbluff. To pass the exam you need to convince all judges by playing with them. You can play only one game with each judge. As a result of a particular game, you can divide the uncertainty of $i$-th judge by any natural divisor of $a_i$ which is at most $k$. If GCD of all indicators is equal to $1$, you will enter to the professional layer and become a judge.

Also, you want to minimize the total amount of spent time. So, if you play with $x$ judges with total experience $y$ you will spend $x \cdot y$ seconds.

Print minimal time to enter to the professional layer or $-1$ if it's impossible.

## Input

There are two numbers in the first line $n$ and $k$ ($1 \leq n \leq 10^6$, $1 \leq k \leq 10^{12}$) — the number of judges and your skill in Cardbluff.

The second line contains $n$ integers, where $i$-th number $a_i$ ($1 \leq a_i \leq 10^{12}$) — the uncertainty of $i$-th judge

The third line contains $n$ integers in the same format ($1 \leq e_i \leq 10^9$), $e_i$ — the experience of $i$-th judge.

## Output

Print the single integer — minimal number of seconds to pass exam, or $-1$ if it's impossible

## Examples

## Input


```

3 6
30 30 30
100 4 5

```
## Output


```

18

```
## Input


```

1 1000000
1
100

```
## Output


```

0

```
## Input


```

3 5
7 7 7
1 1 1

```
## Output


```

-1

```


#### tags 

#3100 #bitmasks #dp 