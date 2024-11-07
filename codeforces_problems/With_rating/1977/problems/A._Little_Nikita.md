<h1 style='text-align: center;'> A. Little Nikita</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The little boy Nikita was given some cubes as a present. He decided to build a tower out of them.

Initially, the tower doesn't have any cubes. In one move, Nikita either puts exactly $1$ cube on top of the tower or removes exactly $1$ cube from the top of the tower. Is it possible that after $n$ moves, the resulting tower has exactly $m$ cubes?

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $n$ and $m$ ($1 \le n, m \le 100$).

### Output

For each test case, output "Yes" (without quotes) if Nikita can obtain a tower with $m$ cubes, and "No" (without quotes) otherwise.

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.

## Example

### Input


```text
33 32 45 3
```
### Output

```text

Yes
No
Yes

```
## Note

In the first test case, Nikita can put $1$ cube on top of the tower $3$ times in a row, so the answer is "Yes".

In the second test case, Nikita can only end up with either a tower with no blocks or a tower with $2$ blocks, so the answer is "No".



#### Tags 

#800 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_948_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
