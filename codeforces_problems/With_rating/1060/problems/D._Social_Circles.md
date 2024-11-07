<h1 style='text-align: center;'> D. Social Circles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You invited $n$ guests to dinner! You plan to arrange one or more circles of chairs. Each chair is going to be either occupied by one guest, or be empty. You can make any number of circles. 

Your guests happen to be a little bit shy, so the $i$-th guest wants to have a least $l_i$ free chairs to the left of his chair, and at least $r_i$ free chairs to the right. The "left" and "right" directions are chosen assuming all guests are going to be seated towards the center of the circle. 
## Note

 that when a guest is the only one in his circle, the $l_i$ chairs to his left and $r_i$ chairs to his right may overlap.

What is smallest total number of chairs you have to use?

##### Input

First line contains one integer $n$  — number of guests, ($1 \leqslant n \leqslant 10^5$). 

Next $n$ lines contain $n$ pairs of space-separated integers $l_i$ and $r_i$ ($0 \leqslant l_i, r_i \leqslant 10^9$).

##### Output

##### Output

 a single integer — the smallest number of chairs you have to use.

## Examples

##### Input


```text
3  
1 1  
1 1  
1 1  

```
##### Output


```text
6  

```
##### Input


```text
4  
1 2  
2 1  
3 5  
5 3  

```
##### Output


```text
15  

```
##### Input


```text
1  
5 6  

```
##### Output


```text
7  

```
## Note

In the second sample the only optimal answer is to use two circles: a circle with $5$ chairs accomodating guests $1$ and $2$, and another one with $10$ chairs accomodationg guests $3$ and $4$.

In the third sample, you have only one circle with one person. The guest should have at least five free chairs to his left, and at least six free chairs to his right to the next person, which is in this case the guest herself. So, overall number of chairs should be at least 6+1=7.



#### Tags 

#1900 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_513_by_Barcelona_Bootcamp_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
