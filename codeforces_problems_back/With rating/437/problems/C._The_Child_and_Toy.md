<h1 style='text-align: center;'> C. The Child and Toy</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On Children's Day, the child got a toy from Delayyy as a present. However, the child is so naughty that he can't wait to destroy the toy.

The toy consists of *n* parts and *m* ropes. Each rope links two parts, but every pair of parts is linked by at most one rope. To split the toy, the child must remove all its parts. The child can remove a single part at a time, and each remove consume an energy. Let's define an energy value of part *i* as *v**i*. The child spend *v**f*1 + *v**f*2 + ... + *v**f**k* energy for removing part *i* where *f*1, *f*2, ..., *f**k* are the parts that are directly connected to the *i*-th and haven't been removed.

Help the child to find out, what is the minimum total energy he should spend to remove all *n* parts.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 1000; 0 ≤ *m* ≤ 2000). The second line contains *n* integers: *v*1, *v*2, ..., *v**n* (0 ≤ *v**i* ≤ 105). Then followed *m* lines, each line contains two integers *x**i* and *y**i*, representing a rope from part *x**i* to part *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*; *x**i* ≠ *y**i*).

Consider all the parts are numbered from 1 to *n*.

## Output

## Output

 the minimum total energy the child should spend to remove all *n* parts of the toy.

## Examples

## Input


```
4 3  
10 20 30 40  
1 4  
1 2  
2 3  

```
## Output


```
40  

```
## Input


```
4 4  
100 100 100 100  
1 2  
2 3  
2 4  
3 4  

```
## Output


```
400  

```
## Input


```
7 10  
40 10 20 10 20 80 40  
1 5  
4 7  
4 5  
5 2  
5 7  
6 4  
1 6  
1 3  
4 3  
1 4  

```
## Output


```
160  

```
## Note

One of the optimal sequence of actions in the first sample is:

* First, remove part 3, cost of the action is 20.
* Then, remove part 2, cost of the action is 10.
* Next, remove part 4, cost of the action is 10.
* At last, remove part 1, cost of the action is 0.

So the total energy the child paid is 20 + 10 + 10 + 0 = 40, which is the minimum.

In the second sample, the child will spend 400 no matter in what order he will remove the parts.



#### tags 

#1400 #graphs #greedy #sortings 