<h1 style='text-align: center;'> F. Paths</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a positive integer *n*. Let's build a graph on vertices 1, 2, ..., *n* in such a way that there is an edge between vertices *u* and *v* if and only if ![](images/a9f8cfef2277cc8f4fc17d13f965e877c0eaed30.png). Let *d*(*u*, *v*) be the shortest distance between *u* and *v*, or 0 if there is no path between them. Compute the sum of values *d*(*u*, *v*) over all 1 ≤ *u* < *v* ≤ *n*.

The *gcd* (greatest common divisor) of two positive integers is the maximum positive integer that divides both of the integers.

## Input

Single integer *n* (1 ≤ *n* ≤ 107).

## Output

Print the sum of *d*(*u*, *v*) over all 1 ≤ *u* < *v* ≤ *n*.

## Examples

## Input


```
6  

```
## Output


```
8  

```
## Input


```
10  

```
## Output


```
44  

```
## Note

All shortest paths in the first example: 

* ![](images/7b7a110945393c2b47718b811aadf12cbe125f3f.png)
* ![](images/e9af98cb64a31b6dae850dbfb30429b9a091c123.png)
* ![](images/d43a3ea9a040a07b650cc4d74a5f6a69395d0005.png)
* ![](images/1725357f3b9d9284226b8c2848aab916720da24f.png)
* ![](images/9e05d0e132bba9db531dc61149062e6f9f5ff34a.png)
* ![](images/043fdd1108540c9fbac49c9177d6ec0021cbd896.png)

There are no paths between other pairs of vertices.

The total distance is 2 + 1 + 1 + 2 + 1 + 1 = 8.



#### tags 

#2700 #data_structures #number_theory 