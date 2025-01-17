<h1 style='text-align: center;'> F. Mathematical Analysis Rocks!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Students of group 199 have written their lectures dismally. Now an exam on Mathematical Analysis is approaching and something has to be done asap (that is, quickly). Let's number the students of the group from 1 to *n*. Each student *i* (1 ≤ *i* ≤ *n*) has a best friend *p*[*i*] (1 ≤ *p*[*i*] ≤ *n*). In fact, each student is a best friend of exactly one student. In other words, all *p*[*i*] are different. It is possible that the group also has some really "special individuals" for who *i* = *p*[*i*].

Each student wrote exactly one notebook of lecture notes. We know that the students agreed to act by the following algorithm: 

* on the first day of revising each student studies his own Mathematical Analysis notes,
* in the morning of each following day each student gives the notebook to his best friend and takes a notebook from the student who calls him the best friend.

Thus, on the second day the student *p*[*i*] (1 ≤ *i* ≤ *n*) studies the *i*-th student's notes, on the third day the notes go to student *p*[*p*[*i*]] and so on. Due to some characteristics of the boys' friendship (see paragraph 1), each day each student has exactly one notebook to study.

You are given two sequences that describe the situation on the third and fourth days of revising:

* *a*1, *a*2, ..., *a**n*, where *a**i* means the student who gets the *i*-th student's notebook on the third day of revising;
* *b*1, *b*2, ..., *b**n*, where *b**i* means the student who gets the *i*-th student's notebook on the fourth day of revising.

You do not know array *p*, that is you do not know who is the best friend to who. Write a program that finds *p* by the given sequences *a* and *b*.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of students in the group. The second line contains sequence of different integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*). The third line contains the sequence of different integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ *n*).

## Output

Print sequence *n* of different integers *p*[1], *p*[2], ..., *p*[*n*] (1 ≤ *p*[*i*] ≤ *n*). It is guaranteed that the solution exists and that it is unique.

## Examples

## Input


```
4  
2 1 4 3  
3 4 2 1  

```
## Output


```
4 3 1 2 
```
## Input


```
5  
5 2 3 1 4  
1 3 2 4 5  

```
## Output


```
4 3 2 5 1 
```
## Input


```
2  
1 2  
2 1  

```
## Output


```
2 1 
```


#### tags 

#1200 #constructive_algorithms #implementation #math 