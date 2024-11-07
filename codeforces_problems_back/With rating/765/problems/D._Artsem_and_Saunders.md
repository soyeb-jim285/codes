<h1 style='text-align: center;'> D. Artsem and Saunders</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Artsem has a friend Saunders from University of Chicago. Saunders presented him with the following problem.

Let [*n*] denote the set {1, ..., *n*}. We will also write *f*: [*x*] → [*y*] when a function *f* is defined in integer points 1, ..., *x*, and all its values are integers from 1 to *y*.

Now then, you are given a function *f*: [*n*] → [*n*]. Your task is to find a positive integer *m*, and two functions *g*: [*n*] → [*m*], *h*: [*m*] → [*n*], such that *g*(*h*(*x*)) = *x* for all ![](images/a256711cc012560db991a322ff7b75323883dd8e.png), and *h*(*g*(*x*)) = *f*(*x*) for all ![](images/2ad9b8e566fe6c09697f5cee64720999d04e8a6f.png), or determine that finding these is impossible.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 105).

The second line contains *n* space-separated integers — values *f*(1), ..., *f*(*n*) (1 ≤ *f*(*i*) ≤ *n*).

## Output

If there is no answer, print one integer -1.

Otherwise, on the first line print the number *m* (1 ≤ *m* ≤ 106). On the second line print *n* numbers *g*(1), ..., *g*(*n*). On the third line print *m* numbers *h*(1), ..., *h*(*m*).

If there are several correct answers, you may output any of them. It is guaranteed that if a valid answer exists, then there is an answer satisfying the above restrictions.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
3  
1 2 3  
1 2 3  

```
## Input


```
3  
2 2 2  

```
## Output


```
1  
1 1 1  
2  

```
## Input


```
2  
2 1  

```
## Output


```
-1  

```


#### tags 

#1700 #constructive_algorithms #dsu #math 