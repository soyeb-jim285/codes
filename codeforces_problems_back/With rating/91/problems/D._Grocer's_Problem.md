<h1 style='text-align: center;'> D. Grocer's Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yesterday was a fair in a supermarket's grocery section. There were *n* jars with spices on the fair. Before the event the jars were numbered from 1 to *n* from the left to the right. After the event the jars were moved and the grocer had to sort them by the increasing of the numbers.

The grocer has a special machine at his disposal. The machine can take any 5 or less jars and rearrange them in the way the grocer wants. ## Note

 that the jars do not have to stand consecutively. For example, from the permutation 2, 6, 5, 4, 3, 1 one can get permutation 1, 2, 3, 4, 5, 6, if pick the jars on the positions 1, 2, 3, 5 and 6. 

Which minimum number of such operations is needed to arrange all the jars in the order of their numbers' increasing?

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 105). The second line contains *n* space-separated integers *a**i* (1 ≤ *a**i* ≤ *n*) — the *i*-th number represents the number of a jar that occupies the *i*-th position. It is guaranteed that all the numbers are distinct.

## Output

Print on the first line the least number of operations needed to rearrange all the jars in the order of the numbers' increasing. Then print the description of all actions in the following format.

On the first line of the description of one action indicate the number of jars that need to be taken (*k*), on the second line indicate from which positions the jars need to be taken (*b*1, *b*2, ..., *b**k*), on the third line indicate the jar's new order (*c*1, *c*2, ..., *c**k*). After the operation is fulfilled the jar from position *b**i* will occupy the position *c**i*. The set (*c*1, *c*2, ..., *c**k*) should be the rearrangement of the set (*b*1, *b*2, ..., *b**k*).

If there are multiple solutions, output any.

## Examples

## Input


```
6  
3 5 6 1 2 4  

```
## Output


```
2  
4  
1 3 6 4   
3 6 4 1   
2  
2 5   
5 2   

```
## Input


```
14  
9 13 11 3 10 7 12 14 1 5 4 6 8 2  

```
## Output


```
3  
4  
2 13 8 14   
13 8 14 2   
5  
6 7 12 5 10   
7 12 6 10 5   
5  
3 11 4 1 9   
11 4 3 9 1   

```
## Note

Let's consider the first sample. The jars can be sorted within two actions.

During the first action we take the jars from positions 1, 3, 6 and 4 and put them so that the jar that used to occupy the position 1 will occupy the position 3 after the operation is completed. The jar from position 3 will end up in position 6, the jar from position 6 will end up in position 4 and the jar from position 4 will end up in position 1.

After the first action the order will look like that: 1, 5, 3, 4, 2, 6. 

During the second operation the jars in positions 2 and 5 will change places.



#### tags 

#2600 #constructive_algorithms #graphs #greedy 