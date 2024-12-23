<h1 style='text-align: center;'> J. Date calculation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

In Gregorian calendar a typical year consists of 365 days and 12 months. The numbers of days in the months are: 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31. If year index is divisible by 400, or divisible by 4 but not by 100, the year becomes leap year, with one extra day in the second month (the one which typically has 28 days).

You are given the index of the year and the index of the day in the year. Find out the date of this day (day and month it will fall upon).

## Input

The first line of input contains the year index, between 1600 and 2400, inclusive. The second line contains the day index, between 1 and 366, inclusive. It is guaranteed that the day index will be valid for this year, i.e., day 366 will occur only in a leap year.

## Output

## Output

 the index of the day and the index of the month, separated with a space.

## Examples

## Input


```
2011  
324  

```
## Output


```
20 11  

```
## Input


```
2012  
274  

```
## Output


```
30 9  

```
## Note

All indexes are 1-based.



#### tags 

#1800 #*special 