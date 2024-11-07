<h1 style='text-align: center;'> C. Bertown Subway</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The construction of subway in Bertown is almost finished! The President of Berland will visit this city soon to look at the new subway himself.

There are *n* stations in the subway. It was built according to the Bertown Transport Law:

1. For each station *i* there exists exactly one train that goes from this station. Its destination station is *p**i*, possibly *p**i* = *i*;
2. For each station *i* there exists exactly one station *j* such that *p**j* = *i*.

The President will consider the convenience of subway after visiting it. The convenience is the number of ordered pairs (*x*, *y*) such that person can start at station *x* and, after taking some subway trains (possibly zero), arrive at station *y* (1 ≤ *x*, *y* ≤ *n*).

The mayor of Bertown thinks that if the subway is not convenient enough, then the President might consider installing a new mayor (and, of course, the current mayor doesn't want it to happen). Before President visits the city mayor has enough time to rebuild some paths of subway, thus changing the values of *p**i* for not more than two subway stations. Of course, breaking the Bertown Transport Law is really bad, so the subway must be built according to the Law even after changes.

The mayor wants to do these changes in such a way that the convenience of the subway is maximized. Help him to calculate the maximum possible convenience he can get! 

## Input

The first line contains one integer number *n* (1 ≤ *n* ≤ 100000) — the number of stations.

The second line contains *n* integer numbers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the current structure of the subway. All these numbers are distinct.

## Output

Print one number — the maximum possible value of convenience.

## Examples

## Input


```
3  
2 1 3  

```
## Output


```
9  

```
## Input


```
5  
1 5 4 3 2  

```
## Output


```
17  

```
## Note

In the first example the mayor can change *p*2 to 3 and *p*3 to 1, so there will be 9 pairs: (1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3), (3, 1), (3, 2), (3, 3).

In the second example the mayor can change *p*2 to 4 and *p*3 to 5.



#### tags 

#1500 #dfs_and_similar #greedy #math 