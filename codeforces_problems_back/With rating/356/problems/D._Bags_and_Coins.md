<h1 style='text-align: center;'> D. Bags and Coins</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

When you were a child you must have been told a puzzle of bags and coins. Anyway, here's one of its versions: 

A horse has three bags. The first bag has one coin, the second bag has one coin and the third bag has three coins. In total, the horse has three coins in the bags. How is that possible? 

The answer is quite simple. The third bag contains a coin and two other bags. 

This problem is a generalization of the childhood puzzle. You have *n* bags. You know that the first bag contains *a*1 coins, the second bag contains *a*2 coins, ..., the *n*-th bag contains *a**n* coins. In total, there are *s* coins. Find the way to arrange the bags and coins so that they match the described scenario or else state that it is impossible to do.

## Input

The first line contains two integers *n* and *s* (1 ≤ *n*, *s* ≤ 70000) — the number of bags and the total number of coins. The next line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 70000), where *a**i* shows the number of coins in the *i*-th bag.

## Output

If the answer doesn't exist, print -1. 

Otherwise, print *n* lines, on the *i*-th line print the contents of the *i*-th bag. The first number in the line, *c**i* (0 ≤ *c**i* ≤ *a**i*), must represent the number of coins lying directly in the *i*-th bag (the coins in the bags that are in the *i*-th bag are not taken into consideration). The second number in the line, *k**i* (0 ≤ *k**i* < *n*) must represent the number of bags that lie directly in the *i*-th bag (the bags that are inside the bags lying in the *i*-th bag are not taken into consideration). Next, the line must contain *k**i* integers — the numbers of the bags that are lying directly in the *i*-th bag.

The total number of coins in the solution must equal *s*. If we count the total number of coins the *i*-th bag in the solution has, we should get *a**i*. 

No bag can directly lie in more than one bag. The bags can be nested in more than one level (see the second test case). If there are multiple correct answers, you can print any of them.

## Examples

## Input


```
3 3  
1 3 1  

```
## Output


```
1 0  
1 2 3 1  
1 0  

```
## Input


```
3 3  
1 3 1  

```
## Output


```
1 0  
2 1 3  
0 1 1  

```
## Input


```
1 2  
1  

```
## Output


```
-1  

```
## Input


```
8 10  
2 7 3 4 1 3 1 2  

```
## Output


```
2 0  
1 2 1 4  
0 2 7 8  
0 2 5 6  
1 0  
3 0  
1 0  
2 0  

```
## Note

The pictures below show two possible ways to solve one test case from the statement. The left picture corresponds to the first test case, the right picture corresponds to the second one.

 ![](images/7cff2ea9e29b147645657d9f20592a38b94cf3c4.png) 

#### tags 

#2700 #bitmasks #constructive_algorithms #dp #greedy 