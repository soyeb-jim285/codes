<h1 style='text-align: center;'> F. Roads in the Kingdom</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the Kingdom K., there are *n* towns numbered with integers from 1 to *n*. The towns are connected by *n* bi-directional roads numbered with integers from 1 to *n*. The *i*-th road connects the towns *u**i* and *v**i* and its length is *l**i*. There is no more than one road between two towns. Also, there are no roads that connect the towns with itself.

Let's call the inconvenience of the roads the maximum of the shortest distances between all pairs of towns.

Because of lack of money, it was decided to close down one of the roads so that after its removal it is still possible to reach any town from any other. You have to find the minimum possible inconvenience of the roads after closing down one of the roads.

## Input

The first line contains the integer *n* (3 ≤ *n* ≤ 2·105) — the number of towns and roads.

The next *n* lines contain the roads description. The *i*-th from these lines contains three integers *u**i*, *v**i*, *l**i* (1 ≤ *u**i*, *v**i* ≤ *n*, 1 ≤ *l**i* ≤ 109) — the numbers of towns connected by the *i*-th road and the length of the *i*-th road. No road connects a town to itself, no two roads connect the same towns.

It's guaranteed that it's always possible to close down one of the roads so that all the towns are still reachable from each other.

## Output

Print a single integer — the minimum possible inconvenience of the roads after the refusal from one of the roads.

## Examples

## Input


```
3  
1 2 4  
2 3 5  
1 3 1  

```
## Output


```
5  

```
## Input


```
5  
2 3 7  
3 1 9  
4 1 8  
3 5 4  
4 5 5  

```
## Output


```
18  

```


#### tags 

#2500 #dfs_and_similar #dp #graphs #trees 