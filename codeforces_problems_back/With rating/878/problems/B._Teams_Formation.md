<h1 style='text-align: center;'> B. Teams Formation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This time the Berland Team Olympiad in Informatics is held in a remote city that can only be reached by one small bus. Bus has *n* passenger seats, seat *i* can be occupied only by a participant from the city *a**i*.

Today the bus has completed *m* trips, each time bringing *n* participants. The participants were then aligned in one line in the order they arrived, with people from the same bus standing in the order of their seats (i. e. if we write down the cities where the participants came from, we get the sequence *a*1, *a*2, ..., *a**n* repeated *m* times).

After that some teams were formed, each consisting of *k* participants form the same city standing next to each other in the line. Once formed, teams left the line. The teams were formed until there were no *k* neighboring participants from the same city.

Help the organizers determine how many participants have left in the line after that process ended. We can prove that answer doesn't depend on the order in which teams were selected.

## Input

The first line contains three integers *n*, *k* and *m* (1 ≤ *n* ≤ 105, 2 ≤ *k* ≤ 109, 1 ≤ *m* ≤ 109).

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105), where *a**i* is the number of city, person from which must take seat *i* in the bus. 

## Output

## Output

 the number of remaining participants in the line.

## Examples

## Input


```
4 2 5  
1 2 3 1  

```
## Output


```
12  

```
## Input


```
1 9 10  
1  

```
## Output


```
1  

```
## Input


```
3 2 10  
1 2 1  

```
## Output


```
0  

```
## Note

In the second example, the line consists of ten participants from the same city. Nine of them will form a team. At the end, only one participant will stay in the line.



#### tags 

#2300 #data_structures #implementation 