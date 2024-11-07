<h1 style='text-align: center;'> F. Expected Earnings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a game with a bag of red and black balls. Initially, you are told that the bag has *n* balls total. In addition, you are also told that the bag has probability *p**i* / 106 of containing exactly *i* red balls.

You now would like to buy balls from this bag. You really like the color red, so red balls are worth a unit of 1, while black balls are worth nothing. To buy a ball, if there are still balls in the bag, you pay a cost *c* with 0 ≤ *c* ≤ 1, and draw a ball randomly from the bag. You can choose to stop buying at any point (and you can even choose to not buy anything at all).

Given that you buy optimally to maximize the expected profit (i.e. # red balls - cost needed to obtain them), print the maximum expected profit.

## Input

The first line of input will contain two integers *n*, *X* (1 ≤ *n* ≤ 10 000, 0 ≤ *X* ≤ 106).

The next line of input will contain *n* + 1 integers *p*0, *p*1, ... *p**n* (0 ≤ *p**i* ≤ 106, ![](images/6210c2461d50e5ce40c1d3fd9e1ec97646e407f6.png))

The value of *c* can be computed as ![](images/fcfdfb54ed7d543ab1428e780439cb4c068066a4.png).

## Output

Print a single floating point number representing the optimal expected value.

Your answer will be accepted if it has absolute or relative error at most 10- 9. More specifically, if your answer is *a* and the jury answer is *b*, your answer will be accepted if ![](images/c5e2d5f952bf0600d65151cbd23c801f49c2c594.png).

## Example

## Input


```
3 200000  
250000 250000 250000 250000  

```
## Output


```
0.9000000000  

```
## Note

Here, there is equal probability for the bag to contain 0,1,2,3 red balls. Also, it costs 0.2 to draw a ball from the bag.



#### tags 

#2800 