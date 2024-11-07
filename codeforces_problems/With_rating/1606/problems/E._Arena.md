<h1 style='text-align: center;'> E. Arena</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ heroes fighting in the arena. Initially, the $i$-th hero has $a_i$ health points.

The fight in the arena takes place in several rounds. At the beginning of each round, each alive hero deals $1$ damage to all other heroes. Hits of all heroes occur simultaneously. Heroes whose health is less than $1$ at the end of the round are considered killed.

If exactly $1$ hero remains alive after a certain round, then he is declared the winner. Otherwise, there is no winner.

Your task is to calculate the number of ways to choose the initial health points for each hero $a_i$, where $1 \le a_i \le x$, so that there is no winner of the fight. The number of ways can be very large, so print it modulo $998244353$. Two ways are considered different if at least one hero has a different amount of health. For example, $[1, 2, 1]$ and $[2, 1, 1]$ are different.

###### Input

The only line contains two integers $n$ and $x$ ($2 \le n \le 500; 1 \le x \le 500$).

###### Output

Print one integer — the number of ways to choose the initial health points for each hero $a_i$, where $1 \le a_i \le x$, so that there is no winner of the fight, taken modulo $998244353$. 

## Examples

###### Input


```text
2 5
```
###### Output


```text
5
```
###### Input


```text
3 3
```
###### Output


```text
15
```
###### Input


```text
5 4
```
###### Output


```text
1024
```
###### Input


```text
13 37
```
###### Output


```text
976890680
```


#### Tags 

#2100 #NOT OK #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_116_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
