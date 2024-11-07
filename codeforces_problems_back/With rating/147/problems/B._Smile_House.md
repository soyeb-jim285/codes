<h1 style='text-align: center;'> B. Smile House</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A smile house is created to raise the mood. It has *n* rooms. Some of the rooms are connected by doors. For each two rooms (number *i* and *j*), which are connected by a door, Petya knows their value *c**ij* — the value which is being added to his mood when he moves from room *i* to room *j*.

Petya wondered whether he can raise his mood infinitely, moving along some cycle? And if he can, then what minimum number of rooms he will need to visit during one period of a cycle?

## Input

The first line contains two positive integers *n* and *m* (![](images/0d16348eee67d88f6667edf93a293fdb8b30603c.png)), where *n* is the number of rooms, and *m* is the number of doors in the Smile House. Then follows the description of the doors: *m* lines each containing four integers *i*, *j*, *c**ij* и *c**ji* (1 ≤ *i*, *j* ≤ *n*, *i* ≠ *j*,  - 104 ≤ *c**ij*, *c**ji* ≤ 104). It is guaranteed that no more than one door connects any two rooms. No door connects the room with itself.

## Output

Print the minimum number of rooms that one needs to visit during one traverse of the cycle that can raise mood infinitely. If such cycle does not exist, print number 0.

## Examples

## Input


```
4 4  
1 2 -10 3  
1 3 1 -10  
2 4 -10 -1  
3 4 0 -3  

```
## Output


```
4  

```
## Note

Cycle is such a sequence of rooms *a*1, *a*2, ..., *a**k*, that *a*1 is connected with *a*2, *a*2 is connected with *a*3, ..., *a**k* - 1 is connected with *a**k*, *a**k* is connected with *a*1. Some elements of the sequence can coincide, that is, the cycle should not necessarily be simple. The number of rooms in the cycle is considered as *k*, the sequence's length. ## Note

 that the minimum possible length equals two.



#### tags 

#2500 #binary_search #graphs #matrices 