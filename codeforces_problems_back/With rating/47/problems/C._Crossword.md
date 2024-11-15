<h1 style='text-align: center;'> C. Crossword</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya trains to compose crossword puzzles. He can only compose crosswords of a very simplе type so far. All of them consist of exactly six words; the words can be read only from top to bottom vertically and from the left to the right horizontally. The words are arranged in the form of a rectangular "eight" or infinity sign, not necessarily symmetrical.

The top-left corner of the crossword coincides with the top-left corner of the rectangle. The same thing is correct for the right-bottom corners. The crossword can't degrade, i.e. it always has exactly four blank areas, two of which are surrounded by letters. Look into the output for the samples for clarification.

Help Vasya — compose a crossword of the described type using the given six words. It is allowed to use the words in any order.

## Input

Six lines contain the given words. Every word consists of no more than 30 and no less than 3 uppercase Latin letters. 

## Output

If it is impossible to solve the problem, print Impossible. Otherwise, print the sought crossword. All the empty squares should be marked as dots.

If there can be several solutions to that problem, print the lexicographically minimum one. I.e. the solution where the first line is less than the first line of other solutions should be printed. If the two lines are equal, compare the second lines and so on. The lexicographical comparison of lines is realized by the < operator in the modern programming languages.

## Examples

## Input


```
NOD  
BAA  
YARD  
AIRWAY  
NEWTON  
BURN  

```
## Output


```
BAA...  
U.I...  
R.R...  
NEWTON  
..A..O  
..YARD  

```
## Input


```
AAA  
AAA  
AAAAA  
AAA  
AAA  
AAAAA  

```
## Output


```
AAA..  
A.A..  
AAAAA  
..A.A  
..AAA  

```
## Input


```
PTC  
JYNYFDSGI  
ZGPPC  
IXEJNDOP  
JJFS  
SSXXQOFGJUZ  

```
## Output


```
JJFS....  
Y..S....  
N..X....  
Y..X....  
F..Q....  
D..O....  
S..F....  
G..G....  
IXEJNDOP  
...U...T  
...ZGPPC  

```


#### tags 

#2000 #implementation 