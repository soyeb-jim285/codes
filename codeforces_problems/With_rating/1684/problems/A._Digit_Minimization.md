<h1 style='text-align: center;'> A. Digit Minimization</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an integer $n$ without zeros in its decimal representation. Alice and Bob are playing a game with this integer. Alice starts first. They play the game in turns.

On her turn, Alice must swap any two digits of the integer that are on different positions. Bob on his turn always removes the last digit of the integer. The game ends when there is only one digit left.

You have to find the smallest integer Alice can get in the end, if she plays optimally.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first and the only line of each test case contains the integer $n$ ($10 \le n \le 10^9$) — the integer for the game. $n$ does not have zeros in its decimal representation.

### Output

For each test case output a single integer — the smallest integer Alice can get in the end of the game.

## Example

### Input


```text
312132487456398
```
### Output

```text

2
1
3

```
## Note

In the first test case Alice has to swap $1$ and $2$. After that Bob removes the last digit, $1$, so the answer is $2$.

In the second test case Alice can swap $3$ and $1$: $312$. After that Bob deletes the last digit: $31$. Then Alice swaps $3$ and $1$: $13$ and Bob deletes $3$, so the answer is $1$.



#### Tags 

#800 #OK #constructive_algorithms #games #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_792_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
