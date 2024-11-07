<h1 style='text-align: center;'> B. Producing Snow</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice likes snow a lot! Unfortunately, this year's winter is already over, and she can't expect to have any more of it. Bob has thus bought her a gift — a large snow maker. He plans to make some amount of snow every day. On day *i* he will make a pile of snow of volume *V**i* and put it in her garden.

Each day, every pile will shrink a little due to melting. More precisely, when the temperature on a given day is *T**i*, each pile will reduce its volume by *T**i*. If this would reduce the volume of a pile to or below zero, it disappears forever. All snow piles are independent of each other. 

## Note

 that the pile made on day *i* already loses part of its volume on the same day. In an extreme case, this may mean that there are no piles left at the end of a particular day.

You are given the initial pile sizes and the temperature on each day. Determine the total volume of snow melted on each day. 

## Input

The first line contains a single integer *N* (1 ≤ *N* ≤ 105) — the number of days. 

The second line contains *N* integers *V*1, *V*2, ..., *V**N* (0 ≤ *V**i* ≤ 109), where *V**i* is the initial size of a snow pile made on the day *i*.

The third line contains *N* integers *T*1, *T*2, ..., *T**N* (0 ≤ *T**i* ≤ 109), where *T**i* is the temperature on the day *i*.

## Output

## Output

 a single line with *N* integers, where the *i*-th integer represents the total volume of snow melted on day *i*.

## Examples

## Input


```
3  
10 10 5  
5 7 2  

```
## Output


```
5 12 4  

```
## Input


```
5  
30 25 20 15 10  
9 10 12 4 13  

```
## Output


```
9 20 35 11 25  

```
## Note

In the first sample, Bob first makes a snow pile of volume 10, which melts to the size of 5 on the same day. On the second day, he makes another pile of size 10. Since it is a bit warmer than the day before, the first pile disappears completely while the second pile shrinks to 3. At the end of the second day, he has only a single pile of size 3. On the third day he makes a smaller pile than usual, but as the temperature dropped too, both piles survive till the end of the day.



#### tags 

#1600 #binary_search #data_structures 