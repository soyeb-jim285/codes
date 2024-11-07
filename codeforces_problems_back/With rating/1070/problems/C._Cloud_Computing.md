<h1 style='text-align: center;'> C. Cloud Computing</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Buber is a Berland technology company that specializes in waste of investor's money. Recently Buber decided to transfer its infrastructure to a cloud. The company decided to rent CPU cores in the cloud for $n$ consecutive days, which are numbered from $1$ to $n$. Buber requires $k$ CPU cores each day.

The cloud provider offers $m$ tariff plans, the $i$-th tariff plan is characterized by the following parameters:

* $l_i$ and $r_i$ — the $i$-th tariff plan is available only on days from $l_i$ to $r_i$, inclusive,
* $c_i$ — the number of cores per day available for rent on the $i$-th tariff plan,
* $p_i$ — the price of renting one core per day on the $i$-th tariff plan.

Buber can arbitrarily share its computing core needs between the tariff plans. Every day Buber can rent an arbitrary number of cores (from 0 to $c_i$) on each of the available plans. The number of rented cores on a tariff plan can vary arbitrarily from day to day.

Find the minimum amount of money that Buber will pay for its work for $n$ days from $1$ to $n$. If on a day the total number of cores for all available tariff plans is strictly less than $k$, then this day Buber will have to work on fewer cores (and it rents all the available cores), otherwise Buber rents exactly $k$ cores this day.

## Input

The first line of the input contains three integers $n$, $k$ and $m$ ($1 \le n,k \le 10^6, 1 \le m \le 2\cdot10^5$) — the number of days to analyze, the desired daily number of cores, the number of tariff plans.

The following $m$ lines contain descriptions of tariff plans, one description per line. Each line contains four integers $l_i$, $r_i$, $c_i$, $p_i$ ($1 \le l_i \le r_i \le n$, $1 \le c_i, p_i \le 10^6$), where $l_i$ and $r_i$ are starting and finishing days of the $i$-th tariff plan, $c_i$ — number of cores, $p_i$ — price of a single core for daily rent on the $i$-th tariff plan.

## Output

Print a single integer number — the minimal amount of money that Buber will pay.

## Examples

## Input


```
5 7 3  
1 4 5 3  
1 3 5 2  
2 5 10 1  

```
## Output


```
44  

```
## Input


```
7 13 5  
2 3 10 7  
3 5 10 10  
1 2 10 6  
4 5 10 9  
3 4 10 8  

```
## Output


```
462  

```
## Input


```
4 100 3  
3 3 2 5  
1 1 3 2  
2 4 4 4  

```
## Output


```
64  

```


#### tags 

#2000 #data_structures #greedy 