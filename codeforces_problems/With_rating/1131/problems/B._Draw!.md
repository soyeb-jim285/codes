<h1 style='text-align: center;'> B. Draw!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You still have partial information about the score during the historic football match. You are given a set of pairs $(a_i, b_i)$, indicating that at some point during the match the score was "$a_i$: $b_i$". It is known that if the current score is «$x$:$y$», then after the goal it will change to "$x+1$:$y$" or "$x$:$y+1$". What is the largest number of times a draw could appear on the scoreboard?

The pairs "$a_i$:$b_i$" are given in chronological order (time increases), but you are given score only for some moments of time. The last pair corresponds to the end of the match.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 10000$) — the number of known moments in the match.

Each of the next $n$ lines contains integers $a_i$ and $b_i$ ($0 \le a_i, b_i \le 10^9$), denoting the score of the match at that moment (that is, the number of goals by the first team and the number of goals by the second team).

All moments are given in chronological order, that is, sequences $x_i$ and $y_j$ are non-decreasing. The last score denotes the final result of the match.

##### Output

Print the maximum number of moments of time, during which the score was a draw. The starting moment of the match (with a score 0:0) is also counted.

## Examples

##### Input


```text
3  
2 0  
3 1  
3 4  

```
##### Output


```text
2  

```
##### Input


```text
3  
0 0  
0 0  
0 0  

```
##### Output


```text
1  

```
##### Input


```text
1  
5 4  

```
##### Output


```text
5  

```
## Note

In the example one of the possible score sequences leading to the maximum number of draws is as follows: 0:0, 1:0, 2:0, 2:1, 3:1, 3:2, 3:3, 3:4.



#### Tags 

#1400 #NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_541_(Div._2).md)
- [Announcement #1 (ru)](../blogs/Announcement_1_(ru).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial](../blogs/Tutorial.md)
