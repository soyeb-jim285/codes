<h1 style='text-align: center;'> K. Send the Fool Further! (medium)</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Thank you for helping Heidi! It is now the second of April, but she has been summoned by Jenny again. The pranks do not seem to end...

In the meantime, Heidi has decided that she does not trust her friends anymore. Not too much, anyway. Her relative lack of trust is manifested as follows: whereas previously she would not be made to visit the same person twice, now she can only be sure that she will not be made to visit the same person more than *k* times. (In the case of Jenny, this includes her first visit in the beginning. The situation from the easy version corresponds to setting *k* = 1.)

This is not as bad as it looks, since a single ticket for a route between two friends allows Heidi to travel between this pair of friends the whole day (in both directions). In other words, once she pays for travel between a pair of friends, all further travels between that pair are free.

How much money will Heidi waste now, in a worst-case scenario?

## Input

The first line contains two space-separated integers – the number of friends *n* (![](images/6cfddf59d26f14b3f6f52cff132a0df05df10a0d.png)) and the parameter *k* (1 ≤ *k* ≤ 105). The next *n* - 1 lines each contain three space-separated integers *u*, *v* and *c* (0 ≤ *u*, *v* ≤ *n* - 1, 1 ≤ *c* ≤ 104) meaning that *u* and *v* are friends and the cost for traveling between *u* and *v* is *c*.

It is again guaranteed that the social network of the input forms a tree.

## Output

Again, output a single integer – the maximum sum of costs of tickets.

## Examples

## Input


```
9 3  
0 1 1  
0 2 1  
1 3 2  
1 4 2  
1 5 2  
2 6 3  
2 7 3  
2 8 3  

```
## Output


```
15  

```
## Input


```
9 5  
0 1 1  
0 2 1  
1 3 2  
1 4 2  
1 5 2  
2 6 3  
2 7 3  
2 8 3  

```
## Output


```
17  

```
## Input


```
11 6  
1 0 7932  
2 1 1952  
3 2 2227  
4 0 9112  
5 4 6067  
6 0 6786  
7 6 3883  
8 4 7137  
9 1 2796  
10 5 6200  

```
## Output


```
54092  

```
## Note

In the first example, the worst-case scenario for Heidi is to visit the friends in the following order: 0, 1, 5, 1, 3, 1, 0, 2, 6, 2, 7, 2, 8. Observe that no friend is visited more than 3 times.



#### tags 

#2100 #dp #trees 