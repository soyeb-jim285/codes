<h1 style='text-align: center;'> D. Roads in Yusland</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mayor of Yusland just won the lottery and decided to spent money on something good for town. For example, repair all the roads in the town.

Yusland consists of *n* intersections connected by *n* - 1 bidirectional roads. One can travel from any intersection to any other intersection using only these roads.

There is only one road repairing company in town, named "RC company". Company's center is located at the intersection 1. RC company doesn't repair roads you tell them. Instead, they have workers at some intersections, who can repair only some specific paths. The *i*-th worker can be paid *c**i* coins and then he repairs all roads on a path from *u**i* to some *v**i* that lies on the path from *u**i* to intersection 1. 

Mayor asks you to choose the cheapest way to hire some subset of workers in order to repair all the roads in Yusland. It's allowed that some roads will be repaired more than once.

If it's impossible to repair all roads print  - 1.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 300 000) — the number of cities in Yusland and the number of workers respectively.

Then follow *n*−1 line, each of them contains two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*) — indices of intersections connected by the *i*-th road.

Last *m* lines provide the description of workers, each line containing three integers *u**i*, *v**i* and *c**i* (1 ≤ *u**i*, *v**i* ≤ *n*, 1 ≤ *c**i* ≤ 109). This means that the *i*-th worker can repair all roads on the path from *v**i* to *u**i* for *c**i* coins. It's guaranteed that *v**i* lies on the path from *u**i* to 1. ## Note

 that *v**i* and *u**i* may coincide.

## Output

If it's impossible to repair all roads then print  - 1. Otherwise print a single integer — minimum cost required to repair all roads using "RC company" workers.

## Example

## Input


```
6 5  
1 2  
1 3  
3 4  
4 5  
4 6  
2 1 2  
3 1 4  
4 1 3  
5 3 1  
6 3 2  

```
## Output


```
8  

```
## Note

In the first sample, we should choose workers with indices 1, 3, 4 and 5, some roads will be repaired more than once but it is OK. The cost will be equal to 2 + 3 + 1 + 2 = 8 coins.



#### tags 

#2900 #data_structures #dp #greedy 