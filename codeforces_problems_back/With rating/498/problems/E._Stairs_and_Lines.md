<h1 style='text-align: center;'> E. Stairs and Lines</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a figure on a grid representing stairs consisting of 7 steps. The width of the stair on height *i* is *w**i* squares. Formally, the figure is created by consecutively joining rectangles of size *w**i* × *i* so that the *w**i* sides lie on one straight line. Thus, for example, if all *w**i* = 1, the figure will look like that (different colors represent different rectangles):

 ![](images/ef5a2ec4e0d2cd5ed62080dfbbed2ecaef23d74e.png) And if *w* = {5, 1, 0, 3, 0, 0, 1}, then it looks like that:

 ![](images/0e50e7b25f4dd40b8277d09d5fa8856fb4e1c551.png) Find the number of ways to color some borders of the figure's inner squares so that no square had all four borders colored. The borders of the squares lying on the border of the figure should be considered painted. The ways that differ with the figure's rotation should be considered distinct. 

## Input

The single line of the input contains 7 numbers *w*1, *w*2, ..., *w*7 (0 ≤ *w**i* ≤ 105). It is guaranteed that at least one of the *w**i*'s isn't equal to zero.

## Output

In the single line of the output display a single number — the answer to the problem modulo 109 + 7.

## Examples

## Input


```
0 1 0 0 0 0 0  

```
## Output


```
1  

```
## Input


```
0 2 0 0 0 0 0  

```
## Output


```
7  

```
## Input


```
1 1 1 0 0 0 0  

```
## Output


```
9  

```
## Input


```
5 1 0 3 0 0 1  

```
## Output


```
411199181  

```
## Note

All the possible ways of painting the third sample are given below:

 ![](images/6a59c271529ffcfebd32f9b79a31c2c97d50a5e9.png) 

#### tags 

#2700 #dp #matrices 