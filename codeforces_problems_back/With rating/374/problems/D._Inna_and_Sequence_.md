<h1 style='text-align: center;'> D. Inna and Sequence </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dima's spent much time thinking what present to give to Inna and gave her an empty sequence *w*. Now they want to fill sequence *w* with numbers zero and one. For that, they decided to play an amusing game. 

Before the game begins, Dima chooses *m* integers *a*1, *a*2, ..., *a**m* (1 ≤ *a*1 < *a*2 < ... < *a**m*). Then Inna and Dima start playing, that is, adding numbers to sequence *w*. Each new number they choose is added to the end of the sequence. At some moments of time Dima feels that the game is going to end too soon (and he wants to play with Inna as long as possible), so he hits a table hard with his fist. At that the *a*1-th, *a*2-th, *a*3-th, ..., *a**k*-th numbers from the beginning simultaneously fall out of the sequence (the sequence gets *k* numbers less). Here *k* is such maximum number that value *a**k* doesn't exceed the current length of the sequence. If number *a*1 is larger than the current length of *w*, then nothing falls out of the sequence.

You are given the chronological sequence of events in the game. Each event is either adding a number to the end of sequence *w* or Dima's hit on the table. Calculate the sequence *w* after all these events happen.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 106) showing how many events took place and how many numbers Dima chose.

The next line contains *m* distinct integers *a**i* (1 ≤ *a**i* ≤ 106) sorted in the increasing order. 

Next *n* lines describe the events in the chronological order. Each line contains a single integer: -1, 0 or 1. Number -1 means that Dima hits the table. Number 0 means that Inna and Dima add number 0 to the end of the sequence. Number 1 means that Inna and Dima add number 1 to the end of the sequence.

## Output

In a single line print a sequence of numbers 0 and 1 — the elements of the sequence after all events happen. Print the elements of the sequence in the order from the beginning to the end of the sequence.

If after all events the sequence ends up empty, print "Poor stack!".

## Examples

## Input


```
10 3  
1 3 6  
-1  
1  
1  
0  
0  
-1  
0  
1  
-1  
1  

```
## Output


```
011  

```
## Input


```
2 1  
1  
1  
-1  

```
## Output


```
Poor stack!  

```


#### tags 

#2000 #binary_search #data_structures #dp #trees 