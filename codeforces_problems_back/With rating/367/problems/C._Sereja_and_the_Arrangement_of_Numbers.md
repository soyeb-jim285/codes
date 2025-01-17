<h1 style='text-align: center;'> C. Sereja and the Arrangement of Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an array consisting of *n* integer numbers *a*1, *a*2, ..., *a**n*, beautiful if it has the following property:

* consider all pairs of numbers *x*, *y* (*x* ≠ *y*), such that number *x* occurs in the array *a* and number *y* occurs in the array *a*;
* for each pair *x*, *y* must exist some position *j* (1 ≤ *j* < *n*), such that at least one of the two conditions are met, either *a**j* = *x*, *a**j* + 1 = *y*, or *a**j* = *y*, *a**j* + 1 = *x*.

Sereja wants to build a beautiful array *a*, consisting of *n* integers. But not everything is so easy, Sereja's friend Dima has *m* coupons, each contains two integers *q**i*, *w**i*. Coupon *i* costs *w**i* and allows you to use as many numbers *q**i* as you want when constructing the array *a*. Values *q**i* are distinct. Sereja has no coupons, so Dima and Sereja have made the following deal. Dima builds some beautiful array *a* of *n* elements. After that he takes *w**i* rubles from Sereja for each *q**i*, which occurs in the array *a*. Sereja believed his friend and agreed to the contract, and now he is wondering, what is the maximum amount of money he can pay.

Help Sereja, find the maximum amount of money he can pay to Dima.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 2·106, 1 ≤ *m* ≤ 105). Next *m* lines contain pairs of integers. The *i*-th line contains numbers *q**i*, *w**i* (1 ≤ *q**i*, *w**i* ≤ 105).

It is guaranteed that all *q**i* are distinct.

## Output

In a single line print maximum amount of money (in rubles) Sereja can pay.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
5 2  
1 2  
2 3  

```
## Output


```
5  

```
## Input


```
100 3  
1 2  
2 1  
3 1  

```
## Output


```
4  

```
## Input


```
1 2  
1 1  
2 100  

```
## Output


```
100  

```
## Note

In the first sample Sereja can pay 5 rubles, for example, if Dima constructs the following array: [1, 2, 1, 2, 2]. There are another optimal arrays for this test.

In the third sample Sereja can pay 100 rubles, if Dima constructs the following array: [2].



#### tags 

#2000 #graphs #greedy #sortings 