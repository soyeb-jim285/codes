<h1 style='text-align: center;'> C. Number Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game. They have an array of positive integers $a$ of size $n$.

Before starting the game, Alice chooses an integer $k \ge 0$. The game lasts for $k$ stages, the stages are numbered from $1$ to $k$. During the $i$-th stage, Alice must remove an element from the array that is less than or equal to $k - i + 1$. After that, if the array is not empty, Bob must add $k - i + 1$ to an arbitrary element of the array. Note that both Alice's move and Bob's move are two parts of the same stage of the game. If Alice can't delete an element during some stage, she loses. If the $k$-th stage ends and Alice hasn't lost yet, she wins.

Your task is to determine the maximum value of $k$ such that Alice can win if both players play optimally. Bob plays against Alice, so he tries to make her lose the game, if it's possible.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the size of the array $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$).

### Output

For each test case, print one integer — the maximum value of $k$ such that Alice can win if both players play optimally.

## Example

### Input


```text
431 1 244 4 4 41151 3 2 1 1
```
### Output

```text

2
0
1
3

```


#### Tags 

#1400 #OK #binary_search #data_structures #games #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_138_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
