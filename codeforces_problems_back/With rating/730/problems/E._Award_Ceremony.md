<h1 style='text-align: center;'> E. Award Ceremony</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

All-Berland programming contest comes to an end. In total, *n* teams participated in it. Like in ACM-ICPC, current results stopped refreshing one hour before the contest ends. So at the Award Ceremony, results are partially known. For each team the value *a**i* is given — the number of points the *i*-th team has earned before the last hour of the contest. Besides that, the Jury has evaluated all submissions sent during the last hour and knows values *d**i* — the number of points earned by the *i*-th team during the last hour (these values can be negative, which means that a team can lose points).

Before the contest, each team got unique id from 1 to *n*. According to the contest rules, a team with more points takes a higher place. If two or more teams have equal number of points, the team with lower id will take the higher place. So no two teams can share the same place.

The Award Ceremony proceeds in the following way. At the beginning of the ceremony, a large screen shows the results for the time moment "one hour before the end", which means that the *i*-th team has *a**i* points. Then the Jury unfreezes results of the teams one by one in some order. When result of the *j*-th team is unfrozen, its score changes from *a**j* to *a**j* + *d**j*. At this time the table of results is modified and the place of the team can change. The unfreezing of the *j*-th team is followed by the applause from the audience with duration of |*x**j* - *y**j*| seconds, where *x**j* is the place of the *j*-th team before unfreezing and *y**j* is the place right after the unfreezing. For example, if the team does not change the place, there is no applause from the audience. As you can see, during the Award Ceremony, each team will be unfrozen exactly once.

Your task is to find such an order to unfreeze all the teams that the total duration of applause is maximum possible.

## Input

The first line of the input file contains a single integer *n* (1 ≤ *n* ≤ 100) — the number of teams.

Each of the next *n* lines contains two integers *a**i* and *d**i* (1 ≤ *a**i* ≤ 100,  - 100 ≤ *d**i* ≤ 100) — the number of points the *i*-th team has earned before the last hour of the contest and the number of points earned by this team during the last hour. It is possible that after unfreezing a team will have a negative score.

## Output

Print the only integer — maximal total applause duration in seconds if the Jury can choose any order of the teams to unfreeze.

## Examples

## Input


```
4  
17 -14  
52 -5  
1 52  
6 0  

```
## Output


```
4  

```
## Input


```
5  
4 5  
3 2  
5 -3  
6 -2  
4 3  

```
## Output


```
14  

```
## Note

In the first example the initial standings are:

1. Team 2, 52 points
2. Team 1, 17 points
3. Team 4, 6 points
4. Team 3, 1 point

Here any order of unfreezing the teams leads to 4 seconds of applause in total. For example, let's unfreeze teams in their order from the Team 1 to the Team 4.

After the Team 1 became unfrozen the standings are:

1. Team 2, 52 points
2. Team 4, 6 points
3. Team 1, 3 points
4. Team 3, 1 point

So there is 1 second of applause, because the difference between old and new places |2 - 3| = 1.

After the Team 2 became unfrozen the standings are:

1. Team 2, 47 points
2. Team 4, 6 points
3. Team 1, 3 points
4. Team 3, 1 point

The place of the Team 2 has not changed, so no applause during unfreezing.

After the Team 3 became unfrozen the standings are:

1. Team 3, 53 point
2. Team 2, 47 points
3. Team 4, 6 points
4. Team 1, 3 points

The place of the Team 3 has changed from 4 to 1, so the duration of applause is |4 - 1| = 3.

The unfreezing of the Team 4 has not changed any place because *d*4 = 0.

Therefore, the total duration of applause is 1 + 0 + 3 + 0 = 4 seconds.



#### tags 

#2200 #greedy #implementation 