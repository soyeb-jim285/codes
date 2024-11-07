<h1 style='text-align: center;'> A. Equator</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has created his own training plan to prepare for the programming contests. He will train for $n$ days, all days are numbered from $1$ to $n$, beginning from the first.

On the $i$-th day Polycarp will necessarily solve $a_i$ problems. One evening Polycarp plans to celebrate the equator. He will celebrate it on the first evening of such a day that from the beginning of the training and to this day inclusive he will solve half or more of all the problems.

Determine the index of day when Polycarp will celebrate the equator.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 200\,000$) — the number of days to prepare for the programming contests.

The second line contains a sequence $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10\,000$), where $a_i$ equals to the number of problems, which Polycarp will solve on the $i$-th day.

#### Output

Print the index of the day when Polycarp will celebrate the equator.

## Examples

#### Input


```text
4  
1 3 2 1  

```
#### Output


```text
2  

```
#### Input


```text
6  
2 2 2 2 2 2  

```
#### Output


```text
3  

```
## Note

In the first example Polycarp will celebrate the equator on the evening of the second day, because up to this day (inclusive) he will solve $4$ out of $7$ scheduled problems on four days of the training.

In the second example Polycarp will celebrate the equator on the evening of the third day, because up to this day (inclusive) he will solve $6$ out of $12$ scheduled problems on six days of the training.



#### Tags 

#1300 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_42_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Разбор задач](../blogs/Разбор_задач.md)
