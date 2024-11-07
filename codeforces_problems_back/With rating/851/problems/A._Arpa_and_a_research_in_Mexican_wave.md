<h1 style='text-align: center;'> A. Arpa and a research in Mexican wave</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arpa is researching the Mexican wave.

There are *n* spectators in the stadium, labeled from 1 to *n*. They start the Mexican wave at time 0. 

* At time 1, the first spectator stands.
* At time 2, the second spectator stands.
* ...
* At time *k*, the *k*-th spectator stands.
* At time *k* + 1, the (*k* + 1)-th spectator stands and the first spectator sits.
* At time *k* + 2, the (*k* + 2)-th spectator stands and the second spectator sits.
* ...
* At time *n*, the *n*-th spectator stands and the (*n* - *k*)-th spectator sits.
* At time *n* + 1, the (*n* + 1 - *k*)-th spectator sits.
* ...
* At time *n* + *k*, the *n*-th spectator sits.

Arpa wants to know how many spectators are standing at time *t*.

## Input

The first line contains three integers *n*, *k*, *t* (1 ≤ *n* ≤ 109, 1 ≤ *k* ≤ *n*, 1 ≤ *t* < *n* + *k*).

## Output

Print single integer: how many spectators are standing at time *t*.

## Examples

## Input


```
10 5 3  

```
## Output


```
3  

```
## Input


```
10 5 7  

```
## Output


```
5  

```
## Input


```
10 5 12  

```
## Output


```
3  

```
## Note

In the following a sitting spectator is represented as -, a standing spectator is represented as ^.

* At *t* = 0  ---------- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 0.
* At *t* = 1  ^--------- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 1.
* At *t* = 2  ^^-------- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 2.
* At *t* = 3  ^^^------- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 3.
* At *t* = 4  ^^^^------ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 4.
* At *t* = 5  ^^^^^----- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 6  -^^^^^---- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 7  --^^^^^--- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 8  ---^^^^^-- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 9  ----^^^^^- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 10 -----^^^^^ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 5.
* At *t* = 11 ------^^^^ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 4.
* At *t* = 12 -------^^^ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 3.
* At *t* = 13 --------^^ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 2.
* At *t* = 14 ---------^ ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 1.
* At *t* = 15 ---------- ![](images/4d97e684117250a9afe9be022ab8a63653dd15aa.png) number of standing spectators = 0.


#### tags 

#800 #implementation #math 