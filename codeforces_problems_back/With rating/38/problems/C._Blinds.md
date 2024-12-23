<h1 style='text-align: center;'> C. Blinds</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The blinds are known to consist of opaque horizontal stripes that can be rotated thus regulating the amount of light flowing in the room. There are *n* blind stripes with the width of 1 in the factory warehouse for blind production. The problem is that all of them are spare details from different orders, that is, they may not have the same length (it is even possible for them to have different lengths)

Every stripe can be cut into two or more parts. The cuttings are made perpendicularly to the side along which the length is measured. Thus the cuttings do not change the width of a stripe but each of the resulting pieces has a lesser length (the sum of which is equal to the length of the initial stripe)

After all the cuttings the blinds are constructed through consecutive joining of several parts, similar in length, along sides, along which length is measured. Also, apart from the resulting pieces an initial stripe can be used as a blind if it hasn't been cut. It is forbidden to construct blinds in any other way.

Thus, if the blinds consist of *k* pieces each *d* in length, then they are of form of a rectangle of *k* × *d* bourlemeters. 

Your task is to find for what window possessing the largest possible area the blinds can be made from the given stripes if on technical grounds it is forbidden to use pieces shorter than *l* bourlemeter. The window is of form of a rectangle with side lengths as positive integers.

## Input

The first output line contains two space-separated integers *n* and *l* (1 ≤ *n*, *l* ≤ 100). They are the number of stripes in the warehouse and the minimal acceptable length of a blind stripe in bourlemeters. The second line contains space-separated *n* integers *a**i*. They are the lengths of initial stripes in bourlemeters (1 ≤ *a**i* ≤ 100).

## Output

Print the single number — the maximal area of the window in square bourlemeters that can be completely covered. If no window with a positive area that can be covered completely without breaking any of the given rules exist, then print the single number 0.

## Examples

## Input


```
4 2  
1 2 3 4  

```
## Output


```
8  

```
## Input


```
5 3  
5 5 7 3 1  

```
## Output


```
15  

```
## Input


```
2 3  
1 2  

```
## Output


```
0  

```
## Note

In the first sample test the required window is 2 × 4 in size and the blinds for it consist of 4 parts, each 2 bourlemeters long. One of the parts is the initial stripe with the length of 2, the other one is a part of a cut stripe with the length of 3 and the two remaining stripes are parts of a stripe with the length of 4 cut in halves.



#### tags 

#1400 #brute_force 