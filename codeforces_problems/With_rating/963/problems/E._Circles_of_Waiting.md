<h1 style='text-align: center;'> E. Circles of Waiting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A chip was placed on a field with coordinate system onto point (0, 0).

Every second the chip moves randomly. If the chip is currently at a point (*x*, *y*), after a second it moves to the point (*x* - 1, *y*) with probability *p*1, to the point (*x*, *y* - 1) with probability *p*2, to the point (*x* + 1, *y*) with probability *p*3 and to the point (*x*, *y* + 1) with probability *p*4. It's guaranteed that *p*1 + *p*2 + *p*3 + *p*4 = 1. The moves are independent.

Find out the expected time after which chip will move away from origin at a distance greater than *R* (i.e. ![](images/9f4670fa50106dc217721881b50d148d5cb411e6.png) will be satisfied).

##### Input

First line contains five integers *R*, *a*1, *a*2, *a*3 and *a*4 (0 ≤ *R* ≤ 50, 1 ≤ *a*1, *a*2, *a*3, *a*4 ≤ 1000).

Probabilities *p**i* can be calculated using formula ![](images/65ccb7dfe60ba768ddd49ae4fc254f5cf595d980.png).

##### Output

It can be shown that answer for this problem is always a rational number of form ![](images/b795551c4ba5b501281e7063ac11feb87c7f234f.png), where ![](images/deeb778b5db74d34de7beb4fe39bce44379acd40.png).

Print *P*·*Q*- 1 modulo 109 + 7. 

## Examples

##### Input


```text
0 1 1 1 1  

```
##### Output


```text
1
```
##### Input


```text
1 1 1 1 1  

```
##### Output


```text
666666674
```
##### Input


```text
1 1 2 1 2  

```
##### Output


```text
538461545
```
## Note

In the first example initially the chip is located at a distance 0 from origin. In one second chip will move to distance 1 is some direction, so distance to origin will become 1.

Answers to the second and the third tests: ![](images/4698d4bc5d3f09c8d2261ff8d109754f88454614.png) and ![](images/43b509b340db034f967064e721a5926972df0e73.png).



#### Tags 

#3100 #NOT OK #math 

## Blogs
- [All Contest Problems](../Tinkoff_Internship_Warmup_Round_2018_and_Codeforces_Round_475_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
