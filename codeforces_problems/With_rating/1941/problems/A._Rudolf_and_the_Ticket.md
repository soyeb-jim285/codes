<h1 style='text-align: center;'> A. Rudolf and the Ticket</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rudolf is going to visit Bernard, and he decided to take the metro to get to him. The ticket can be purchased at a machine that accepts exactly two coins, the sum of which does not exceed $k$.

Rudolf has two pockets with coins. In the left pocket, there are $n$ coins with denominations $b_1, b_2, \dots, b_n$. In the right pocket, there are $m$ coins with denominations $c_1, c_2, \dots, c_m$. He wants to choose exactly one coin from the left pocket and exactly one coin from the right pocket (two coins in total).

Help Rudolf determine how many ways there are to select indices $f$ and $s$ such that $b_f + c_s \le k$.

### Input

The first line contains an integer $t$ ($1 \le t \le 100$) — the number of test cases. Then follows the description of each test case.

The first line of each test case contains three natural numbers $n$, $m$, and $k$ ($1 \le n, m \le 100, 1 \le k \le 2000$) — the number of coins in the left and right pockets, and the maximum sum of two coins for the ticket payment at the counter, respectively.

The second line of each test case contains $n$ integers $b_i$ ($1 \le b_i \le 1000$) — the denominations of coins in the left pocket.

The third line of each test case contains $m$ integers $c_i$ ($1 \le c_i \le 1000$) — the denominations of coins in the right pocket.

### Output

For each testcase, output a single integer — the number of ways Rudolf can select two coins, taking one from each pocket, so that the sum of the coins does not exceed $k$.

## Example

### Input


```text
44 4 81 5 10 142 1 8 12 3 44 81 2 34 2 71 1 1 12 73 4 20001 1 11 1 1 1
```
### Output

```text

6
0
4
12

```
## Note

## Note

 that the pairs indicate the indices of the coins in the array, not their denominations.

In the first test case, Rudolf can choose the following pairs of coins: $[1, 1], [1, 2], [1, 4], [2, 1], [2, 2], [2, 4]$.

In the second test case, Rudolf cannot choose one coin from each pocket in any way, as the sum of any two elements from the first and second arrays will exceed the value of $k=4$.

In the third test case, Rudolf can choose: $[1, 1], [2, 1], [3, 1], [4, 1]$.

In the fourth test case, Rudolf can choose any coin from the left pocket and any coin from the right pocket.



#### Tags 

#800 #NOT OK #brute_force #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_933_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
- [../blogs/https:_codeforces.com_blog_entry_126654.md](../blogs/https:_codeforces.com_blog_entry_126654.md)
