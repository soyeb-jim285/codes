<h1 style='text-align: center;'> E. Level Up</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp is playing a computer game. He starts the game being level $1$. He is about to fight $n$ monsters, in order from $1$ to $n$. The level of the $i$-th monster is $a_i$.

For each monster in the given order, Monocarp's encounter goes as follows:

* if Monocarp's level is strictly higher than the monster's level, the monster flees (runs away);
* otherwise, Monocarp fights the monster.

After every $k$-th fight with a monster (fleeing monsters do not count), Monocarp's level increases by $1$. So, his level becomes $2$ after $k$ monsters he fights, $3$ after $2k$ monsters, $4$ after $3k$ monsters, and so on.

You need to process $q$ queries of the following form:

* $i~x$: will Monocarp fight the $i$-th monster (or will this monster flee) if the parameter $k$ is equal to $x$?
#### Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$) — the number of monsters and the number of queries.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$) — the levels of the monsters.

In the $j$-th of the following $q$ lines, two integers $i$ and $x$ ($1 \le i, x \le n$) — the index of the monster and the number of fights required for a level up in the $j$-th query.

#### Output

For each query, output "YES", if Monocarp will fight the $i$-th monster in this query, and "NO", if the $i$-th monster flees.

## Examples

#### Input


```text
4 162 1 2 11 12 13 14 11 22 23 24 21 32 33 34 31 42 43 44 4
```
#### Output

```text

YES
NO
YES
NO
YES
YES
YES
NO
YES
YES
YES
NO
YES
YES
YES
YES

```
#### Input


```text
7 151 1 2 1 1 1 15 32 22 21 65 15 57 73 57 44 32 51 25 64 16 1
```
#### Output

```text

NO
YES
YES
YES
NO
YES
YES
YES
NO
NO
YES
YES
YES
NO
NO

```


#### Tags 

#NOT OK #binary_search #brute_force #data_structures #divide_and_conquer #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_168_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
