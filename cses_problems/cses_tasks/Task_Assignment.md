![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Task Assignment

  * Task
  * Statistics

CSES - Task Assignment

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A company has $n$ employees and there are $n$ tasks that need to be done. We
know for each employee the cost of carrying out each task. Every employee
should be assigned to exactly one task. What is the minimum total cost if we
assign the tasks optimally and how could they be assigned?

# Input

The first input line has one integer $n$: the number of employees and the
number of tasks that need to be done.

After this, there are $n$ lines each consisting of $n$ integers. The $i$th
line consists of integers $c_{i1},c_{i2},\ldots,c_{in}$: the cost of each task
when it is assigned to the $i$th employee.

# Output

First print the minimum total cost.

Then print $n$ lines each consisting of two integers $a$ and $b$: you assign
the $b$th task to the $a$th employee.

If there are multiple solutions you can print any of them.

# Constraints

  * $1 \le n \le 200$
  * $1 \le c_{ij} \le 1000$

# Example

Input:

``` 4 17 8 16 9 7 15 12 19 6 9 10 11 14 7 13 10 ```

Output:

``` 33 1 4 2 1 3 3 4 2 ```

Explanation: The minimum total cost is $33$. We can reach this by assigning
employee 1 task 4, employee 2 task 1, employee 3 task 3 and employee 4 task 2.
This will cost $9 + 7 + 10 + 7 = 33$.

#### Advanced Techniques

... Apples and BananasOne Bit PositionsSignal ProcessingNew Roads
QueriesDynamic ConnectivityParcel DeliveryTask AssignmentDistinct Routes II

* * *

