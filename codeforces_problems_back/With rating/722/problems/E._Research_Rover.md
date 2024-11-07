<h1 style='text-align: center;'> E. Research Rover</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Unfortunately, the formal description of the task turned out to be too long, so here is the legend.

Research rover finally reached the surface of Mars and is ready to complete its mission. Unfortunately, due to the mistake in the navigation system design, the rover is located in the wrong place.

The rover will operate on the grid consisting of *n* rows and *m* columns. We will define as (*r*, *c*) the cell located in the row *r* and column *c*. From each cell the rover is able to move to any cell that share a side with the current one.

The rover is currently located at cell (1, 1) and has to move to the cell (*n*, *m*). It will randomly follow some shortest path between these two cells. Each possible way is chosen equiprobably.

The cargo section of the rover contains the battery required to conduct the research. Initially, the battery charge is equal to *s* units of energy.

Some of the cells contain anomaly. Each time the rover gets to the cell with anomaly, the battery looses half of its charge rounded down. Formally, if the charge was equal to *x* before the rover gets to the cell with anomaly, the charge will change to ![](images/f12f73ab57d327f2f2cb7c8de54e8e6e246f6b2e.png).

While the rover picks a random shortest path to proceed, compute the expected value of the battery charge after it reaches cell (*n*, *m*). If the cells (1, 1) and (*n*, *m*) contain anomaly, they also affect the charge of the battery.

## Input

The first line of the input contains four integers *n*, *m*, *k* and *s* (1 ≤ *n*, *m* ≤ 100 000, 0 ≤ *k* ≤ 2000, 1 ≤ *s* ≤ 1 000 000) — the number of rows and columns of the field, the number of cells with anomaly and the initial charge of the battery respectively.

The follow *k* lines containing two integers *r**i* and *c**i* (1 ≤ *r**i* ≤ *n*, 1 ≤ *c**i* ≤ *m*) — coordinates of the cells, containing anomaly. It's guaranteed that each cell appears in this list no more than once.

## Output

The answer can always be represented as an irreducible fraction ![](images/46898f7da6d890f88194a3d5535e5e990ecdd3fa.png). Print the only integer *P*·*Q*- 1 modulo 109 + 7.

## Examples

## Input


```
3 3 2 11  
2 1  
2 3  

```
## Output


```
333333342  

```
## Input


```
4 5 3 17  
1 2  
3 3  
4 1  

```
## Output


```
514285727  

```
## Input


```
1 6 2 15  
1 1  
1 5  

```
## Output


```
4  

```
## Note

In the first sample, the rover picks one of the following six routes:

1. ![](images/c9ec158c30775d6289140a3854e05168b09af399.png), after passing cell (2, 3) charge is equal to 6.
2. ![](images/fcc490c05d2acb731046a7c4c861f4c9ebff3633.png), after passing cell (2, 3) charge is equal to 6.
3. ![](images/8d5828aadc35714d7a3453c40de81ad186e87ab3.png), charge remains unchanged and equals 11.
4. ![](images/3bc680a61ca3712bbbec0eb682f3af16ab7664a2.png), after passing cells (2, 1) and (2, 3) charge equals 6 and then 3.
5. ![](images/9a87005ef2b3eb1efc9e486e608fadf3a5b557fa.png), after passing cell (2, 1) charge is equal to 6.
6. ![](images/342ddbff927874c07e9d307d73383aa50f2117b6.png), after passing cell (2, 1) charge is equal to 6.

Expected value of the battery charge is calculated by the following formula:

![](images/7ddca3ad80b71df649b7beb01944a4ad8f863265.png).

Thus *P* = 19, and *Q* = 3.

3- 1 modulo 109 + 7 equals 333333336.

19·333333336 = 333333342 (*mod* 109 + 7)



#### tags 

#2900 #combinatorics #dp 