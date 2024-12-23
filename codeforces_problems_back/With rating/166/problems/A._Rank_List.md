<h1 style='text-align: center;'> A. Rank List</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Another programming contest is over. You got hold of the contest's final results table. The table has the following data. For each team we are shown two numbers: the number of problems and the total penalty time. However, for no team we are shown its final place.

You know the rules of comparing the results of two given teams very well. Let's say that team *a* solved *p**a* problems with total penalty time *t**a* and team *b* solved *p**b* problems with total penalty time *t**b*. Team *a* gets a higher place than team *b* in the end, if it either solved more problems on the contest, or solved the same number of problems but in less total time. In other words, team *a* gets a higher place than team *b* in the final results' table if either *p**a* > *p**b*, or *p**a* = *p**b* and *t**a* < *t**b*. 

It is considered that the teams that solve the same number of problems with the same penalty time share all corresponding places. More formally, let's say there is a group of *x* teams that solved the same number of problems with the same penalty time. Let's also say that *y* teams performed better than the teams from this group. In this case all teams from the group share places *y* + 1, *y* + 2, ..., *y* + *x*. The teams that performed worse than the teams from this group, get their places in the results table starting from the *y* + *x* + 1-th place.

Your task is to count what number of teams from the given list shared the *k*-th place. 

## Input

The first line contains two integers *n* and *k* (1 ≤ *k* ≤ *n* ≤ 50). Then *n* lines contain the description of the teams: the *i*-th line contains two integers *p**i* and *t**i* (1 ≤ *p**i*, *t**i* ≤ 50) — the number of solved problems and the total penalty time of the *i*-th team, correspondingly. All numbers in the lines are separated by spaces. 

## Output

In the only line print the sought number of teams that got the *k*-th place in the final results' table.

## Examples

## Input


```
7 2  
4 10  
4 10  
4 10  
3 20  
2 1  
2 1  
1 10  

```
## Output


```
3  

```
## Input


```
5 4  
3 1  
3 1  
5 3  
3 1  
3 1  

```
## Output


```
4  

```
## Note

The final results' table for the first sample is: 

* 1-3 places — 4 solved problems, the penalty time equals 10
* 4 place — 3 solved problems, the penalty time equals 20
* 5-6 places — 2 solved problems, the penalty time equals 1
* 7 place — 1 solved problem, the penalty time equals 10

The table shows that the second place is shared by the teams that solved 4 problems with penalty time 10. There are 3 such teams.

The final table for the second sample is:

* 1 place — 5 solved problems, the penalty time equals 3
* 2-5 places — 3 solved problems, the penalty time equals 1

The table shows that the fourth place is shared by the teams that solved 3 problems with penalty time 1. There are 4 such teams.



#### tags 

#1100 #binary_search #implementation #sortings 