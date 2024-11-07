<h1 style='text-align: center;'> F. Three Chairs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Kira found $n$ friends from Morioh and decided to gather them around a table to have a peaceful conversation. The height of friend $i$ is equal to $a_i$. It so happened that the height of each of the friends is unique.

Unfortunately, there were only $3$ chairs in Kira's house, and obviously, it will not be possible to seat all friends! So, Kira has to invite only $3$ of his friends.

But everything is not so simple! If the heights of the lowest and the tallest of the invited friends are not coprime, then the friends will play tricks on each other, which will greatly anger Kira.

Kira became interested, how many ways are there to choose $3$ of his friends so that they don't play tricks? Two ways are considered different if there is a friend invited in one way, but not in the other.

Formally, if Kira invites friends $i$, $j$, and $k$, then the following should be true: $\gcd(\min(a_i, a_j, a_k), \max(a_i, a_j, a_k)) = 1$, where $\gcd(x, y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of the numbers $x$ and $y$.

Kira is not very strong in computer science, so he asks you to count the number of ways to invide friends.

###### Input

The first line contains the number $n$ ($3 \le n \le 3\cdot10^5$) — the number of Kira's friends.

The next line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 3\cdot10^5$) — heights of Kira's friends.

###### Output

In a single line output the number of ways to invite three friends.

## Examples

###### Input


```text
3
1 2 3
```
###### Output


```text
1
```
###### Input


```text
4
1 6 2 3
```
###### Output


```text
3
```
###### Input


```text
4
16 4 8 2
```
###### Output


```text
0
```
###### Input


```text
10
10 1 6 7 9 8 4 3 5 2
```
###### Output


```text
77
```
## Note

In the first example, only one way is suitable: invite friends $1$, $2$, and $3$. Here $1 < 2 < 3$, and the numbers $1$ and $3$ are coprime.



#### Tags 

#2300 #NOT OK #bitmasks #brute_force #combinatorics #data_structures #dp #number_theory #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_846_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
