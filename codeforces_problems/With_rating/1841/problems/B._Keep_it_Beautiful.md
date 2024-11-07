<h1 style='text-align: center;'> B. Keep it Beautiful</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

The array $[a_1, a_2, \dots, a_k]$ is called beautiful if it is possible to remove several (maybe zero) elements from the beginning of the array and insert all these elements to the back of the array in the same order in such a way that the resulting array is sorted in non-descending order.

In other words, the array $[a_1, a_2, \dots, a_k]$ is beautiful if there exists an integer $i \in [0, k-1]$ such that the array $[a_{i+1}, a_{i+2}, \dots, a_{k-1}, a_k, a_1, a_2, \dots, a_i]$ is sorted in non-descending order.

For example:

* $[3, 7, 7, 9, 2, 3]$ is beautiful: we can remove four first elements and insert them to the back in the same order, and we get the array $[2, 3, 3, 7, 7, 9]$, which is sorted in non-descending order;
* $[1, 2, 3, 4, 5]$ is beautiful: we can remove zero first elements and insert them to the back, and we get the array $[1, 2, 3, 4, 5]$, which is sorted in non-descending order;
* $[5, 2, 2, 1]$ is not beautiful.

## Note

 that any array consisting of zero elements or one element is beautiful.

You are given an array $a$, which is initially empty. You have to process $q$ queries to it. During the $i$-th query, you will be given one integer $x_i$, and you have to do the following:

* if you can append the integer $x_i$ to the back of the array $a$ so that the array $a$ stays beautiful, you have to append it;
* otherwise, do nothing.

After each query, report whether you appended the given integer $x_i$, or not.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries. The second line contains $q$ integers $x_1, x_2, \dots, x_q$ ($0 \le x_i \le 10^9$).

Additional constraint on the input: the sum of $q$ over all test cases does not exceed $2 \cdot 10^5$).

### Output

For each test case, print one string consisting of exactly $q$ characters. The $i$-th character of the string should be 1 if you appended the integer during the $i$-th query; otherwise, it should be 0.

## Example

### Input


```text
393 7 7 9 2 4 6 3 451 1 1 1 153 2 1 2 3
```
### Output

```text

111110010
11111
11011

```
## Note

Consider the first test case of the example. Initially, the array is $[]$.

* trying to append an integer $3$. The array $[3]$ is beautiful, so we append $3$;
* trying to append an integer $7$. The array $[3, 7]$ is beautiful, so we append $7$;
* trying to append an integer $7$. The array $[3, 7, 7]$ is beautiful, so we append $7$;
* trying to append an integer $9$. The array $[3, 7, 7, 9]$ is beautiful, so we append $9$;
* trying to append an integer $2$. The array $[3, 7, 7, 9, 2]$ is beautiful, so we append $2$;
* trying to append an integer $4$. The array $[3, 7, 7, 9, 2, 4]$ is not beautiful, so we don't append $4$;
* trying to append an integer $6$. The array $[3, 7, 7, 9, 2, 6]$ is not beautiful, so we don't append $6$;
* trying to append an integer $3$. The array $[3, 7, 7, 9, 2, 3]$ is beautiful, so we append $3$;
* trying to append an integer $4$. The array $[3, 7, 7, 9, 2, 3, 4]$ is not beautiful, so we don't append $4$.


#### Tags 

#1000 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_150_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
