<h1 style='text-align: center;'> D. Balancing Weapons</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You've got a job in a game studio that developed an online shooter, and your first big task is to help to balance weapons. The game has $n$ weapons: the $i$-th gun has an integer fire rate $f_i$ and an integer damage per bullet $d_i$. The $i$-th gun's total firepower is equal to $p_i = f_i \cdot d_i$.

You have to modify the values $d_i$ of some guns in such a way that the new values $d_i$ will still be integers, and the firepower of all guns will become balanced. Given an integer $k$, the guns are said to be balanced if $\max\limits_{1 \le i \le n}{p_i} - \min\limits_{1 \le i \le n}{p_i} \le k$.

Since gamers that play your game don't like big changes, you need to change the values $d_i$ for the minimum possible number of guns. What is the minimum number of guns for which you have to change these values to make the guns balanced?

## Note

 that the new values $d_i$ must be integers greater than $0$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($2 \le n \le 3000$; $0 \le k \le 1500$) — the number of guns to balance, and the maximum allowed gap between the most and the least powerful weapons.

The second line contains $n$ integers $f_1, f_2, \dots, f_n$ ($1 \le f_i \le 2000$), where $f_i$ is the fire rate of the $i$-th gun.

The third line contains $n$ integers $d_1, d_2, \dots, d_n$ ($1 \le d_i \le 10^9$), where $d_i$ is the damage per bullet of the $i$-th gun.

It's guaranteed that the sum of $n$ over all test cases doesn't exceed $3000$.

## Output

For each test case, print the minimum number of guns which damage $d_i$ you have to change in order to make the guns balanced.

## Note

 that the new values $d_i$ must be integers greater than $0$.

## Example

## Input


```

54 26 3 13 71 2 1 23 2100 101 102100 99 985 01 12 4 4 312 1 3 3 42 501000 101000000000 13 51 19 1149 4 72
```
## Output


```

2
3
0
1
2

```
## Note

In the first test case, you can set $d_1 = 2$ and $d_2 = 4$. You'll get an array $d = [2, 4, 1, 2]$, and the values of firepower will be $p = [12, 12, 13, 14]$. The guns are balanced, since $14 - 12 \le 2$.

In the second test case, you have to change the value $d_i$ for all three guns. For example, you can set $d = [5151, 5100, 5050]$.

In the third test case, all guns are already balanced, so you don't have to change anything.



#### tags 

#2500 #binary_search #brute_force #data_structures #math #two_pointers 