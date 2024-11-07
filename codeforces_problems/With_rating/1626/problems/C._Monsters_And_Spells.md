<h1 style='text-align: center;'> C. Monsters And Spells</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing a computer game once again. He is a wizard apprentice, who only knows a single spell. Luckily, this spell can damage the monsters.

The level he's currently on contains $n$ monsters. The $i$-th of them appears $k_i$ seconds after the start of the level and has $h_i$ health points. As an additional constraint, $h_i \le k_i$ for all $1 \le i \le n$. All $k_i$ are different.

Monocarp can cast the spell at moments which are positive integer amounts of second after the start of the level: $1, 2, 3, \dots$ The damage of the spell is calculated as follows. If he didn't cast the spell at the previous second, the damage is $1$. Otherwise, let the damage at the previous second be $x$. Then he can choose the damage to be either $x + 1$ or $1$. A spell uses mana: casting a spell with damage $x$ uses $x$ mana. Mana doesn't regenerate.

To kill the $i$-th monster, Monocarp has to cast a spell with damage at least $h_i$ at the exact moment the monster appears, which is $k_i$.

## Note

 that Monocarp can cast the spell even when there is no monster at the current second.

The mana amount required to cast the spells is the sum of mana usages for all cast spells. Calculate the least amount of mana required for Monocarp to kill all monsters.

It can be shown that it's always possible to kill all monsters under the constraints of the problem.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of the testcase contains a single integer $n$ ($1 \le n \le 100$) — the number of monsters in the level.

The second line of the testcase contains $n$ integers $k_1 < k_2 < \dots < k_n$ ($1 \le k_i \le 10^9$) — the number of second from the start the $i$-th monster appears at. All $k_i$ are different, $k_i$ are provided in the increasing order.

The third line of the testcase contains $n$ integers $h_1, h_2, \dots, h_n$ ($1 \le h_i \le k_i \le 10^9$) — the health of the $i$-th monster.

The sum of $n$ over all testcases doesn't exceed $10^4$.

### Output

For each testcase, print a single integer — the least amount of mana required for Monocarp to kill all monsters.

## Example

### Input


```text
316424 52 235 7 92 1 2
```
### Output

```text

10
6
7

```
## Note

In the first testcase of the example, Monocarp can cast spells $3, 4, 5$ and $6$ seconds from the start with damages $1, 2, 3$ and $4$, respectively. The damage dealt at $6$ seconds is $4$, which is indeed greater than or equal to the health of the monster that appears.

In the second testcase of the example, Monocarp can cast spells $3, 4$ and $5$ seconds from the start with damages $1, 2$ and $3$, respectively.

In the third testcase of the example, Monocarp can cast spells $4, 5, 7, 8$ and $9$ seconds from the start with damages $1, 2, 1, 1$ and $2$, respectively.



#### Tags 

#1700 #NOT OK #binary_search #data_structures #dp #greedy #implementation #math #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_121_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
