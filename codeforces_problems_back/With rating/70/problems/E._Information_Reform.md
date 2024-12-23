<h1 style='text-align: center;'> E. Information Reform</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Thought it is already the XXI century, the Mass Media isn't very popular in Walrusland. The cities get news from messengers who can only travel along roads. The network of roads in Walrusland is built so that it is possible to get to any city from any other one in exactly one way, and the roads' lengths are equal.

The North Pole governor decided to carry out an information reform. Several cities were decided to be chosen and made regional centers. Maintaining a region center takes *k* fishlars (which is a local currency) per year. It is assumed that a regional center always has information on the latest news.

For every city which is not a regional center, it was decided to appoint a regional center which will be responsible for keeping this city informed. In that case the maintenance costs will be equal to *d**len* fishlars per year, where *len* is the distance from a city to the corresponding regional center, measured in the number of roads along which one needs to go.

Your task is to minimize the costs to carry out the reform.

## Input

The first line contains two given numbers *n* and *k* (1 ≤ *n* ≤ 180, 1 ≤ *k* ≤ 105).

The second line contains *n* - 1 integers *d**i*, numbered starting with 1 (*d**i* ≤ *d**i* + 1, 0 ≤ *d**i* ≤ 105).

Next *n* - 1 lines contain the pairs of cities connected by a road.

## Output

On the first line print the minimum number of fishlars needed for a year's maintenance. On the second line print *n* numbers, where the *i*-th number will represent the number of the regional center, appointed to the *i*-th city. If the *i*-th city is a regional center itself, then you should print number *i*.

If there are several solutions to that problem, print any of them.

## Examples

## Input


```
8 10  
2 5 9 11 15 19 20  
1 4  
1 3  
1 7  
4 6  
2 8  
2 3  
3 5  

```
## Output


```
38  
3 3 3 4 3 4 3 3 
```


#### tags 

#2700 #dp #implementation #trees 