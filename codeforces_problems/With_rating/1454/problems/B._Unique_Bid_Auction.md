<h1 style='text-align: center;'> B. Unique Bid Auction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a game called "Unique Bid Auction". You can read more about it here: https://en.wikipedia.org/wiki/Unique_bid_auction (though you don't have to do it to solve this problem).

Let's simplify this game a bit. Formally, there are $n$ participants, the $i$-th participant chose the number $a_i$. The winner of the game is such a participant that the number he chose is unique (i. e. nobody else chose this number except him) and is minimal (i. e. among all unique values of $a$ the minimum one is the winning one).

Your task is to find the index of the participant who won the game (or -1 if there is no winner). Indexing is $1$-based, i. e. the participants are numbered from $1$ to $n$.

You have to answer $t$ independent test cases.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. Then $t$ test cases follow.

The first line of the test case contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of participants. The second line of the test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$), where $a_i$ is the $i$-th participant chosen number.

It is guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$ ($\sum n \le 2 \cdot 10^5$).

### Output

For each test case, print the answer — the index of the participant who won the game (or -1 if there is no winner). Note that the answer is always unique.

## Example

### Input


```text
6
2
1 1
3
2 1 3
4
2 2 2 3
1
1
5
2 3 2 4 2
6
1 1 5 5 4 4
```
### Output


```text
-1
2
4
1
2
-1
```


#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_686_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
