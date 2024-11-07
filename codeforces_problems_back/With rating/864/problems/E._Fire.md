<h1 style='text-align: center;'> E. Fire</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is in really serious trouble — his house is on fire! It's time to save the most valuable items. Polycarp estimated that it would take *t**i* seconds to save *i*-th item. In addition, for each item, he estimated the value of *d**i* — the moment after which the item *i* will be completely burned and will no longer be valuable for him at all. In particular, if *t**i* ≥ *d**i*, then *i*-th item cannot be saved.

Given the values *p**i* for each of the items, find a set of items that Polycarp can save such that the total value of this items is maximum possible. Polycarp saves the items one after another. For example, if he takes item *a* first, and then item *b*, then the item *a* will be saved in *t**a* seconds, and the item *b* — in *t**a* + *t**b* seconds after fire started.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of items in Polycarp's house.

Each of the following *n* lines contains three integers *t**i*, *d**i*, *p**i* (1 ≤ *t**i* ≤ 20, 1 ≤ *d**i* ≤ 2 000, 1 ≤ *p**i* ≤ 20) — the time needed to save the item *i*, the time after which the item *i* will burn completely and the value of item *i*.

## Output

In the first line print the maximum possible total value of the set of saved items. In the second line print one integer *m* — the number of items in the desired set. In the third line print *m* distinct integers — numbers of the saved items in the order Polycarp saves them. Items are 1-indexed in the same order in which they appear in the input. If there are several answers, print any of them.

## Examples

## Input


```
3  
3 7 4  
2 6 5  
3 7 6  

```
## Output


```
11  
2  
2 3   

```
## Input


```
2  
5 6 1  
3 3 5  

```
## Output


```
1  
1  
1   

```
## Note

In the first example Polycarp will have time to save any two items, but in order to maximize the total value of the saved items, he must save the second and the third item. For example, he can firstly save the third item in 3 seconds, and then save the second item in another 2 seconds. Thus, the total value of the saved items will be 6 + 5 = 11.

In the second example Polycarp can save only the first item, since even if he immediately starts saving the second item, he can save it in 3 seconds, but this item will already be completely burned by this time.



#### tags 

#2000 #dp #sortings 