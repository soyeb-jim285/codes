<h1 style='text-align: center;'> F. Controversial Rounds</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob play a game. The game consists of several sets, and each set consists of several rounds. Each round is won either by Alice or by Bob, and the set ends when one of the players has won $x$ rounds in a row. For example, if Bob won five rounds in a row and $x = 2$, then two sets ends.

You know that Alice and Bob have already played $n$ rounds, and you know the results of some rounds. For each $x$ from $1$ to $n$, calculate the maximum possible number of sets that could have already finished if each set lasts until one of the players wins $x$ rounds in a row. It is possible that the last set is still not finished — in that case, you should not count it in the answer.

##### Input

The first line contains one integer $n$ ($1 \le n \le 10^6$) — the number of rounds.

The second line contains one string $s$ of length $n$ — the descriptions of rounds. If the $i$-th element of the string is 0, then Alice won the $i$-th round; if it is 1, then Bob won the $i$-th round, and if it is ?, then you don't know who won the $i$-th round.

##### Output

In the only line print $n$ integers. The $i$-th integer should be equal to the maximum possible number of sets that could have already finished if each set lasts until one of the players wins $i$ rounds in a row.

## Examples

##### Input


```text
6
11?000
```
##### Output


```text
6 3 2 1 0 0 
```
##### Input


```text
5
01?01
```
##### Output


```text
5 1 0 0 0 
```
##### Input


```text
12
???1??????1?
```
##### Output


```text
12 6 4 3 2 2 1 1 1 1 1 1 
```
## Note

Let's consider the first test case:

* if $x = 1$ and $s = 110000$ or $s = 111000$ then there are six finished sets;
* if $x = 2$ and $s = 110000$ then there are three finished sets;
* if $x = 3$ and $s = 111000$ then there are two finished sets;
* if $x = 4$ and $s = 110000$ then there is one finished set;
* if $x = 5$ then there are no finished sets;
* if $x = 6$ then there are no finished sets.


#### Tags 

#2500 #NOT OK #binary_search #data_structures #dp #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_93_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
