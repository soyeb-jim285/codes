<h1 style='text-align: center;'> B. Restoring Painting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya works as a watchman in the gallery. Unfortunately, one of the most expensive paintings was stolen while he was on duty. He doesn't want to be fired, so he has to quickly restore the painting. He remembers some facts about it.

* The painting is a square 3 × 3, each cell contains a single integer from 1 to *n*, and different cells may contain either different or equal integers.
* The sum of integers in each of four squares 2 × 2 is equal to the sum of integers in the top left square 2 × 2.
* Four elements *a*, *b*, *c* and *d* are known and are located as shown on the picture below.

![](images/f8d85b32daa63482cff27d57913b93181fcadda8.png)Help Vasya find out the number of distinct squares the satisfy all the conditions above. ## Note

, that this number may be equal to 0, meaning Vasya remembers something wrong.

Two squares are considered to be different, if there exists a cell that contains two different integers in different squares.

## Input

The first line of the input contains five integers *n*, *a*, *b*, *c* and *d* (1 ≤ *n* ≤ 100 000, 1 ≤ *a*, *b*, *c*, *d* ≤ *n*) — maximum possible value of an integer in the cell and four integers that Vasya remembers.

## Output

Print one integer — the number of distinct valid squares.

## Examples

## Input


```
2 1 1 1 2  

```
## Output


```
2  

```
## Input


```
3 3 1 2 3  

```
## Output


```
6  

```
## Note

Below are all the possible paintings for the first sample. ![](images/c4c53d4e7b6814d8aad7b72604b6089d61dadb48.png) ![](images/46a6ad6a5d3db202f3779b045b9dc77fc2348cf1.png)

In the second sample, only paintings displayed below satisfy all the rules. ![](images/776f231305f8ce7c33e79e887722ce46aa8b6e61.png) ![](images/2fce9e9a31e70f1e46ea26f11d7305b3414e9b6b.png) ![](images/be084a4d1f7e475be1183f7dff10e9c89eb175ef.png) ![](images/96afdb4a35ac14f595d29bea2282f621098902f4.png) ![](images/79ca8d720334a74910514f017ecf1d0166009a03.png) ![](images/ad3c37e950bf5702d54f05756db35c831da59ad9.png)



#### tags 

#1400 #brute_force #constructive_algorithms #math 