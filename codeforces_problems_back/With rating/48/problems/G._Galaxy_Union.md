<h1 style='text-align: center;'> G. Galaxy Union</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a far away galaxy there are *n* inhabited planets numbered with numbers from 1 to *n*. One day the presidents of all the *n* planets independently from each other came up with an idea of creating the Galaxy Union. Now they need to share this wonderful idea with their galaxymates, that’s why each president is busy working out a project of negotiating with the other presidents.

For negotiations between some pairs of the planets there are bidirectional communication channels, each of which is characterized with "dial duration" *t**i* which, as a rule, takes several hours and exceeds the call duration greatly. Overall the galaxy has *n* communication channels and they unite all the planets into a uniform network. That means that it is possible to phone to any planet *v* from any planet *u*, perhaps, using some transitional planets *v*1, *v*2, ..., *v**m* via the existing channels between *u* and *v*1, *v*1 and *v*2, ..., *v**m* - 1 and *v**m*, *v**m* and *v*. At that the dial duration from *u* to *v* will be equal to the sum of dial durations of the used channels.

So, every president has to talk one by one to the presidents of all the rest *n* - 1 planets. At that the negotiations take place strictly consecutively, and until the negotiations with a planet stop, the dial to another one does not begin. As the matter is urgent, from the different ways to call the needed planet every time the quickest one is chosen. Little time is needed to assure another president on the importance of the Galaxy Union, that’s why the duration of the negotiations with each planet can be considered equal to the dial duration time for those planets. As the presidents know nothing about each other’s plans, they do not take into consideration the possibility that, for example, the sought president may call himself or already know about the founding of the Galaxy Union from other sources.

The governments of all the *n* planets asked you to work out the negotiation plans. First you are to find out for every president how much time his supposed negotiations will take.

## Input

The first line contains an integer *n* (3 ≤ *n* ≤ 200000) which represents the number of planets in the Galaxy and the number of communication channels equal to it. The next *n* lines contain three integers each *a**i*, *b**i* and *t**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*, 1 ≤ *t**i* ≤ 103) that represent the numbers of planet joined by a communication channel and its "dial duration". There can be no more than one communication channel between a pair of planets. 

## Output

In the first line output *n* integers — the durations of the supposed negotiations for each president. Separate the numbers by spaces.

## Examples

## Input


```
3  
1 2 3  
2 3 2  
1 3 1  

```
## Output


```
4 5 3  

```
## Input


```
3  
1 2 3  
2 3 2  
1 3 5  

```
## Output


```
8 5 7  

```
## Input


```
4  
1 2 3  
2 3 2  
3 4 1  
4 1 4  

```
## Output


```
12 8 8 8  

```


#### tags 

#2700 #dp #trees #two_pointers 