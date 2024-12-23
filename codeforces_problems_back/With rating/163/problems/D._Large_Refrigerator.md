<h1 style='text-align: center;'> D. Large Refrigerator</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya wants to buy a new refrigerator. He believes that a refrigerator should be a rectangular parallelepiped with integer edge lengths. Vasya calculated that for daily use he will need a refrigerator with volume of at least *V*. Moreover, Vasya is a minimalist by nature, so the volume should be no more than *V*, either — why take up extra space in the apartment? Having made up his mind about the volume of the refrigerator, Vasya faced a new challenge — for a fixed volume of *V* the refrigerator must have the minimum surface area so that it is easier to clean.

The volume and the surface area of a refrigerator with edges *a*, *b*, *c* are equal to *V* = *abc* and *S* = 2(*ab* + *bc* + *ca*), correspondingly.

Given the volume *V*, help Vasya find the integer lengths for the refrigerator's edges *a*, *b*, *c* so that the refrigerator's volume equals *V* and its surface area *S* is minimized.

## Input

The first line contains a single integer *t* (1 ≤ *t* ≤ 500) — the number of data sets.

The description of *t* data sets follows. Each set consists of a single integer *V* (2 ≤ *V* ≤ 1018), given by its factorization as follows.

Let *V* = *p*1*a*1*p*2*a*2... *p**k**a**k*, where *p**i* are different prime numbers and *a**i* are positive integer powers. 

Then the first line describing a data set contains a single positive integer *k* — the number of different prime divisors of *V*. Next *k* lines contain prime numbers *p**i* and their powers *a**i*, separated by spaces. All *p**i* are different, all *a**i* > 0.

## Output

Print *t* lines, on the *i*-th line print the answer to the *i*-th data set as four space-separated integers: the minimum possible surface area *S* and the corresponding edge lengths *a*, *b*, *c*. If there are multiple variants of the lengths of edges that give the minimum area, you are allowed to print any of them. You can print the lengths of the fridge's edges in any order.

## Examples

## Input


```
3  
1  
2 3  
1  
17 1  
3  
3 1  
2 3  
5 1  

```
## Output


```
24 2 2 2  
70 1 1 17  
148 4 6 5  

```
## Note

In the first data set of the sample the fridge's volume *V* = 23 = 8, and the minimum surface area will be produced by the edges of equal length.

In the second data set the volume *V* = 17, and it can be produced by only one set of integer lengths.



#### tags 

#2900 #brute_force 