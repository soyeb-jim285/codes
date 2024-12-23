<h1 style='text-align: center;'> C. Buns</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lavrenty, a baker, is going to make several buns with stuffings and sell them.

Lavrenty has *n* grams of dough as well as *m* different stuffing types. The stuffing types are numerated from 1 to *m*. Lavrenty knows that he has *a**i* grams left of the *i*-th stuffing. It takes exactly *b**i* grams of stuffing *i* and *c**i* grams of dough to cook a bun with the *i*-th stuffing. Such bun can be sold for *d**i* tugriks.

Also he can make buns without stuffings. Each of such buns requires *c*0 grams of dough and it can be sold for *d*0 tugriks. So Lavrenty can cook any number of buns with different stuffings or without it unless he runs out of dough and the stuffings. Lavrenty throws away all excess material left after baking.

Find the maximum number of tugriks Lavrenty can earn.

## Input

The first line contains 4 integers *n*, *m*, *c*0 and *d*0 (1 ≤ *n* ≤ 1000, 1 ≤ *m* ≤ 10, 1 ≤ *c*0, *d*0 ≤ 100). Each of the following *m* lines contains 4 integers. The *i*-th line contains numbers *a**i*, *b**i*, *c**i* and *d**i* (1 ≤ *a**i*, *b**i*, *c**i*, *d**i* ≤ 100).

## Output

Print the only number — the maximum number of tugriks Lavrenty can earn.

## Examples

## Input


```
10 2 2 1  
7 3 2 100  
12 3 1 10  

```
## Output


```
241
```
## Input


```
100 1 25 50  
15 5 20 10  

```
## Output


```
200
```
## Note

To get the maximum number of tugriks in the first sample, you need to cook 2 buns with stuffing 1, 4 buns with stuffing 2 and a bun without any stuffing.

In the second sample Lavrenty should cook 4 buns without stuffings.



#### tags 

#1700 #dp 