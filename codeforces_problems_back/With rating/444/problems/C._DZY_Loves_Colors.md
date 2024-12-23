<h1 style='text-align: center;'> C. DZY Loves Colors</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

DZY loves colors, and he enjoys painting.

On a colorful day, DZY gets a colorful ribbon, which consists of *n* units (they are numbered from 1 to *n* from left to right). The color of the *i*-th unit of the ribbon is *i* at first. It is colorful enough, but we still consider that the colorfulness of each unit is 0 at first.

DZY loves painting, we know. He takes up a paintbrush with color *x* and uses it to draw a line on the ribbon. In such a case some contiguous units are painted. Imagine that the color of unit *i* currently is *y*. When it is painted by this paintbrush, the color of the unit becomes *x*, and the colorfulness of the unit increases by |*x* - *y*|.

DZY wants to perform *m* operations, each operation can be one of the following:

1. Paint all the units with numbers between *l* and *r* (both inclusive) with color *x*.
2. Ask the sum of colorfulness of the units between *l* and *r* (both inclusive).

Can you help DZY?

## Input

The first line contains two space-separated integers *n*, *m* (1 ≤ *n*, *m* ≤ 105).

Each of the next *m* lines begins with a integer *type* (1 ≤ *type* ≤ 2), which represents the type of this operation.

If *type* = 1, there will be 3 more integers *l*, *r*, *x* (1 ≤ *l* ≤ *r* ≤ *n*; 1 ≤ *x* ≤ 108) in this line, describing an operation 1.

If *type* = 2, there will be 2 more integers *l*, *r* (1 ≤ *l* ≤ *r* ≤ *n*) in this line, describing an operation 2.

## Output

For each operation 2, print a line containing the answer — sum of colorfulness.

## Examples

## Input


```
3 3  
1 1 2 4  
1 2 3 5  
2 1 3  

```
## Output


```
8  

```
## Input


```
3 4  
1 1 3 4  
2 1 1  
2 2 2  
2 3 3  

```
## Output


```
3  
2  
1  

```
## Input


```
10 6  
1 1 5 3  
1 2 7 9  
1 10 10 11  
1 3 8 12  
1 1 10 3  
2 1 10  

```
## Output


```
129  

```
## Note

In the first sample, the color of each unit is initially [1, 2, 3], and the colorfulness is [0, 0, 0].

After the first operation, colors become [4, 4, 3], colorfulness become [3, 2, 0].

After the second operation, colors become [4, 5, 5], colorfulness become [3, 3, 2].

So the answer to the only operation of type 2 is 8.



#### tags 

#2400 #data_structures 