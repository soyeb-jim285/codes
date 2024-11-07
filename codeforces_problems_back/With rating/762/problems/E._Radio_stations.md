<h1 style='text-align: center;'> E. Radio stations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the lattice points of the coordinate line there are *n* radio stations, the *i*-th of which is described by three integers:

* *x**i* — the coordinate of the *i*-th station on the line,
* *r**i* — the broadcasting range of the *i*-th station,
* *f**i* — the broadcasting frequency of the *i*-th station.

We will say that two radio stations with numbers *i* and *j* reach each other, if the broadcasting range of each of them is more or equal to the distance between them. In other words *min*(*r**i*, *r**j*) ≥ |*x**i* - *x**j*|.

Let's call a pair of radio stations (*i*, *j*) bad if *i* < *j*, stations *i* and *j* reach each other and they are close in frequency, that is, |*f**i* - *f**j*| ≤ *k*.

Find the number of bad pairs of radio stations.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 105, 0 ≤ *k* ≤ 10) — the number of radio stations and the maximum difference in the frequencies for the pair of stations that reach each other to be considered bad.

In the next *n* lines follow the descriptions of radio stations. Each line contains three integers *x**i*, *r**i* and *f**i* (1 ≤ *x**i*, *r**i* ≤ 109, 1 ≤ *f**i* ≤ 104) — the coordinate of the *i*-th radio station, it's broadcasting range and it's broadcasting frequency. No two radio stations will share a coordinate.

## Output

## Output

 the number of bad pairs of radio stations.

## Examples

## Input


```
3 2  
1 3 10  
3 2 5  
4 10 8  

```
## Output


```
1  

```
## Input


```
3 3  
1 3 10  
3 2 5  
4 10 8  

```
## Output


```
2  

```
## Input


```
5 1  
1 3 2  
2 2 4  
3 2 1  
4 2 1  
5 3 3  

```
## Output


```
2  

```
## Input


```
5 1  
1 5 2  
2 5 4  
3 5 1  
4 5 1  
5 5 3  

```
## Output


```
5  

```


#### tags 

#2200 #binary_search #data_structures 