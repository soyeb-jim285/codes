<h1 style='text-align: center;'> C. Till I Collapse</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rick and Morty want to find MR. PBH and they can't do it alone. So they need of Mr. Meeseeks. They Have generated *n* Mr. Meeseeks, standing in a line numbered from 1 to *n*. Each of them has his own color. *i*-th Mr. Meeseeks' color is *a**i*. 

Rick and Morty are gathering their army and they want to divide Mr. Meeseeks into some squads. They don't want their squads to be too colorful, so each squad should have Mr. Meeseeks of at most *k* different colors. Also each squad should be a continuous subarray of Mr. Meeseeks in the line. Meaning that for each 1 ≤ *i* ≤ *e* ≤ *j* ≤ *n*, if Mr. Meeseeks number *i* and Mr. Meeseeks number *j* are in the same squad then Mr. Meeseeks number *e* should be in that same squad.

 ![](images/29768635332701edee5966c3719c3792b3462ba3.png) Also, each squad needs its own presidio, and building a presidio needs money, so they want the total number of squads to be minimized.

Rick and Morty haven't finalized the exact value of *k*, so in order to choose it, for each *k* between 1 and *n* (inclusive) need to know the minimum number of presidios needed.

## Input

The first line of input contains a single integer *n* (1 ≤ *n* ≤ 105) — number of Mr. Meeseeks.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* separated by spaces (1 ≤ *a**i* ≤ *n*) — colors of Mr. Meeseeks in order they standing in a line.

## Output

In the first and only line of input print *n* integers separated by spaces. *i*-th integer should be the minimum number of presidios needed if the value of *k* is *i*.

## Examples

## Input


```
5  
1 3 4 3 3  

```
## Output


```
4 2 1 1 1   

```
## Input


```
8  
1 5 7 8 1 7 6 1  

```
## Output


```
8 4 3 2 1 1 1 1   

```
## Note

For the first sample testcase, some optimal ways of dividing army into squads for each *k* are:

1. [1], [3], [4], [3, 3]
2. [1], [3, 4, 3, 3]
3. [1, 3, 4, 3, 3]
4. [1, 3, 4, 3, 3]
5. [1, 3, 4, 3, 3]

For the second testcase, some optimal ways of dividing army into squads for each *k* are:

1. [1], [5], [7], [8], [1], [7], [6], [1]
2. [1, 5], [7, 8], [1, 7], [6, 1]
3. [1, 5, 7], [8], [1, 7, 6, 1]
4. [1, 5, 7, 8], [1, 7, 6, 1]
5. [1, 5, 7, 8, 1, 7, 6, 1]
6. [1, 5, 7, 8, 1, 7, 6, 1]
7. [1, 5, 7, 8, 1, 7, 6, 1]
8. [1, 5, 7, 8, 1, 7, 6, 1]


#### tags 

#2400 #data_structures #divide_and_conquer 