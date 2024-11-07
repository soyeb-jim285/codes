<h1 style='text-align: center;'> F. Unfair Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob gathered in the evening to play an exciting game on a sequence of $n$ integers, each integer of the sequence doesn't exceed $4$. The rules of the game are too complex to describe, so let's just describe the winning condition — Alice wins if the [bitwise XOR](http://tiny.cc/xor_wiki_eng) of all the numbers in the sequence is non-zero; otherwise, Bob wins.

The guys invited Eve to act as a judge. Initially, Alice and Bob play with $n$ numbers. After one game, Eve removes one of the numbers from the sequence, then Alice and Bob play with $n-1$ numbers. Eve removes one number again, after which Alice and Bob play with $n - 2$ numbers. This continues until the sequence of numbers is empty.

Eve seems to think that in such a game, Alice almost always wins, so she wants Bob to win as many times as possible. Determine the maximum number of times Bob can win against Alice if Eve removes the numbers optimally.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first and only line of each test case contains four integers $p_i$ ($0 \le p_i \le 200$) — the number of ones, twos, threes, and fours in the sequence at the beginning of the game.

## Output

For each test case, print the maximum number of times Bob will win in a separate line, if Eve removes the numbers optimally.

## Example

## Input


```

51 1 1 01 0 1 22 2 2 03 3 2 00 9 9 9
```
## Output


```

1
1
3
3
12

```
## Note

In the first example, Bob wins when Eve has not removed any numbers yet.

In the second example, Bob wins if Eve removes one one and one three.



#### tags 

#1800 #dp #games #greedy #math #schedules 