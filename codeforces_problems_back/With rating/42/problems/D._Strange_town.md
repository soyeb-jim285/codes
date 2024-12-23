<h1 style='text-align: center;'> D. Strange town</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Volodya has recently visited a very odd town. There are *N* tourist attractions in the town and every two of them are connected by a bidirectional road. Each road has some travel price (natural number) assigned to it and all prices are distinct. But the most striking thing about this town is that each city sightseeing tour has the same total price! That is, if we choose any city sightseeing tour — a cycle which visits every attraction exactly once — the sum of the costs of the tour roads is independent of the tour. Volodya is curious if you can find such price system with all road prices not greater than 1000.

## Input

## Input

 contains just one natural number (3 ≤ *N* ≤ 20) — the number of town attractions.

## Output

## Output

 should contain *N* rows containing *N* positive integer numbers each — the adjacency matrix of the prices graph (thus, *j*-th number in *i*-th row should be equal to the price of the road between the *j*-th and the *i*-th attraction). Diagonal numbers should be equal to zero. All numbers should not be greater than 1000. All prices should be positive and pairwise distinct. If there are several solutions, output any of them.

## Examples

## Input


```
3  

```
## Output


```
0 3 4   
3 0 5   
4 5 0   

```


#### tags 

#2300 #constructive_algorithms #math 