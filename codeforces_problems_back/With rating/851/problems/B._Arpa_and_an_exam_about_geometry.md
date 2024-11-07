<h1 style='text-align: center;'> B. Arpa and an exam about geometry</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arpa is taking a geometry exam. Here is the last problem of the exam.

You are given three points *a*, *b*, *c*.

Find a point and an angle such that if we rotate the page around the point by the angle, the new position of *a* is the same as the old position of *b*, and the new position of *b* is the same as the old position of *c*.

Arpa is doubting if the problem has a solution or not (i.e. if there exists a point and an angle satisfying the condition). Help Arpa determine if the question has a solution or not.

## Input

The only line contains six integers *a**x*, *a**y*, *b**x*, *b**y*, *c**x*, *c**y* (|*a**x*|, |*a**y*|, |*b**x*|, |*b**y*|, |*c**x*|, |*c**y*| ≤ 109). It's guaranteed that the points are distinct.

## Output

Print "Yes" if the problem has a solution, "No" otherwise.

You can print each letter in any case (upper or lower).

## Examples

## Input


```
0 1 1 1 1 0  

```
## Output


```
Yes  

```
## Input


```
1 1 0 0 1000 1000  

```
## Output


```
No  

```
## Note

In the first sample test, rotate the page around (0.5, 0.5) by ![](images/9d845923f4d356a48d8ede337db0303821311f0c.png).

In the second sample test, you can't find any solution.



#### tags 

#1400 #geometry #math 