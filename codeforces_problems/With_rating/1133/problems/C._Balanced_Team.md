<h1 style='text-align: center;'> C. Balanced Team</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are a coach at your local university. There are $n$ students under your supervision, the programming skill of the $i$-th student is $a_i$.

You have to create a team for a new programming competition. As you know, the more students some team has the more probable its victory is! So you have to create a team with the maximum number of students. But you also know that a team should be balanced. It means that the programming skill of each pair of students in a created team should differ by no more than $5$.

Your task is to report the maximum possible number of students in a balanced team.

##### Input

The first line of the input contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of students.

The second line of the input contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is a programming skill of the $i$-th student.

##### Output

Print one integer — the maximum possible number of students in a balanced team.

## Examples

##### Input


```text
6
1 10 17 12 15 2
```
##### Output


```text
3
```
##### Input


```text
10
1337 1337 1337 1337 1337 1337 1337 1337 1337 1337
```
##### Output


```text
10
```
##### Input


```text
6
1 1000 10000 10 100 1000000000
```
##### Output


```text
1
```
## Note

In the first example you can create a team with skills $[12, 17, 15]$.

In the second example you can take all students in a team because their programming skills are equal.

In the third example you can create a team consisting of a single student (and you cannot create a team consisting of at least two students).



#### Tags 

#1200 #NOT OK #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_544_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
