<h1 style='text-align: center;'> B. Valera and Contest</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera loves to participate in competitions. Especially in programming contests. Today he has participated in the contest with his team, consisting of *n* students (including Valera). This contest was an individual competition, so each student in the team solved problems individually.

After the contest was over, Valera was interested in results. He found out that:

* each student in the team scored at least *l* points and at most *r* points;
* in total, all members of the team scored exactly *s**all* points;
* the total score of the *k* members of the team who scored the most points is equal to exactly *s**k*; more formally, if *a*1, *a*2, ..., *a**n* is the sequence of points earned by the team of students in the non-increasing order (*a*1 ≥ *a*2 ≥ ... ≥ *a**n*), then *s**k* = *a*1 + *a*2 + ... + *a**k*.

However, Valera did not find out exactly how many points each of *n* students scored. Valera asked you to recover any distribution of scores between the students of the team, such that all the conditions above are met.

## Input

The first line of the input contains exactly six integers *n*, *k*, *l*, *r*, *s**all*, *s**k* (1 ≤ *n*, *k*, *l*, *r* ≤ 1000; *l* ≤ *r*; *k* ≤ *n*; 1 ≤ *s**k* ≤ *s**all* ≤ 106).

It's guaranteed that the input is such that the answer exists.

## Output

Print exactly *n* integers *a*1, *a*2, ..., *a**n* — the number of points each student scored. If there are multiple solutions, you can print any of them. You can print the distribution of points in any order. 

## Examples

## Input


```
5 3 1 3 13 9  

```
## Output


```
2 3 2 3 3 
```
## Input


```
5 3 1 3 15 9  

```
## Output


```
3 3 3 3 3 
```


#### tags 

#1400 #constructive_algorithms #implementation #math 