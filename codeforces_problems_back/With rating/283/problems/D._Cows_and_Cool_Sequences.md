<h1 style='text-align: center;'> D. Cows and Cool Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bessie and the cows have recently been playing with "cool" sequences and are trying to construct some. Unfortunately they are bad at arithmetic, so they need your help!

A pair (*x*, *y*) of positive integers is "cool" if *x* can be expressed as the sum of *y* consecutive integers (not necessarily positive). A sequence (*a*1, *a*2, ..., *a**n*) is "cool" if the pairs (*a*1, *a*2), (*a*2, *a*3), ..., (*a**n* - 1, *a**n*) are all cool. 

The cows have a sequence of *n* positive integers, *a*1, *a*2, ..., *a**n*. In one move, they may replace some *a**i* with any other positive integer (there are no other limits on the new value of *a**i*). Determine the smallest number of moves needed to make the resulting sequence cool.

## Input

The first line contains a single integer, *n* (2 ≤ *n* ≤ 5000). The next line contains *n* space-separated integers, *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1015).

Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Output

A single integer, the minimum number of *a**i* that must be changed to make the sequence cool.

## Examples

## Input


```
3  
6 4 1  

```
## Output


```
0  

```
## Input


```
4  
20 6 3 4  

```
## Output


```
2  

```
## Note

In the first sample, the sequence is already cool, so we don't need to change any elements. In the second sample, we can change *a*2 to 5 and *a*3 to 10 to make (20, 5, 10, 4) which is cool. This changes 2 elements.



#### tags 

#2400 #dp #math #number_theory 