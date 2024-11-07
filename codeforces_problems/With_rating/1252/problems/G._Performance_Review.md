<h1 style='text-align: center;'> G. Performance Review</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Randall is a software engineer at a company with $N$ employees. Every year, the company re-evaluates its employees. At the end of every year, the company replaces its several worst-performing employees and replaces with the same number of new employees, so that the company keeps having $N$ employees. Each person has a constant performance and can be represented by an integer (higher integer means better performance), and no two people have the same performance.

The performance of the initial employees are represented by an array of integers $A = [A_1, A_2, \dots, A_N]$ where $A_i$ is the performance of the $i^{th}$ employee. Randall is employee $1$, so his performance is $A_1$. We will consider the first $M$ years. At the end of the $i^{th}$ year, the company replaces its $R_i$ worst-performing employees and replaces with $R_i$ new employees. The performance of these new employees are represented by an array of integers $B_i = [(B_i)_1, (B_i)_2, \dots, (B_i)_{R_i}]$ where $(B_i)_j$ is the performance of the $j^{th}$ new employee.

He will consider $Q$ scenarios. On the $i^{th}$ scenario, he will change the value of $(B_{X_i})_{Y_i}$ to $Z_i$. For each scenario, Randall is wondering whether he will still be in the company after $M$ years. 
## Note

 that the changes in each scenario are kept for the subsequent scenarios.

### Input

### Input

 begins with a line containing three integers: $N$ $M$ $Q$ ($2 \le N \le 100\,000$; $1 \le M, Q \le 100\,000$) representing the number of employees, the number of years to be considered, and the number of scenarios, respectively. The next line contains $N$ integers: $A_i$ ($0 \le A_i \le 10^9$) representing the performance of the initial employees. The next $M$ lines each contains several integers: $R_i$ $(B_i)_1$, $(B_i)_2$, $\cdots$, $(B_i)_{R_i}$ ($1 \le R_i < N$; $0 \le (B_i)_j \le 10^9$) representing the number of employees replaced and the performance of the new employees, respectively. It is guaranteed that the sum of $R_i$ does not exceed $10^6$. The next $Q$ lines each contains three integers: $X_i$ $Y_i$ $Z_i$ ($1 \le X_i \le M$; $1 \le Y_i \le R_{(X_i)}$; $0 \le Z_i \le 10^9$) representing a scenario. It is guaranteed that all integers in all $A_i$, $(B_i)_j$, and $Z_i$ (combined together) are distinct.

### Output

For each scenario in the same order as input, output in a line an integer $0$ if Randall will not be in the company after $M$ years, or $1$ if Randall will still be in the company after $M$ years.

## Example

### Input


```text
5 3 3
50 40 30 20 10
4 1 2 3 100
1 4
2 6 7
1 3 300
2 1 400
2 1 5
```
### Output


```text
1
0
1
```
## Note

Explanation for the sample input/output #1

Randall performance is represented by $50$. For the first scenario, the value of $(B_1)_3$ is updated to $300$, causes the following: 

* Initially, the performance of the employees is $[50, 40, 30, 20, 10]$.
* At the end of the first year, $4$ worst-performing employees are replaced by employees with performance $[300, 100, 2, 1]$. Therefore, the performance of the employees is $[300, 100, 50, 2, 1]$.
* At the end of the second year, the performance of the employees is $[300, 100, 50, 4, 2]$.
* At the end of the third year, the performance of the employees is $[300, 100, 50, 7, 6]$.

 Therefore, Randall will still be in the company after $3$ years.For the second scenario, the value of $(B_2)_1$ is updated to $400$, causes the following: 

* Initially, the performance of the employees is $[50, 40, 30, 20, 10]$.
* At the end of the first year, the performance of the employees is $[300, 100, 50, 2, 1]$. Recall that the change in the first scenario is kept for this scenario as well.
* At the end of the second year, the performance of the employees is $[400, 300, 100, 50, 2]$.
* At the end of the third year, the performance of the employees is $[400, 300, 100, 7, 6]$.

 Therefore, Randall will not be in the company after $3$ years.

#### Tags 

#2100 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../2019-2020_ICPC,_Asia_Jakarta_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
