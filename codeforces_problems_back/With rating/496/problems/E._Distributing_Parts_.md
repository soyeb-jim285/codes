<h1 style='text-align: center;'> E. Distributing Parts </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are an assistant director in a new musical play. The play consists of *n* musical parts, each part must be performed by exactly one actor. After the casting the director chose *m* actors who can take part in the play. Your task is to assign the parts to actors. However, there are several limitations.

First, each actor has a certain voice range and there are some parts that he cannot sing. Formally, there are two integers for each actor, *c**i* and *d**i* (*c**i* ≤ *d**i*) — the pitch of the lowest and the highest note that the actor can sing. There also are two integers for each part — *a**j* and *b**j* (*a**j* ≤ *b**j*) — the pitch of the lowest and the highest notes that are present in the part. The *i*-th actor can perform the *j*-th part if and only if *c**i* ≤ *a**j* ≤ *b**j* ≤ *d**i*, i.e. each note of the part is in the actor's voice range.

According to the contract, the *i*-th actor can perform at most *k**i* parts. Besides, you are allowed not to give any part to some actors (then they take part in crowd scenes).

The rehearsal starts in two hours and you need to do the assignment quickly!

## Input

The first line contains a single integer *n* — the number of parts in the play (1 ≤ *n* ≤ 105).

Next *n* lines contain two space-separated integers each, *a**j* and *b**j* — the range of notes for the *j*-th part (1 ≤ *a**j* ≤ *b**j* ≤ 109).

The next line contains a single integer *m* — the number of actors (1 ≤ *m* ≤ 105).

Next *m* lines contain three space-separated integers each, *c**i*, *d**i* and *k**i* — the range of the *i*-th actor and the number of parts that he can perform (1 ≤ *c**i* ≤ *d**i* ≤ 109, 1 ≤ *k**i* ≤ 109).

## Output

If there is an assignment that meets all the criteria aboce, print a single word "YES" (without the quotes) in the first line.

In the next line print *n* space-separated integers. The *i*-th integer should be the number of the actor who should perform the *i*-th part. If there are multiple correct assignments, print any of them.

If there is no correct assignment, print a single word "NO" (without the quotes).

## Examples

## Input


```
3  
1 3  
2 4  
3 5  
2  
1 4 2  
2 5 1  

```
## Output


```
YES  
1 1 2  

```
## Input


```
3  
1 3  
2 4  
3 5  
2  
1 3 2  
2 5 1  

```
## Output


```
NO  

```


#### tags 

#2100 #greedy #sortings 