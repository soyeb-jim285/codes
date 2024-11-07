<h1 style='text-align: center;'> G. One Billion Shades of Grey</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have to paint with shades of grey the tiles of an $n\times n$ wall. The wall has $n$ rows of tiles, each with $n$ tiles.

The tiles on the boundary of the wall (i.e., on the first row, last row, first column and last column) are already painted and you shall not change their color. All the other tiles are not painted. Some of the tiles are broken, you shall not paint those tiles. It is guaranteed that the tiles on the boundary are not broken.

You shall paint all the non-broken tiles that are not already painted. When you paint a tile you can choose from $10^9$ shades of grey, indexed from $1$ to $10^9$. You can paint multiple tiles with the same shade. Formally, painting the wall is equivalent to assigning a shade (an integer between $1$ and $10^9$) to each non-broken tile that is not already painted.

The contrast between two tiles is the absolute value of the difference between the shades of the two tiles. The total contrast of the wall is the sum of the contrast of all the pairs of adjacent non-broken tiles (two tiles are adjacent if they share a side).

Compute the minimum possible total contrast of the wall.

###### Input

The first line contains $n$ ($3\le n\le 200$) – the number of rows and columns.

Then $n$ lines, each containing $n$ integers, follow. The $i$-th of these lines describe the $i$-th row of tiles. It contains the $n$ integers $a_{ij}$ ($-1\le a_{ij} \le 10^9)$. The value of $a_{ij}$ described the tile on the $i$-th row and $j$-th column: 

* If $a_{ij}=0$, then the tile is not painted and shall be painted.
* If $a_{ij}=-1$, then the tile is broken and shall not be painted.
* If $1\le a_{ij}\le 10^9$, then the tile is already painted with the shade $a_{ij}$.

 It is guaranteed that the tiles on the boundary are already painted, the tiles not on the boundary are not already painted, and the tiles on the boundary are not broken.
###### Output

Print a single integer – the minimum possible total contrast of the wall.

## Examples

###### Input


```text
3
1 7 6
4 0 6
1 1 1
```
###### Output


```text
26
```
###### Input


```text
3
10 100 1
1 -1 100
10 10 10
```
###### Output


```text
396
```
###### Input


```text
5
6 6 5 4 4
6 0 0 0 4
7 0 0 0 3
8 0 0 0 2
8 8 1 2 2
```
###### Output


```text
34
```
###### Input


```text
7
315055237 841510063 581663979 148389224 405375301 243686840 882512379
683199716 -1 -1 0 0 0 346177625
496442279 0 0 0 0 0 815993623
223938231 0 0 -1 0 0 16170511
44132173 0 -1 0 0 0 130735659
212201259 0 0 -1 0 0 166102576
123213235 506794677 467013743 410119347 791447348 80193382 142887538
```
###### Output


```text
10129482893
```
## Note

Explanation of the first testcase: The initial configuration of the tiles is (tiles to paint are denoted by ?): 

 
```text
  
1 7 6  
4 ? 6  
1 1 1  

```
  A possible way to paint the tile achieving the minimum possible contrast of $26$ is:  
```text
  
1 7 6  
4 5 6  
1 1 1  

```
 Explanation of the second testcase: Since all tiles are either painted or broken, there is nothing to do. The total contrast is $396$.

Explanation of the third testcase: The initial configuration of the tiles is (tiles to paint are denoted by ?): 

 
```text
  
6 6 5 4 4  
6 ? ? ? 4  
7 ? ? ? 3  
8 ? ? ? 2  
8 8 1 2 2  

```
  A possible way to paint the tiles achieving the minimum possible contrast of $34$ is:  
```text
  
6 6 5 4 4  
6 6 5 4 4  
7 7 5 3 3  
8 8 2 2 2  
8 8 1 2 2  

```
 

#### Tags 

#3300 #NOT OK #flows #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_11.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
