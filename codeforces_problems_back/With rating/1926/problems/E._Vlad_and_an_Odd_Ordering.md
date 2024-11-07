<h1 style='text-align: center;'> E. Vlad and an Odd Ordering</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vladislav has $n$ cards numbered $1, 2, \dots, n$. He wants to lay them down in a row as follows: 

* First, he lays down all the odd-numbered cards from smallest to largest.
* Next, he lays down all cards that are twice an odd number from smallest to largest (i.e. $2$ multiplied by an odd number).
* Next, he lays down all cards that are $3$ times an odd number from smallest to largest (i.e. $3$ multiplied by an odd number).
* Next, he lays down all cards that are $4$ times an odd number from smallest to largest (i.e. $4$ multiplied by an odd number).
* And so on, until all cards are laid down.

 What is the $k$-th card he lays down in this process? Once Vladislav puts a card down, he cannot use that card again.## Input

The first line contains an integer $t$ ($1 \leq t \leq 5 \cdot 10^4$) — the number of test cases.

The only line of each test case contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 10^9$) — the number of cards Vlad has, and the position of the card you need to output.

## Output

For each test case, output a single integer — the $k$-th card Vladislav lays down.

## Example

## Input


```

117 17 27 37 47 57 67 71 134 1484 191000000000 1000000000
```
## Output


```

1
3
5
7
2
6
4
1
27
37
536870912

```
## Note

In the first seven test cases, $n=7$. Vladislav lays down the cards as follows: 

* First — all the odd-numbered cards in the order $1$, $3$, $5$, $7$.
* Next — all cards that are twice an odd number in the order $2$, $6$.
* Next, there are no remaining cards that are $3$ times an odd number. (Vladislav has only one of each card.)
* Next — all cards that are $4$ times an odd number, and there is only one such card: $4$.
* There are no more cards left, so Vladislav stops.

 Thus the order of cards is $1$, $3$, $5$, $7$, $2$, $6$, $4$.

#### tags 

#1500 #binary_search #bitmasks #data_structures #dp #implementation #math #number_theory 