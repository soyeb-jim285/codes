<h1 style='text-align: center;'> D. Dominoes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ dominoes. Each domino has a left and a right cell. Each cell can be colored either black or white. Some cells are already colored, while some aren't yet.

The coloring is said to be valid if and only if it is possible to rearrange the dominoes in some order such that for each $1 \le i \le n$ the color of the right cell of the $i$-th domino is different from the color of the left cell of the $((i \bmod n)+1)$-st domino. 

## Note

 that you can't rotate the dominoes, so the left cell always remains the left cell, and the right cell always remains the right cell.

Count the number of valid ways to color the yet uncolored cells of dominoes. Two ways are considered different if there is a cell that is colored white in one way and black in the other. In particular, colorings BW WB and WB BW different (and both invalid).

As this number can be very big, output it modulo $998\,244\,353$.

##### Input

The first line of the input contains a single integer $n$ ($1 \le n \le 10^5$) — the number of dominoes.

The next $n$ lines describe dominoes. Each line contains two characters which represent the left and the right cell. Character B means that the corresponding cell is black, character W means that the corresponding cell is white, and ? means that the cell is yet to be colored. 

##### Output

Print a single integer — the answer to the problem.

## Examples

##### Input


```text
1
?W
```
##### Output


```text
1
```
##### Input


```text
2
??
W?
```
##### Output


```text
2
```
##### Input


```text
4
BB
??
W?
??
```
##### Output


```text
10
```
## Note

In the first test case, there is only one domino, and we need the color of its right cell to be different from the color of its left cell. There is only one way to achieve this.

In the second test case, there are only $2$ such colorings:

BB WW and WB WB.



#### Tags 

#2400 #NOT OK #combinatorics #fft #graphs #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_758_(Div.1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
