<h1 style='text-align: center;'> A. Let's Watch Football</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valeric and Valerko missed the last Euro football game, so they decided to watch the game's key moments on the Net. They want to start watching as soon as possible but the connection speed is too low. If they turn on the video right now, it will "hang up" as the size of data to watch per second will be more than the size of downloaded data per second.

The guys want to watch the whole video without any pauses, so they have to wait some integer number of seconds for a part of the video to download. After this number of seconds passes, they can start watching. Waiting for the whole video to download isn't necessary as the video can download after the guys started to watch.

Let's suppose that video's length is *c* seconds and Valeric and Valerko wait *t* seconds before the watching. Then for any moment of time *t*0, *t* ≤ *t*0 ≤ *c* + *t*, the following condition must fulfill: the size of data received in *t*0 seconds is not less than the size of data needed to watch *t*0 - *t* seconds of the video.

Of course, the guys want to wait as little as possible, so your task is to find the minimum integer number of seconds to wait before turning the video on. The guys must watch the video without pauses.

## Input

The first line contains three space-separated integers *a*, *b* and *c* (1 ≤ *a*, *b*, *c* ≤ 1000, *a* > *b*). The first number (*a*) denotes the size of data needed to watch one second of the video. The second number (*b*) denotes the size of data Valeric and Valerko can download from the Net per second. The third number (*c*) denotes the video's length in seconds.

## Output

Print a single number — the minimum integer number of seconds that Valeric and Valerko must wait to watch football without pauses.

## Examples

## Input


```
4 1 1  

```
## Output


```
3  

```
## Input


```
10 3 2  

```
## Output


```
5  

```
## Input


```
13 12 1  

```
## Output


```
1  

```
## Note

In the first sample video's length is 1 second and it is necessary 4 units of data for watching 1 second of video, so guys should download 4 · 1 = 4 units of data to watch the whole video. The most optimal way is to wait 3 seconds till 3 units of data will be downloaded and then start watching. While guys will be watching video 1 second, one unit of data will be downloaded and Valerik and Valerko will have 4 units of data by the end of watching. Also every moment till the end of video guys will have more data then necessary for watching.

In the second sample guys need 2 · 10 = 20 units of data, so they have to wait 5 seconds and after that they will have 20 units before the second second ends. However, if guys wait 4 seconds, they will be able to watch first second of video without pauses, but they will download 18 units of data by the end of second second and it is less then necessary.



#### tags 

#1000 #binary_search #brute_force #math 