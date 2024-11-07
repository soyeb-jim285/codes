<h1 style='text-align: center;'> F. Multi-Colored Segments</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dmitry has $n$ segments of different colors on the coordinate axis $Ox$. Each segment is characterized by three integers $l_i$, $r_i$ and $c_i$ ($1 \le l_i \le r_i \le 10^9, 1 \le c_i \le n$), where $l_i$ and $r_i$ are are the coordinates of the ends of the $i$-th segment, and $c_i$ is its color.

Dmitry likes to find the minimum distances between segments. However, he considers pairs of segments of the same color uninteresting. Therefore, he wants to know for each segment the distance from this segment to the nearest differently colored segment.

The distance between two segments is the minimum of the distances between a point of the first segment and a point of the second segment. In particular, if the segments intersect, then the distance between them is equal to $0$.

For example, Dmitry has $5$ segments:

 ![](images/97f31043ea9b58e53f94e49629cc6504b5830c6c.png) * The first segment intersects with the second (and these are segments of different colors), so the answers for them are equal to $0$.
* For the $3$-rd segment, the nearest segment of a different color is the $2$-nd segment, the distance to which is equal to $2$.
* For the $4$-th segment, the nearest segment of a different color is the $5$-th segment, the distance to which is equal to $1$.
* The $5$-th segment lies inside the $2$-nd segment (and these are segments of different colors), so the answers for them are equal to $0$.
## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of description of each test case contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of segments.

The next $n$ lines contain descriptions of the segments. Each segment is described by three integers $l_i$, $r_i$ and $c_i$ ($1 \le l_i \le r_i \le 10^9, 1 \le c_i \le n$) — coordinates of the left and right ends of $i$-th segment, as well as the color of this segment. It is guaranteed that there are at least $2$ segments of different colors.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, on a separate line print $n$ integers, where the $i$-th number is equal to the distance from the $i$-th segment to the nearest segment of a different color.

## Examples

## Input


```

931 2 13 4 15 6 22100000000 200000000 1900000000 1000000000 251 2 12 3 23 4 34 5 45 6 551 5 14 9 21 2 18 9 25 7 321 100 210 90 131 1 110 10 21000000000 1000000000 333 4 12 5 11 6 265 6 211 12 37 8 23 4 21 2 19 10 221 3 12 3 2
```
## Output


```

3 1 1 
700000000 700000000 
0 0 0 0 0 
0 0 2 1 0 
0 0 
9 9 999999990 
0 0 0 
3 1 3 1 1 1 
0 0 

```
## Input


```

4811 16 712 15 72 5 817 22 51 8 819 23 816 16 66 7 591 4 35 11 18 11 31 10 12 11 11 10 43 11 15 7 11 11 1925 25 126 26 124 24 213 14 212 16 217 18 119 19 124 27 224 27 1915 18 120 22 213 22 213 22 23 13 26 10 23 6 219 24 222 24 2
```
## Output


```

0 1 1 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 
0 0 0 3 1 1 3 0 0 
0 2 0 0 2 5 9 1 4 

```
## Note

In the first test case of the first sample there is only one segment of color $2$, and all other segments have color $1$. Therefore, for segments of color $1$, the answer is equal to the distance to the $3$rd segment, and for $3$rd one, the answer is equal to the minimum of the distances to segments of color $1$.

In the second test case of the first sample there are only $2$ segments, and for both of them the answer is equal to the distance between them.

In the third test case of the first sample, each segment intersects at least one of its ends with a segment of a different color, so all answers are equal to $0$.

The fourth test case of the first sample is described in the problem statement.

In the fifth test case of the first sample, one segment lies completely inside the other, and for both of them the answer is $0$.

In the sixth test case of the first sample, all segments are points of different colors.



#### tags 

#2000 #binary_search #data_structures #math #sortings 