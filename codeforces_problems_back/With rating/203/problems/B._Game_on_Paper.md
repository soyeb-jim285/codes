<h1 style='text-align: center;'> B. Game on Paper</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One not particularly beautiful evening Valera got very bored. To amuse himself a little bit, he found the following game.

He took a checkered white square piece of paper, consisting of *n* × *n* cells. After that, he started to paint the white cells black one after the other. In total he painted *m* different cells on the piece of paper. Since Valera was keen on everything square, he wondered, how many moves (i.e. times the boy paints a square black) he should make till a black square with side 3 can be found on the piece of paper. But Valera does not know the answer to this question, so he asks you to help him.

Your task is to find the minimum number of moves, till the checkered piece of paper has at least one black square with side of 3. Otherwise determine that such move does not exist.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 1000, 1 ≤ *m* ≤ *min*(*n*·*n*, 105)) — the size of the squared piece of paper and the number of moves, correspondingly. 

Then, *m* lines contain the description of the moves. The *i*-th line contains two integers *x**i*, *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*) — the number of row and column of the square that gets painted on the *i*-th move. 

All numbers on the lines are separated by single spaces. It is guaranteed that all moves are different. The moves are numbered starting from 1 in the order, in which they are given in the input. The columns of the squared piece of paper are numbered starting from 1, from the left to the right. The rows of the squared piece of paper are numbered starting from 1, from top to bottom.

## Output

On a single line print the answer to the problem — the minimum number of the move after which the piece of paper has a black square with side 3. If no such move exists, print -1.

## Examples

## Input


```
4 11  
1 1  
1 2  
1 3  
2 2  
2 3  
1 4  
2 4  
3 4  
3 2  
3 3  
4 1  

```
## Output


```
10  

```
## Input


```
4 12  
1 1  
1 2  
1 3  
2 2  
2 3  
1 4  
2 4  
3 4  
3 2  
4 2  
4 1  
3 1  

```
## Output


```
-1  

```


#### tags 

#1300 #brute_force #implementation 