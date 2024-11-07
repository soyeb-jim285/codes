<h1 style='text-align: center;'> C. Sofa Thief</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yet another round on DecoForces is coming! Grandpa Maks wanted to participate in it but someone has stolen his precious sofa! And how can one perform well with such a major loss?

Fortunately, the thief had left a note for Grandpa Maks. This note got Maks to the sofa storehouse. Still he had no idea which sofa belongs to him as they all looked the same!

The storehouse is represented as matrix *n* × *m*. Every sofa takes two neighbouring by some side cells. No cell is covered by more than one sofa. There can be empty cells.

Sofa *A* is standing to the left of sofa *B* if there exist two such cells *a* and *b* that *x**a* < *x**b*, *a* is covered by *A* and *b* is covered by *B*. Sofa *A* is standing to the top of sofa *B* if there exist two such cells *a* and *b* that *y**a* < *y**b*, *a* is covered by *A* and *b* is covered by *B*. Right and bottom conditions are declared the same way. 

## Note

 that in all conditions *A* ≠ *B*. Also some sofa *A* can be both to the top of another sofa *B* and to the bottom of it. The same is for left and right conditions.

The note also stated that there are *cnt**l* sofas to the left of Grandpa Maks's sofa, *cnt**r* — to the right, *cnt**t* — to the top and *cnt**b* — to the bottom.

Grandpa Maks asks you to help him to identify his sofa. It is guaranteed that there is no more than one sofa of given conditions.

## Output

 the number of Grandpa Maks's sofa. If there is no such sofa that all the conditions are met for it then output -1.

## Input

The first line contains one integer number *d* (1 ≤ *d* ≤ 105) — the number of sofas in the storehouse.

The second line contains two integer numbers *n*, *m* (1 ≤ *n*, *m* ≤ 105) — the size of the storehouse.

Next *d* lines contains four integer numbers *x*1, *y*1, *x*2, *y*2 (1 ≤ *x*1, *x*2 ≤ *n*, 1 ≤ *y*1, *y*2 ≤ *m*) — coordinates of the *i*-th sofa. It is guaranteed that cells (*x*1, *y*1) and (*x*2, *y*2) have common side, (*x*1, *y*1)  ≠  (*x*2, *y*2) and no cell is covered by more than one sofa.

The last line contains four integer numbers *cnt**l*, *cnt**r*, *cnt**t*, *cnt**b* (0 ≤ *cnt**l*, *cnt**r*, *cnt**t*, *cnt**b* ≤ *d* - 1).

## Output

Print the number of the sofa for which all the conditions are met. Sofas are numbered 1 through *d* as given in input. If there is no such sofa then print -1.

## Examples

## Input


```
2  
3 2  
3 1 3 2  
1 2 2 2  
1 0 0 1  

```
## Output


```
1  

```
## Input


```
3  
10 10  
1 2 1 1  
5 5 6 5  
6 4 5 4  
2 1 2 0  

```
## Output


```
2  

```
## Input


```
2  
2 2  
2 1 1 1  
1 2 2 2  
1 0 0 0  

```
## Output


```
-1  

```
## Note

Let's consider the second example. 

* The first sofa has 0 to its left, 2 sofas to its right ((1, 1) is to the left of both (5, 5) and (5, 4)), 0 to its top and 2 to its bottom (both 2nd and 3rd sofas are below).
* The second sofa has *cnt**l* = 2, *cnt**r* = 1, *cnt**t* = 2 and *cnt**b* = 0.
* The third sofa has *cnt**l* = 2, *cnt**r* = 1, *cnt**t* = 1 and *cnt**b* = 1.

So the second one corresponds to the given conditions.

In the third example 

* The first sofa has *cnt**l* = 1, *cnt**r* = 1, *cnt**t* = 0 and *cnt**b* = 1.
* The second sofa has *cnt**l* = 1, *cnt**r* = 1, *cnt**t* = 1 and *cnt**b* = 0.

And there is no sofa with the set (1, 0, 0, 0) so the answer is -1.



#### tags 

#2000 #brute_force #implementation 