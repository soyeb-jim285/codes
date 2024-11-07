<h1 style='text-align: center;'> E. BCPC</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

BCPC stands for Byteforces Collegiate Programming Contest, and is the most famous competition in Byteforces.

BCPC is a team competition. Each team is composed by a coach and three contestants. Blenda is the coach of the Bit State University(BSU), and she is very strict selecting the members of her team.

 ![](images/c175f2b90ef7af2e933d24c35f9d0312c7e2b770.png) In BSU there are *n* students numbered from 1 to *n*. Since all BSU students are infinitely smart, the only important parameters for Blenda are their reading and writing speed. After a careful measuring, Blenda have found that the *i*-th student have a reading speed equal to *r**i* (words per minute), and a writing speed of *w**i* (symbols per minute). Since BSU students are very smart, the measured speeds are sometimes very big and Blenda have decided to subtract some constant value *c* from all the values of reading speed and some value *d* from all the values of writing speed. Therefore she considers *r**i*' = *r**i* - *c* and *w**i*' = *w**i* - *d*. 

The student *i* is said to overwhelm the student *j* if and only if *r**i*'·*w**j*' > *r**j*'·*w**i*'. Blenda doesn’t like fights in teams, so she thinks that a team consisting of three distinct students *i*, *j* and *k* is good if *i* overwhelms *j*, *j* overwhelms *k*, and *k* overwhelms *i*. Yes, the relation of overwhelming is not transitive as it often happens in real life.

Since Blenda is busy preparing a training camp in Codeforces, you are given a task to calculate the number of different good teams in BSU. Two teams are considered to be different if there is at least one student that is present in one team but is not present in the other. In other words, two teams are different if the sets of students that form these teams are different.

## Input

In the first line of the input three integers *n*, *c* and *d* (3 ≤ *n* ≤ 345678, 1 ≤ *c*, *d* ≤ 109) are written. They denote the number of students Blenda can use to form teams, the value subtracted from all reading speeds and the value subtracted from all writing speeds respectively.

Each of the next *n* lines contains two integers *r**i* and *w**i* (0 < *r**i*, *w**i* ≤ 109, |*r**i* - *c*| + |*w**i* - *d*| > 0). There are no two students, such that both their reading and writing speeds coincide, i.e. for every *i* ≠ *j* condition |*r**i* - *r**j*| + |*w**i* - *w**j*| > 0 holds.

## Output

Print the number of different teams in BSU, that are good according to Blenda's definition.

## Examples

## Input


```
5 2 2  
1 1  
4 1  
2 3  
3 2  
3 4  

```
## Output


```
4  

```
## Input


```
7 6 6  
3 2  
1 7  
5 7  
3 7  
6 4  
8 9  
8 5  

```
## Output


```
11  

```
## Note

In the first sample the following teams are good: (*i* = 1, *j* = 2, *k* = 3), (*i* = 2, *j* = 5, *k* = 1), (*i* = 1, *j* = 4, *k* = 3), (*i* = 5, *j* = 1, *k* = 4).

## Note

, that for example the team (*i* = 3, *j* = 1, *k* = 2) is also good, but is considered to be the same as the team (*i* = 1, *j* = 2, *k* = 3).



#### tags 

#2700 #binary_search #geometry #two_pointers 