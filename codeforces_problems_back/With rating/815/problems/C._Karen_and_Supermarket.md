<h1 style='text-align: center;'> C. Karen and Supermarket</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

On the way home, Karen decided to stop by the supermarket to buy some groceries.

 ![](images/81dd125b7f62dae31b785bdf2ec388da248f59eb.png) She needs to buy a lot of goods, but since she is a student her budget is still quite limited. In fact, she can only spend up to *b* dollars.

The supermarket sells *n* goods. The *i*-th good can be bought for *c**i* dollars. Of course, each good can only be bought once.

Lately, the supermarket has been trying to increase its business. Karen, being a loyal customer, was given *n* coupons. If Karen purchases the *i*-th good, she can use the *i*-th coupon to decrease its price by *d**i*. Of course, a coupon cannot be used without buying the corresponding good.

There is, however, a constraint with the coupons. For all *i* ≥ 2, in order to use the *i*-th coupon, Karen must also use the *x**i*-th coupon (which may mean using even more coupons to satisfy the requirement for that coupon).

Karen wants to know the following. What is the maximum number of goods she can buy, without exceeding her budget *b*?

## Input

The first line of input contains two integers *n* and *b* (1 ≤ *n* ≤ 5000, 1 ≤ *b* ≤ 109), the number of goods in the store and the amount of money Karen has, respectively.

The next *n* lines describe the items. Specifically:

* The *i*-th line among these starts with two integers, *c**i* and *d**i* (1 ≤ *d**i* < *c**i* ≤ 109), the price of the *i*-th good and the discount when using the coupon for the *i*-th good, respectively.
* If *i* ≥ 2, this is followed by another integer, *x**i* (1 ≤ *x**i* < *i*), denoting that the *x**i*-th coupon must also be used before this coupon can be used.
## Output

## Output

 a single integer on a line by itself, the number of different goods Karen can buy, without exceeding her budget.

## Examples

## Input


```
6 16  
10 9  
10 5 1  
12 2 1  
20 18 3  
10 2 3  
2 1 5  

```
## Output


```
4  

```
## Input


```
5 10  
3 1  
3 1 1  
3 1 2  
3 1 3  
3 1 4  

```
## Output


```
5  

```
## Note

In the first test case, Karen can purchase the following 4 items:

* Use the first coupon to buy the first item for 10 - 9 = 1 dollar.
* Use the third coupon to buy the third item for 12 - 2 = 10 dollars.
* Use the fourth coupon to buy the fourth item for 20 - 18 = 2 dollars.
* Buy the sixth item for 2 dollars.

The total cost of these goods is 15, which falls within her budget. ## Note

, for example, that she cannot use the coupon on the sixth item, because then she should have also used the fifth coupon to buy the fifth item, which she did not do here.

In the second test case, Karen has enough money to use all the coupons and purchase everything.



#### tags 

#2400 #brute_force #dp #trees 