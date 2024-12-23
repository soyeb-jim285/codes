<h1 style='text-align: center;'> A. Power Consumption Calculation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tom is interested in power consumption of his favourite laptop. His laptop has three modes. In normal mode laptop consumes *P*1 watt per minute. *T*1 minutes after Tom moved the mouse or touched the keyboard for the last time, a screensaver starts and power consumption changes to *P*2 watt per minute. Finally, after *T*2 minutes from the start of the screensaver, laptop switches to the "sleep" mode and consumes *P*3 watt per minute. If Tom moves the mouse or touches the keyboard when the laptop is in the second or in the third mode, it switches to the first (normal) mode. Tom's work with the laptop can be divided into *n* time periods [*l*1, *r*1], [*l*2, *r*2], ..., [*l**n*, *r**n*]. During each interval Tom continuously moves the mouse and presses buttons on the keyboard. Between the periods Tom stays away from the laptop. Find out the total amount of power consumed by the laptop during the period [*l*1, *r**n*].

## Input

The first line contains 6 integer numbers *n*, *P*1, *P*2, *P*3, *T*1, *T*2 (1 ≤ *n* ≤ 100, 0 ≤ *P*1, *P*2, *P*3 ≤ 100, 1 ≤ *T*1, *T*2 ≤ 60). The following *n* lines contain description of Tom's work. Each *i*-th of these lines contains two space-separated integers *l**i* and *r**i* (0 ≤ *l**i* < *r**i* ≤ 1440, *r**i* < *l**i* + 1 for *i* < *n*), which stand for the start and the end of the *i*-th period of work.

## Output

## Output

 the answer to the problem.

## Examples

## Input


```
1 3 2 1 5 10  
0 10  

```
## Output


```
30
```
## Input


```
2 8 4 2 5 10  
20 30  
50 100  

```
## Output


```
570
```


#### tags 

#900 #implementation 