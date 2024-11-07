<h1 style='text-align: center;'> A. Uncowed Forces</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kevin Sun has just finished competing in Codeforces Round #334! The round was 120 minutes long and featured five problems with maximum point values of 500, 1000, 1500, 2000, and 2500, respectively. Despite the challenging tasks, Kevin was uncowed and bulldozed through all of them, distinguishing himself from the herd as the best cowmputer scientist in all of Bovinia. Kevin knows his submission time for each problem, the number of wrong submissions that he made on each problem, and his total numbers of successful and unsuccessful hacks. Because Codeforces scoring is complicated, Kevin wants you to write a program to compute his final score.

Codeforces scores are computed as follows: If the maximum point value of a problem is *x*, and Kevin submitted correctly at minute *m* but made *w* wrong submissions, then his score on that problem is ![](images/3f09e285d608f9145474d19a6be3d314d100341d.png). His total score is equal to the sum of his scores for each problem. In addition, Kevin's total score gets increased by 100 points for each successful hack, but gets decreased by 50 points for each unsuccessful hack.

All arithmetic operations are performed with absolute precision and no rounding. It is guaranteed that Kevin's final score is an integer.

## Input

The first line of the input contains five space-separated integers *m*1, *m*2, *m*3, *m*4, *m*5, where *m**i* (0 ≤ *m**i* ≤ 119) is the time of Kevin's last submission for problem *i*. His last submission is always correct and gets accepted.

The second line contains five space-separated integers *w*1, *w*2, *w*3, *w*4, *w*5, where *w**i* (0 ≤ *w**i* ≤ 10) is Kevin's number of wrong submissions on problem *i*.

The last line contains two space-separated integers *h**s* and *h**u* (0 ≤ *h**s*, *h**u* ≤ 20), denoting the Kevin's numbers of successful and unsuccessful hacks, respectively.

## Output

Print a single integer, the value of Kevin's final score.

## Examples

## Input


```
20 40 60 80 100  
0 1 2 3 4  
1 0  

```
## Output


```
4900  

```
## Input


```
119 119 119 119 119  
0 0 0 0 0  
10 0  

```
## Output


```
4930  

```
## Note

In the second sample, Kevin takes 119 minutes on all of the problems. Therefore, he gets ![](images/42158dc2bc78cd21fa679530ae9ef8b9ea298d15.png) of the points on each problem. So his score from solving problems is ![](images/fdf392d8508500b57f8057ac0c4c892ab5f925a2.png). Adding in 10·100 = 1000 points from hacks, his total score becomes 3930 + 1000 = 4930.



#### tags 

#1000 #implementation 