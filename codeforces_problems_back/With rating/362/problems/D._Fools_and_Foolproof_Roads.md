<h1 style='text-align: center;'> D. Fools and Foolproof Roads</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You must have heard all about the Foolland on your Geography lessons. Specifically, you must know that federal structure of this country has been the same for many centuries. The country consists of *n* cities, some pairs of cities are connected by bidirectional roads, each road is described by its length *l**i*.

The fools lived in their land joyfully, but a recent revolution changed the king. Now the king is Vasily the Bear. Vasily divided the country cities into regions, so that any two cities of the same region have a path along the roads between them and any two cities of different regions don't have such path. Then Vasily decided to upgrade the road network and construct exactly *p* new roads in the country. Constructing a road goes like this:

1. We choose a pair of distinct cities *u*, *v* that will be connected by a new road (at that, it is possible that there already is a road between these cities).
2. We define the length of the new road: if cities *u*, *v* belong to distinct regions, then the length is calculated as *min*(109, *S* + 1) (*S* — the total length of all roads that exist in the linked regions), otherwise we assume that the length equals 1000.
3. We build a road of the specified length between the chosen cities. If the new road connects two distinct regions, after construction of the road these regions are combined into one new region.

Vasily wants the road constructing process to result in the country that consists exactly of *q* regions. Your task is to come up with such road constructing plan for Vasily that it meets the requirement and minimizes the total length of the built roads.

## Input

The first line contains four integers *n* (1 ≤ *n* ≤ 105), *m* (0 ≤ *m* ≤ 105), *p* (0 ≤ *p* ≤ 105), *q* (1 ≤ *q* ≤ *n*) — the number of cities in the Foolland, the number of existing roads, the number of roads that are planned to construct and the required number of regions.

Next *m* lines describe the roads that exist by the moment upgrading of the roads begun. Each of these lines contains three integers *x**i*, *y**i*, *l**i*: *x**i*, *y**i* — the numbers of the cities connected by this road (1 ≤ *x**i*, *y**i* ≤ *n*, *x**i* ≠ *y**i*), *l**i* — length of the road (1 ≤ *l**i* ≤ 109). ## Note

 that one pair of cities can be connected with multiple roads.

## Output

If constructing the roads in the required way is impossible, print a single string "NO" (without the quotes). Otherwise, in the first line print word "YES" (without the quotes), and in the next *p* lines print the road construction plan. Each line of the plan must consist of two distinct integers, giving the numbers of the cities connected by a road. The road must occur in the plan in the order they need to be constructed. If there are multiple optimal solutions, you can print any of them.

## Examples

## Input


```
9 6 2 2  
1 2 2  
3 2 1  
4 6 20  
1 3 8  
7 8 3  
5 7 2  

```
## Output


```
YES  
9 5  
1 9  

```
## Input


```
2 0 1 2  

```
## Output


```
NO  

```
## Input


```
2 0 0 2  

```
## Output


```
YES  

```
## Note

Consider the first sample. Before the reform the Foolland consists of four regions. The first region includes cities 1, 2, 3, the second region has cities 4 and 6, the third region has cities 5, 7, 8, the fourth region has city 9. The total length of the roads in these cities is 11, 20, 5 and 0, correspondingly. According to the plan, we first build the road of length 6 between cities 5 and 9, then the road of length 23 between cities 1 and 9. Thus, the total length of the built roads equals 29.



#### tags 

#2100 #data_structures #dfs_and_similar #dsu #graphs #greedy 