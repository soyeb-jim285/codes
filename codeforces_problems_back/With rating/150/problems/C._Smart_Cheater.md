<h1 style='text-align: center;'> C. Smart Cheater</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

I guess there's not much point in reminding you that Nvodsk winters aren't exactly hot. That increased the popularity of the public transport dramatically. The route of bus 62 has exactly *n* stops (stop 1 goes first on its way and stop *n* goes last). The stops are positioned on a straight line and their coordinates are 0 = *x*1 < *x*2 < ... < *x**n*. 

Each day exactly *m* people use bus 62. For each person we know the number of the stop where he gets on the bus and the number of the stop where he gets off the bus. A ticket from stop *a* to stop *b* (*a* < *b*) costs *x**b* - *x**a* rubles. However, the conductor can choose no more than one segment NOT TO SELL a ticket for. We mean that conductor should choose C and D (С <= D) and sell a ticket for the segments [*A*, *C*] and [*D*, *B*], or not sell the ticket at all. The conductor and the passenger divide the saved money between themselves equally. The conductor's "untaxed income" is sometimes interrupted by inspections that take place as the bus drives on some segment of the route located between two consecutive stops. The inspector fines the conductor by *c* rubles for each passenger who doesn't have the ticket for this route's segment.

You know the coordinated of all stops *x**i*; the numbers of stops where the *i*-th passenger gets on and off, *a**i* and *b**i* (*a**i* < *b**i*); the fine *c*; and also *p**i* — the probability of inspection on segment between the *i*-th and the *i* + 1-th stop. The conductor asked you to help him make a plan of selling tickets that maximizes the mathematical expectation of his profit.

## Input

The first line contains three integers *n*, *m* and *c* (2 ≤ *n* ≤ 150 000, 1 ≤ *m* ≤ 300 000, 1 ≤ *c* ≤ 10 000).

The next line contains *n* integers *x**i* (0 ≤ *x**i* ≤ 109, *x*1 = 0, *x**i* < *x**i* + 1) — the coordinates of the stops on the bus's route.

The third line contains *n* - 1 integer *p**i* (0 ≤ *p**i* ≤ 100) — the probability of inspection in percents on the segment between stop *i* and stop *i* + 1.

Then follow *m* lines that describe the bus's passengers. Each line contains exactly two integers *a**i* and *b**i* (1 ≤ *a**i* < *b**i* ≤ *n*) — the numbers of stops where the *i*-th passenger gets on and off.

## Output

Print the single real number — the maximum expectation of the conductor's profit. Your answer will be considered correct if its absolute or relative error does not exceed 10- 6. 

Namely: let's assume that your answer is *a*, and the answer of the jury is *b*. The checker program will consider your answer correct, if ![](images/c97ba2000ebfad962bff7ffd8d043594f5ae1086.png).

## Examples

## Input


```
3 3 10  
0 10 100  
100 0  
1 2  
2 3  
1 3  

```
## Output


```
90.000000000  

```
## Input


```
10 8 187  
0 10 30 70 150 310 630 1270 2550 51100  
13 87 65 0 100 44 67 3 4  
1 10  
2 9  
3 8  
1 5  
6 10  
2 7  
4 10  
4 5  

```
## Output


```
76859.990000000  

```
## Note

A comment to the first sample:

The first and third passengers get tickets from stop 1 to stop 2. The second passenger doesn't get a ticket. There always is inspection on the segment 1-2 but both passengers have the ticket for it. There never is an inspection on the segment 2-3, that's why the second passenger gets away with the cheating. Our total profit is (0 + 90 / 2 + 90 / 2) = 90.



#### tags 

#2200 #data_structures #math #probabilities 