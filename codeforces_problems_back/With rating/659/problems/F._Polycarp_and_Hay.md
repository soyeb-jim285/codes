<h1 style='text-align: center;'> F. Polycarp and Hay</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The farmer Polycarp has a warehouse with hay, which can be represented as an *n* × *m* rectangular table, where *n* is the number of rows, and *m* is the number of columns in the table. Each cell of the table contains a haystack. The height in meters of the hay located in the *i*-th row and the *j*-th column is equal to an integer *a**i*, *j* and coincides with the number of cubic meters of hay in the haystack, because all cells have the size of the base 1 × 1. Polycarp has decided to tidy up in the warehouse by removing an arbitrary integer amount of cubic meters of hay from the top of each stack. You can take different amounts of hay from different haystacks. Besides, it is allowed not to touch a stack at all, or, on the contrary, to remove it completely. If a stack is completely removed, the corresponding cell becomes empty and no longer contains the stack.

Polycarp wants the following requirements to hold after the reorganization:

* the total amount of hay remaining in the warehouse must be equal to *k*,
* the heights of all stacks (i.e., cells containing a non-zero amount of hay) should be the same,
* the height of at least one stack must remain the same as it was,
* for the stability of the remaining structure all the stacks should form one connected region.

The two stacks are considered adjacent if they share a side in the table. The area is called connected if from any of the stack in the area you can get to any other stack in this area, moving only to adjacent stacks. In this case two adjacent stacks necessarily belong to the same area.

Help Polycarp complete this challenging task or inform that it is impossible.

## Input

The first line of the input contains three integers *n*, *m* (1 ≤ *n*, *m* ≤ 1000) and *k* (1 ≤ *k* ≤ 1018) — the number of rows and columns of the rectangular table where heaps of hay are lain and the required total number cubic meters of hay after the reorganization. 

Then *n* lines follow, each containing *m* positive integers *a**i*, *j* (1 ≤ *a**i*, *j* ≤ 109), where *a**i*, *j* is equal to the number of cubic meters of hay making the hay stack on the *i*-th row and *j*-th column of the table.

## Output

In the first line print "YES" (without quotes), if Polycarpus can perform the reorganisation and "NO" (without quotes) otherwise. If the answer is "YES" (without quotes), then in next *n* lines print *m* numbers — the heights of the remaining hay stacks. All the remaining non-zero values should be equal, represent a connected area and at least one of these values shouldn't be altered.

If there are multiple answers, print any of them.

## Examples

## Input


```
2 3 35  
10 4 9  
9 9 7  

```
## Output


```
YES  
7 0 7   
7 7 7   

```
## Input


```
4 4 50  
5 9 1 1  
5 1 1 5  
5 1 5 5  
5 5 7 1  

```
## Output


```
YES  
5 5 0 0   
5 0 0 5   
5 0 5 5   
5 5 5 0   

```
## Input


```
2 4 12  
1 1 3 1  
1 6 2 4  

```
## Output


```
NO  

```
## Note

In the first sample non-zero values make up a connected area, their values do not exceed the initial heights of hay stacks. All the non-zero values equal 7, and their number is 5, so the total volume of the remaining hay equals the required value *k* = 7·5 = 35. At that the stack that is on the second line and third row remained unaltered.



#### tags 

#2000 #dfs_and_similar #dsu #graphs #greedy #sortings 