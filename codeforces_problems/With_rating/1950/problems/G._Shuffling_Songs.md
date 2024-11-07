<h1 style='text-align: center;'> G. Shuffling Songs</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vladislav has a playlist consisting of $n$ songs, numbered from $1$ to $n$. Song $i$ has genre $g_i$ and writer $w_i$. He wants to make a playlist in such a way that every pair of adjacent songs either have the same writer or are from the same genre (or both). He calls such a playlist exciting. Both $g_i$ and $w_i$ are strings of length no more than $10^4$.

It might not always be possible to make an exciting playlist using all the songs, so the shuffling process occurs in two steps. First, some amount (possibly zero) of the songs are removed, and then the remaining songs in the playlist are rearranged to make it exciting.

Since Vladislav doesn't like when songs get removed from his playlist, he wants the making playlist to perform as few removals as possible. Help him find the minimum number of removals that need to be performed in order to be able to rearrange the rest of the songs to make the playlist exciting.

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 16$) — the number of songs in the original playlist.

Then $n$ lines follow, the $i$-th of which contains two strings of lowercase letters $g_i$ and $w_i$ ($1 \leq |g_i|, |w_i| \leq 10^4$) — the genre and the writer of the $i$-th song. Where $|g_i|$ and $|w_i|$ are lengths of the strings.

The sum of $2^n$ over all test cases does not exceed $2^{16}$.

The sum of $|g_i| + |w_i|$ over all test cases does not exceed $4 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimum number of removals necessary so that the resulting playlist can be made exciting.

## Example

### Input


```text
41pop taylorswift4electronic themotanselectronic carlasdreamspop themotanspop irinarimes7rap eminemrap drdrerap kanyewestpop taylorswiftindierock arcticmonkeysindierock arcticmonkeyspunkrock theoffspring4a bc de fg h
```
### Output

```text

0
0
4
3

```
## Note

In the first test case, the playlist is already exciting.

In the second test case, if you have the songs in the order $4, 3, 1, 2$, it is exciting, so you don't need to remove any songs.

In the third test case, you can remove songs $4, 5, 6, 7$. Then the playlist with songs in the order $1, 2, 3$ is exciting.



#### Tags 

#1900 #NOT OK #bitmasks #dfs_and_similar #dp #graphs #hashing #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_937_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
