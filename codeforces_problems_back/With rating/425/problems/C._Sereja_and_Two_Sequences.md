<h1 style='text-align: center;'> C. Sereja and Two Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Sereja has two sequences *a*1, *a*2, ..., *a**n* and *b*1, *b*2, ..., *b**m*, consisting of integers. One day Sereja got bored and he decided two play with them. The rules of the game was very simple. Sereja makes several moves, in one move he can perform one of the following actions:

1. Choose several (at least one) first elements of sequence *a* (non-empty prefix of *a*), choose several (at least one) first elements of sequence *b* (non-empty prefix of *b*); the element of sequence *a* with the maximum index among the chosen ones must be equal to the element of sequence *b* with the maximum index among the chosen ones; remove the chosen elements from the sequences.
2. Remove all elements of both sequences.

The first action is worth *e* energy units and adds one dollar to Sereja's electronic account. The second action is worth the number of energy units equal to the number of elements Sereja removed from the sequences before performing this action. After Sereja performed the second action, he gets all the money that he earned on his electronic account during the game.

Initially Sereja has *s* energy units and no money on his account. What maximum number of money can Sereja get? Note, the amount of Seraja's energy mustn't be negative at any time moment.

## Input

The first line contains integers *n*, *m*, *s*, *e* (1 ≤ *n*, *m* ≤ 105; 1 ≤ *s* ≤ 3·105; 103 ≤ *e* ≤ 104). The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105). The third line contains *m* integers *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ 105).

## Output

Print a single integer — maximum number of money in dollars that Sereja can get.

## Examples

## Input


```
5 5 100000 1000  
1 2 3 4 5  
3 2 4 5 1  

```
## Output


```
3  

```
## Input


```
3 4 3006 1000  
1 2 3  
1 2 4 3  

```
## Output


```
2  

```


#### tags 

#2300 #data_structures #dp 