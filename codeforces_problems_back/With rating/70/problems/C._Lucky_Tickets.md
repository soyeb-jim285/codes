<h1 style='text-align: center;'> C. Lucky Tickets</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Walrusland public transport tickets are characterized by two integers: by the number of the series and by the number of the ticket in the series. Let the series number be represented by *a* and the ticket number — by *b*, then a ticket is described by the ordered pair of numbers (*a*, *b*). 

The walruses believe that a ticket is lucky if *a* * *b* = *rev*(*a*) * *rev*(*b*). The function *rev*(*x*) reverses a number written in the decimal system, at that the leading zeroes disappear. For example, *rev*(12343) = 34321, *rev*(1200) = 21.

The Public Transport Management Committee wants to release *x* series, each containing *y* tickets, so that at least *w* lucky tickets were released and the total number of released tickets (*x* * *y*) were minimum. The series are numbered from 1 to *x* inclusive. The tickets in each series are numbered from 1 to *y* inclusive. The Transport Committee cannot release more than *max**x* series and more than *max**y* tickets in one series.

## Input

The first line contains three integers *max**x*, *max**y*, *w* (1 ≤ *max**x*, *max**y* ≤ 105, 1 ≤ *w* ≤ 107).

## Output

Print on a single line two space-separated numbers, the *x* and the *y*. If there are several possible variants, print any of them. If such *x* and *y* do not exist, print a single number  - 1.

## Examples

## Input


```
2 2 1  

```
## Output


```
1 1
```
## Input


```
132 10 35  

```
## Output


```
7 5
```
## Input


```
5 18 1000  

```
## Output


```
-1  

```
## Input


```
48 132 235  

```
## Output


```
22 111
```


#### tags 

#2200 #binary_search #data_structures #sortings #two_pointers 