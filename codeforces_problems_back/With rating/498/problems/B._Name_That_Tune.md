<h1 style='text-align: center;'> B. Name That Tune</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It turns out that you are a great fan of rock band AC/PE. Peter learned that and started the following game: he plays the first song of the list of *n* songs of the group, and you have to find out the name of the song. After you tell the song name, Peter immediately plays the following song in order, and so on.

The *i*-th song of AC/PE has its recognizability *p**i*. This means that if the song has not yet been recognized by you, you listen to it for exactly one more second and with probability of *p**i* percent you recognize it and tell it's name. Otherwise you continue listening it. Note that you can only try to guess it only when it is integer number of seconds after the moment the song starts playing.

In all AC/PE songs the first words of chorus are the same as the title, so when you've heard the first *t**i* seconds of *i*-th song and its chorus starts, you immediately guess its name for sure.

For example, in the song Highway To Red the chorus sounds pretty late, but the song has high recognizability. In the song Back In Blue, on the other hand, the words from the title sound close to the beginning of the song, but it's hard to name it before hearing those words. You can name both of these songs during a few more first seconds.

Determine the expected number songs of you will recognize if the game lasts for exactly *T* seconds (i. e. you can make the last guess on the second *T*, after that the game stops).

If all songs are recognized faster than in *T* seconds, the game stops after the last song is recognized.

## Input

The first line of the input contains numbers *n* and *T* (1 ≤ *n* ≤ 5000, 1 ≤ *T* ≤ 5000), separated by a space. Next *n* lines contain pairs of numbers *p**i* and *t**i* (0 ≤ *p**i* ≤ 100, 1 ≤ *t**i* ≤ *T*). The songs are given in the same order as in Petya's list.

## Output

## Output

 a single number — the expected number of the number of songs you will recognize in *T* seconds. Your answer will be considered correct if its absolute or relative error does not exceed 10- 6.

## Examples

## Input


```
2 2  
50 2  
10 1  

```
## Output


```
1.500000000  

```
## Input


```
2 2  
0 2  
100 2  

```
## Output


```
1.000000000  

```
## Input


```
3 3  
50 3  
50 2  
25 2  

```
## Output


```
1.687500000  

```
## Input


```
2 2  
0 2  
0 2  

```
## Output


```
1.000000000  

```


#### tags 

#2400 #dp #probabilities #two_pointers 