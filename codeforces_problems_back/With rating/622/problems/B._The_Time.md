<h1 style='text-align: center;'> B. The Time</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given the current time in 24-hour format hh:mm. Find and print the time after *a* minutes.

Note that you should find only the time after *a* minutes, see the examples to clarify the problem statement.

You can read more about 24-hour format here [https://en.wikipedia.org/wiki/24-hour_clock](https://en.wikipedia.org/wiki/24-hour_clock).

## Input

The first line contains the current time in the format hh:mm (0 ≤ *hh* < 24, 0 ≤ *mm* < 60). The hours and the minutes are given with two digits (the hours or the minutes less than 10 are given with the leading zeroes).

The second line contains integer *a* (0 ≤ *a* ≤ 104) — the number of the minutes passed.

## Output

The only line should contain the time after *a* minutes in the format described in the input. Note that you should print exactly two digits for the hours and the minutes (add leading zeroes to the numbers if needed).

See the examples to check the input/output format.

## Examples

## Input


```
23:59  
10  

```
## Output


```
00:09  

```
## Input


```
20:20  
121  

```
## Output


```
22:21  

```
## Input


```
10:10  
0  

```
## Output


```
10:10  

```


#### tags 

#900 #implementation 