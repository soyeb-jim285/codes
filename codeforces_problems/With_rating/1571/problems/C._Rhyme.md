<h1 style='text-align: center;'> C. Rhyme</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's say that two strings $s$ and $t$ rhyme if both strings have length at least $k$, and their last $k$ characters are equal. For example, if $k = 3$, the strings abcd and cebcd rhyme, the strings ab and ab don't rhyme, the strings aaaa and aaaaa rhyme, the strings abcd and abce don't rhyme.

You have $n$ pairs of strings $(s_i, t_i)$, and for each pair of strings you know, should they rhyme or should not.

Find all possible non-negative integer values for $k$ such that pairs that have to rhyme, rhyme and pairs that must not rhyme, don't rhyme.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the number of string pairs.

Next $n$ lines contains descriptions of pairs — one per line. The $i$-th line contains space-separated strings $s_i$ and $t_i$ and marker $r_i$. Strings are non-empty, consist of lowercase Latin letters and each have length at most $2 \cdot 10^5$. The marker $r_i$ equals to $1$ if strings have to rhyme, or $0$ if they must not rhyme.

It's guaranteed that for each test case there is at least one pair with $r_i$ equal to $1$ and that the total length of all strings over all test cases doesn't exceed $4 \cdot 10^5$.

### Output

For each test case, firstly print integer $m$ — the number of possible non-negative integer values of $k$ such that pairs that have to rhyme, rhyme and pairs that must not rhyme, don't rhyme. Next, print all these values of $k$ (without repetitions). You can print them in any order.

## Example

### Input


```text
3
1
kotlin heroes 1
2
join kotlin 1
episode eight 0
4
abc abcdef 0
xyz zzz 1
aaa bba 0
c d 0
```
### Output


```text
1
0
2
1 2
0
```
## Note

In the first test case, if $k$ is at least $1$ then kotlin and heroes don't rhyme.

In the second test case, for $k = 2$ join and kotlin rhyme, and episode and eight don't rhyme.



#### Tags 

#1800 #NOT OK #*special #implementation 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_8.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
