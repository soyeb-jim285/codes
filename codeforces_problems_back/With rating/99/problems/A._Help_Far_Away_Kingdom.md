<h1 style='text-align: center;'> A. Help Far Away Kingdom</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a far away kingdom lived the King, the Prince, the Shoemaker, the Dressmaker and many other citizens. They lived happily until great trouble came into the Kingdom. The ACMers settled there.

Most damage those strange creatures inflicted upon the kingdom was that they loved high precision numbers. As a result, the Kingdom healers had already had three appointments with the merchants who were asked to sell, say, exactly 0.273549107 beer barrels. To deal with the problem somehow, the King issued an order obliging rounding up all numbers to the closest integer to simplify calculations. Specifically, the order went like this:

* If a number's integer part does not end with digit 9 and its fractional part is strictly less than 0.5, then the rounded up number coincides with the number’s integer part.
* If a number's integer part does not end with digit 9 and its fractional part is not less than 0.5, the rounded up number is obtained if we add 1 to the last digit of the number’s integer part.
* If the number’s integer part ends with digit 9, to round up the numbers one should go to Vasilisa the Wise. In the whole Kingdom she is the only one who can perform the tricky operation of carrying into the next position.

Merchants found the algorithm very sophisticated and they asked you (the ACMers) to help them. Can you write a program that would perform the rounding according to the King’s order?

## Input

The first line contains a single number to round up — the integer part (a non-empty set of decimal digits that do not start with 0 — with the exception of a case when the set consists of a single digit — in this case 0 can go first), then follows character «.» (a dot), and then follows the fractional part (any non-empty set of decimal digits). The number's length does not exceed 1000 characters, including the dot. There are no other characters in the input data.

## Output

If the last number of the integer part is not equal to 9, print the rounded-up number without leading zeroes. Otherwise, print the message "GOTO Vasilisa." (without the quotes).

## Examples

## Input


```
0.0  

```
## Output


```
0
```
## Input


```
1.49  

```
## Output


```
1
```
## Input


```
1.50  

```
## Output


```
2
```
## Input


```
2.71828182845904523536  

```
## Output


```
3
```
## Input


```
3.14159265358979323846  

```
## Output


```
3
```
## Input


```
12345678901234567890.1  

```
## Output


```
12345678901234567890
```
## Input


```
123456789123456789.999  

```
## Output


```
GOTO Vasilisa.
```


#### tags 

#800 #strings 