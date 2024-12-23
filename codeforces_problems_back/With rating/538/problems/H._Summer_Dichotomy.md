<h1 style='text-align: center;'> H. Summer Dichotomy</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

*T* students applied into the ZPP class of Summer Irrelevant School. The organizing committee of the school may enroll any number of them, but at least *t* students must be enrolled. The enrolled students should be divided into two groups in any manner (it is possible that one of the groups will be empty!)

During a shift the students from the ZPP grade are tutored by *n* teachers. Due to the nature of the educational process, each of the teachers should be assigned to exactly one of two groups (it is possible that no teacher will be assigned to some of the groups!). The *i*-th teacher is willing to work in a group as long as the group will have at least *l**i* and at most *r**i* students (otherwise it would be either too boring or too hard). Besides, some pairs of the teachers don't like each other other and therefore can not work in the same group; in total there are *m* pairs of conflicting teachers.

You, as the head teacher of Summer Irrelevant School, have got a difficult task: to determine how many students to enroll in each of the groups and in which group each teacher will teach.

## Input

The first line contains two space-separated integers, *t* and *T* (1 ≤ *t* ≤ *T* ≤ 109).

The second line contains two space-separated integers *n* and *m* (1 ≤ *n* ≤ 105, 0 ≤ *m* ≤ 105).

The *i*-th of the next *n* lines contain integers *l**i* and *r**i* (0 ≤ *l**i* ≤ *r**i* ≤ 109).

The next *m* lines describe the pairs of conflicting teachers. Each of these lines contain two space-separated integers — the indices of teachers in the pair. The teachers are indexed starting from one. It is guaranteed that no teacher has a conflict with himself and no pair of conflicting teachers occurs in the list more than once.

## Output

If the distribution is possible, print in the first line a single word 'POSSIBLE' (without the quotes). In the second line print two space-separated integers *n*1 and *n*2 — the number of students in the first and second group, correspondingly, the contstraint *t* ≤ *n*1 + *n*2 ≤ *T* should be met. In the third line print *n* characters, the *i*-th of which should be 1 or 2, if the *i*-th teacher should be assigned to the first or second group, correspondingly. If there are multiple possible distributions of students and teachers in groups, you can print any of them.

If the sought distribution doesn't exist, print a single word 'IMPOSSIBLE' (without the quotes).

## Examples

## Input


```
10 20  
3 0  
3 6  
4 9  
16 25  

```
## Output


```
POSSIBLE  
4 16  
112  

```
## Input


```
1 10  
3 3  
0 10  
0 10  
0 10  
1 2  
1 3  
2 3  

```
## Output


```
IMPOSSIBLE  

```


#### tags 

#3200 #2-sat #data_structures #dfs_and_similar #greedy 