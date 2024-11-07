<h1 style='text-align: center;'> B. Choosing Cubes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dmitry has $n$ cubes, numbered from left to right from $1$ to $n$. The cube with index $f$ is his favorite.

Dmitry threw all the cubes on the table, and the $i$-th cube showed the value $a_i$ ($1 \le a_i \le 100$). After that, he arranged the cubes in non-increasing order of their values, from largest to smallest. If two cubes show the same value, they can go in any order.

After sorting, Dmitry removed the first $k$ cubes. Then he became interested in whether he removed his favorite cube (note that its position could have changed after sorting).

For example, if $n=5$, $f=2$, $a = [4, \color{green}3, 3, 2, 3]$ (the favorite cube is highlighted in green), and $k = 2$, the following could have happened:

* After sorting $a=[4, \color{green}3, 3, 3, 2]$, since the favorite cube ended up in the second position, it will be removed.
* After sorting $a=[4, 3, \color{green}3, 3, 2]$, since the favorite cube ended up in the third position, it will not be removed.
### Input

The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases. Then follow the descriptions of the test cases.

The first line of each test case description contains three integers $n$, $f$, and $k$ ($1 \le f, k \le n \le 100$) — the number of cubes, the index of Dmitry's favorite cube, and the number of removed cubes, respectively.

The second line of each test case description contains $n$ integers $a_i$ ($1 \le a_i \le 100$) — the values shown on the cubes.

### Output

For each test case, output one line — "YES" if the cube will be removed in all cases, "NO" if it will not be removed in any case, "MAYBE" if it may be either removed or left.

You can output the answer in any case. For example, the strings "YES", "nO", "mAyBe" will be accepted as answers.

## Example

### Input


```text
125 2 24 3 3 2 35 5 34 2 1 3 55 5 25 2 4 1 35 5 51 2 5 4 35 5 43 1 2 4 55 5 54 3 2 1 56 5 31 2 3 1 2 310 1 11 1 1 1 1 1 1 1 1 11 1 1425 2 32 2 1 1 22 1 12 15 3 13 3 2 3 2
```
### Output

```text

MAYBE
YES
NO
YES
YES
YES
MAYBE
MAYBE
YES
YES
YES
NO

```


#### Tags 

#800 #NOT OK #sortings #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_950_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
