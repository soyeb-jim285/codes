<h1 style='text-align: center;'> A. Sockets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has got many devices that work on electricity. He's got *n* supply-line filters to plug the devices, the *i*-th supply-line filter has *a**i* sockets.

Overall Vasya has got *m* devices and *k* electrical sockets in his flat, he can plug the devices or supply-line filters directly. Of course, he can plug the supply-line filter to any other supply-line filter. The device (or the supply-line filter) is considered plugged to electricity if it is either plugged to one of *k* electrical sockets, or if it is plugged to some supply-line filter that is in turn plugged to electricity. 

What minimum number of supply-line filters from the given set will Vasya need to plug all the devices he has to electricity? ## Note

 that all devices and supply-line filters take one socket for plugging and that he can use one socket to plug either one device or one supply-line filter.

## Input

The first line contains three integers *n*, *m*, *k* (1 ≤ *n*, *m*, *k* ≤ 50) — the number of supply-line filters, the number of devices and the number of sockets that he can plug to directly, correspondingly. The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 50) — number *a**i* stands for the number of sockets on the *i*-th supply-line filter.

## Output

Print a single number — the minimum number of supply-line filters that is needed to plug all the devices to electricity. If it is impossible to plug all the devices even using all the supply-line filters, print -1.

## Examples

## Input


```
3 5 3  
3 1 2  

```
## Output


```
1  

```
## Input


```
4 7 2  
3 3 2 4  

```
## Output


```
2  

```
## Input


```
5 5 1  
1 3 1 2 1  

```
## Output


```
-1  

```
## Note

In the first test case he can plug the first supply-line filter directly to electricity. After he plug it, he get 5 (3 on the supply-line filter and 2 remaining sockets for direct plugging) available sockets to plug. Thus, one filter is enough to plug 5 devices.

One of the optimal ways in the second test sample is to plug the second supply-line filter directly and plug the fourth supply-line filter to one of the sockets in the second supply-line filter. Thus, he gets exactly 7 sockets, available to plug: one to plug to the electricity directly, 2 on the second supply-line filter, 4 on the fourth supply-line filter. There's no way he can plug 7 devices if he use one supply-line filter.



#### tags 

#1100 #greedy #implementation #sortings 