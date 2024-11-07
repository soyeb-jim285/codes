<h1 style='text-align: center;'> A. Find Square</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a table of size $n \times m$, initially fully white. Rows are numbered $1$ through $n$ from top to bottom, columns $1$ through $m$ from left to right. Some square inside the table with odd side length was painted black. Find the center of this square.

#### Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 115$) — the number of rows and the number of columns in the table.

The $i$-th of the next $n$ lines contains a string of $m$ characters $s_{i1} s_{i2} \ldots s_{im}$ ($s_{ij}$ is 'W' for white cells and 'B' for black cells), describing the $i$-th row of the table.

#### Output

#### Output

 two integers $r$ and $c$ ($1 \le r \le n$, $1 \le c \le m$) separated by a space — the row and column numbers of the center of the black square.

## Examples

#### Input


```text
5 6  
WWBBBW  
WWBBBW  
WWBBBW  
WWWWWW  
WWWWWW  

```
#### Output


```text
2 4  

```
#### Input


```text
3 3  
WWW  
BWW  
WWW  

```
#### Output


```text
2 1  

```


#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../AIM_Tech_Round_5_(rated,_Div._1_+_Div._2).md)
- [Анонс](../blogs/Анонс.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
