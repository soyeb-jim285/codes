<h1 style='text-align: center;'> D. Lonely Mountain Dungeons</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once, the people, elves, dwarves, and other inhabitants of Middle-earth gathered to reclaim the treasures stolen from them by Smaug. In the name of this great goal, they rallied around the powerful elf Timothy and began to plan the overthrow of the ruler of the Lonely Mountain.

The army of Middle-earth inhabitants will consist of several squads. It is known that each pair of creatures of the same race, which are in different squads, adds $b$ units to the total strength of the army. But since it will be difficult for Timothy to lead an army consisting of a large number of squads, the total strength of an army consisting of $k$ squads is reduced by $(k - 1) \cdot x$ units. ## Note

 that the army always consists of at least one squad.

It is known that there are $n$ races in Middle-earth, and the number of creatures of the $i$-th race is equal to $c_i$. Help the inhabitants of Middle-earth determine the maximum strength of the army they can assemble.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers $n$, $b$, and $x$ ($1 \le n \le 2 \cdot 10^5$, $1 \le b \le 10^6, 0 \le x \le 10^9$) — the number of races and the constants $b$ and $x$ described above.

The second line of each test case contains $n$ integers $c_1, c_2, \ldots, c_n$ ($1 \le c_i \le 2 \cdot 10^5$) — the number of creatures of each of the $n$ races.

It is guaranteed that the sum of the values $c_1 + c_2 + \ldots + c_n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the maximum strength of the army that the inhabitants of Middle-earth can assemble.

## Example

## Input


```

53 1 01 2 33 5 102 5 34 3 33 2 1 24 1 04 1 4 24 1 104 1 4 2
```
## Output


```

4
40
9
13
0

```
## Note

In the first test case, the inhabitants of Middle-earth can form $3$ squads. Since $x = 0$, the army's strength will not decrease due to the number of squads. The inhabitants can be distributed among the squads as follows:

* The single representative of the first species can be sent to the first squad.
* The first representative of the second species can be sent to the first squad, the second representative of the second species can be sent to the second squad. Then the total strength of the army will increase by $b = 1$.
* The first representative of the third species can be sent to the first squad, the second representative of the third species can be sent to the second squad, the third representative of the third species can be sent to the third squad. Then the total strength of the army will increase by $3 \cdot b = 3$, as they form three pairs in different squads.

Thus, the total strength of the army is $4$.

In the second test case, the inhabitants of Middle-earth can form $3$ squads. Since $x = 10$, the army's strength will decrease by $20$. The inhabitants can be distributed among the squads as follows:

* The first representative of the first species can be sent to the first squad, the second representative of the first species can be sent to the second squad. Then the total strength of the army will increase by $b = 5$.
* The first and second representatives of the second species can be sent to the first squad, the third and fourth representatives of the second species can be sent to the second squad, the fifth representative of the second species can be sent to the third squad. Then the total strength of the army will increase by $8 \cdot b = 40$.
* The first representative of the third species can be sent to the first squad, the second representative of the third species can be sent to the second squad, the third representative of the third species can be sent to the third squad. Then the total strength of the army will increase by $3 \cdot b = 15$, as they form three pairs in different squads.

Thus, the total strength of the army is $5 + 40 + 15 - 20 = 40$.



#### tags 

#1900 #brute_force #data_structures #greedy #math #ternary_search 