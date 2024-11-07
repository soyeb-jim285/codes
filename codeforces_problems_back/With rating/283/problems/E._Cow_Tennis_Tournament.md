<h1 style='text-align: center;'> E. Cow Tennis Tournament</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Farmer John is hosting a tennis tournament with his *n* cows. Each cow has a skill level *s**i*, and no two cows having the same skill level. Every cow plays every other cow exactly once in the tournament, and each cow beats every cow with skill level lower than its own.

However, Farmer John thinks the tournament will be demoralizing for the weakest cows who lose most or all of their matches, so he wants to flip some of the results. In particular, at *k* different instances, he will take two integers *a**i*, *b**i* (*a**i* < *b**i*) and flip all the results between cows with skill level between *a**i* and *b**i* inclusive. That is, for any pair *x*, *y* ![](images/57add0354e27dbc2e3c27b74ec0078855596d12b.png) he will change the result of the match on the final scoreboard (so if *x* won the match, the scoreboard will now display that *y* won the match, and vice versa). It is possible that Farmer John will change the result of a match multiple times. It is not guaranteed that *a**i* and *b**i* are equal to some cow's skill level.

Farmer John wants to determine how balanced he made the tournament results look. In particular, he wants to count the number of triples of cows (*p*, *q*, *r*) for which the final leaderboard shows that cow *p* beats cow *q*, cow *q* beats cow *r*, and cow *r* beats cow *p*. Help him determine this number.

## Note

 that two triples are considered different if they do not contain the same set of cows (i.e. if there is a cow in one triple that is not in the other).

## Input

On the first line are two space-separated integers, *n* and *k* (3 ≤ *n* ≤ 105; 0 ≤ *k* ≤ 105). On the next line are *n* space-separated distinct integers, *s*1, *s*2, ..., *s**n* (1 ≤ *s**i* ≤ 109), denoting the skill levels of the cows. On the next *k* lines are two space separated integers, *a**i* and *b**i* (1 ≤ *a**i* < *b**i* ≤ 109) representing the changes Farmer John made to the scoreboard in the order he makes it.

## Output

A single integer, containing the number of triples of cows (*p*, *q*, *r*) for which the final leaderboard shows that cow *p* beats cow *q*, cow *q* beats cow *r*, and cow *r* beats cow *p*.

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3 2  
1 2 3  
1 2  
2 3  

```
## Output


```
1  

```
## Input


```
5 3  
5 9 4 1 7  
1 7  
2 8  
3 9  

```
## Output


```
3  

```
## Note

In the first sample, cow 3 > cow 1, cow 3 > cow 2, and cow 2 > cow 1. However, the results between cows 1 and 2 and cows 2 and 3 are flipped, so now FJ's results show that cow 1 > cow 2, cow 2 > cow 3, and cow 3 > cow 1, so cows 1, 2, and 3 form a balanced triple. 



#### tags 

#2800 #combinatorics #data_structures #math 