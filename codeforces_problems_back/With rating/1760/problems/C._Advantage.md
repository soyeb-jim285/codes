<h1 style='text-align: center;'> C. Advantage</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ participants in a competition, participant $i$ having a strength of $s_i$. 

Every participant wonders how much of an advantage they have over the other best participant. In other words, each participant $i$ wants to know the difference between $s_i$ and $s_j$, where $j$ is the strongest participant in the competition, not counting $i$ (a difference can be negative).

So, they ask you for your help! For each $i$ ($1 \leq i \leq n$) output the difference between $s_i$ and the maximum strength of any participant other than participant $i$.

## Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2\cdot10^5$) — the length of the array.

The following line contains $n$ space-separated positive integers $s_1$, $s_2$, ..., $s_n$ ($1 \leq s_i \leq 10^9$) — the strengths of the participants.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$.

## Output

For each test case, output $n$ space-separated integers. For each $i$ ($1 \leq i \leq n$) output the difference between $s_i$ and the maximum strength of any other participant.

## Example

## Input


```

544 7 3 521 251 2 3 4 534 9 444 4 4 4
```
## Output


```

-3 2 -4 -2 
-1 1 
-4 -3 -2 -1 1 
-5 5 -5 
0 0 0 0 

```
## Note

For the first test case:

* The first participant has a strength of $4$ and the largest strength of a participant different from the first one is $7$, so the answer for the first participant is $4 - 7 = -3$.
* The second participant has a strength of $7$ and the largest strength of a participant different from the second one is $5$, so the answer for the second participant is $7 - 5 = 2$.
* The third participant has a strength of $3$ and the largest strength of a participant different from the third one is $7$, so the answer for the third participant is $3 - 7 = -4$.
* The fourth participant has a strength of $5$ and the largest strength of a participant different from the fourth one is $7$, so the answer for the fourth participant is $5 - 7 = -2$.


#### tags 

#800 #data_structures #implementation #sortings 