<h1 style='text-align: center;'> D. Campus</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Oscolcovo city has a campus consisting of *n* student dormitories, *n* universities and *n* military offices. Initially, the *i*-th dormitory belongs to the *i*-th university and is assigned to the *i*-th military office.

Life goes on and the campus is continuously going through some changes. The changes can be of four types:

1. University *a**j* merges with university *b**j*. After that all the dormitories that belonged to university *b**j* are assigned to to university *a**j*, and university *b**j* disappears.
2. Military office *c**j* merges with military office *d**j*. After that all the dormitories that were assigned to military office *d**j*, are assigned to military office *c**j*, and military office *d**j* disappears.
3. Students of university *x**j* move in dormitories. Lets *k**x**j* is the number of dormitories that belong to this university at the time when the students move in. Then the number of students in each dormitory of university *x**j* increases by *k**x**j* (note that the more dormitories belong to the university, the more students move in each dormitory of the university).
4. Military office number *y**j* conducts raids on all the dormitories assigned to it and takes all students from there.

Thus, at each moment of time each dormitory is assigned to exactly one university and one military office. Initially, all the dormitory are empty.

Your task is to process the changes that take place in the campus and answer the queries, how many people currently live in dormitory *q**j*.

## Input

The first line contains two integers, *n* and *m* (1 ≤ *n*, *m* ≤ 5·105) — the number of dormitories and the number of queries, respectively.

Next *m* lines contain the queries, each of them is given in one of the following formats: 

* «U *a**j* *b**j*» — merging universities;
* «M *c**j* *d**j*» — merging military offices;
* «A *x**j*» — students of university *x**j* moving in the dormitories;
* «Z *y**j*» — a raid in military office *y**j*;
* «Q *q**j*» — a query asking the number of people in dormitory *q**j*.

 All the numbers in the queries are positive integers and do not exceed *n*. It is guaranteed that at the moment of the query the universities and military offices, that are present in the query, exist.## Output

In the *i*-th line print the answer to the *i*-th query asking the number of people in the dormitory.

## Examples

## Input


```
2 7  
A 1  
Q 1  
U 1 2  
A 1  
Z 1  
Q 1  
Q 2  

```
## Output


```
1  
0  
2  

```
## Input


```
5 12  
U 1 2  
M 4 5  
A 1  
Q 1  
A 3  
A 4  
Q 3  
Q 4  
Z 4  
Q 4  
A 5  
Q 5  

```
## Output


```
2  
1  
1  
0  
1  

```
## Note

Consider the first sample test: 

* In the first query university 1 owns only dormitory 1, so after the query dormitory 1 will have 1 student.
* After the third query university 1 owns dormitories 1 and 2.
* The fourth query increases by 2 the number of students living in dormitories 1 and 2 that belong to university number 1. After that 3 students live in the first dormitory and 2 students live in the second dormitory.
* At the fifth query the number of students living in dormitory 1, assigned to the military office 1, becomes zero.


#### tags 

#3100 #binary_search #data_structures #dsu #trees 