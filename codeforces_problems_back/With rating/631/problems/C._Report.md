<h1 style='text-align: center;'> C. Report</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Each month Blake gets the report containing main economic indicators of the company "Blake Technologies". There are *n* commodities produced by the company. For each of them there is exactly one integer in the final report, that denotes corresponding revenue. Before the report gets to Blake, it passes through the hands of *m* managers. Each of them may reorder the elements in some order. Namely, the *i*-th manager either sorts first *r**i* numbers in non-descending or non-ascending order and then passes the report to the manager *i* + 1, or directly to Blake (if this manager has number *i* = *m*).

Employees of the "Blake Technologies" are preparing the report right now. You know the initial sequence *a**i* of length *n* and the description of each manager, that is value *r**i* and his favourite order. You are asked to speed up the process and determine how the final report will look like.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 200 000) — the number of commodities in the report and the number of managers, respectively.

The second line contains *n* integers *a**i* (|*a**i*| ≤ 109) — the initial report before it gets to the first manager.

Then follow *m* lines with the descriptions of the operations managers are going to perform. The *i*-th of these lines contains two integers *t**i* and *r**i* (![](images/4c7c768da8395489b31f8f3db90a6fe799bdeb0f.png), 1 ≤ *r**i* ≤ *n*), meaning that the *i*-th manager sorts the first *r**i* numbers either in the non-descending (if *t**i* = 1) or non-ascending (if *t**i* = 2) order.

## Output

Print *n* integers — the final report, which will be passed to Blake by manager number *m*.

## Examples

## Input


```
3 1  
1 2 3  
2 2  

```
## Output


```
2 1 3 
```
## Input


```
4 2  
1 2 4 3  
2 3  
1 2  

```
## Output


```
2 4 1 3 
```
## Note

In the first sample, the initial report looked like: 1 2 3. After the first manager the first two numbers were transposed: 2 1 3. The report got to Blake in this form.

In the second sample the original report was like this: 1 2 4 3. After the first manager the report changed to: 4 2 1 3. After the second manager the report changed to: 2 4 1 3. This report was handed over to Blake.



#### tags 

#1700 #data_structures #sortings 