<h1 style='text-align: center;'> D. Theseus and labyrinth</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Theseus has just arrived to Crete to fight Minotaur. He found a labyrinth that has a form of a rectangular field of size *n* × *m* and consists of blocks of size 1 × 1.

Each block of the labyrinth has a button that rotates all blocks 90 degrees clockwise. Each block rotates around its center and doesn't change its position in the labyrinth. Also, each block has some number of doors (possibly none). In one minute, Theseus can either push the button in order to rotate all the blocks 90 degrees clockwise or pass to the neighbouring block. Theseus can go from block *A* to some neighbouring block *B* only if block *A* has a door that leads to block *B* and block *B* has a door that leads to block *A*.

Theseus found an entrance to labyrinth and is now located in block (*x**T*, *y**T*) — the block in the row *x**T* and column *y**T*. Theseus know that the Minotaur is hiding in block (*x**M*, *y**M*) and wants to know the minimum number of minutes required to get there.

Theseus is a hero, not a programmer, so he asks you to help him.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 1000) — the number of rows and the number of columns in labyrinth, respectively.

Each of the following *n* lines contains *m* characters, describing the blocks of the labyrinth. The possible characters are:

* «+» means this block has 4 doors (one door to each neighbouring block);
* «-» means this block has 2 doors — to the left and to the right neighbours;
* «|» means this block has 2 doors — to the top and to the bottom neighbours;
* «^» means this block has 1 door — to the top neighbour;
* «>» means this block has 1 door — to the right neighbour;
* «<» means this block has 1 door — to the left neighbour;
* «v» means this block has 1 door — to the bottom neighbour;
* «L» means this block has 3 doors — to all neighbours except left one;
* «R» means this block has 3 doors — to all neighbours except right one;
* «U» means this block has 3 doors — to all neighbours except top one;
* «D» means this block has 3 doors — to all neighbours except bottom one;
* «*» means this block is a wall and has no doors.

Left, right, top and bottom are defined from representing labyrinth as a table, where rows are numbered from 1 to *n* from top to bottom and columns are numbered from 1 to *m* from left to right.

Next line contains two integers — coordinates of the block (*x**T*, *y**T*) (1 ≤ *x**T* ≤ *n*, 1 ≤ *y**T* ≤ *m*), where Theseus is initially located.

Last line contains two integers — coordinates of the block (*x**M*, *y**M*) (1 ≤ *x**M* ≤ *n*, 1 ≤ *y**M* ≤ *m*), where Minotaur hides.

It's guaranteed that both the block where Theseus starts and the block where Minotaur is hiding have at least one door. Theseus and Minotaur may be initially located at the same block.

## Output

If Theseus is not able to get to Minotaur, then print -1 in the only line of the output. Otherwise, print the minimum number of minutes required to get to the block where Minotaur is hiding.

## Examples

## Input


```
2 2  
+*  
*U  
1 1  
2 2  

```
## Output


```
-1
```
## Input


```
2 3  
<><  
><>  
1 1  
2 1  

```
## Output


```
4
```
## Note

Assume that Theseus starts at the block (*x**T*, *y**T*) at the moment 0.



#### tags 

#2000 #graphs #implementation #shortest_paths 