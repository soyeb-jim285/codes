<h1 style='text-align: center;'> F. Colouring Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game. There are $n$ cells in a row. Initially each cell is either red or blue. Alice goes first.

On each turn, Alice chooses two neighbouring cells which contain at least one red cell, and paints that two cells white. Then, Bob chooses two neighbouring cells which contain at least one blue cell, and paints that two cells white. The player who cannot make a move loses.

Find the winner if both Alice and Bob play optimally.

## Note

 that a chosen cell can be white, as long as the other cell satisfies the constraints.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of test cases follows.

For each test case, the first line contains an integer $n$ ($2 \leq n \leq 5 \cdot 10^5$) — the number of cells.

The second line contains a string $s$ of length $n$ — the initial state of the cells. The $i$-th cell is red if $s_i = $ R, blue if $s_i = $ B.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, output the name of the winner on a separate line.

## Example

## Input


```

83BRB5RRBBB6RBRBRB8BBRRBRRB6BRRBRB12RBRBRBRBRRBB12RBRBRBRBBBRR4RBBR
```
## Output


```

Bob
Bob
Alice
Alice
Alice
Alice
Bob
Bob

```
## Note

In the notes, the cell numbers increase from left to right.

In the first testcase for Alice, she has two choices: paint the first and the second cells, or paint the second and the third cells. No matter what choice Alice makes, there will be exactly one blue cell after Alice's move. Bob just needs to paint the blue cell and its neighbour, then every cell will be white and Alice can't make a move. So Bob is the winner.

In the second testcase no matter what Alice chooses, Bob can choose to paint the fourth and fifth cells in $2$ turns.

In the third testcase at first, Alice paints the third and the fourth cells. It doesn't matter if Bob paints the first and the second cells or the fifth and sixth cells, as Alice can paint the other two cells.

In the fourth testcase at first, Alice paints the second and the third cells. If Bob paints the fifth and the sixth cells or the fourth and the fifth cells, then Alice paints the seventh and the eighth cells. If Bob paints the seventh and the eighth cells, then Alice paints the fifth and the sixth cells.

In the fifth Alice chooses the middle two cells at first, then Bob obviously has only two options, whichever variant he chooses, Alice can choose the other one and win.

In the eighth no matter what Alice chooses, Bob can choose the other two symmetrical cells.



#### tags 

#2600 #constructive_algorithms #dp #games 