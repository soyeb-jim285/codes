<h1 style='text-align: center;'> A. Reconnaissance 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

*n* soldiers stand in a circle. For each soldier his height *a**i* is known. A reconnaissance unit can be made of such two neighbouring soldiers, whose heights difference is minimal, i.e. |*a**i* - *a**j*| is minimal. So each of them will be less noticeable with the other. ## Output

 any pair of soldiers that can form a reconnaissance unit.

## Input

The first line contains integer *n* (2 ≤ *n* ≤ 100) — amount of soldiers. Then follow the heights of the soldiers in their order in the circle — *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1000). The soldier heights are given in clockwise or counterclockwise direction.

## Output

## Output

 two integers — indexes of neighbouring soldiers, who should form a reconnaissance unit. If there are many optimum solutions, output any of them. Remember, that the soldiers stand in a circle.

## Examples

## Input


```
5  
10 12 13 15 10  

```
## Output


```
5 1  

```
## Input


```
4  
10 20 30 40  

```
## Output


```
1 2  

```


#### tags 

#800 #implementation 