<h1 style='text-align: center;'> D. Michael and Charging Stations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Michael has just bought a new electric car for moving across city. Michael does not like to overwork, so each day he drives to only one of two his jobs.

Michael's day starts from charging his electric car for getting to the work and back. He spends 1000 burles on charge if he goes to the first job, and 2000 burles if he goes to the second job.

On a charging station he uses there is a loyalty program that involves bonus cards. Bonus card may have some non-negative amount of bonus burles. Each time customer is going to buy something for the price of *x* burles, he is allowed to pay an amount of *y* (0 ≤ *y* ≤ *x*) burles that does not exceed the bonus card balance with bonus burles. In this case he pays *x* - *y* burles with cash, and the balance on the bonus card is decreased by *y* bonus burles. 

If customer pays whole price with cash (i.e., *y* = 0) then 10% of price is returned back to the bonus card. This means that bonus card balance increases by ![](images/eb16c378f5a5e33f1d0910e36532bb6a46bc4db8.png) bonus burles. Initially the bonus card balance is equal to 0 bonus burles.

Michael has planned next *n* days and he knows how much does the charge cost on each of those days. Help Michael determine the minimum amount of burles in cash he has to spend with optimal use of bonus card. Assume that Michael is able to cover any part of the price with cash in any day. It is not necessary to spend all bonus burles at the end of the given period.

## Input

The first line of input contains a single integer *n* (1 ≤ *n* ≤ 300 000), the number of days Michael has planned.

Next line contains *n* integers *a*1, *a*2, ..., *a**n* (*a**i* = 1000 or *a**i* = 2000) with *a**i* denoting the charging cost at the day *i*.

## Output

## Output

 the minimum amount of burles Michael has to spend.

## Examples

## Input


```
3  
1000 2000 1000  

```
## Output


```
3700  

```
## Input


```
6  
2000 2000 2000 2000 2000 1000  

```
## Output


```
10000  

```
## Note

In the first sample case the most optimal way for Michael is to pay for the first two days spending 3000 burles and get 300 bonus burles as return. After that he is able to pay only 700 burles for the third days, covering the rest of the price with bonus burles.

In the second sample case the most optimal way for Michael is to pay the whole price for the first five days, getting 1000 bonus burles as return and being able to use them on the last day without paying anything in cash.



#### tags 

#2400 #binary_search #dp #greedy 