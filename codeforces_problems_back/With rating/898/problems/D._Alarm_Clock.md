<h1 style='text-align: center;'> D. Alarm Clock</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Every evening Vitalya sets *n* alarm clocks to wake up tomorrow. Every alarm clock rings during exactly one minute and is characterized by one integer *a**i* — number of minute after midnight in which it rings. Every alarm clock begins ringing at the beginning of the minute and rings during whole minute. 

Vitalya will definitely wake up if during some *m* consecutive minutes at least *k* alarm clocks will begin ringing. Pay attention that Vitalya considers only alarm clocks which begin ringing during given period of time. He doesn't consider alarm clocks which started ringing before given period of time and continues ringing during given period of time.

Vitalya is so tired that he wants to sleep all day long and not to wake up. Find out minimal number of alarm clocks Vitalya should turn off to sleep all next day. Now all alarm clocks are turned on. 

## Input

First line contains three integers *n*, *m* and *k* (1 ≤ *k* ≤ *n* ≤ 2·105, 1 ≤ *m* ≤ 106) — number of alarm clocks, and conditions of Vitalya's waking up. 

Second line contains sequence of distinct integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 106) in which *a**i* equals minute on which *i*-th alarm clock will ring. Numbers are given in arbitrary order. Vitalya lives in a Berland in which day lasts for 106 minutes. 

## Output

## Output

 minimal number of alarm clocks that Vitalya should turn off to sleep all next day long.

## Examples

## Input


```
3 3 2  
3 5 1  

```
## Output


```
1  

```
## Input


```
5 10 3  
12 8 18 25 1  

```
## Output


```
0  

```
## Input


```
7 7 2  
7 3 4 1 6 5 2  

```
## Output


```
6  

```
## Input


```
2 2 2  
1 3  

```
## Output


```
0  

```
## Note

In first example Vitalya should turn off first alarm clock which rings at minute 3.

In second example Vitalya shouldn't turn off any alarm clock because there are no interval of 10 consequence minutes in which 3 alarm clocks will ring.

In third example Vitalya should turn off any 6 alarm clocks.



#### tags 

#1600 #greedy 