<h1 style='text-align: center;'> C. Goodbye Souvenir</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

I won't feel lonely, nor will I be sorrowful... not before everything is buried.

A string of *n* beads is left as the message of leaving. The beads are numbered from 1 to *n* from left to right, each having a shape numbered by integers between 1 and *n* inclusive. Some beads may have the same shapes.

The memory of a shape *x* in a certain subsegment of beads, is defined to be the difference between the last position and the first position that shape *x* appears in the segment. The memory of a subsegment is the sum of memories over all shapes that occur in it.

From time to time, shapes of beads change as well as the memories. Sometimes, the past secreted in subsegments are being recalled, and you are to find the memory for each of them.

## Input

The first line of input contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 100 000) — the number of beads in the string, and the total number of changes and queries, respectively.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*) — the initial shapes of beads 1, 2, ..., *n*, respectively.

The following *m* lines each describes either a change in the beads or a query of subsegment. A line has one of the following formats: 

* 1 p x (1 ≤ *p* ≤ *n*, 1 ≤ *x* ≤ *n*), meaning that the shape of the *p*-th bead is changed into *x*;
* 2 l r (1 ≤ *l* ≤ *r* ≤ *n*), denoting a query of memory of the subsegment from *l* to *r*, inclusive.
## Output

For each query, print one line with an integer — the memory of the recalled subsegment.

## Examples

## Input


```
7 6  
1 2 3 1 3 2 1  
2 3 7  
2 1 3  
1 7 2  
1 3 2  
2 1 6  
2 5 7  

```
## Output


```
5  
0  
7  
1  

```
## Input


```
7 5  
1 3 2 1 4 2 3  
1 1 4  
2 2 3  
1 1 7  
2 4 5  
1 1 7  

```
## Output


```
0  
0  

```
## Note

The initial string of beads has shapes (1, 2, 3, 1, 3, 2, 1).

Consider the changes and queries in their order: 

1. 2 3 7: the memory of the subsegment [3, 7] is (7 - 4) + (6 - 6) + (5 - 3) = 5;
2. 2 1 3: the memory of the subsegment [1, 3] is (1 - 1) + (2 - 2) + (3 - 3) = 0;
3. 1 7 2: the shape of the 7-th bead changes into 2. Beads now have shapes (1, 2, 3, 1, 3, 2, 2) respectively;
4. 1 3 2: the shape of the 3-rd bead changes into 2. Beads now have shapes (1, 2, 2, 1, 3, 2, 2) respectively;
5. 2 1 6: the memory of the subsegment [1, 6] is (4 - 1) + (6 - 2) + (5 - 5) = 7;
6. 2 5 7: the memory of the subsegment [5, 7] is (7 - 6) + (5 - 5) = 1.


#### tags 

#2600 #data_structures #divide_and_conquer 