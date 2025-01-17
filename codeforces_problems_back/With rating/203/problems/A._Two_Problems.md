<h1 style='text-align: center;'> A. Two Problems</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A boy Valera registered on site Codeforces as Valera, and wrote his first Codeforces Round #300. He boasted to a friend Arkady about winning as much as *x* points for his first contest. But Arkady did not believe his friend's words and decided to check whether Valera could have shown such a result.

He knows that the contest number 300 was unusual because there were only two problems. The contest lasted for *t* minutes, the minutes are numbered starting from zero. The first problem had the initial cost of *a* points, and every minute its cost reduced by *d**a* points. The second problem had the initial cost of *b* points, and every minute this cost reduced by *d**b* points. Thus, as soon as the zero minute of the contest is over, the first problem will cost *a* - *d**a* points, and the second problem will cost *b* - *d**b* points. It is guaranteed that at any moment of the contest each problem has a non-negative cost.

Arkady asks you to find out whether Valera could have got exactly *x* points for this contest. You should assume that Valera could have solved any number of the offered problems. You should also assume that for each problem Valera made no more than one attempt, besides, he could have submitted both problems at the same minute of the contest, starting with minute 0 and ending with minute number *t* - 1. Please note that Valera can't submit a solution exactly *t* minutes after the start of the contest or later.

## Input

The single line of the input contains six integers *x*, *t*, *a*, *b*, *d**a*, *d**b* (0 ≤ *x* ≤ 600; 1 ≤ *t*, *a*, *b*, *d**a*, *d**b* ≤ 300) — Valera's result, the contest's duration, the initial cost of the first problem, the initial cost of the second problem, the number of points that the first and the second problem lose per minute, correspondingly.

It is guaranteed that at each minute of the contest each problem has a non-negative cost, that is, *a* - *i*·*d**a* ≥ 0 and *b* - *i*·*d**b* ≥ 0 for all 0 ≤ *i* ≤ *t* - 1.

## Output

If Valera could have earned exactly *x* points at a contest, print "YES", otherwise print "NO" (without the quotes).

## Examples

## Input


```
30 5 20 20 3 5  

```
## Output


```
YES  

```
## Input


```
10 4 100 5 5 1  

```
## Output


```
NO  

```
## Note

In the first sample Valera could have acted like this: he could have submitted the first problem at minute 0 and the second problem — at minute 2. Then the first problem brings him 20 points and the second problem brings him 10 points, that in total gives the required 30 points.



#### tags 

#1200 #brute_force #implementation 