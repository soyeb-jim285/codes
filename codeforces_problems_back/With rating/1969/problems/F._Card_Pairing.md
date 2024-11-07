<h1 style='text-align: center;'> F. Card Pairing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a deck of $n$ cards, each card has one of $k$ types. You are given the sequence $a_1, a_2, \dots, a_n$ denoting the types of cards in the deck from top to bottom. Both $n$ and $k$ are even numbers.

You play a game with these cards. First, you draw $k$ topmost cards from the deck. Then, the following happens each turn of the game:

* you choose exactly two cards from your hand and play them. If these cards have the same type, you earn a coin;
* then, if the deck is not empty, you draw exactly two top cards from it;
* then, if both your hand and your deck are empty, the game ends. Otherwise, the new turn begins.

You have to calculate the maximum number of coins you can earn during the game.

## Input

The first line of the input contains two integers $n$ and $k$ ($2 \le k \le n \le 1000$, both $n$ and $k$ are even).

The second line of the input contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le k$).

## Output

Print one integer — the maximum number of coins you can earn.

## Examples

## Input


```

4 21 2 1 2
```
## Output


```

0

```
## Input


```

8 22 1 2 2 1 2 1 2
```
## Output


```

1

```
## Input


```

4 41 2 1 2
```
## Output


```

2

```
## Input


```

6 43 2 3 1 2 1
```
## Output


```

3

```
## Input


```

6 43 2 3 3 2 1
```
## Output


```

2

```
## Input


```

18 65 6 1 1 6 5 4 1 5 1 1 6 2 6 2 2 6 3
```
## Output


```

6

```
## Input


```

8 41 2 3 4 4 3 1 2
```
## Output


```

2

```
## Input


```

8 41 2 3 4 4 3 3 2
```
## Output


```

3

```


#### tags 

#3000 #dp #greedy #hashing #implementation 