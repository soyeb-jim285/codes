<h1 style='text-align: center;'> F. Mobile Communications</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sum of *p* rubles is charged from Arkady's mobile phone account every day in the morning. Among the following *m* days, there are *n* days when Arkady will top up the account: in the day *d**i* he will deposit *t**i* rubles on his mobile phone account. Arkady will always top up the account before the daily payment will be done. There will be no other payments nor tops up in the following *m* days.

Determine the number of days starting from the 1-st to the *m*-th such that the account will have a negative amount on it after the daily payment (i. e. in evening). Initially the account's balance is zero rubles.

## Input

The first line contains three integers *n*, *p* and *m* (1 ≤ *n* ≤ 100 000, 1 ≤ *p* ≤ 109, 1 ≤ *m* ≤ 109, *n* ≤ *m*) — the number of days Arkady will top up the account, the amount of the daily payment, and the number of days you should check.

The *i*-th of the following *n* lines contains two integers *d**i* and *t**i* (1 ≤ *d**i* ≤ *m*, 1 ≤ *t**i* ≤ 109) — the index of the day when Arkady will make the *i*-th top up, and the amount he will deposit on this day. It is guaranteed that the indices of the days are distinct and are given in increasing order, i. e. *d**i* > *d**i* - 1 for all *i* from 2 to *n*.

## Output

Print the number of days from the 1-st to the *m*-th such that the account will have a negative amount on it after the daily payment.

## Examples

## Input


```
3 6 7  
2 13  
4 20  
7 9  

```
## Output


```
3  

```
## Input


```
5 4 100  
10 70  
15 76  
21 12  
30 100  
67 85  

```
## Output


```
26  

```
## Note

In the first example the balance will change as following (remember, initially the balance is zero):

1. in the first day 6 rubles will be charged, the balance in the evening will be equal to  - 6;
2. in the second day Arkady will deposit 13 rubles, then 6 rubles will be charged, the balance in the evening will be equal to 1;
3. in the third day 6 rubles will be charged, the balance in the evening will be equal to  - 5;
4. in the fourth day Arkady will deposit 20 rubles, then 6 rubles will be charged, the balance in the evening will be equal to 9;
5. in the fifth day 6 rubles will be charged, the balance in the evening will be equal to 3;
6. in the sixth day 6 rubles will be charged, the balance in the evening will be equal to  - 3;
7. in the seventh day Arkady will deposit 9 rubles, then 6 rubles will be charged, the balance in the evening will be equal to 0.

Thus, in the end of the first, third and sixth days the balance will be negative in the end of the day.



#### tags 

#2000 