<h1 style='text-align: center;'> D. Kay and Eternity</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Snow Queen told Kay to form a word "eternity" using pieces of ice. Kay is eager to deal with the task, because he will then become free, and Snow Queen will give him all the world and a pair of skates.

Behind the palace of the Snow Queen there is an infinite field consisting of cells. There are *n* pieces of ice spread over the field, each piece occupying exactly one cell and no two pieces occupying the same cell. To estimate the difficulty of the task Kay looks at some squares of size *k* × *k* cells, with corners located at the corners of the cells and sides parallel to coordinate axis and counts the number of pieces of the ice inside them.

This method gives an estimation of the difficulty of some part of the field. However, Kay also wants to estimate the total difficulty, so he came up with the following criteria: for each *x* (1 ≤ *x* ≤ *n*) he wants to count the number of squares of size *k* × *k*, such that there are exactly *x* pieces of the ice inside.

Please, help Kay estimate the difficulty of the task given by the Snow Queen.

## Input

The first line of the input contains two integers *n* and *k* (1 ≤ *n* ≤ 100 000, 1 ≤ *k* ≤ 300) — the number of pieces of the ice and the value *k*, respectively. Each of the next *n* lines contains two integers *x**i* and *y**i* ( - 109 ≤ *x**i*, *y**i* ≤ 109) — coordinates of the cell containing *i*-th piece of the ice. It's guaranteed, that no two pieces of the ice occupy the same cell.

## Output

Print *n* integers: the number of squares of size *k* × *k* containing exactly 1, 2, ..., *n* pieces of the ice.

## Example

## Input


```
5 3  
4 5  
4 6  
5 5  
5 6  
7 7  

```
## Output


```
10 8 1 4 0   

```


#### tags 

#2600 #brute_force #implementation #sortings 