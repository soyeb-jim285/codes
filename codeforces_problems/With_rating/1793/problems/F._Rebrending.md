<h1 style='text-align: center;'> F. Rebrending</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kostya and Zhenya — the creators of the band "Paper" — after the release of the legendary album decided to create a new band "Day movers", for this they need to find two new people.

They invited $n$ people to the casting. The casting will last $q$ days. On the $i$th of the days, Kostya and Zhenya want to find two people on the segment from $l_i$ to $r_i$ who are most suitable for their band. Since "Day movers" are doing a modern art, musical skills are not important to them and they look only at other signs: they want the height difference between two people to be as small as possible.

Help them, and for each day, find the minimum difference in the growth of people from the casting on this segment!

##### Input

In the first line you are given two integers $n$ and $q$ ($2 \leq n \leq 3 \cdot 10^5, 1 \leq q \leq 10^6$) — the number of people who came to the casting and the number of casting days.

In the second line, you are given $n$ integers $a_1, a_2, a_3, \ldots, a_n$ ($1 \leq a_i \leq n$) — the growth of each of the candidates.

It is also guaranteed that all $a_i$ are different.

The following $q$ lines each contains two integers $l_i$ and $r_i$ ($1 \leq l_i < r_i \leq n$) — a segment of people on the $i$th day of casting.

##### Output

##### Output

 $q$ lines. In the $i$-th line there should be a minimum height difference between the two candidates on the segment on the $i$-th day of casting.

## Examples

##### Input


```text
3 31 3 21 22 31 3
```
##### Output

```text

2
1
1

```
##### Input


```text
5 34 1 5 3 21 23 42 4
```
##### Output

```text

3
2
2

```
##### Input


```text
7 42 6 1 7 3 5 44 61 23 61 3
```
##### Output

```text

2
4
2
1

```
## Note

In the first example, the minimum difference on the segment $[1, 2]$ is $2$, on the segment $[2, 3]$ — $1$, on the segment $[1, 3]$ is also $1$.

In the third example, the numbers with the minimum difference on the segment $[4, 6]$ are $3$ and $5$ ($5 - 3 = 2$). On the segment $[1, 2]$, the numbers with the minimum difference are $2$ and $6$ ($6 - 2 = 4$). On the segment $[3, 6]$, the numbers with the minimum difference are $1$ and $3$ ($3 - 1 = 2$). On the segment $[1, 3]$, the minimum difference is formed by the numbers $1$ and $2$ ($2 - 1 = 1$).



#### Tags 

#2600 #NOT OK #brute_force #data_structures #divide_and_conquer #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_852_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
