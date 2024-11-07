<h1 style='text-align: center;'> F. Conference</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You have been asked to organize a very important art conference. The first step is to choose the dates.

The conference must last for a certain number of consecutive days. Each day, one lecturer must perform, and the same lecturer cannot perform more than once.

You asked $n$ potential lecturers if they could participate in the conference. Lecturer $i$ indicated that they could perform on any day from $l_i$ to $r_i$ inclusive.

A certain segment of days can be chosen as the conference dates if there is a way to assign an available lecturer to each day of the segment, assigning each lecturer to no more than one day.

For each $k$ from $1$ to $n$, find how many ways there are to choose a segment of $k$ consecutive days as the conference dates.

## Input

The first line of input contains one integer $n$ — the number of potential lecturers ($1 \le n \le 2 \cdot 10^5$).

Each of the next $n$ lines contains two integers $l_i$ and $r_i$ — the segment of available days for the $i$th lecturer ($1 \le l_i \le r_i \le 2 \cdot 10^5$).

## Output

Print $n$ integers, where the $k$th number denotes the number of ways to select a segment of $k$ consecutive days as conference dates.

## Examples

## Input


```

31 23 45 6
```
## Output


```

6
2
0

```
## Input


```

51 31 31 31 31 3
```
## Output


```

3
2
1
0
0

```
## Note

In the first testcase, a one-day conference can be organized on any of the days from $1$ to $6$. A two-day conference can be organized from day $2$ to day $3$, as well as from day $4$ to day $5$.

In the second testcase, five lecturers can perform only from day $1$ to day $3$, so it will not be possible to organize a conference longer than three days.



#### tags 

#3300 #data_structures #flows 