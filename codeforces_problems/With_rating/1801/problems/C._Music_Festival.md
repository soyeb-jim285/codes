<h1 style='text-align: center;'> C. Music Festival</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

 The boy Vitya loves to listen to music very much. He knows that $n$ albums are due to be released this Friday, $i$-th of which contains $k_i$ tracks. Of course, Vitya has already listened to all the tracks, and knows that in the $i$-th album, the coolness of the $j$-th track is equal to $a_{i,j}$.Vitya has a friend Masha, whom he really wants to invite to the festival, where his favorite bands perform. However, in order for a friend to agree, she must first evaluate the released novelties. Vitya knows that if Masha listens to a track that was cooler than all the previous ones, she will get 1 unit of impression. Unfortunately, albums can only be listened to in their entirety, without changing the songs in them in places.

Help Vitya find such an order of albums so that Masha's impression turns out to be as much as possible, and she definitely went to the festival with him. 

### Input

Each test consists of multiple test cases. The first line contains a single integer t ($1 \le t \le 200\,000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 200\,000$) — number of albums.

The album descriptions follow. Each album description consists of two lines:

The first line contains a single integer $k_i$ ($1 \le k_i \le 200\,000$) — the number of tracks in the $i$th album.

The following line contains $k_i$ integers $a_{i, 1},\ a_{i, 2},\ a_{i, 3},\ \ldots,\ a_{i, k_i}$ ($1 \le a_{i,j} \le 200\,000$) — the coolness of the tracks in the $i$ album. 

Denote for $\sum k_i$ the sum of all $k_i$. It is guaranteed that $\sum k_i \le 200\,000$. 

### Output

For each test case print the singular number  — the maximum impression that Masha can get. 

## Example

 

### Input


```text
2454 9 4 6 81728 611423 421 822 827 9
```
### Output

```text

4
4

```
 
## Note

In the first test example, the optimal order is listening to the 4th, 2nd, 3rd and 1st albums. 

In this case, Masha will listen to the tracks in the following order: 1; 7; 8, 6; 4, 9, 4, 6, 8 and will receive 4 units of impression.

In the second test example, you must first listen to the 1st, then the 4th, and in any order the 2nd and 3rd. In this case, Masha will get the maximum impression, and for every song in the 1st and 4th albums and nothing for the 2nd and 3rd. 



#### Tags 

#1900 #NOT OK #binary_search #data_structures #dp #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_857_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (ru)](../blogs/Tutorial_(ru).md)
