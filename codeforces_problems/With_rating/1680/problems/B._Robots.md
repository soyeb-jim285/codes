<h1 style='text-align: center;'> B. Robots</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a field divided into $n$ rows and $m$ columns. Some cells are empty (denoted as E), other cells contain robots (denoted as R).

You can send a command to all robots at the same time. The command can be of one of the four types:

* move up;
* move right;
* move down;
* move left.

When you send a command, all robots at the same time attempt to take one step in the direction you picked. If a robot tries to move outside the field, it explodes; otherwise, every robot moves to an adjacent cell in the chosen direction.

You can send as many commands as you want (possibly, zero), in any order. Your goal is to make at least one robot reach the upper left corner of the field. Can you do this without forcing any of the robots to explode?

### Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

Each test case starts with a line containing two integers $n$ and $m$ ($1 \le n, m \le 5$) — the number of rows and the number of columns, respectively. Then $n$ lines follow; each of them contains a string of $m$ characters. Each character is either E (empty cell} or R (robot).

Additional constraint on the input: in each test case, there is at least one robot on the field.

### Output

If it is possible to make at least one robot reach the upper left corner of the field so that no robot explodes, print YES. Otherwise, print NO.

## Example

### Input


```text
61 3ERR2 2ERRE2 2ERER1 1R4 3EEEEEEERREER3 3EEEEERREE
```
### Output

```text

YES
NO
YES
YES
YES
NO

```
## Note

Explanations for test cases of the example:

1. in the first test case, it is enough to send a command to move left.
2. in the second test case, if you try to send any command, at least one robot explodes.
3. in the third test case, it is enough to send a command to move left.
4. in the fourth test case, there is already a robot in the upper left corner.
5. in the fifth test case, the sequence "move up, move left, move up" leads one robot to the upper left corner;
6. in the sixth test case, if you try to move any robot to the upper left corner, at least one other robot explodes.


#### Tags 

#800 #OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_128_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
