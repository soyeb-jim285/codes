<h1 style='text-align: center;'> G. Prediction</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider a tournament with $n$ participants. The rating of the $i$-th participant is $a_i$.

The tournament will be organized as follows. First of all, organizers will assign each participant an index from $1$ to $n$. All indices will be unique. Let $p_i$ be the participant who gets the index $i$.

Then, $n-1$ games will be held. In the first game, participants $p_1$ and $p_2$ will play. In the second game, the winner of the first game will play against $p_3$. In the third game, the winner of the second game will play against $p_4$, and so on — in the last game, the winner of the $(n-2)$-th game will play against $p_n$.

Monocarp wants to predict the results of all $n-1$ games (of course, he will do the prediction only after the indices of the participants are assigned). He knows for sure that, when two participants with ratings $x$ and $y$ play, and $|x - y| > k$, the participant with the higher rating wins. But if $|x - y| \le k$, any of the two participants may win.

Among all $n!$ ways to assign the indices to participants, calculate the number of ways to do this so that Monocarp can predict the results of all $n-1$ games. Since the answer can be large, print it modulo $998244353$.

####### Input

The first line contains two integers $n$ and $k$ ($2 \le n \le 10^6$; $0 \le k \le 10^9$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_1 \le a_2 \le \dots \le a_n \le 10^9$).

####### Output

Print one integer — the number of ways to assign the indices to the participants so that Monocarp can predict the results of all $n-1$ games.

## Examples

####### Input


```text
4 3
7 12 17 21
```
####### Output


```text
24
```
####### Input


```text
3 7
4 9 28
```
####### Output


```text
4
```
####### Input


```text
4 1
1 2 3 4
```
####### Output


```text
0
```
####### Input


```text
4 1
1 2 2 4
```
####### Output


```text
12
```
####### Input


```text
16 30
8 12 15 27 39 44 49 50 51 53 58 58 59 67 68 100
```
####### Output


```text
527461297
```
## Note

In the first example, a match with any pair of players can be predicted by Monocarp, so all $24$ ways to assign indices should be counted.

In the second example, suitable ways are $[1, 3, 2]$, $[2, 3, 1]$, $[3, 1, 2$] and $[3, 2, 1]$.



#### Tags 

#2800 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
