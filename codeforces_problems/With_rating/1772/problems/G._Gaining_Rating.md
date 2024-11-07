<h1 style='text-align: center;'> G. Gaining Rating</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing chess on one popular website. He has $n$ opponents he can play with. The $i$-th opponent has rating equal to $a_i$. Monocarp's initial rating is $x$. Monocarp wants to raise his rating to the value $y$ ($y > x$).

When Monocarp is playing against one of the opponents, he will win if his current rating is bigger or equal to the opponent's rating. If Monocarp wins, his rating is increased by $1$, otherwise it is decreased by $1$. The rating of his opponent does not change.

Monocarp wants to gain rating $y$ playing as few games as possible. But he can't just grind it, playing against weak opponents. The website has a rule that you should play against all opponents as evenly as possible. Speaking formally, if Monocarp wants to play against an opponent $i$, there should be no other opponent $j$ such that Monocarp has played more games against $i$ than against $j$.

Calculate the minimum possible number of games Monocarp needs to gain rating $y$ or say it's impossible. 
## Note

 that ratings of Monocarp's opponents don't change, while Monocarp's rating does change.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains three integers $n$, $x$ and $y$ ($1 \le n \le 2 \cdot 10^5$; $1 \le x < y \le 10^{12}$) — the number of Monocarp's opponents, his initial and desired ratings.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^{12}$) — ratings of Monocarp's opponents.

Additional constraint on the input: the total sum of $n$ over all $t$ test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the minimum number of games Monocarp needs to play to gain rating $y$, or $-1$ if it's impossible.

## Example

### Input


```text
37 2 103 1 9 2 5 20 87 1 103 1 9 2 5 20 85 10 12100 1 200 11 300
```
### Output

```text

20
-1
2

```
## Note

In the first test case, Monocarp can use the following strategy: 

1. Monocarp plays against the $2$-nd opponent to increase rating ($2 \to 3$);
2. Monocarp plays against the $1$-st opponent to increase rating ($3 \to 4$);
3. Monocarp plays against the $4$-th opponent to increase rating ($4 \to 5$);
4. Monocarp plays against the $5$-th opponent to increase rating ($5 \to 6$);
5. Now Monocarp have to play with remaining three opponents. So, he will lose $3$ times and get rating $3$ ($6 \to 5 \to 4 \to 3$);
6. After that, Monocarp will repeat steps 1-5 again. After $14$ games, he has played twice with each opponent and get final rating $4$.
7. Monocarp plays against the $1$-st opponent to increase rating ($4 \to 5$);
8. Monocarp plays against the $2$-nd opponent to increase rating ($5 \to 6$);
9. Monocarp plays against the $4$-th opponent to increase rating ($6 \to 7$);
10. Monocarp plays against the $5$-th opponent to increase rating ($7 \to 8$);
11. Monocarp plays against the $7$-th opponent to increase rating ($8 \to 9$);
12. Monocarp plays against the $3$-rd opponent to increase rating ($9 \to 10$);

 In total, Monocarp, played twice against the $6$-th opponent and three times against other opponents and got rating $10$ in $14 + 6 = 20$ games.In the second test case, it can be proven that whichever games Monocarp plays, he can't get his rating higher than $4$.



#### Tags 

#2200 #NOT OK #binary_search #greedy #implementation #math #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_839_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
