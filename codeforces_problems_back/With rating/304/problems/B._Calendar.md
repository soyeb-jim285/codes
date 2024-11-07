<h1 style='text-align: center;'> B. Calendar</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Calendars in widespread use today include the Gregorian calendar, which is the de facto international standard, and is used almost everywhere in the world for civil purposes. The Gregorian reform modified the Julian calendar's scheme of leap years as follows:

 Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100; the centurial years that are exactly divisible by 400 are still leap years. For example, the year 1900 is not a leap year; the year 2000 is a leap year. 

 ![](images/a85d337a1f028a3432db399b9b226673dbe39328.png) In this problem, you have been given two dates and your task is to calculate how many days are between them. Note, that leap years have unusual number of days in February.

Look at the sample to understand what borders are included in the aswer.

## Input

The first two lines contain two dates, each date is in the format yyyy:mm:dd (1900 ≤ *yyyy* ≤ 2038 and yyyy:mm:dd is a legal date).

## Output

Print a single integer — the answer to the problem.

## Examples

## Input


```
1900:01:01  
2038:12:31  

```
## Output


```
50768  

```
## Input


```
1996:03:09  
1991:11:12  

```
## Output


```
1579  

```


#### tags 

#1300 #brute_force #implementation 