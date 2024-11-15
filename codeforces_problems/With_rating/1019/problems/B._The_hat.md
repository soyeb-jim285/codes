<h1 style='text-align: center;'> B. The hat</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Imur Ishakov decided to organize a club for people who love to play the famous game «The hat». The club was visited by *n* students, where *n* is even. Imur arranged them all in a circle and held a draw to break the students in pairs, but something went wrong. The participants are numbered so that participant *i* and participant *i* + 1 (1 ≤ *i* ≤ *n* - 1) are adjacent, as well as participant *n* and participant 1. Each student was given a piece of paper with a number in such a way, that for every two adjacent students, these numbers differ exactly by one. The plan was to form students with the same numbers in a pair, but it turned out that not all numbers appeared exactly twice.

As you know, the most convenient is to explain the words to the partner when he is sitting exactly across you. Students with numbers *i* and ![](images/bb70c692e73bcdcab618b5caa2269589ff959700.png) sit across each other. Imur is wondering if there are two people sitting across each other with the same numbers given. Help him to find such pair of people if it exists.

You can ask questions of form «which number was received by student *i*?», and the goal is to determine whether the desired pair exists in no more than 60 questions.

#### Input

At the beginning the even integer *n* (2 ≤ *n* ≤ 100 000) is given — the total number of students.

You are allowed to ask no more than 60 questions.

#### Output

To ask the question about the student *i* (1 ≤ *i* ≤ *n*), you should print «? *i*». Then from standard output you can read the number *a**i* received by student *i* ( - 109 ≤ *a**i* ≤ 109).

When you find the desired pair, you should print «! *i*», where *i* is any student who belongs to the pair (1 ≤ *i* ≤ *n*). If you determined that such pair doesn't exist, you should output «! -1». In both cases you should immediately terminate the program.

The query that contains your answer is not counted towards the limit of 60 queries.

Please make sure to flush the standard output after each command. For example, in C++ use function fflush(stdout), in Java call System.out.flush(), in Pascal use flush(output) and stdout.flush() for Python language.

Hacking

Use the following format for hacking:

In the first line, print one even integer *n* (2 ≤ *n* ≤ 100 000) — the total number of students.

In the second line print *n* integers *a**i* ( - 109 ≤ *a**i* ≤ 109) separated by spaces, where *a**i* is the number to give to *i*-th student. Any two adjacent elements, including *n* and 1, must differ by 1 or  - 1.

The hacked solution will not have direct access to the sequence *a**i*.

## Examples

#### Input


```text
8  
  
2  
  
2  

```
#### Output


```text
  
? 4  
  
? 8  
  
! 4  

```
#### Input


```text
6  
  
1  
  
2  
  
3   
  
2  
  
1  
  
0
```
#### Output


```text
  
? 1  
  
? 2  
  
? 3  
  
? 4  
  
? 5  
  
? 6  
  
! -1
```
## Note

#### Input

-output in statements illustrates example interaction.

In the first sample the selected sequence is 1, 2, 1, 2, 3, 4, 3, 2

In the second sample the selection sequence is 1, 2, 3, 2, 1, 0.



#### Tags 

#2000 #NOT OK #binary_search #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_503_(by_SIS,_Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
