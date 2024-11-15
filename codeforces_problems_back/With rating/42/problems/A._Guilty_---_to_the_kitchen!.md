<h1 style='text-align: center;'> A. Guilty — to the kitchen!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It's a very unfortunate day for Volodya today. He got bad mark in algebra and was therefore forced to do some work in the kitchen, namely to cook borscht (traditional Russian soup). This should also improve his algebra skills.

According to the borscht recipe it consists of *n* ingredients that have to be mixed in proportion ![](images/4467b8f0f99d920b459ab653d9632f721329571b.png) litres (thus, there should be *a*1 ·*x*, ..., *a**n* ·*x* litres of corresponding ingredients mixed for some non-negative *x*). In the kitchen Volodya found out that he has *b*1, ..., *b**n* litres of these ingredients at his disposal correspondingly. In order to correct his algebra mistakes he ought to cook as much soup as possible in a *V* litres volume pan (which means the amount of soup cooked can be between 0 and *V* litres). What is the volume of borscht Volodya will cook ultimately?

## Input

The first line of the input contains two space-separated integers *n* and *V* (1 ≤ *n* ≤ 20, 1 ≤ *V* ≤ 10000). The next line contains *n* space-separated integers *a**i* (1 ≤ *a**i* ≤ 100). Finally, the last line contains *n* space-separated integers *b**i* (0 ≤ *b**i* ≤ 100).

## Output

Your program should output just one real number — the volume of soup that Volodya will cook. Your answer must have a relative or absolute error less than 10- 4.

## Examples

## Input


```
1 100  
1  
40  

```
## Output


```
40.0  

```
## Input


```
2 100  
1 1  
25 30  

```
## Output


```
50.0  

```
## Input


```
2 100  
1 1  
60 60  

```
## Output


```
100.0  

```


#### tags 

#1400 #greedy #implementation 