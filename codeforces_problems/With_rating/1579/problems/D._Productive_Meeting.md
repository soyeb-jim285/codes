<h1 style='text-align: center;'> D. Productive Meeting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An important meeting is to be held and there are exactly $n$ people invited. At any moment, any two people can step back and talk in private. The same two people can talk several (as many as they want) times per meeting.

Each person has limited sociability. The sociability of the $i$-th person is a non-negative integer $a_i$. This means that after exactly $a_i$ talks this person leaves the meeting (and does not talk to anyone else anymore). If $a_i = 0$, the $i$-th person leaves the meeting immediately after it starts.

A meeting is considered most productive if the maximum possible number of talks took place during it.

You are given an array of sociability $a$, determine which people should talk to each other so that the total number of talks is as large as possible.

### Input

The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The next $2t$ lines contain descriptions of the test cases.

The first line of each test case description contains an integer $n$ ($2 \le n \le 2 \cdot 10^5$) —the number of people in the meeting. The second line consists of $n$ space-separated integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 2 \cdot 10^5$) — the sociability parameters of all people. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. It is also guaranteed that the sum of all $a_i$ (over all test cases and all $i$) does not exceed $2 \cdot 10^5$.

### Output

Print $t$ answers to all test cases.

On the first line of each answer print the number $k$ — the maximum number of talks possible in a meeting.

On each of the next $k$ lines print two integers $i$ and $j$ ($1 \le i, j \le n$ and $i \neq j$) — the numbers of people who will have another talk.

If there are several possible answers, you may print any of them.

## Example

### Input


```text
8
2
2 3
3
1 2 3
4
1 2 3 4
3
0 0 2
2
6 2
3
0 0 2
5
8 2 0 1 1
5
0 1 0 0 6
```
### Output


```text
2
1 2
1 2
3
1 3
2 3
2 3
5
1 3
2 4
2 4
3 4
3 4
0
2
1 2
1 2
0
4
1 2
1 5
1 4
1 2
1
5 2
```


#### Tags 

#1400 #NOT OK #constructive_algorithms #graphs #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_744_(Div._3).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
