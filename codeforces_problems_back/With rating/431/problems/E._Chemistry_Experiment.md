<h1 style='text-align: center;'> E. Chemistry Experiment</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day two students, Grisha and Diana, found themselves in the university chemistry lab. In the lab the students found *n* test tubes with mercury numbered from 1 to *n* and decided to conduct an experiment.

The experiment consists of *q* steps. On each step, one of the following actions occurs:

1. Diana pours all the contents from tube number *p**i* and then pours there exactly *x**i* liters of mercury.
2. Let's consider all the ways to add *v**i* liters of water into the tubes; for each way let's count the volume of liquid (water and mercury) in the tube with water with maximum amount of liquid; finally let's find the minimum among counted maximums. That is the number the students want to count. At that, the students don't actually pour the mercury. They perform calculations without changing the contents of the tubes.

Unfortunately, the calculations proved to be too complex and the students asked you to help them. Help them conduct the described experiment.

## Input

The first line contains two integers *n* and *q* (1 ≤ *n*, *q* ≤ 105) — the number of tubes ans the number of experiment steps. The next line contains *n* space-separated integers: *h*1, *h*2, ..., *h**n* (0 ≤ *h**i* ≤ 109), where *h**i* is the volume of mercury in the *і*-th tube at the beginning of the experiment.

The next *q* lines contain the game actions in the following format:

* A line of form "1 *p**i* *x**i*" means an action of the first type (1 ≤ *p**i* ≤ *n*; 0 ≤ *x**i* ≤ 109).
* A line of form "2 *v**i*" means an action of the second type (1 ≤ *v**i* ≤ 1015).

It is guaranteed that there is at least one action of the second type. It is guaranteed that all numbers that describe the experiment are integers.

## Output

For each action of the second type print the calculated value. The answer will be considered correct if its relative or absolute error doesn't exceed 10- 4.

## Examples

## Input


```
3 3  
1 2 0  
2 2  
1 2 1  
2 3  

```
## Output


```
1.50000  
1.66667  

```
## Input


```
4 5  
1 3 0 1  
2 3  
2 1  
1 3 2  
2 3  
2 4  

```
## Output


```
1.66667  
1.00000  
2.33333  
2.66667  

```


#### tags 

#2200 #binary_search #data_structures #ternary_search 