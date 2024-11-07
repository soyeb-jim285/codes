<h1 style='text-align: center;'> F. Souvenirs</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Artsem is on vacation and wants to buy souvenirs for his two teammates. There are *n* souvenir shops along the street. In *i*-th shop Artsem can buy one souvenir for *a**i* dollars, and he cannot buy more than one souvenir in one shop. He doesn't want to introduce envy in his team, so he wants to buy two souvenirs with least possible difference in price.

Artsem has visited the shopping street *m* times. For some strange reason on the *i*-th day only shops with numbers from *l**i* to *r**i* were operating (weird? yes it is, but have you ever tried to come up with a reasonable legend for a range query problem?). For each visit, Artsem wants to know the minimum possible difference in prices of two different souvenirs he can buy in the opened shops.

In other words, for each Artsem's visit you should find the minimum possible value of |*a**s* - *a**t*| where *l**i* ≤ *s*, *t* ≤ *r**i*, *s* ≠ *t*.

## Input

The first line contains an integer *n* (2 ≤ *n* ≤ 105).

The second line contains *n* space-separated integers *a*1, ..., *a**n* (0 ≤ *a**i* ≤ 109).

The third line contains the number of queries *m* (1 ≤ *m* ≤ 3·105).

Next *m* lines describe the queries. *i*-th of these lines contains two space-separated integers *l**i* and *r**i* denoting the range of shops working on *i*-th day (1 ≤ *l**i* < *r**i* ≤ *n*).

## Output

Print the answer to each query in a separate line.

## Example

## Input


```
8  
3 1 4 1 5 9 2 6  
4  
1 8  
1 3  
4 8  
5 7  

```
## Output


```
0  
1  
1  
3  

```


#### tags 

#3100 #data_structures 