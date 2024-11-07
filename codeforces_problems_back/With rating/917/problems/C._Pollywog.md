<h1 style='text-align: center;'> C. Pollywog</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As we all know, Dart is some kind of creature from Upside Down world. For simplicity, we call their kind pollywogs. Dart and *x* - 1 other pollywogs are playing a game. There are *n* stones in a row, numbered from 1 through *n* from left to right. At most 1 pollywog may be sitting on each stone at a time. Initially, the pollywogs are sitting on the first *x* stones (one pollywog on each stone).

 ![](images/d746add45f2265820a8f0e77d8904f5bb03dde9a.png) Dart and his friends want to end up on the last *x* stones. At each second, the leftmost pollywog should jump to the right. A pollywog can jump at most *k* stones; more specifically, a pollywog can jump from stone number *i* to stones *i* + 1, *i* + 2, ... *i* + *k*. A pollywog can't jump on an occupied stone. Jumping a distance *i* takes *c**i* amounts of energy from the pollywog. 

Also, *q* stones are special Each time landing on a special stone *p*, takes *w**p* amounts of energy (in addition to the energy for jump) from the pollywog. *w**p* could be negative, in this case, it means the pollywog absorbs |*w**p*| amounts of energy.

Pollywogs want to spend as little energy as possible (this value could be negative). 

They're just pollywogs, so they asked for your help. Tell them the total change in their energy, in case they move optimally.

## Input

The first line of input contains four integers, *x*, *k*, *n* and *q* (1 ≤ *x* ≤ *k* ≤ 8, *k* ≤ *n* ≤ 108, 0 ≤ *q* ≤ *min*(25, *n* - *x*)) — the number of pollywogs, the maximum length of jump, the number of stones and the number of special stones.

The next line contains *k* integers, *c*1, *c*2, ... *c**k*, separated by spaces (1 ≤ *c**i* ≤ 109) — the energetic costs of jumps.

The next *q* lines contain description of the special stones. Each line contains two integers *p* and *w**p* (*x* + 1 ≤ *p* ≤ *n*, |*w**p*| ≤ 109). All *p* are distinct.

## Output

Print the minimum amount of energy they need, in the first and only line of output.

## Examples

## Input


```
2 3 10 2  
1 2 3  
5 -10  
6 1000  

```
## Output


```
6  

```
## Input


```
4 7 85 3  
17 5 28 4 52 46 6  
59 -76  
33 -69  
19 2018  

```
## Output


```
135  

```


#### tags 

#2900 #combinatorics #dp #matrices 