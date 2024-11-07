<h1 style='text-align: center;'> E. Hanoi Factory</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Of course you have heard the famous task about Hanoi Towers, but did you know that there is a special factory producing the rings for this wonderful game? Once upon a time, the ruler of the ancient Egypt ordered the workers of Hanoi Factory to create as high tower as possible. They were not ready to serve such a strange order so they had to create this new tower using already produced rings.

There are *n* rings in factory's stock. The *i*-th ring has inner radius *a**i*, outer radius *b**i* and height *h**i*. The goal is to select some subset of rings and arrange them such that the following conditions are satisfied:

* Outer radiuses form a non-increasing sequence, i.e. one can put the *j*-th ring on the *i*-th ring only if *b**j* ≤ *b**i*.
* Rings should not fall one into the the other. That means one can place ring *j* on the ring *i* only if *b**j* > *a**i*.
* The total height of all rings used should be maximum possible.
## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 100 000) — the number of rings in factory's stock.

The *i*-th of the next *n* lines contains three integers *a**i*, *b**i* and *h**i* (1 ≤ *a**i*, *b**i*, *h**i* ≤ 109, *b**i* > *a**i*) — inner radius, outer radius and the height of the *i*-th ring respectively.

## Output

Print one integer — the maximum height of the tower that can be obtained.

## Examples

## Input


```
3  
1 5 1  
2 6 2  
3 7 3  

```
## Output


```
6  

```
## Input


```
4  
1 2 1  
1 3 3  
4 6 2  
5 7 1  

```
## Output


```
4  

```
## Note

In the first sample, the optimal solution is to take all the rings and put them on each other in order 3, 2, 1.

In the second sample, one can put the ring 3 on the ring 4 and get the tower of height 3, or put the ring 1 on the ring 2 and get the tower of height 4.



#### tags 

#2000 #brute_force #data_structures #dp #greedy #sortings 