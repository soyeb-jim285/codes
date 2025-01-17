<h1 style='text-align: center;'> C. Hiring Staff</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A new Berland businessman Vitaly is going to open a household appliances' store. All he's got to do now is to hire the staff.

The store will work seven days a week, but not around the clock. Every day at least *k* people must work in the store.

Berland has a law that determines the order of working days and non-working days. Namely, each employee must work for exactly *n* consecutive days, then rest for exactly *m* days, then work for *n* more days and rest for *m* more, and so on. Vitaly doesn't want to break the law. Fortunately, there is a loophole: the law comes into force on the day when the employee is hired. For example, if an employee is hired on day *x*, then he should work on days [*x*, *x* + 1, ..., *x* + *n* - 1], [*x* + *m* + *n*, *x* + *m* + *n* + 1, ..., *x* + *m* + 2*n* - 1], and so on. Day *x* can be chosen arbitrarily by Vitaly.

There is one more thing: the key to the store. Berland law prohibits making copies of keys, so there is only one key. Vitaly is planning to entrust the key to the store employees. At the same time on each day the key must be with an employee who works that day — otherwise on this day no one can get inside the store. During the day the key holder can give the key to another employee, if he also works that day. The key will handed to the first hired employee at his first working day.

Each employee has to be paid salary. Therefore, Vitaly wants to hire as few employees as possible provided that the store can operate normally on each day from 1 to infinity. In other words, on each day with index from 1 to infinity, the store must have at least *k* working employees, and one of the working employees should have the key to the store.

Help Vitaly and determine the minimum required number of employees, as well as days on which they should be hired.

## Input

The first line contains three integers *n*, *m* and *k* (1 ≤ *m* ≤ *n* ≤ 1000, *n* ≠ 1, 1 ≤ *k* ≤ 1000).

## Output

In the first line print a single integer *z* — the minimum required number of employees.

In the second line print *z* positive integers, separated by spaces: the *i*-th integer *a**i* (1 ≤ *a**i* ≤ 104) should represent the number of the day, on which Vitaly should hire the *i*-th employee.

If there are multiple answers, print any of them.

## Examples

## Input


```
4 3 2  

```
## Output


```
4  
1 1 4 5
```
## Input


```
3 3 1  

```
## Output


```
3  
1 3 5
```


#### tags 

#1800 #greedy 