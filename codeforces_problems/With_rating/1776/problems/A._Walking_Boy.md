<h1 style='text-align: center;'> A. Walking Boy</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One of the SWERC judges has a dog named Boy. Besides being a good competitive programmer, Boy loves fresh air, so she wants to be walked at least twice a day. Walking Boy requires $120$ consecutive minutes. Two walks cannot overlap, but one can start as soon as the previous one has finished.

 ![](images/e58c4454baa43646078f2f14e89d150f5959dc84.png)Boy before and after getting ACCEPTED on this problem. 

Today, the judge sent $n$ messages to the SWERC Discord server. The $i$-th message was sent $a_i$ minutes after midnight. You know that, when walking Boy, the judge does not send any messages, but he can send a message right before or right after a walk. Is it possible that the judge walked Boy at least twice today?

## Note

 that a day has $1440$ minutes, and a walk is considered to happen today if it starts at a minute $s \ge 0$ and ends right before a minute $e \le 1440$. In that case, it must hold that $e - s = 120$ and, for every $i = 1, \, 2 \, \dots, \, n$, either $a_i \le s$ or $a_i \ge e$.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 100$) — the number of test cases. The descriptions of the $t$ test cases follow.

The first line of each test case contains an integer $n$ ($1 \le n \le 100$) — the number of messages sent by the judge.

The second line of each test case contains $n$ integers $a_1, \, a_2, \, \dots, \, a_n$ ($0 \le a_1 < a_2 < \cdots < a_n < 1440$) — the times at which the messages have been sent (in minutes elapsed from midnight).

### Output

For each test case, output one line containing $\texttt{YES}$ if it is possible that Boy has been walked at least twice, and $\texttt{NO}$ otherwise.

## Example

### Input


```text
614100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 140012100 200 300 400 600 700 800 900 1100 1200 1300 140013100 200 300 400 500 600 700 800 900 1100 1200 1300 140013101 189 272 356 463 563 659 739 979 1071 1170 1274 135814250 1 2 3 4
```
### Output

```text

NO
YES
NO
YES
YES
YES

```
## Note

In the first test case, the judge has sent a message at each time multiple of $100$ (excluding $0$). It is impossible that he has walked Boy even once.

In the second test case, the times are the same as above, but $500$ and $1000$ are missing. The judge could have walked Boy, for instance, during the time intervals $[440, 560]$ and $[980, 1100]$. The situation is illustrated in the picture below, where the walks are represented by green intervals.

 ![](images/0a2cd5b222f4bd1633da78a0d7d5f4cb48a62532.png) $$$$

In the third test case, the times are the same as in the first test case, but $1000$ is missing. The judge could have walked Boy at most once.

In the fourth test case, Boy could have been walked during the time intervals $[739, 859]$ and $[859, 979]$.

 ![](images/4d392e90c778086e72cf3f32ed16d71119c46005.png) 

#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../SWERC_2022-2023_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
