<h1 style='text-align: center;'> E. Puzzle Lover</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Oleg Petrov loves crossword puzzles and every Thursday he buys his favorite magazine with crosswords and other word puzzles. In the last magazine Oleg found a curious puzzle, and the magazine promised a valuable prize for it's solution. We give a formal description of the problem below.

The puzzle field consists of two rows, each row contains *n* cells. Each cell contains exactly one small English letter. You also are given a word *w*, which consists of *k* small English letters. A solution of the puzzle is a sequence of field cells *c*1, ..., *c**k*, such that:

* For all *i* from 1 to *k* the letter written in the cell *c**i* matches the letter *w**i*;
* All the cells in the sequence are pairwise distinct;
* For all *i* from 1 to *k* - 1 cells *c**i* and *c**i* + 1 have a common side.

Oleg Petrov quickly found a solution for the puzzle. Now he wonders, how many distinct solutions are there for this puzzle. Oleg Petrov doesn't like too large numbers, so calculate the answer modulo 109 + 7.

Two solutions *c**i* and *c*'*i* are considered distinct if the sequences of cells do not match in at least one position, that is there is such *j* in range from 1 to *k*, such that *c**j* ≠ *c*'*j*.

## Input

The first two lines contain the state of the field for the puzzle. Each of these non-empty lines contains exactly *n* small English letters.

The next line is left empty.

The next line is non-empty and contains word *w*, consisting of small English letters.

The length of each line doesn't exceed 2 000.

## Output

Print a single integer — the number of distinct solutions for the puzzle modulo 109 + 7.

## Examples

## Input


```
code  
edoc  
  
code  

```
## Output


```
4  

```
## Input


```
aaa  
aaa  
  
aa  

```
## Output


```
14  

```


#### tags 

#3200 #dp #hashing #strings 