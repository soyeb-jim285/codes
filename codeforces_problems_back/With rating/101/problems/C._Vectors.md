<h1 style='text-align: center;'> C. Vectors</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

At a geometry lesson Gerald was given a task: to get vector *B* out of vector *A*. Besides, the teacher permitted him to perform the following operations with vector *А*:

* Turn the vector by 90 degrees clockwise.
* Add to the vector a certain vector *C*.

Operations could be performed in any order any number of times.

Can Gerald cope with the task?

## Input

The first line contains integers *x*1 и *y*1 — the coordinates of the vector *A* ( - 108 ≤ *x*1, *y*1 ≤ 108). The second and the third line contain in the similar manner vectors *B* and *C* (their coordinates are integers; their absolute value does not exceed 108).

## Output

Print "YES" (without the quotes) if it is possible to get vector *B* using the given operations. Otherwise print "NO" (without the quotes).

## Examples

## Input


```
0 0  
1 1  
0 1  

```
## Output


```
YES  

```
## Input


```
0 0  
1 1  
1 1  

```
## Output


```
YES  

```
## Input


```
0 0  
1 1  
2 2  

```
## Output


```
NO  

```


#### tags 

#2000 #implementation #math 