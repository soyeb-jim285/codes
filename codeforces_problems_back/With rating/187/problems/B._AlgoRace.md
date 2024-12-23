<h1 style='text-align: center;'> B. AlgoRace</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

PMP is getting a warrior. He is practicing a lot, but the results are not acceptable yet. This time instead of programming contests, he decided to compete in a car racing to increase the spirit of victory. He decides to choose a competition that also exhibits algorithmic features.

AlgoRace is a special league of car racing where different teams compete in a country of *n* cities. Cities are numbered 1 through *n*. Every two distinct cities in the country are connected with one bidirectional road. Each competing team should introduce one driver and a set of cars.

The competition is held in *r* rounds. In *i*-th round, drivers will start at city *s**i* and finish at city *t**i*. Drivers are allowed to change their cars at most *k**i* times. Changing cars can take place in any city in no time. One car can be used multiple times in one round, but total number of changes should not exceed *k**i*. Drivers can freely choose their path to destination.

PMP has prepared *m* type of purpose-built cars. Beside for PMP’s driving skills, depending on properties of the car and the road, a car traverses each road in each direction in different times. 

PMP Warriors wants to devise best strategies of choosing car and roads in each round to maximize the chance of winning the cup. For each round they want to find the minimum time required to finish it.

## Input

The first line contains three space-separated integers *n*, *m*, *r* (2 ≤ *n* ≤ 60, 1 ≤ *m* ≤ 60, 1 ≤ *r* ≤ 105) — the number of cities, the number of different types of cars and the number of rounds in the competition, correspondingly.

Next *m* sets of *n* × *n* matrices of integers between 0 to 106 (inclusive) will follow — describing the time one car requires to traverse different roads. The *k*-th integer in *j*-th line of the *i*-th set is the time that *i*-th car requires to traverse the road from *j*-th city to *k*-th city. These matrices are not necessarily symmetric, but their diagonal is always zero.

Next *r* lines contain description of the rounds. The *i*-th of these lines contains space-separated integers *s**i*, *t**i*, *k**i* (1 ≤ *s**i*, *t**i* ≤ *n*, *s**i* ≠ *t**i*, 0 ≤ *k**i* ≤ 1000) — the number of starting city, finishing city and the number of possible car changes in *i*-th round, correspondingly.

## Output

For each round you should print the minimum required time to complete the round in a single line.

## Examples

## Input


```
4 2 3  
0 1 5 6  
2 0 3 6  
1 3 0 1  
6 6 7 0  
0 3 5 6  
2 0 1 6  
1 3 0 2  
6 6 7 0  
1 4 2  
1 4 1  
1 4 3  

```
## Output


```
3  
4  
3  

```
## Input


```
4 2 3  
0 7 3 3  
8 0 10 5  
1 1 0 4  
8 9 2 0  
0 3 3 9  
7 0 4 9  
3 8 0 4  
4 8 9 0  
2 3 3  
2 1 3  
1 2 2  

```
## Output


```
4  
5  
3  

```
## Note

In the first sample, in all rounds PMP goes from city #1 to city #2, then city #3 and finally city #4. But the sequences of types of the cars he uses are (1, 2, 1) in the first round and (1, 2, 2) in the second round. In the third round, although he can change his car three times, he uses the same strategy as the first round which only needs two car changes.



#### tags 

#1800 #dp #shortest_paths 