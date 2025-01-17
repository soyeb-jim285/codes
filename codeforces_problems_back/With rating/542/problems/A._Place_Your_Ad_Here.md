<h1 style='text-align: center;'> A. Place Your Ad Here</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan Anatolyevich's agency is starting to become famous in the town. 

They have already ordered and made *n* TV commercial videos. Each video is made in a special way: the colors and the soundtrack are adjusted to the time of the day and the viewers' mood. That's why the *i*-th video can only be shown within the time range of [*l**i*, *r**i*] (it is not necessary to use the whole segment but the broadcast time should be within this segment).

Now it's time to choose a TV channel to broadcast the commercial. Overall, there are *m* TV channels broadcasting in the city, the *j*-th one has *c**j* viewers, and is ready to sell time [*a**j*, *b**j*] to broadcast the commercial.

Ivan Anatolyevich is facing a hard choice: he has to choose exactly one video *i* and exactly one TV channel *j* to broadcast this video and also a time range to broadcast [*x*, *y*]. At that the time range should be chosen so that it is both within range [*l**i*, *r**i*] and within range [*a**j*, *b**j*].

Let's define the efficiency of the broadcast as value (*y* - *x*)·*c**j* — the total sum of time that all the viewers of the TV channel are going to spend watching the commercial. Help Ivan Anatolyevich choose the broadcast with the maximum efficiency!

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 2·105) — the number of commercial videos and channels, respectively.

Each of the following *n* lines contains two integers *l**i*, *r**i* (0 ≤ *l**i* ≤ *r**i* ≤ 109) — the segment of time when it is possible to show the corresponding video.

Each of the following *m* lines contains three integers *a**j*, *b**j*, *c**j* (0 ≤ *a**j* ≤ *b**j* ≤ 109, 1 ≤ *c**j* ≤ 109), characterizing the TV channel.

## Output

In the first line print an integer — the maximum possible efficiency of the broadcast. If there is no correct way to get a strictly positive efficiency, print a zero.

If the maximum efficiency is strictly positive, in the second line also print the number of the video *i* (1 ≤ *i* ≤ *n*) and the number of the TV channel *j* (1 ≤ *j* ≤ *m*) in the most effective broadcast.

If there are multiple optimal answers, you can print any of them.

## Examples

## Input


```
2 3  
7 9  
1 4  
2 8 2  
0 4 1  
8 9 3  

```
## Output


```
4  
2 1  

```
## Input


```
1 1  
0 0  
1 1 10  

```
## Output


```
0  

```
## Note

In the first sample test the most optimal solution is to show the second commercial using the first TV channel at time [2, 4]. The efficiency of such solution is equal to (4 - 2)·2 = 4.

In the second sample test Ivan Anatolievich's wish does not meet the options of the TV channel, the segments do not intersect, so the answer is zero.



#### tags 

#2400 #data_structures #sortings 