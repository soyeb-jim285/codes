<h1 style='text-align: center;'> F. To Play or not to Play</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya and Petya are playing an online game. As most online games, it has hero progress system that allows players to gain experience that make their heroes stronger. Of course, Vasya would like to get as many experience points as possible. After careful study of experience points allocation, he found out that if he plays the game alone, he gets one experience point each second. However, if two players are playing together, and their current experience values differ by at most *C* points, they can boost their progress, and each of them gets 2 experience points each second.

Since Vasya and Petya are middle school students, their parents don't allow them to play all the day around. Each of the friends has his own schedule: Vasya can only play during intervals [*a*1;*b*1], [*a*2;*b*2], ..., [*a**n*;*b**n*], and Petya can only play during intervals [*c*1;*d*1], [*c*2;*d*2], ..., [*c**m*;*d**m*]. All time periods are given in seconds from the current moment. Vasya is good in math, so he has noticed that sometimes it can be profitable not to play alone, because experience difference could become too big, and progress would not be boosted even when played together.

Now they would like to create such schedule of playing that Vasya's final experience was greatest possible. The current players experience is the same. Petya is not so concerned about his experience, so he is ready to cooperate and play when needed to maximize Vasya's experience.

## Input

The first line of input data contains integers *n*, *m* and *C* — the number of intervals when Vasya can play, the number of intervals when Petya can play, and the maximal difference in experience level when playing together still gives a progress boost (1 ≤ *n*, *m* ≤ 2·105, 0 ≤ *C* ≤ 1018). 

The following *n* lines contain two integers each: *a**i*, *b**i* — intervals when Vasya can play (0 ≤ *a**i* < *b**i* ≤ 1018, *b**i* < *a**i* + 1).

The following *m* lines contain two integers each: *c**i*, *d**i* — intervals when Petya can play (0 ≤ *c**i* < *d**i* ≤ 1018, *d**i* < *c**i* + 1).

## Output

## Output

 one integer — the maximal experience that Vasya can have in the end, if both players try to maximize this value.

## Examples

## Input


```
2 1 5  
1 7  
10 20  
10 20  

```
## Output


```
25  

```
## Input


```
1 2 5  
0 100  
20 60  
85 90  

```
## Output


```
125  

```


#### tags 

#3000 #greedy 