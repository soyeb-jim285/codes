<h1 style='text-align: center;'> C. Pokémon Arena</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are at a dueling arena. You also possess $n$ Pokémons. Initially, only the $1$-st Pokémon is standing in the arena.

Each Pokémon has $m$ attributes. The $j$-th attribute of the $i$-th Pokémon is $a_{i,j}$. Each Pokémon also has a cost to be hired: the $i$-th Pokémon's cost is $c_i$.

You want to have the $n$-th Pokémon stand in the arena. To do that, you can perform the following two types of operations any number of times in any order: 

* Choose three integers $i$, $j$, $k$ ($1 \le i \le n$, $1 \le j \le m$, $k > 0$), increase $a_{i,j}$ by $k$ permanently. The cost of this operation is $k$.
* Choose two integers $i$, $j$ ($1 \le i \le n$, $1 \le j \le m$) and hire the $i$-th Pokémon to duel with the current Pokémon in the arena based on the $j$-th attribute. The $i$-th Pokémon will win if $a_{i,j}$ is greater than or equal to the $j$-th attribute of the current Pokémon in the arena (otherwise, it will lose). After the duel, only the winner will stand in the arena. The cost of this operation is $c_i$.

Find the minimum cost you need to pay to have the $n$-th Pokémon stand in the arena.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n \le 4 \cdot 10^5$, $1 \le m \le 2 \cdot 10^5$, $2 \leq n \cdot m \leq 4 \cdot 10^5$).

The second line of each test case contains $n$ integers $c_1, c_2, \ldots, c_n$ ($1 \le c_i \le 10^9$).

The $i$-th of the following $n$ lines contains $m$ integers $a_{i,1}, a_{i,2}, \ldots, a_{i,m}$ ($1 \le a_{i,j} \le 10^9$).

It is guaranteed that the sum of $n \cdot m$ over all test cases does not exceed $4 \cdot 10^5$.

## Output

For each test case, output the minimum cost to make the $n$-th Pokémon stand in the arena.

## Example

## Input


```

43 32 3 12 9 96 1 71 2 13 32 3 19 9 96 1 71 2 14 22 8 3 518 2417 101 101 16 321412674 3212925 172015806 250849370 306960171 333018900950000001 950000001 950000001821757276 783362401 760000001570000001 700246226 600757652380000001 423513575 474035234315201473 300580025 2870234451 1 1
```
## Output


```

2
6
17
1224474550

```
## Note

In the first test case, the attribute array of the $1$-st Pokémon (which is standing in the arena initially) is $[2,9,9]$.

In the first operation, you can choose $i=3$, $j=1$, $k=1$, and increase $a_{3,1}$ by $1$ permanently. Now the attribute array of the $3$-rd Pokémon is $[2,2,1]$. The cost of this operation is $k = 1$.

In the second operation, you can choose $i=3$, $j=1$, and hire the $3$-rd Pokémon to duel with the current Pokémon in the arena based on the $1$-st attribute. Since $a_{i,j}=a_{3,1}=2 \ge 2=a_{1,1}$, the $3$-rd Pokémon will win. The cost of this operation is $c_3 = 1$.

Thus, we have made the $3$-rd Pokémon stand in the arena within the cost of $2$. It can be proven that $2$ is minimum possible.

In the second test case, the attribute array of the $1$-st Pokémon in the arena is $[9,9,9]$.

In the first operation, you can choose $i=2$, $j=3$, $k=2$, and increase $a_{2,3}$ by $2$ permanently. Now the attribute array of the $2$-nd Pokémon is $[6,1,9]$. The cost of this operation is $k = 2$.

In the second operation, you can choose $i=2$, $j=3$, and hire the $2$-nd Pokémon to duel with the current Pokémon in the arena based on the $3$-rd attribute. Since $a_{i,j}=a_{2,3}=9 \ge 9=a_{1,3}$, the $2$-nd Pokémon will win. The cost of this operation is $c_2 = 3$.

In the third operation, you can choose $i=3$, $j=2$, and hire the $3$-rd Pokémon to duel with the current Pokémon in the arena based on the $2$-nd attribute. Since $a_{i,j}=a_{1,2}=2 \ge 1=a_{2,2}$, the $3$-rd Pokémon can win. The cost of this operation is $c_3 = 1$.

Thus, we have made the $3$-rd Pokémon stand in the arena within the cost of $6$. It can be proven that $6$ is minimum possible.



#### tags 

#2400 #data_structures #graphs #greedy #implementation #shortest_paths #sortings 