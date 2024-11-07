<h1 style='text-align: center;'> I. Omkar and Mosaic</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Omkar is creating a mosaic using colored square tiles, which he places in an $n \times n$ grid. When the mosaic is complete, each cell in the grid will have either a glaucous or sinoper tile. However, currently he has only placed tiles in some cells. 

A completed mosaic will be a mastapeece if and only if each tile is adjacent to exactly $2$ tiles of the same color ($2$ tiles are adjacent if they share a side.) Omkar wants to fill the rest of the tiles so that the mosaic becomes a mastapeece. Now he is wondering, is the way to do this unique, and if it is, what is it?

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 2000$).

Then follow $n$ lines with $n$ characters in each line. The $i$-th character in the $j$-th line corresponds to the cell in row $i$ and column $j$ of the grid, and will be $S$ if Omkar has placed a sinoper tile in this cell, $G$ if Omkar has placed a glaucous tile, $.$ if it's empty. 

## Output

On the first line, print UNIQUE if there is a unique way to get a mastapeece, NONE if Omkar cannot create any, and MULTIPLE if there is more than one way to do so. All letters must be uppercase.

If you print UNIQUE, then print $n$ additional lines with $n$ characters in each line, such that the $i$-th character in the $j^{\text{th}}$ line is $S$ if the tile in row $i$ and column $j$ of the mastapeece is sinoper, and $G$ if it is glaucous. 

## Examples

## Input


```

4
S...
..G.
....
...S

```
## Output


```

MULTIPLE

```
## Input


```

6
S.....
....G.
..S...
.....S
....G.
G.....

```
## Output


```

NONE

```
## Input


```

10
.S....S...
..........
...SSS....
..........
..........
...GS.....
....G...G.
..........
......G...
..........

```
## Output


```

UNIQUE
SSSSSSSSSS
SGGGGGGGGS
SGSSSSSSGS
SGSGGGGSGS
SGSGSSGSGS
SGSGSSGSGS
SGSGGGGSGS
SGSSSSSSGS
SGGGGGGGGS
SSSSSSSSSS

```
## Input


```

1
.

```
## Output


```

NONE

```
## Note

For the first test case, Omkar can make the mastapeeces

SSSS

SGGS

SGGS

SSSS

and 

SSGG

SSGG

GGSS

GGSS.

For the second test case, it can be proven that it is impossible for Omkar to add tiles to create a mastapeece.

For the third case, it can be proven that the given mastapeece is the only mastapeece Omkar can create by adding tiles.

For the fourth test case, it's clearly impossible for the only tile in any mosaic Omkar creates to be adjacent to two tiles of the same color, as it will be adjacent to $0$ tiles total. 



#### tags 

#3500 #combinatorics #constructive_algorithms #math 