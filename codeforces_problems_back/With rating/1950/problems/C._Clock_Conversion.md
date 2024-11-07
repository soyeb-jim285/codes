<h1 style='text-align: center;'> C. Clock Conversion</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given the time in 24-hour format, output the equivalent time in 12-hour format. 

* [24-hour format](https://en.wikipedia.org/wiki/24-hour_clock#Description) divides the day into 24 hours from $00$ to $23$, each of which has 60 minutes from $00$ to $59$.
* [12-hour format](https://en.wikipedia.org/wiki/12-hour_clock#Description) divides the day into two halves: the first half is $\mathrm{AM}$, and the second half is $\mathrm{PM}$. In each half, the hours are numbered in the order $12, 01, 02, 03, \dots, 11$. Each hour has 60 minutes numbered from $00$ to $59$.
## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1440$) — the number of test cases.

The only line of each test case contains a string $s$ of length $5$ with format hh:mm representing a valid time in the 24-hour format. hh represents the hour from $00$ to $23$, and mm represents the minute from $00$ to $59$.

The input will always be a valid time in 24-hour format.

## Output

For each test case, output two strings separated by a space ("hh:mm AM" or "hh:mm PM"), which are the 12-hour equivalent to the time provided in the test case (without quotes).

You should output the time exactly as indicated; in particular, you should not remove leading zeroes.

## Example

## Input


```

1109:4118:0612:1400:5900:0014:3401:0119:0711:5912:0021:37
```
## Output


```

09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM

```


#### tags 

#800 #implementation #math 