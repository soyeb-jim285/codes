<h1 style='text-align: center;'> L. Send the Fool Further! (hard)</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Heidi is terrified by your estimate and she found it unrealistic that her friends would collaborate to drive her into debt. She expects that, actually, each person will just pick a random friend to send Heidi to. (This randomness assumption implies, however, that she can now visit the same friend an arbitrary number of times...) Moreover, if a person only has one friend in common with Heidi (i.e., if that person is in a leaf of the tree), then that person will not send Heidi back (so that Heidi's travel will end at some point).

Heidi also found unrealistic the assumption that she can make all the travels in one day. Therefore now she assumes that every time she travels a route between two friends, she needs to buy a new ticket. She wants to know: how much should she expect to spend on the trips?

For what it's worth, Heidi knows that Jenny has at least two friends.

## Input

The first line contains the number of friends *n* (3 ≤ *n* ≤ 105). The next *n* - 1 lines each contain three space-separated integers *u*, *v* and *c* (0 ≤ *u*, *v* ≤ *n* - 1, 1 ≤ *c* ≤ 104) meaning that *u* and *v* are friends and the cost for traveling between *u* and *v* is *c* (paid every time!).

It is again guaranteed that the social network of the input forms a tree.

## Output

Assume that the expected cost of the trips is written as an irreducible fraction *a* / *b* (that is, *a* and *b* are coprime). Then Heidi, the weird cow that she is, asks you to output ![](images/036b26794425c84a742df3e8f7ad0fb3a87d9c01.png). (## Output

 a single integer between 0 and 109 + 6.)

## Examples

## Input


```
3  
0 1 10  
0 2 20  

```
## Output


```
15  

```
## Input


```
4  
0 1 3  
0 2 9  
0 3 27  

```
## Output


```
13  

```
## Input


```
7  
0 1 3  
0 5 7  
1 2 2  
1 3 1  
1 4 5  
5 6 8  

```
## Output


```
400000019  

```
## Input


```
11  
1 0 6646  
2 0 8816  
3 2 9375  
4 2 5950  
5 1 8702  
6 2 2657  
7 2 885  
8 7 2660  
9 2 5369  
10 6 3798  

```
## Output


```
153869806  

```
## Input


```
6  
0 1 8  
0 2 24  
1 3 40  
1 4 16  
4 5 8  

```
## Output


```
39  

```
## Note

In the first example, with probability 1 / 2 Heidi will go to 1 from 0, and with probability 1 / 2 she will go to 2. In the first case the cost would be 10, and in the second it would be 20. After reaching 1 or 2 she will stop, as 1 and 2 are leaves of the social tree. Hence, the expected cost she has to pay is 10·1 / 2 + 20·1 / 2 = 15.

In the third example, the expected cost is 81 / 5. You should output 400000019.

In her travels, Heidi has learned an intriguing fact about the structure of her social network. She tells you the following: The mysterious determinant that you might be wondering about is such that it does not cause strange errors in your reasonable solution... Did we mention that Heidi is a weird cow?



#### tags 

#2400 #dfs_and_similar #dp #math #trees 