<h1 style='text-align: center;'> C. Mushroom Strife</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pasha and Akim were making a forest map — the lawns were the graph's vertexes and the roads joining the lawns were its edges. They decided to encode the number of laughy mushrooms on every lawn in the following way: on every edge between two lawns they wrote two numbers, the greatest common divisor (GCD) and the least common multiple (LCM) of the number of mushrooms on these lawns. But one day Pasha and Akim had an argument about the laughy mushrooms and tore the map. Pasha was left with just some part of it, containing only *m* roads. Your task is to help Pasha — use the map he has to restore the number of mushrooms on every lawn. As the result is not necessarily unique, help Pasha to restore any one or report that such arrangement of mushrooms does not exist. It is guaranteed that the numbers on the roads on the initial map were no less that 1 and did not exceed 106.

## Input

The first line contains two numbers *n* and *m* (![](images/a187a1d9b67001db2abcc54c470f3f166a0fd081.png)) which are the numbers of lawns and roads we know about. Each of the following *m* lines contains four numbers which are the numbers of lawns the road connects, the GCD and the LCM of the numbers of mushrooms on these lawns (1 ≤ *GCD*, *LCM* ≤ 106).

It is guaranteed, that no road connects lawn to itself, and no two lawns are connected by more than one road.

## Output

The answer should contain "YES" or "NO" on the first line, saying whether it is possible or not to perform the arrangement. If the answer is "YES", print on the following line *n* numbers which are the numbers of mushrooms on the corresponding lawns.

## Examples

## Input


```
1 0  

```
## Output


```
YES  
1 
```
## Input


```
2 1  
1 2 1 3  

```
## Output


```
YES  
1 3 
```
## Input


```
3 2  
3 2 1 2  
3 1 1 10  

```
## Output


```
YES  
5 1 2 
```
## Input


```
2 1  
1 2 3 7  

```
## Output


```
NO  

```


#### tags 

#2100 #brute_force #dfs_and_similar 