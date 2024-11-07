<h1 style='text-align: center;'> G. Discarding Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Eulampius has created a game with the following rules:

* there are two players in the game: a human and a computer;
* the game lasts for no more than $n$ rounds. Initially both players have $0$ points. In the $j$-th round the human gains $a_j$ points, and the computer gains $b_j$ points. The points are gained simultaneously;
* the game ends when one of the players gets $k$ or more points. This player loses the game. If both players get $k$ or more points simultaneously, both lose;
* if both players have less than $k$ points after $n$ rounds, the game ends in a tie;
* after each round the human can push the "Reset" button. If the human had $x$ points, and the computer had $y$ points before the button is pushed (of course, $x < k$ and $y < k$), then after the button is pushed the human will have $x' = max(0, \, x - y)$ points, and the computer will have $y' = max(0, \, y - x)$ points. E. g. the push of "Reset" button transforms the state $(x=3, \, y=5)$ into the state $(x'=0, \, y'=2)$, and the state $(x=8, \, y=2)$ into the state $(x'=6, \, y'=0)$.

Eulampius asked his friend Polycarpus to test the game. Polycarpus has quickly revealed that amounts of points gained by the human and the computer in each of $n$ rounds are generated before the game and stored in a file. In other words, the pushes of the "Reset" button do not influence the values $a_j$ and $b_j$, so sequences $a$ and $b$ are fixed and known in advance.

Polycarpus wants to make a plan for the game. He would like to win the game pushing the "Reset" button as few times as possible. Your task is to determine this minimal number of pushes or determine that Polycarpus cannot win.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 10000$) — the number of test cases. Then the test cases follow.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$, $2 \le k \le 10^9$) — the maximum possible number of rounds in the game and the number of points, after reaching which a player loses, respectively.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_j < k)$, where $a_j$ is the amount of points the human gains in the $j$-th round.

The third line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_j < k$), where $b_j$ is the amount of points the computer gains in the $j$-th round.

The sum of $n$ over all test cases in the input does not exceed $2 \cdot 10^5$.

### Output

Print the answers for all test cases in the order they appear in the input.

If Polycarpus cannot win the game, then simply print one line "-1" (without quotes). In this case, you should not output anything else for that test case. Otherwise, the first line of the test case answer should contain one integer $d$ — the minimum possible number of "Reset" button pushes, required to win the game. The next line should contain $d$ distinct integers $r_1, r_2, \dots, r_d$ ($1 \le r_i < n$) — the numbers of rounds, at the end of which Polycarpus has to press the "Reset" button, in arbitrary order. If $d=0$ then either leave the second line of the test case answer empty, or do not print the second line at all.

If there are several possible solutions, print any of them.

## Example

### Input


```text
3
4 17
1 3 5 7
3 5 7 9
11 17
5 2 8 2 4 6 1 2 7 2 5
4 6 3 3 5 1 7 4 2 5 3
6 17
6 1 2 7 2 5
1 7 4 2 5 3
```
### Output


```text

0

2
2 4
-1
```
## Note

In the second test case, if the human pushes the "Reset" button after the second and the fourth rounds, the game goes as follows:

1. after the first round the human has $5$ points, the computer — $4$ points;
2. after the second round the human has $7$ points, the computer — $10$ points;
3. the human pushes the "Reset" button and now he has $0$ points and the computer — $3$ points;
4. after the third round the human has $8$ points, the computer — $6$ points;
5. after the fourth round the human has $10$ points, the computer — $9$ points;
6. the human pushes "Reset" button again, after it he has $1$ point, the computer — $0$ points;
7. after the fifth round the human has $5$ points, the computer — $5$ points;
8. after the sixth round the human has $11$ points, the computer — $6$ points;
9. after the seventh round the human has $12$ points, the computer — $13$ points;
10. after the eighth round the human has $14$ points, the computer — $17$ points;
11. the human wins, as the computer has $k$ or more points and the human — strictly less than $k$ points.


#### Tags 

#2300 #NOT OK #dp #greedy #two_pointers 

## Blogs
- [All Contest Problems](../2019-2020_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
