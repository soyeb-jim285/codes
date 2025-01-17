<h1 style='text-align: center;'> E. Awards For Contestants</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alexey recently held a programming contest for students from Berland. *n* students participated in a contest, *i*-th of them solved *a**i* problems. Now he wants to award some contestants. Alexey can award the students with diplomas of three different degrees. Each student either will receive one diploma of some degree, or won't receive any diplomas at all. Let *cnt**x* be the number of students that are awarded with diplomas of degree *x* (1 ≤ *x* ≤ 3). The following conditions must hold:

* For each *x* (1 ≤ *x* ≤ 3) *cnt**x* > 0;
* For any two degrees *x* and *y* *cnt**x* ≤ 2·*cnt**y*.

Of course, there are a lot of ways to distribute the diplomas. Let *b**i* be the degree of diploma *i*-th student will receive (or  - 1 if *i*-th student won't receive any diplomas). Also for any *x* such that 1 ≤ *x* ≤ 3 let *c**x* be the maximum number of problems solved by a student that receives a diploma of degree *x*, and *d**x* be the minimum number of problems solved by a student that receives a diploma of degree *x*. Alexey wants to distribute the diplomas in such a way that:

1. If student *i* solved more problems than student *j*, then he has to be awarded not worse than student *j* (it's impossible that student *j* receives a diploma and *i* doesn't receive any, and also it's impossible that both of them receive a diploma, but *b**j* < *b**i*);
2. *d*1 - *c*2 is maximum possible;
3. Among all ways that maximize the previous expression, *d*2 - *c*3 is maximum possible;
4. Among all ways that correspond to the two previous conditions, *d*3 - *c*- 1 is maximum possible, where *c*- 1 is the maximum number of problems solved by a student that doesn't receive any diploma (or 0 if each student is awarded with some diploma).

Help Alexey to find a way to award the contestants!

## Input

The first line contains one integer number *n* (3 ≤ *n* ≤ 3000).

The second line contains *n* integer numbers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 5000).

## Output

## Output

 *n* numbers. *i*-th number must be equal to the degree of diploma *i*-th contestant will receive (or  - 1 if he doesn't receive any diploma).

If there are multiple optimal solutions, print any of them. It is guaranteed that the answer always exists.

## Examples

## Input


```
4  
1 2 3 4  

```
## Output


```
3 3 2 1   

```
## Input


```
6  
1 4 3 1 1 2  

```
## Output


```
-1 1 2 -1 -1 3   

```


#### tags 

#2300 #brute_force #data_structures #dp 