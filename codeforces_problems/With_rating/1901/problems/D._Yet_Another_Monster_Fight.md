<h1 style='text-align: center;'> D. Yet Another Monster Fight</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya is a sorcerer that fights monsters. Again. There are $n$ monsters standing in a row, the amount of health points of the $i$-th monster is $a_i$.

Vasya is a very powerful sorcerer who knows many overpowered spells. In this fight, he decided to use a chain lightning spell to defeat all the monsters. Let's see how this spell works.

Firstly, Vasya chooses an index $i$ of some monster ($1 \le i \le n$) and the initial power of the spell $x$. Then the spell hits monsters exactly $n$ times, one hit per monster. The first target of the spell is always the monster $i$. For every target except for the first one, the chain lightning will choose a random monster who was not hit by the spell and is adjacent to one of the monsters that already was hit. So, each monster will be hit exactly once. The first monster hit by the spell receives $x$ damage, the second monster receives $(x-1)$ damage, the third receives $(x-2)$ damage, and so on.

Vasya wants to show how powerful he is, so he wants to kill all the monsters with a single chain lightning spell. The monster is considered dead if the damage he received is not less than the amount of its health points. On the other hand, Vasya wants to show he doesn't care that much, so he wants to choose the minimum initial power of the spell $x$ such that it kills all monsters, no matter which monster (among those who can get hit) gets hit on each step.

Of course, Vasya is a sorcerer, but the amount of calculations required to determine the optimal spell setup is way above his possibilities, so you have to help him find the minimum spell power required to kill all the monsters.

Note that Vasya chooses the initial target and the power of the spell, other things should be considered random and Vasya wants to kill all the monsters even in the worst possible scenario.

##### Input

The first line of the input contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of monsters.

The second line of the input contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the amount of health points of the $i$-th monster.

##### Output

Print one integer — the minimum spell power required to kill all the monsters if Vasya chooses the first target optimally, and the order of spell hits can be any possible within the given rules.

## Examples

##### Input


```text
6
2 1 5 6 4 3
```
##### Output


```text
8
```
##### Input


```text
5
4 4 4 4 4
```
##### Output


```text
8
```
##### Input


```text
2
1 1000000000
```
##### Output


```text
1000000000
```


#### Tags 

#1700 #NOT OK #binary_search #dp #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_158_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
