<h1 style='text-align: center;'> F. Editorial for Two</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland Intercollegiate Contest has just finished. Monocarp and Polycarp, as the jury, are going to conduct an editorial. Unfortunately, the time is limited, since they have to finish before the closing ceremony.

There were $n$ problems in the contest. The problems are numbered from $1$ to $n$. The editorial for the $i$-th problem takes $a_i$ minutes. Monocarp and Polycarp are going to conduct an editorial for exactly $k$ of the problems.

The editorial goes as follows. They have a full problemset of $n$ problems before them, in order. They remove $n - k$ problems without changing the order of the remaining $k$ problems. Then, Monocarp takes some prefix of these $k$ problems (possibly, an empty one or all problems). Polycarp takes the remaining suffix of them. After that, they go to different rooms and conduct editorials for their problems in parallel. So, the editorial takes as much time as the longer of these two does.

Please, help Monocarp and Polycarp to choose the problems and the split in such a way that the editorial finishes as early as possible. Print the duration of the editorial.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains two integers $n$ and $k$ ($1 \le k \le n \le 3 \cdot 10^5$) — the number of problems in the full problemset and the number of problems Monocarp and Polycarp are going to conduct an editorial for.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the time each editorial takes.

The sum of $n$ over all testcases doesn't exceed $3 \cdot 10^5$.

### Output

For each testcase, print a single integer — the smallest amount of time the editorial takes, if Monocarp and Polycarp can choose which $k$ of $n$ problems to conduct an editorial for and how to split them among themselves.

## Example

### Input


```text
65 41 10 1 1 15 31 20 5 15 35 31 20 3 15 510 610 8 20 14 3 8 6 4 16 1110 59 9 2 13 15 19 4 9 13 121 11
```
### Output

```text

2
6
5
21
18
1

```


#### Tags 

#2400 #NOT OK #binary_search #data_structures #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_149_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
