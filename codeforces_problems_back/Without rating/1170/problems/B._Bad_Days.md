<h1 style='text-align: center;'> B. Bad Days</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Every day Kotlin heroes analyze the statistics of their website. For $n$ days, they wrote out $n$ numbers $a_1, a_2, \dots, a_n$, where $a_i$ is the number of visits on the $i$-th day.

They believe that a day is bad if there are at least $2$ days before it with a strictly greater number of visits. For example, if $n=8$ and $a=[3, 1, 4, 1, 5, 9, 2, 6]$, then the day $4$ is bad (because $a_4=1$, but there are $a_1=3$ and $a_3=4$). Also, the day with the number $7$ is bad too.

Write a program that finds the number of bad days.

## Input

The first line contains an integer $n$ ($1 \le n \le 2\cdot10^5$), where $n$ is the number of days. The second line contains $n$ positive integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the number of website visits on the $i$-th day.

## Output

Print the number of bad days, i.e. such days that there are at least two days before it with a strictly greater number of visits.

## Examples

## Input


```

8
3 1 4 1 5 9 2 6

```
## Output


```

2

```
## Input


```

5
1 1 1 1 1

```
## Output


```

0

```
## Input


```

13
2 7 1 8 2 8 1 8 2 8 4 5 9

```
## Output


```

6

```


#### tags 

#*special #implementation 