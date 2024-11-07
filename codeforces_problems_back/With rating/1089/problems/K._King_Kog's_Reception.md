<h1 style='text-align: center;'> K. King Kog's Reception</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

King Kog got annoyed of the usual laxity of his knights — they can break into his hall without prior notice! Thus, the King decided to build a reception with a queue where each knight chooses in advance the time when he will come and how long the visit will take. The knights are served in the order of the recorded time, but each knight has to wait until the visits of all the knights before him are finished.

Princess Keabeanie wants to see her father. However, she does not want to interrupt the knights so she joins the queue. Unfortunately, the knights change their minds very often — they can join the queue or cancel their visits. Please help the princess to understand how long she will have to wait until she sees her father if she enters the queue at the specified moments of time given the records at the reception.

## Input

The first line of the input contains a single integer $q$ ($1 \leq q \leq 3 \cdot 10^5$) — the number of events. An event can be of three types: join, cancel, or query.

* Join "+ $t$ $d$" ($1 \leq t, d \leq 10^6$) — a new knight joins the queue, where $t$ is the time when the knight will come and $d$ is the duration of the visit.
* Cancel "- $i$" ($1 \leq i \leq q$) — the knight cancels the visit, where $i$ is the number (counted starting from one) of the corresponding join event in the list of all events.
* Query "? $t$" ($1 \leq t \leq 10^6$) — Keabeanie asks how long she will wait if she comes at the time $t$.

It is guaranteed that after each event there are no two knights with the same entrance time in the queue. Cancel events refer to the previous joins that were not cancelled yet.

Keabeanie can come at the same time as some knight, but Keabeanie is very polite and she will wait for the knight to pass.

## Output

For each query write a separate line with the amount of time Keabeanie will have to wait.

## Example

## Input


```

19
? 3
+ 2 2
? 3
? 4
+ 5 2
? 5
? 6
+ 1 2
? 2
? 3
? 4
? 5
? 6
? 7
? 9
- 8
? 2
? 3
? 6

```
## Output


```

0
1
0
2
1
3
2
1
2
1
0
0
2
1
1

```


#### tags 

#2400 #data_structures 