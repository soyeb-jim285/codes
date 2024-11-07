<h1 style='text-align: center;'> E. Delivery Club</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Petya and Vasya got employed as couriers. During the working day they are to deliver packages to *n* different points on the line. According to the company's internal rules, the delivery of packages must be carried out strictly in a certain order. Initially, Petya is at the point with the coordinate *s*1, Vasya is at the point with the coordinate *s*2, and the clients are at the points *x*1, *x*2, ..., *x**n* in the order of the required visit.

The guys agree in advance who of them will deliver the package to which of the customers, and then they act as follows. When the package for the *i*-th client is delivered, the one who delivers the package to the (*i* + 1)-st client is sent to the path (it can be the same person who went to the point *x**i*, or the other). The friend who is not busy in delivering the current package, is standing still.

To communicate with each other, the guys have got walkie-talkies. The walkie-talkies work rather poorly at great distances, so Petya and Vasya want to distribute the orders so that the maximum distance between them during the day is as low as possible. Help Petya and Vasya to minimize the maximum distance between them, observing all delivery rules. 

## Input

The first line contains three integers *n*, *s*1, *s*2 (1 ≤ *n* ≤ 100 000, 0 ≤ *s*1, *s*2 ≤ 109) — number of points of delivery and starting positions of Petya and Vasya.

The second line contains *n* integers *x*1, *x*2, ..., *x**n* — customers coordinates (0 ≤ *x**i* ≤ 109), in the order to make a delivery. 

It is guaranteed, that among the numbers *s*1, *s*2, *x*1, ..., *x**n* there are no two equal.

## Output

## Output

 the only integer, minimum possible maximal distance between couriers during delivery.

## Examples

## Input


```
2 0 10  
5 6  

```
## Output


```
10  

```
## Input


```
3 2 1  
3 4 5  

```
## Output


```
1  

```
## Input


```
1 4 5  
2  

```
## Output


```
2  

```
## Note

In the first test case the initial distance between the couriers is 10. This value will be the answer, for example, Petya can perform both deliveries, and Vasya will remain at the starting point.

In the second test case you can optimally act, for example, like this: Vasya delivers the package to the first customer, Petya to the second and, finally, Vasya delivers the package to the third client. With this order of delivery, the distance between the couriers will never exceed 1.

In the third test case only two variants are possible: if the delivery of a single package is carried out by Petya, the maximum distance between them will be 5 - 2 = 3. If Vasya will deliver the package, the maximum distance is 4 - 2 = 2. The latter method is optimal.



#### tags 

#2600 #binary_search #data_structures #dp 