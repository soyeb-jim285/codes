<h1 style='text-align: center;'> B. Skills</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lesha plays the recently published new version of the legendary game hacknet. In this version character skill mechanism was introduced. Now, each player character has exactly *n* skills. Each skill is represented by a non-negative integer *a**i* — the current skill level. All skills have the same maximum level *A*.

Along with the skills, global ranking of all players was added. Players are ranked according to the so-called Force. The Force of a player is the sum of the following values:

* The number of skills that a character has perfected (i.e., such that *a**i* = *A*), multiplied by coefficient *c**f*.
* The minimum skill level among all skills (*min* *a**i*), multiplied by coefficient *c**m*.

Now Lesha has *m* hacknetian currency units, which he is willing to spend. Each currency unit can increase the current level of any skill by 1 (if it's not equal to *A* yet). Help him spend his money in order to achieve the maximum possible value of the Force.

## Input

The first line of the input contains five space-separated integers *n*, *A*, *c**f*, *c**m* and *m* (1 ≤ *n* ≤ 100 000, 1 ≤ *A* ≤ 109, 0 ≤ *c**f*, *c**m* ≤ 1000, 0 ≤ *m* ≤ 1015).

The second line contains exactly *n* integers *a**i* (0 ≤ *a**i* ≤ *A*), separated by spaces, — the current levels of skills.

## Output

On the first line print the maximum value of the Force that the character can achieve using no more than *m* currency units.

On the second line print *n* integers *a*'*i* (*a**i* ≤ *a*'*i* ≤ *A*), skill levels which one must achieve in order to reach the specified value of the Force, while using no more than *m* currency units. Numbers should be separated by spaces.

## Examples

## Input


```
3 5 10 1 5  
1 3 1  

```
## Output


```
12  
2 5 2   

```
## Input


```
3 5 10 1 339  
1 3 1  

```
## Output


```
35  
5 5 5   

```
## Note

In the first test the optimal strategy is to increase the second skill to its maximum, and increase the two others by 1.

In the second test one should increase all skills to maximum.



#### tags 

#1900 #binary_search #brute_force #dp #greedy #sortings #two_pointers 