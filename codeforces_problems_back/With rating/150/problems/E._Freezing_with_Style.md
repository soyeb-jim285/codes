<h1 style='text-align: center;'> E. Freezing with Style</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This winter is so... well, you've got the idea :-) The Nvodsk road system can be represented as *n* junctions connected with *n* - 1 bidirectional roads so that there is a path between any two junctions. The organizers of some event want to choose a place to accommodate the participants (junction *v*), and the place to set up the contests (junction *u*). Besides, at the one hand, they want the participants to walk about the city and see the neighbourhood (that's why the distance between *v* and *u* should be no less than *l*). On the other hand, they don't want the participants to freeze (so the distance between *v* and *u* should be no more than *r*). Besides, for every street we know its beauty — some integer from 0 to 109. Your task is to choose the path that fits in the length limits and has the largest average beauty. We shall define the average beauty as a median of sequence of the beauties of all roads along the path.

We can put it more formally like that: let there be a path with the length *k*. Let *a**i* be a non-decreasing sequence that contains exactly *k* elements. Each number occurs there exactly the number of times a road with such beauty occurs along on path. We will represent the path median as number *a*⌊*k* / 2⌋, assuming that indexation starting from zero is used. ⌊*x*⌋ — is number *х*, rounded down to the nearest integer.

For example, if *a* = {0, 5, 12}, then the median equals to 5, and if *a* = {0, 5, 7, 12}, then the median is number 7.

It is guaranteed that there will be at least one path with the suitable quantity of roads.

## Input

The first line contains three integers *n*, *l*, *r* (1 ≤ *l* ≤ *r* < *n* ≤ 105).

Next *n* - 1 lines contain descriptions of roads of the Nvodsk, each line contains three integers *a**i*, *b**i*, *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*, 0 ≤ *c**i* ≤ 109, *a**i* ≠ *b**i*) — junctions *a**i* and *b**i* are connected with a street whose beauty equals *c**i*.

## Output

Print two integers — numbers of the junctions, where to accommodate the participants and set up the contests, correspondingly. If there are multiple optimal variants, print any of them.

## Examples

## Input


```
6 3 4  
1 2 1  
2 3 1  
3 4 1  
4 5 1  
5 6 1  

```
## Output


```
4 1  

```
## Input


```
6 3 4  
1 2 1  
2 3 1  
3 4 1  
4 5 2  
5 6 2  

```
## Output


```
6 3  

```
## Input


```
5 1 4  
1 2 1  
1 3 4  
3 4 7  
3 5 2  

```
## Output


```
4 3  

```
## Input


```
8 3 6  
1 2 9  
2 3 7  
3 4 7  
4 5 8  
5 8 2  
3 6 3  
2 7 4  

```
## Output


```
5 1  

```
## Note

In the first sample all roads have the same beauty. That means that all paths of the positive length have the same median. Thus, any path with length from 3 to 4, inclusive will be valid for us.

In the second sample the city looks like that: 1 - 2 - 3 - 4 - 5 - 6. Two last roads are more valuable and we should choose any path that contains both of them and has the suitable length. It is either the path between 2 and 6 or the path between 3 and 6.



#### tags 

#3000 #binary_search #data_structures #divide_and_conquer #trees 