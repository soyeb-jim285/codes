<h1 style='text-align: center;'> C. Boredom</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ilya is sitting in a waiting area of Metropolis airport and is bored of looking at time table that shows again and again that his plane is delayed. So he took out a sheet of paper and decided to solve some problems.

First Ilya has drawn a grid of size *n* × *n* and marked *n* squares on it, such that no two marked squares share the same row or the same column. He calls a rectangle on a grid with sides parallel to grid sides beautiful if exactly two of its corner squares are marked. There are exactly *n*·(*n* - 1) / 2 beautiful rectangles.

Ilya has chosen *q* query rectangles on a grid with sides parallel to grid sides (not necessarily beautiful ones), and for each of those rectangles he wants to find its beauty degree. Beauty degree of a rectangle is the number of beautiful rectangles that share at least one square with the given one.

Now Ilya thinks that he might not have enough time to solve the problem till the departure of his flight. You are given the description of marked cells and the query rectangles, help Ilya find the beauty degree of each of the query rectangles.

## Input

The first line of input contains two integers *n* and *q* (2 ≤ *n* ≤ 200 000, 1 ≤ *q* ≤ 200 000) — the size of the grid and the number of query rectangles.

The second line contains *n* integers *p*1, *p*2, ..., *p**n*, separated by spaces (1 ≤ *p**i* ≤ *n*, all *p**i* are different), they specify grid squares marked by Ilya: in column *i* he has marked a square at row *p**i*, rows are numbered from 1 to *n*, bottom to top, columns are numbered from 1 to *n*, left to right.

The following *q* lines describe query rectangles. Each rectangle is described by four integers: *l*, *d*, *r*, *u* (1 ≤ *l* ≤ *r* ≤ *n*, 1 ≤ *d* ≤ *u* ≤ *n*), here *l* and *r* are the leftmost and the rightmost columns of the rectangle, *d* and *u* the bottommost and the topmost rows of the rectangle.

## Output

For each query rectangle output its beauty degree on a separate line.

## Examples

## Input


```
2 3  
1 2  
1 1 1 1  
1 1 1 2  
1 1 2 2  

```
## Output


```
1  
1  
1  

```
## Input


```
4 2  
1 3 2 4  
4 1 4 4  
1 1 2 3  

```
## Output


```
3  
5  

```
## Note

The first sample test has one beautiful rectangle that occupies the whole grid, therefore the answer to any query is 1.

In the second sample test the first query rectangle intersects 3 beautiful rectangles, as shown on the picture below:

![](images/ab1c66ff4bb212f2eaa1df6a3126acc2bc79535c.png) ![](images/e4576fb30a1da895a09193faaf3d92ff2bf16cc9.png) ![](images/3d67c946457a83004c99989b9ccf062d66affd1f.png)

There are 5 beautiful rectangles that intersect the second query rectangle, as shown on the following picture:

![](images/56bf16b394d5a08e28d2fd8d5ad57392f1cc10e0.png) ![](images/c7d7961cd0d50c64b5a1ec104f16bc95254199a2.png) ![](images/fa6096a3000f51ae6f1d798801441540454f6b9f.png) ![](images/c87e98c04601ad2d95d654f7f31371198d98d1d6.png) ![](images/cab8b66423587e485b08708148a8ce2194ac9558.png)



#### tags 

#2100 #data_structures 