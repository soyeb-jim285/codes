<h1 style='text-align: center;'> C. Elections</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are running for a governor in a small city in Russia. You ran some polls and did some research, and for every person in the city you know whom he will vote for, and how much it will cost to bribe that person to vote for you instead of whomever he wants to vote for right now. You are curious, what is the smallest amount of money you need to spend on bribing to win the elections. To win elections you need to have strictly more votes than any other candidate.

## Input

First line contains one integer *n* (1 ≤ *n* ≤ 105) — number of voters in the city. Each of the next *n* lines describes one voter and contains two integers *a**i* and *b**i* (0 ≤ *a**i* ≤ 105; 0 ≤ *b**i* ≤ 104) — number of the candidate that voter is going to vote for and amount of money you need to pay him to change his mind. You are the candidate 0 (so if a voter wants to vote for you, *a**i* is equal to zero, in which case *b**i* will also be equal to zero).

## Output

Print one integer — smallest amount of money you need to spend to win the elections.

## Examples

## Input


```
5  
1 2  
1 2  
1 2  
2 1  
0 0  

```
## Output


```
3  

```
## Input


```
4  
1 2  
1 2  
2 1  
0 0  

```
## Output


```
2  

```
## Input


```
1  
100000 0  

```
## Output


```
0  

```


#### tags 

#2100 #brute_force 