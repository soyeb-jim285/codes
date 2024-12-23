<h1 style='text-align: center;'> F. Dirty plates</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After one of celebrations there is a stack of dirty plates in Nikita's kitchen. Nikita has to wash them and put into a dryer. In dryer, the plates should be also placed in a stack also, and the plates sizes should increase down up. The sizes of all plates are distinct.

Nikita has no so much free space, specifically, he has a place for only one more stack of plates. Therefore, he can perform only such two operations: 

* Take any number of plates from 1 to *a* from the top of the dirty stack, wash them and put them to the intermediate stack.
* Take any number of plates from 1 to *b* from the top of the intermediate stack and put them to the stack in the dryer.

## Note

 that after performing each of the operations, the plates are put in the same order as they were before the operation.

You are given the sizes of the plates *s*1, *s*2, ..., *s**n* in the down up order in the dirty stack, and integers *a* and *b*. All the sizes are distinct. Write a program that determines whether or not Nikita can put the plates in increasing down up order in the dryer. If he is able to do so, the program should find some sequence of operations (not necessary optimal) to achieve it.

## Input

The first line contains three integers *n*, *a* and *b* (1 ≤ *n* ≤ 2000, 1 ≤ *a*, *b* ≤ *n*). The second line contains integers *s*1, *s*2, ..., *s**n* (1 ≤ *s**i* ≤ *n*) — the sizes of the plates in down up order. All the sizes are distinct.

## Output

In the first line print "YES" if there is a solution. In this case, in the second line print integer *k* — the number of operations. Then in *k* lines print the operations, one per line. Each operation is described by two integers *t**j* and *c**j*, where *t**j* = 1, if the operation is to wash the top *c**j* places from the dirty stack and put them onto the intermediate stack, and *t**j* = 2, if the operation is to move th top *c**j* plates from the intermediate stack to the dryer. 

In case there is no solution, print single line "NO".

If there are multiple solutions, print any of them. ## Note

 that it is not necessary to minimize the number of operations.

## Examples

## Input


```
6 2 3  
2 3 6 4 1 5  

```
## Output


```
YES  
8  
1 2  
1 1  
2 1  
1 2  
1 1  
2 1  
2 1  
2 3  

```
## Input


```
7 7 7  
1 2 3 4 5 6 7  

```
## Output


```
YES  
2  
1 7  
2 7  

```
## Input


```
7 1 1  
1 2 3 4 5 6 7  

```
## Output


```
YES  
14  
1 1  
1 1  
1 1  
1 1  
1 1  
1 1  
1 1  
2 1  
2 1  
2 1  
2 1  
2 1  
2 1  
2 1  

```
## Input


```
4 2 2  
3 2 1 4  

```
## Output


```
NO  

```
## Note

In the first example the initial order of plates was 2, 3, 6, 4, 1, 5. Here is how the stacks look like after each of the operations: 

* [1 2]: Dirty stack: 6, 4, 1, 5. Intermediary stack: 2, 3. The dryer is empty.
* [1 1]: Dirty stack: 4, 1, 5. Intermediary stack: 6, 2, 3. The dryer is empty.
* [2 1]: Dirty stack: 4, 1, 5. Intermediary stack: 2, 3. Dryer stack: 6.
* [1 2]: Dirty stack: 5. Intermediary stack: 4, 1, 2, 3. Dryer stack: 6.
* [1 1]: There are no dirty plates. Intermediary stack: 5, 4, 1, 2, 3. Dryer stack: 6.
* [2 1]: There are no dirty plates. Intermediary stack: 4, 1, 2, 3. Dryer stack: 5, 6.
* [2 1]: There are no dirty plates. Intermediary stack: 1, 2, 3. Dryer stack: 4, 5, 6.
* [2 3]: All the plates are in the dryer: 1, 2, 3, 4, 5, 6.

 In the second example it is possible to wash all the plates in one operation, and then move them all to the dryer.This is not possible in the third example, because it is not permitted to move more than one plate at the same time. It is possible to wash plates one by one so that they are placed onto the intermediary stack in the reverse order, and then move plates one by one to the dryer. The final order is correct.



#### tags 

#3300 #constructive_algorithms #math 