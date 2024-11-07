<h1 style='text-align: center;'> H. Ember and Storm's Tree Game</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ember and Storm play a game. First, Ember picks a labelled tree *T* of *n* vertices, such that the degree of every vertex is at most *d*. Then, Storm picks two distinct vertices *u* and *v* in this tree and writes down the labels of the vertices in the path from *u* to *v* in a sequence *a*1, *a*2... *a**k*. Finally, Ember picks any index *i* (1 ≤ *i* < *k*) in the array. Now he performs one of the following two operations exactly once:

* flip the subrange [*i* + 1, *k*] and add *a**i* to it. After this, the sequence becomes *a*1, ... *a**i*, *a**k* + *a**i*, *a**k* - 1 + *a**i*, ... *a**i* + 1 + *a**i*
* negate the subrange [*i* + 1, *k*] and add *a**i* to it. i.e., the array becomes *a*1, ... *a**i*,  - *a**i* + 1 + *a**i*,  - *a**i* + 2 + *a**i*, ... - *a**k* + *a**i*

Ember wins if the array is monotonically increasing or decreasing after this. Otherwise Storm wins.

The game can be described by the tuple (*T*, *u*, *v*, *i*, *op*) where *op* is «flip» or «negate» depending on the action Ember chose in the last turn. Find the number of tuples that can occur if Ember and Storm play optimally. When they play optimally, if there are multiple moves by which they are guaranteed to win, then they may play any of the winning moves. Otherwise, if someone loses no matter what they play, then they may play any of the possible moves.

Report the answer modulo *m*.

## Input

The input consists of a single line containing three integers *n*, *d* and *m* (2 ≤ *n* ≤ 200, 1 ≤ *d* < *n*, 1 ≤ *m* ≤ 2·109).

## Output

Print a single number  — the number of possible tuples if Ember and Storm play as described, modulo *m*.

## Examples

## Input


```
2 1 1000000007  

```
## Output


```
4  

```
## Input


```
3 1 250  

```
## Output


```
0  

```
## Input


```
3 2 100  

```
## Output


```
36  

```
## Note

In the first sample case, there is only one possible tree. There are two possible paths, 1 to 2 and 2 to 1. For both paths, *i* can only be 1, and *op* can take both possibilities. Therefore, the answer is 4.

In the second sample, there are no possible trees.

In the third sample, there are three possible trees. 



#### tags 

#3400 #combinatorics #dp #games #trees 