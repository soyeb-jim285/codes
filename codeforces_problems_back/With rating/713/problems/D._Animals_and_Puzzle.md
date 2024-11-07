<h1 style='text-align: center;'> D. Animals and Puzzle</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Owl Sonya gave a huge lake puzzle of size *n* × *m* to hedgehog Filya as a birthday present. Friends immediately started to assemble the puzzle, but some parts of it turned out to be empty — there was no picture on them. Parts with picture on it are denoted by 1, while empty parts are denoted by 0. Rows of the puzzle are numbered from top to bottom with integers from 1 to *n*, while columns are numbered from left to right with integers from 1 to *m*.

Animals decided to complete the picture and play with it, as it might be even more fun! Owl and hedgehog ask each other some queries. Each query is provided by four integers *x*1, *y*1, *x*2, *y*2 which define the rectangle, where (*x*1, *y*1) stands for the coordinates of the up left cell of the rectangle, while (*x*2, *y*2) stands for the coordinates of the bottom right cell. The answer to the query is the size of the maximum square consisting of picture parts only (only parts denoted by 1) and located fully inside the query rectangle.

Help Sonya and Filya answer *t* queries.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 1000) — sizes of the puzzle.

Each of the following *n* lines contains *m* integers *a**ij*. Each of them is equal to 1 if the corresponding cell contains a picture and 0 if it's empty.

Next line contains an integer *t* (1 ≤ *t* ≤ 1 000 000) — the number of queries.

Then follow *t* lines with queries' descriptions. Each of them contains four integers *x*1, *y*1, *x*2, *y*2 (1 ≤ *x*1 ≤ *x*2 ≤ *n*, 1 ≤ *y*1 ≤ *y*2 ≤ *m*) — coordinates of the up left and bottom right cells of the query rectangle.

## Output

Print *t* lines. The *i*-th of them should contain the maximum size of the square consisting of 1-s and lying fully inside the query rectangle.

## Example

## Input


```
3 4  
1 1 0 1  
0 1 1 0  
0 1 1 0  
5  
1 1 2 3  
2 1 3 2  
3 2 3 4  
1 1 3 4  
1 2 3 4  

```
## Output


```
1  
1  
1  
2  
2  

```


#### tags 

#2700 #binary_search #data_structures 