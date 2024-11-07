<h1 style='text-align: center;'> E. Final Countdown</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are in a nuclear laboratory that is about to explode and destroy the Earth. You must save the Earth before the final countdown reaches zero. 

The countdown consists of $n$ ($1 \le n \le 4 \cdot 10^5$) mechanical indicators, each showing one decimal digit. You noticed that when the countdown changes its state from $x$ to $x-1$, it doesn't happen in one move. Instead, each change of a single digit takes one second. 

So, for example, if the countdown shows 42, then it will change to 41 in one second, because only one digit is changed, but if the countdown shows 2300, then it will change to 2299 in three seconds, because the three last digits are changed.

Find out how much time is left before the countdown reaches zero.

## Input

The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1\le n\le 4\cdot 10^5$). 

The second line contains a string of $n$ digits, the current state of the countdown. It is guaranteed that at least one digit is not zero.

The sum of $n$ for all tests does not exceed $4\cdot 10^5$.

## Output

For each test case, print a single integer without leading zeroes, the number of seconds left before the countdown reaches zero. ## Note

 that this number may be huge.

## Example

## Input


```

52425123452994000527456480697259671309012631002
```
## Output


```

46
13715
108
5
507200774732968121125145546

```
## Note

In the first example, there are four changes that take 2 seconds: 40 to 39, 30 to 29, 20 to 19, and 10 to 09, other changes take 1 second each. So the total time is $2\cdot 4 + 1\cdot(42-4) = 46$.



#### tags 

#1600 #implementation #math #number_theory 