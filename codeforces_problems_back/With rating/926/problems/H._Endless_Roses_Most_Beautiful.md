<h1 style='text-align: center;'> H. Endless Roses Most Beautiful</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady decided to buy roses for his girlfriend.

A flower shop has white, orange and red roses, and the total amount of them is *n*. Arkady thinks that red roses are not good together with white roses, so he won't buy a bouquet containing both red and white roses. Also, Arkady won't buy a bouquet where all roses have the same color. 

Arkady wants to buy exactly *k* roses. For each rose in the shop he knows its beauty and color: the beauty of the *i*-th rose is *b**i*, and its color is *c**i* ('W' for a white rose, 'O' for an orange rose and 'R' for a red rose). 

Compute the maximum possible total beauty of a bouquet of *k* roses satisfying the constraints above or determine that it is not possible to make such a bouquet.

## Input

The first line contains two integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 200 000) — the number of roses in the show and the number of roses Arkady wants to buy.

The second line contains a sequence of integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 10 000), where *b**i* equals the beauty of the *i*-th rose.

The third line contains a string *c* of length *n*, consisting of uppercase English letters 'W', 'O' and 'R', where *c**i* denotes the color of the *i*-th rose: 'W' denotes white, 'O'  — orange, 'R' — red.

## Output

Print the maximum possible total beauty of a bouquet of *k* roses that satisfies the constraints above. If it is not possible to make a single such bouquet, print -1.

## Examples

## Input


```
5 3  
4 3 4 1 6  
RROWW  

```
## Output


```
11  

```
## Input


```
5 2  
10 20 14 20 11  
RRRRR  

```
## Output


```
-1  

```
## Input


```
11 5  
5 6 3 2 3 4 7 5 4 5 6  
RWOORWORROW  

```
## Output


```
28  

```
## Note

In the first example Arkady wants to buy 3 roses. He can, for example, buy both red roses (their indices are 1 and 2, and their total beauty is 7) and the only orange rose (its index is 3, its beauty is 4). This way the total beauty of the bouquet is 11. 

In the second example Arkady can not buy a bouquet because all roses have the same color.



#### tags 

#2200 