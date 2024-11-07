<h1 style='text-align: center;'> B. Eugeny and Play List</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Eugeny loves listening to music. He has *n* songs in his play list. We know that song number *i* has the duration of *t**i* minutes. Eugeny listens to each song, perhaps more than once. He listens to song number *i* *c**i* times. Eugeny's play list is organized as follows: first song number 1 plays *c*1 times, then song number 2 plays *c*2 times, ..., in the end the song number *n* plays *c**n* times.

Eugeny took a piece of paper and wrote out *m* moments of time when he liked a song. Now for each such moment he wants to know the number of the song that played at that moment. The moment *x* means that Eugeny wants to know which song was playing during the *x*-th minute of his listening to the play list.

Help Eugeny and calculate the required numbers of songs.

## Input

The first line contains two integers *n*, *m* (1 ≤ *n*, *m* ≤ 105). The next *n* lines contain pairs of integers. The *i*-th line contains integers *c**i*, *t**i* (1 ≤ *c**i*, *t**i* ≤ 109) — the description of the play list. It is guaranteed that the play list's total duration doesn't exceed 109 ![](images/920c79400120d0d4ba526d1d58cb85c98953f1f1.png).

The next line contains *m* positive integers *v*1, *v*2, ..., *v**m*, that describe the moments Eugeny has written out. It is guaranteed that there isn't such moment of time *v**i*, when the music doesn't play any longer. It is guaranteed that *v**i* < *v**i* + 1 (*i* < *m*).

The moment of time *v**i* means that Eugeny wants to know which song was playing during the *v**i*-th munite from the start of listening to the playlist.

## Output

Print *m* integers — the *i*-th number must equal the number of the song that was playing during the *v**i*-th minute after Eugeny started listening to the play list.

## Examples

## Input


```
1 2  
2 8  
1 16  

```
## Output


```
1  
1  

```
## Input


```
4 9  
1 2  
2 1  
1 1  
2 2  
1 2 3 4 5 6 7 8 9  

```
## Output


```
1  
1  
2  
2  
3  
4  
4  
4  
4  

```


#### tags 

#1200 #binary_search #implementation #two_pointers 