<h1 style='text-align: center;'> C. Word Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Three guys play a game: first, each person writes down $n$ distinct words of length $3$. Then, they total up the number of points as follows: 

* if a word was written by one person — that person gets 3 points,
* if a word was written by two people — each of the two gets 1 point,
* if a word was written by all — nobody gets any points.

 In the end, how many points does each player have?## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 1000$) — the number of words written by each person.

The following three lines each contain $n$ distinct strings — the words written by each person. Each string consists of $3$ lowercase English characters.

## Output

For each test case, output three space-separated integers — the number of points each of the three guys earned. You should output the answers in the same order as the input; the $i$-th integer should be the number of points earned by the $i$-th guy.

## Example

## Input


```

31abcdefabc3orz for qaqqaq orz forcod for ces5iat roc hem ica llybac ter iol ogi stsbac roc lly iol iat
```
## Output


```

1 3 1 
2 2 6 
9 11 5 

```
## Note

In the first test case: 

* The word $\texttt{abc}$ was written by the first and third guys — they each get $1$ point.
* The word $\texttt{def}$ was written by the second guy only — he gets $3$ points.


#### tags 

#800 #data_structures #implementation 