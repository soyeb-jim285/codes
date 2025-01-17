<h1 style='text-align: center;'> B. Free Market</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

John Doe has recently found a "Free Market" in his city — that is the place where you can exchange some of your possessions for other things for free. 

John knows that his city has *n* items in total (each item is unique). You can bring any number of items to the market and exchange them for any other one. ## Note

 that each item is one of a kind and that means that you cannot exchange set {*a*, *b*} for set {*v*, *a*}. However, you can always exchange set *x* for any set *y*, unless there is item *p*, such that *p* occurs in *x* and *p* occurs in *y*.

For each item, John knows its value *c**i*. John's sense of justice doesn't let him exchange a set of items *x* for a set of items *y*, if *s*(*x*) + *d* < *s*(*y*) (*s*(*x*) is the total price of items in the set *x*). 

During one day John can exchange only one set of items for something else. Initially, he has no items. John wants to get a set of items with the maximum total price. Find the cost of such set and the minimum number of days John can get it in. 

## Input

The first line contains two space-separated integers *n*, *d* (1 ≤ *n* ≤ 50, 1 ≤ *d* ≤ 104) — the number of items on the market and John's sense of justice value, correspondingly. The second line contains *n* space-separated integers *c**i* (1 ≤ *c**i* ≤ 104).

## Output

Print two space-separated integers: the maximum possible price in the set of items John can get and the minimum number of days needed to get such set.

## Examples

## Input


```
3 2  
1 3 10  

```
## Output


```
4 3  

```
## Input


```
3 5  
1 2 3  

```
## Output


```
6 2  

```
## Input


```
10 10000  
10000 9999 1 10000 10000 10000 1 2 3 4  

```
## Output


```
50010 6  

```
## Note

In the first sample John can act like this: 

* Take the first item (1 - 0 ≤ 2).
* Exchange the first item for the second one (3 - 1 ≤ 2).
* Take the first item (1 - 0 ≤ 2).


#### tags 

#2200 #dp #greedy 