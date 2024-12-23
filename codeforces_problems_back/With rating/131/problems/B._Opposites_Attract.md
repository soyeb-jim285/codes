<h1 style='text-align: center;'> B. Opposites Attract</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Everybody knows that opposites attract. That is the key principle of the "Perfect Matching" dating agency. The "Perfect Matching" matchmakers have classified each registered customer by his interests and assigned to the *i*-th client number *t**i* ( - 10 ≤ *t**i* ≤ 10). Of course, one number can be assigned to any number of customers.

"Perfect Matching" wants to advertise its services and publish the number of opposite couples, that is, the couples who have opposite values of *t*. Each couple consists of exactly two clients. The customer can be included in a couple an arbitrary number of times. Help the agency and write the program that will find the sought number by the given sequence *t*1, *t*2, ..., *t**n*. For example, if *t* = (1,  - 1, 1,  - 1), then any two elements *t**i* and *t**j* form a couple if *i* and *j* have different parity. Consequently, in this case the sought number equals 4.

Of course, a client can't form a couple with him/herself.

## Input

The first line of the input data contains an integer *n* (1 ≤ *n* ≤ 105) which represents the number of registered clients of the "Couple Matching". The second line contains a sequence of integers *t*1, *t*2, ..., *t**n* ( - 10 ≤ *t**i* ≤ 10), *t**i* — is the parameter of the *i*-th customer that has been assigned to the customer by the result of the analysis of his interests.

## Output

Print the number of couples of customs with opposite *t*. The opposite number for *x* is number  - *x* (0 is opposite to itself). Couples that only differ in the clients' order are considered the same.

## Note

 that the answer to the problem can be large enough, so you must use the 64-bit integer type for calculations. Please, do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specificator.

## Examples

## Input


```
5  
-3 3 0 0 3  

```
## Output


```
3  

```
## Input


```
3  
0 0 0  

```
## Output


```
3  

```
## Note

In the first sample the couples of opposite clients are: (1,2), (1,5) и (3,4).

In the second sample any couple of clients is opposite.



#### tags 

#1200 #implementation #math 