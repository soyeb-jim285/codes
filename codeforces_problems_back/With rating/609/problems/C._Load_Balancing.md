<h1 style='text-align: center;'> C. Load Balancing</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the school computer room there are *n* servers which are responsible for processing several computing tasks. You know the number of scheduled tasks for each server: there are *m**i* tasks assigned to the *i*-th server.

In order to balance the load for each server, you want to reassign some tasks to make the difference between the most loaded server and the least loaded server as small as possible. In other words you want to minimize expression *m**a* - *m**b*, where *a* is the most loaded server and *b* is the least loaded one.

In one second you can reassign a single task. Thus in one second you can choose any pair of servers and move a single task from one server to another.

Write a program to find the minimum number of seconds needed to balance the load of servers.

## Input

The first line contains positive number *n* (1 ≤ *n* ≤ 105) — the number of the servers. 

The second line contains the sequence of non-negative integers *m*1, *m*2, ..., *m**n* (0 ≤ *m**i* ≤ 2·104), where *m**i* is the number of tasks assigned to the *i*-th server.

## Output

Print the minimum number of seconds required to balance the load.

## Examples

## Input


```
2  
1 6  

```
## Output


```
2  

```
## Input


```
7  
10 11 10 11 10 11 11  

```
## Output


```
0  

```
## Input


```
5  
1 2 3 4 5  

```
## Output


```
3  

```
## Note

In the first example two seconds are needed. In each second, a single task from server #2 should be moved to server #1. After two seconds there should be 3 tasks on server #1 and 4 tasks on server #2.

In the second example the load is already balanced.

A possible sequence of task movements for the third example is:

1. move a task from server #4 to server #1 (the sequence *m* becomes: 2 2 3 3 5);
2. then move task from server #5 to server #1 (the sequence *m* becomes: 3 2 3 3 4);
3. then move task from server #5 to server #2 (the sequence *m* becomes: 3 3 3 3 3).

The above sequence is one of several possible ways to balance the load of servers in three seconds.



#### tags 

#1500 #implementation #math 