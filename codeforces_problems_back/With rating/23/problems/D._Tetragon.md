<h1 style='text-align: center;'> D. Tetragon</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given the centers of three equal sides of a strictly convex tetragon. Your task is to restore the initial tetragon.

## Input

The first input line contains one number *T* — amount of tests (1 ≤ *T* ≤ 5·104). Each of the following *T* lines contains numbers *x*1, *y*1, *x*2, *y*2, *x*3, *y*3 — coordinates of different points that are the centers of three equal sides (non-negative integer numbers, not exceeding 10).

## Output

For each test output two lines. If the required tetragon exists, output in the first line YES, in the second line — four pairs of numbers — coordinates of the polygon's vertices in clockwise or counter-clockwise order. Don't forget, please, that the tetragon should be strictly convex, i.e. no 3 of its points lie on one line. ## Output

 numbers with 9 characters after a decimal point.

If the required tetragon doen't exist, output NO in the first line, and leave the second line empty.

## Examples

## Input


```
3  
1 1 2 2 3 3  
0 1 1 0 2 2  
9 3 7 9 9 8  

```
## Output


```
NO  
  
YES  
3.5 1.5 0.5 2.5 -0.5 -0.5 2.5 0.5  
NO  
  

```


#### tags 

#2600 #geometry #math 