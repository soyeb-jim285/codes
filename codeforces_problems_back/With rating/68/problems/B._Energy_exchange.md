<h1 style='text-align: center;'> B. Energy exchange</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It is well known that the planet suffers from the energy crisis. Little Petya doesn't like that and wants to save the world. For this purpose he needs every accumulator to contain the same amount of energy. Initially every accumulator has some amount of energy: the *i*-th accumulator has *a**i* units of energy. Energy can be transferred from one accumulator to the other. Every time *x* units of energy are transferred (*x* is not necessarily an integer) *k* percent of it is lost. That is, if *x* units were transferred from one accumulator to the other, amount of energy in the first one decreased by *x* units and in other increased by ![](images/5da936c833914e398476bcdcd55a9583860c2e5c.png) units.

Your task is to help Petya find what maximum equal amount of energy can be stored in each accumulator after the transfers.

## Input

First line of the input contains two integers *n* and *k* (1 ≤ *n* ≤ 10000, 0 ≤ *k* ≤ 99) — number of accumulators and the percent of energy that is lost during transfers.

Next line contains *n* integers *a*1, *a*2, ... , *a**n* — amounts of energy in the first, second, .., *n*-th accumulator respectively (0 ≤ *a**i* ≤ 1000, 1 ≤ *i* ≤ *n*).

## Output

## Output

 maximum possible amount of energy that can remain in each of accumulators after the transfers of energy.

The absolute or relative error in the answer should not exceed 10- 6.

## Examples

## Input


```
3 50  
4 2 1  

```
## Output


```
2.000000000  

```
## Input


```
2 90  
1 11  

```
## Output


```
1.909090909  

```


#### tags 

#1600 #binary_search 