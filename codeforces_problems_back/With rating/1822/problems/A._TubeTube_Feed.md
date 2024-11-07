<h1 style='text-align: center;'> A. TubeTube Feed</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mushroom Filippov cooked himself a meal and while having his lunch, he decided to watch a video on TubeTube. He can not spend more than $t$ seconds for lunch, so he asks you for help with the selection of video.

The TubeTube feed is a list of $n$ videos, indexed from $1$ to $n$. The $i$-th video lasts $a_i$ seconds and has an entertainment value $b_i$. Initially, the feed is opened on the first video, and Mushroom can skip to the next video in $1$ second (if the next video exists). Mushroom can skip videos any number of times (including zero).

Help Mushroom choose one video that he can open and watch in $t$ seconds. If there are several of them, he wants to choose the most entertaining one. Print the index of any appropriate video, or $-1$ if there is no such.

## Input

The first line of the input data contains a single integer $q$ ($1 \le q \le 1000$) — the number of test cases in the test.

The description of the test cases follows.

The first line of a test case contains two integers $n$ and $t$ ($1 \le n \le 50$, $1 \le t \le 200$) — the number of videos in the feed and seconds for lunch, respectively.

The second line of a test case contains $n$ integers $a_1, a_2, a_3, \dots, a_n$ ($1 \le a_i \le 100$) — durations of videos. 

The third line of a test case contains $n$ integers $b_1, b_2, b_3, \dots, b_n$ ($1 \le b_i \le 100$) — entertainment values of videos.

## Output

## Output

 $q$ integers, each of which is the answer to the corresponding test case. As an answer, output the index of the most entertaining video that Mushroom will have time to watch. If there are several answers, you are allowed to output any of them. ## Output

 $-1$, if there is no video he can watch during his lunch break.

## Example

## Input


```

55 91 5 7 6 63 4 7 1 94 44 3 3 21 2 3 45 75 5 5 5 52 1 3 9 74 3354 71 69 9642 24 99 12 17955 6677 88
```
## Output


```

3
2
3
-1
2

```


#### tags 

#800 #brute_force #implementation 