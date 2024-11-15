<h1 style='text-align: center;'> E. Trains and Statistic</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya commutes by train every day. There are *n* train stations in the city, and at the *i*-th station it's possible to buy only tickets to stations from *i* + 1 to *a**i* inclusive. No tickets are sold at the last station.

Let ρ*i*, *j* be the minimum number of tickets one needs to buy in order to get from stations *i* to station *j*. As Vasya is fond of different useless statistic he asks you to compute the sum of all values ρ*i*, *j* among all pairs 1 ≤ *i* < *j* ≤ *n*.

## Input

The first line of the input contains a single integer *n* (2 ≤ *n* ≤ 100 000) — the number of stations.

The second line contains *n* - 1 integer *a**i* (*i* + 1 ≤ *a**i* ≤ *n*), the *i*-th of them means that at the *i*-th station one may buy tickets to each station from *i* + 1 to *a**i* inclusive.

## Output

Print the sum of ρ*i*, *j* among all pairs of 1 ≤ *i* < *j* ≤ *n*.

## Examples

## Input


```
4  
4 4 4  

```
## Output


```
6  

```
## Input


```
5  
2 3 5 5  

```
## Output


```
17  

```
## Note

In the first sample it's possible to get from any station to any other (with greater index) using only one ticket. The total number of pairs is 6, so the answer is also 6.

Consider the second sample: 

* ρ1, 2 = 1
* ρ1, 3 = 2
* ρ1, 4 = 3
* ρ1, 5 = 3
* ρ2, 3 = 1
* ρ2, 4 = 2
* ρ2, 5 = 2
* ρ3, 4 = 1
* ρ3, 5 = 1
* ρ4, 5 = 1

Thus the answer equals 1 + 2 + 3 + 3 + 1 + 2 + 2 + 1 + 1 + 1 = 17.



#### tags 

#2300 #data_structures #dp #greedy 