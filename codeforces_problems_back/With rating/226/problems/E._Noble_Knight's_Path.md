<h1 style='text-align: center;'> E. Noble Knight's Path</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Berland each feudal owns exactly one castle and each castle belongs to exactly one feudal.

Each feudal, except one (the King) is subordinate to another feudal. A feudal can have any number of vassals (subordinates).

Some castles are connected by roads, it is allowed to move along the roads in both ways. Two castles have a road between them if and only if the owner of one of these castles is a direct subordinate to the other owner.

Each year exactly one of these two events may happen in Berland.

1. The barbarians attacked castle *c*. The interesting fact is, the barbarians never attacked the same castle twice throughout the whole Berlandian history.
2. A noble knight sets off on a journey from castle *a* to castle *b* (provided that on his path he encounters each castle not more than once).

Let's consider the second event in detail. As the journey from *a* to *b* is not short, then the knight might want to stop at a castle he encounters on his way to have some rest. However, he can't stop at just any castle: his nobility doesn't let him stay in the castle that has been desecrated by the enemy's stench. A castle is desecrated if and only if it has been attacked after the year of *y*. So, the knight chooses the *k*-th castle he encounters, starting from *a* (castles *a* and *b* aren't taken into consideration), that hasn't been attacked in years from *y* + 1 till current year.

The knights don't remember which castles were attacked on what years, so he asked the court scholar, aka you to help them. You've got a sequence of events in the Berland history. Tell each knight, in what city he should stop or else deliver the sad news — that the path from city *a* to city *b* has less than *k* cities that meet his requirements, so the knight won't be able to rest.

## Input

The first input line contains integer *n* (2 ≤ *n* ≤ 105) — the number of feudals. 

The next line contains *n* space-separated integers: the *i*-th integer shows either the number of the *i*-th feudal's master, or a 0, if the *i*-th feudal is the King. 

The third line contains integer *m* (1 ≤ *m* ≤ 105) — the number of queries.

Then follow *m* lines that describe the events. The *i*-th line (the lines are indexed starting from 1) contains the description of the event that occurred in year *i*. Each event is characterised by type *t**i* (1 ≤ *t**i* ≤ 2). The description of the first type event looks as two space-separated integers *t**i* *c**i* (*t**i* = 1; 1 ≤ *c**i* ≤ *n*), where *c**i* is the number of the castle that was attacked by the barbarians in the *i*-th year. The description of the second type contains five space-separated integers: *t**i* *a**i* *b**i* *k**i* *y**i* (*t**i* = 2; 1 ≤ *a**i*, *b**i*, *k**i* ≤ *n*; *a**i* ≠ *b**i*; 0 ≤ *y**i* < *i*), where *a**i* is the number of the castle from which the knight is setting off, *b**i* is the number of the castle to which the knight is going, *k**i* and *y**i* are the *k* and *y* from the second event's description.

You can consider the feudals indexed from 1 to *n*. It is guaranteed that there is only one king among the feudals. It is guaranteed that for the first type events all values *c**i* are different.

## Output

For each second type event print an integer — the number of the castle where the knight must stay to rest, or -1, if he will have to cover the distance from *a**i* to *b**i* without a rest. Separate the answers by whitespaces.

Print the answers in the order, in which the second type events are given in the input.

## Examples

## Input


```
3  
0 1 2  
5  
2 1 3 1 0  
1 2  
2 1 3 1 0  
2 1 3 1 1  
2 1 3 1 2  

```
## Output


```
2  
-1  
-1  
2  

```
## Input


```
6  
2 5 2 2 0 5  
3  
2 1 6 2 0  
1 2  
2 4 5 1 0  

```
## Output


```
5  
-1  

```
## Note

In the first sample there is only castle 2 on the knight's way from castle 1 to castle 3. When the knight covers the path 1 - 3 for the first time, castle 2 won't be desecrated by an enemy and the knight will stay there. In the second year the castle 2 will become desecrated, so the knight won't have anywhere to stay for the next two years (as finding a castle that hasn't been desecrated from years 1 and 2, correspondingly, is important for him). In the fifth year the knight won't consider the castle 2 desecrated, so he will stay there again.



#### tags 

#2900 #data_structures #trees 