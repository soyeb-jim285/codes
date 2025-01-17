<h1 style='text-align: center;'> A. Friends or Not</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus has a hobby — he develops an unusual social network. His work is almost completed, and there is only one more module to implement — the module which determines friends. Oh yes, in this social network one won't have to add friends manually! Pairs of friends are deduced in the following way. Let's assume that user *A* sent user *B* a message at time *t*1, and user *B* sent user *A* a message at time *t*2. If 0 < *t*2 - *t*1 ≤ *d*, then user *B*'s message was an answer to user *A*'s one. Users *A* and *B* are considered to be friends if *A* answered at least one *B*'s message or *B* answered at least one *A*'s message.

You are given the log of messages in chronological order and a number *d*. Find all pairs of users who will be considered to be friends.

## Input

The first line of the input contains two integers *n* and *d* (1 ≤ *n*, *d* ≤ 1000). The next *n* lines contain the messages log. The *i*-th line contains one line of the log formatted as "*A**i* *B**i* *t**i*" (without the quotes), which means that user *A**i* sent a message to user *B**i* at time *t**i* (1 ≤ *i* ≤ *n*). *A**i* and *B**i* are non-empty strings at most 20 characters long, consisting of lowercase letters ('a' ... 'z'), and *t**i* is an integer (0 ≤ *t**i* ≤ 10000). It is guaranteed that the lines are given in non-decreasing order of *t**i*'s and that no user sent a message to himself. The elements in the lines are separated by single spaces.

## Output

In the first line print integer *k* — the number of pairs of friends. In the next *k* lines print pairs of friends as "*A**i* *B**i*" (without the quotes). You can print users in pairs and the pairs themselves in any order. Each pair must be printed exactly once.

## Examples

## Input


```
4 1  
vasya petya 1  
petya vasya 2  
anya ivan 2  
ivan anya 4  

```
## Output


```
1  
petya vasya  

```
## Input


```
1 1000  
a b 0  

```
## Output


```
0  

```
## Note

In the first sample test case Vasya and Petya are friends because their messages' sending times are one second apart. Anya and Ivan are not, because their messages' sending times differ by more than one second.



#### tags 

#1400 #*special #greedy #implementation 