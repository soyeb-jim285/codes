<h1 style='text-align: center;'> F. Music in Car</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha reaches the work by car. It takes exactly *k* minutes. On his way he listens to music. All songs in his playlist go one by one, after listening to the *i*-th song Sasha gets a pleasure which equals *a**i*. The *i*-th song lasts for *t**i* minutes. 

Before the beginning of his way Sasha turns on some song *x* and then he listens to the songs one by one: at first, the song *x*, then the song (*x* + 1), then the song number (*x* + 2), and so on. He listens to songs until he reaches the work or until he listens to the last song in his playlist. 

Sasha can listen to each song to the end or partly.

In the second case he listens to the song for integer number of minutes, at least half of the song's length. Formally, if the length of the song equals *d* minutes, Sasha listens to it for no less than ![](images/1b02a7b3124f1aefddafdd585f9135a37953cdda.png) minutes, then he immediately switches it to the next song (if there is such). For example, if the length of the song which Sasha wants to partly listen to, equals 5 minutes, then he should listen to it for at least 3 minutes, if the length of the song equals 8 minutes, then he should listen to it for at least 4 minutes.

It takes no time to switch a song.

Sasha wants to listen partly no more than *w* songs. If the last listened song plays for less than half of its length, then Sasha doesn't get pleasure from it and that song is not included to the list of partly listened songs. It is not allowed to skip songs. A pleasure from a song does not depend on the listening mode, for the *i*-th song this value equals *a**i*.

Help Sasha to choose such *x* and no more than *w* songs for partial listening to get the maximum pleasure. Write a program to find the maximum pleasure Sasha can get from the listening to the songs on his way to the work.

## Input

The first line contains three integers *n*, *w* and *k* (1 ≤ *w* ≤ *n* ≤ 2·105, 1 ≤ *k* ≤ 2·109) — the number of songs in the playlist, the number of songs Sasha can listen to partly and time in minutes which Sasha needs to reach work. 

The second line contains *n* positive integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 104), where *a**i* equals the pleasure Sasha gets after listening to the *i*-th song.

The third line contains *n* positive integers *t*1, *t*2, ..., *t**n* (2 ≤ *t**i* ≤ 104), where *t**i* equals the length of the *i*-th song in minutes.

## Output

Print the maximum pleasure Sasha can get after listening to the songs on the way to work. 

## Examples

## Input


```
7 2 11  
3 4 3 5 1 4 6  
7 7 3 6 5 3 9  

```
## Output


```
12  

```
## Input


```
8 4 20  
5 6 4 3 7 5 4 1  
10 12 5 12 14 8 5 8  

```
## Output


```
19  

```
## Input


```
1 1 5  
6  
9  

```
## Output


```
6  

```
## Input


```
1 1 3  
4  
7  

```
## Output


```
0  

```
## Note

In the first example Sasha needs to start listening from the song number 2. He should listen to it partly (for 4 minutes), then listen to the song number 3 to the end (for 3 minutes) and then partly listen to the song number 4 (for 3 minutes). After listening to these songs Sasha will get pleasure which equals 4 + 3 + 5 = 12. Sasha will not have time to listen to the song number 5 because he will spend 4 + 3 + 3 = 10 minutes listening to songs number 2, 3 and 4 and only 1 minute is left after that. 



#### tags 

#2200 #data_structures #greedy #two_pointers 