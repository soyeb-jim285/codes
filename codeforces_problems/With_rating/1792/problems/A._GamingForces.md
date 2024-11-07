<h1 style='text-align: center;'> A. GamingForces</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a computer game. He's going to kill $n$ monsters, the $i$-th of them has $h_i$ health.

Monocarp's character has two spells, either of which he can cast an arbitrary number of times (possibly, zero) and in an arbitrary order: 

* choose exactly two alive monsters and decrease their health by $1$;
* choose a single monster and kill it.

When a monster's health becomes $0$, it dies.

What's the minimum number of spell casts Monocarp should perform in order to kill all monsters?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 100$) — the number of monsters.

The second line contains $n$ integers $h_1, h_2, \dots, h_n$ ($1 \le h_i \le 100$) — the health of each monster.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^4$.

### Output

For each testcase, print a single integer — the minimum number of spell casts Monocarp should perform in order to kill all monsters.

## Example

### Input


```text
341 2 1 232 4 251 2 3 4 5
```
### Output

```text

3
3
5

```
## Note

In the first testcase, the initial health list is $[1, 2, 1, 2]$. Three spells are casted: 

* the first spell on monsters $1$ and $2$ — monster $1$ dies, monster $2$ has now health $1$, new health list is $[0, 1, 1, 2]$;
* the first spell on monsters $3$ and $4$ — monster $3$ dies, monster $4$ has now health $1$, new health list is $[0, 1, 0, 1]$;
* the first spell on monsters $2$ and $4$ — both monsters $2$ and $4$ die.

In the second testcase, the initial health list is $[2, 4, 2]$. Three spells are casted: 

* the first spell on monsters $1$ and $3$ — both monsters have health $1$ now, new health list is $[1, 4, 1]$;
* the second spell on monster $2$ — monster $2$ dies, new health list is $[1, 0, 1]$;
* the first spell on monsters $1$ and $3$ — both monsters $1$ and $3$ die.

In the third testcase, the initial health list is $[1, 2, 3, 4, 5]$. Five spells are casted. The $i$-th of them kills the $i$-th monster with the second spell. Health list sequence: $[1, 2, 3, 4, 5]$ $\rightarrow$ $[0, 2, 3, 4, 5]$ $\rightarrow$ $[0, 0, 3, 4, 5]$ $\rightarrow$ $[0, 0, 0, 4, 5]$ $\rightarrow$ $[0, 0, 0, 0, 5]$ $\rightarrow$ $[0, 0, 0, 0, 0]$.



#### Tags 

#800 #OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_142_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
