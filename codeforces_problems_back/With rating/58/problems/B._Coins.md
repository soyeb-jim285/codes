<h1 style='text-align: center;'> B. Coins</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Berland a money reform is being prepared. New coins are being introduced. After long economic calculations was decided that the most expensive coin should possess the denomination of exactly *n* Berland dollars. Also the following restriction has been introduced for comfort: the denomination of each coin should be divisible by the denomination of any cheaper coin. It is known that among all the possible variants the variant with the largest number of new coins will be chosen. Find this variant. Print in the order of decreasing of the coins' denominations.

## Input

The first and only line contains an integer *n* (1 ≤ *n* ≤ 106) which represents the denomination of the most expensive coin. 

## Output

Print the denominations of all the coins in the order of decreasing. The number of coins must be the largest possible (with the given denomination *n* of the most expensive coin). Also, the denomination of every coin must be divisible by the denomination of any cheaper coin. Naturally, the denominations of all the coins should be different. If there are several solutins to that problem, print any of them.

## Examples

## Input


```
10  

```
## Output


```
10 5 1  

```
## Input


```
4  

```
## Output


```
4 2 1  

```
## Input


```
3  

```
## Output


```
3 1  

```


#### tags 

#1300 #greedy 