<h1 style='text-align: center;'> F. Monocarp and a Strategic Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp plays a strategic computer game in which he develops a city. The city is inhabited by creatures of four different races — humans, elves, orcs, and dwarves.

Each inhabitant of the city has a happiness value, which is an integer. It depends on how many creatures of different races inhabit the city. Specifically, the happiness of each inhabitant is $0$ by default; it increases by $1$ for each other creature of the same race and decreases by $1$ for each creature of a hostile race. Humans are hostile to orcs (and vice versa), and elves are hostile to dwarves (and vice versa).

At the beginning of the game, Monocarp's city is not inhabited by anyone. During the game, $n$ groups of creatures will come to his city, wishing to settle there. The $i$-th group consists of $a_i$ humans, $b_i$ orcs, $c_i$ elves, and $d_i$ dwarves. Each time, Monocarp can either accept the entire group of creatures into the city, or reject the entire group.

The game calculates Monocarp's score according to the following formula: $m + k$, where $m$ is the number of inhabitants in the city, and $k$ is the sum of the happiness values of all creatures in the city.

Help Monocarp earn the maximum possible number of points by the end of the game!

## Input

The first line contains an integer $n$ ($1 \leq n \leq 3 \cdot 10^{5}$) — the number of groups of creatures that come to Monocarp's city.

Then $n$ lines follow. The $i$-th of them contains four integers $a_i$, $b_i$, $c_i$, and $d_i$ ($0 \leq a_i, b_i, c_i, d_i \leq 10^{9}$) — the number of humans, orcs, elves and dwarves (respectively) in the $i$-th group.

## Output

## Output

 a single number — the maximum score Monocarp can have by the end of the game. Your answer will be considered correct if its absolute or relative error does not exceed $10^{-9}$. That is, if your answer is $a$, and the jury's answer is $b$, then the solution will be accepted if $\frac{|a-b|}{\max(1,|b|)} \le 10^{-9}$.

## Note

 that the correct answer is always an integer, but sometimes it doesn't fit in $64$-bit integer types, so you are allowed to print it as a non-integer number.

## Examples

## Input


```

5
0 0 1 0
1 3 4 2
2 5 1 2
4 5 4 3
1 4 4 5

```
## Output


```

85

```
## Input


```

4
3 3 1 5
5 1 5 3
4 4 4 1
1 3 4 4

```
## Output


```

41

```
## Note

In the first example, the best course of action is to accept all of the groups.

In the second example, the best course of action is to accept the groups $2$ and $3$, and decline the groups $1$ and $4$.



#### tags 

#2700 #geometry #sortings #two_pointers 