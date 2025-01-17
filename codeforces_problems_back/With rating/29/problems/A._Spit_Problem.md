<h1 style='text-align: center;'> A. Spit Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a Berland's zoo there is an enclosure with camels. It is known that camels like to spit. Bob watched these interesting animals for the whole day and registered in his notepad where each animal spitted. Now he wants to know if in the zoo there are two camels, which spitted at each other. Help him to solve this task.

The trajectory of a camel's spit is an arc, i.e. if the camel in position *x* spits *d* meters right, he can hit only the camel in position *x* + *d*, if such a camel exists.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 100) — the amount of camels in the zoo. Each of the following *n* lines contains two integers *x**i* and *d**i* ( - 104 ≤ *x**i* ≤ 104, 1 ≤ |*d**i*| ≤ 2·104) — records in Bob's notepad. *x**i* is a position of the *i*-th camel, and *d**i* is a distance at which the *i*-th camel spitted. Positive values of *d**i* correspond to the spits right, negative values correspond to the spits left. No two camels may stand in the same position.

## Output

If there are two camels, which spitted at each other, output YES. Otherwise, output NO.

## Examples

## Input


```
2  
0 1  
1 -1  

```
## Output


```
YES  

```
## Input


```
3  
0 1  
1 1  
2 -2  

```
## Output


```
NO  

```
## Input


```
5  
2 -10  
3 10  
0 5  
5 -5  
10 1  

```
## Output


```
YES  

```


#### tags 

#1000 #brute_force 