<h1 style='text-align: center;'> E. Lucky Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya brought home string *s* with the length of *n*. The string only consists of lucky digits. The digits are numbered from the left to the right starting with 1. Now Petya should execute *m* queries of the following form:

* switch *l* *r* — "switch" digits (i.e. replace them with their opposites) at all positions with indexes from *l* to *r*, inclusive: each digit 4 is replaced with 7 and each digit 7 is replaced with 4 (1 ≤ *l* ≤ *r* ≤ *n*);
* count — find and print on the screen the length of the longest non-decreasing subsequence of string *s*.

Subsequence of a string *s* is a string that can be obtained from *s* by removing zero or more of its elements. A string is called non-decreasing if each successive digit is not less than the previous one.

Help Petya process the requests.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 106, 1 ≤ *m* ≤ 3·105) — the length of the string *s* and the number of queries correspondingly. The second line contains *n* lucky digits without spaces — Petya's initial string. Next *m* lines contain queries in the form described in the statement.

## Output

For each query count print an answer on a single line.

## Examples

## Input


```
2 3  
47  
count  
switch 1 2  
count  

```
## Output


```
2  
1  

```
## Input


```
3 5  
747  
count  
switch 1 1  
count  
switch 1 3  
count  

```
## Output


```
2  
3  
2  

```
## Note

In the first sample the chronology of string *s* after some operations are fulfilled is as follows (the sought maximum subsequence is marked with bold): 

1. 47
2. 74
3. 74

 In the second sample: 1. 747
2. 447
3. 447
4. 774
5. 774


#### tags 

#2400 #data_structures 