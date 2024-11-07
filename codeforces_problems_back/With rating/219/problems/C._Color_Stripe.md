<h1 style='text-align: center;'> C. Color Stripe</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A colored stripe is represented by a horizontal row of *n* square cells, each cell is pained one of *k* colors. Your task is to repaint the minimum number of cells so that no two neighbouring cells are of the same color. You can use any color from 1 to *k* to repaint the cells.

## Input

The first input line contains two integers *n* and *k* (1 ≤ *n* ≤ 5·105; 2 ≤ *k* ≤ 26). The second line contains *n* uppercase English letters. Letter "A" stands for the first color, letter "B" stands for the second color and so on. The first *k* English letters may be used. Each letter represents the color of the corresponding cell of the stripe.

## Output

Print a single integer — the required minimum number of repaintings. In the second line print any possible variant of the repainted stripe.

## Examples

## Input


```
6 3  
ABBACC  

```
## Output


```
2  
ABCACA  

```
## Input


```
3 2  
BBB  

```
## Output


```
1  
BAB  

```


#### tags 

#1600 #brute_force #dp #greedy 