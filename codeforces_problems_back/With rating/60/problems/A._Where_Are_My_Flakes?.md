<h1 style='text-align: center;'> A. Where Are My Flakes?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/d1498b1262e9be4d39048f1d8d3113d0d81e77f4.png) One morning the Cereal Guy found out that all his cereal flakes were gone. He found a note instead of them. It turned out that his smart roommate hid the flakes in one of *n* boxes. The boxes stand in one row, they are numbered from 1 to *n* from the left to the right. The roommate left hints like "Hidden to the left of the *i*-th box" ("To the left of *i*"), "Hidden to the right of the *i*-th box" ("To the right of *i*"). Such hints mean that there are no flakes in the *i*-th box as well. The Cereal Guy wants to know the minimal number of boxes he necessarily needs to check to find the flakes considering all the hints. Or he wants to find out that the hints are contradictory and the roommate lied to him, that is, no box has the flakes.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 1000, 0 ≤ *m* ≤ 1000) which represent the number of boxes and the number of hints correspondingly. Next *m* lines contain hints like "To the left of *i*" and "To the right of *i*", where *i* is integer (1 ≤ *i* ≤ *n*). The hints may coincide.

## Output

The answer should contain exactly one integer — the number of boxes that should necessarily be checked or "-1" if the hints are contradictory.

## Examples

## Input


```
2 1  
To the left of 2  

```
## Output


```
1  

```
## Input


```
3 2  
To the right of 1  
To the right of 2  

```
## Output


```
1  

```
## Input


```
3 1  
To the left of 3  

```
## Output


```
2  

```
## Input


```
3 2  
To the left of 2  
To the right of 1  

```
## Output


```
-1  

```


#### tags 

#1300 #implementation #two_pointers 