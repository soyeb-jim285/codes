<h1 style='text-align: center;'> B. Inna, Dima and Song</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Inna is a great piano player and Dima is a modest guitar player. Dima has recently written a song and they want to play it together. Of course, Sereja wants to listen to the song very much. 

A song is a sequence of notes. Dima and Inna want to play each note at the same time. At that, they can play the *i*-th note at volume *v* (1 ≤ *v* ≤ *a**i*; *v* is an integer) both on the piano and the guitar. They should retain harmony, so the total volume with which the *i*-th note was played on the guitar and the piano must equal *b**i*. If Dima and Inna cannot play a note by the described rules, they skip it and Sereja's joy drops by 1. But if Inna and Dima play the *i*-th note at volumes *x**i* and *y**i* (*x**i* + *y**i* = *b**i*) correspondingly, Sereja's joy rises by *x**i*·*y**i*. 

Sereja has just returned home from the university and his current joy is 0. Help Dima and Inna play the song so as to maximize Sereja's total joy after listening to the whole song!

## Input

The first line of the input contains integer *n* (1 ≤ *n* ≤ 105) — the number of notes in the song. The second line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 106). The third line contains *n* integers *b**i* (1 ≤ *b**i* ≤ 106).

## Output

In a single line print an integer — the maximum possible joy Sereja feels after he listens to a song.

## Examples

## Input


```
3  
1 1 2  
2 2 3  

```
## Output


```
4  

```
## Input


```
1  
2  
5  

```
## Output


```
-1  

```
## Note

In the first sample, Dima and Inna play the first two notes at volume 1 (1 + 1 = 2, the condition holds), they should play the last note at volumes 1 and 2. Sereja's total joy equals: 1·1 + 1·1 + 1·2 = 4.

In the second sample, there is no such pair (*x*, *y*), that 1 ≤ *x*, *y* ≤ 2, *x* + *y* = 5, so Dima and Inna skip a note. Sereja's total joy equals -1.



#### tags 

#implementation 