<h1 style='text-align: center;'> D. Renting Bikes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A group of *n* schoolboys decided to ride bikes. As nobody of them has a bike, the boys need to rent them.

The renting site offered them *m* bikes. The renting price is different for different bikes, renting the *j*-th bike costs *p**j* rubles.

In total, the boys' shared budget is *a* rubles. Besides, each of them has his own personal money, the *i*-th boy has *b**i* personal rubles. The shared budget can be spent on any schoolchildren arbitrarily, but each boy's personal money can be spent on renting only this boy's bike.

Each boy can rent at most one bike, one cannot give his bike to somebody else.

What maximum number of schoolboys will be able to ride bikes? What minimum sum of personal money will they have to spend in total to let as many schoolchildren ride bikes as possible?

## Input

The first line of the input contains three integers *n*, *m* and *a* (1 ≤ *n*, *m* ≤ 105; 0 ≤ *a* ≤ 109). The second line contains the sequence of integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 104), where *b**i* is the amount of the *i*-th boy's personal money. The third line contains the sequence of integers *p*1, *p*2, ..., *p**m* (1 ≤ *p**j* ≤ 109), where *p**j* is the price for renting the *j*-th bike.

## Output

Print two integers *r* and *s*, where *r* is the maximum number of schoolboys that can rent a bike and *s* is the minimum total personal money needed to rent *r* bikes. If the schoolchildren cannot rent any bikes, then *r* = *s* = 0.

## Examples

## Input


```
2 2 10  
5 5  
7 6  

```
## Output


```
2 3  

```
## Input


```
4 5 2  
8 1 1 2  
6 3 7 5 2  

```
## Output


```
3 8  

```
## Note

In the first sample both schoolchildren can rent a bike. For instance, they can split the shared budget in half (5 rubles each). In this case one of them will have to pay 1 ruble from the personal money and the other one will have to pay 2 rubles from the personal money. In total, they spend 3 rubles of their personal money. This way of distribution of money minimizes the amount of spent personal money.



#### tags 

#1800 #binary_search #greedy 