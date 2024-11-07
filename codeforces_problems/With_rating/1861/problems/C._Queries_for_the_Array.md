<h1 style='text-align: center;'> C. Queries for the Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp had an array $a$ consisting of integers. Initially, this array was empty.

Monocarp performed three types of queries to this array:

* choose an integer and append it to the end of the array. Each time Monocarp performed a query of this type, he wrote out a character +;
* remove the last element from the array. Each time Monocarp performed a query of this type, he wrote out a character -. Monocarp never performed this query on an empty array;
* check if the array is sorted in non-descending order, i.,e. $a_1 \le a_2 \le \dots \le a_k$, where $k$ is the number of elements in the array currently. Every array with less than $2$ elements is considered sorted. If the array was sorted by the time Monocarp was performing that query, he wrote out a character 1. Otherwise, he wrote out a character 0.

You are given a sequence $s$ of $q$ characters 0, 1, + and/or -. These are the characters that were written out by Monocarp, given in the exact order he wrote them out.

You have to check if this sequence is consistent, i. e. it was possible for Monocarp to perform the queries so that the sequence of characters he wrote out is exactly $s$.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of one line containing the string $s$ ($1 \le |s| \le 2 \cdot 10^5$). This string consists of characters 0, 1, + and/or -. This is the sequence of characters written by Monocarp, in the order he wrote them.

Additional constraints on the input: 

* for every prefix of $s$, the number of characters + on it is not less than the number of characters - on it. In other words, if Monocarp actually performed these queries, he would never try to remove the last element from the empty array;
* the sum of $|s|$ over all test cases does not exceed $2 \cdot 10^5$.
### Output

For each test case, print YES if it was possible for Monocarp to perform the queries so that the sequence of characters he wrote is exactly $s$. Otherwise, print NO.

You can print each letter in any register.

## Example

### Input


```text
7++1+++1--0+00++0-+1-+0++0+-1+-0+1-+0
```
### Output

```text

YES
NO
NO
NO
YES
NO
NO

```
## Note

In the first test case, Monocarp could perform the following sequence of queries:

* add the integer $13$;
* add the integer $37$;
* check that the current array $[13, 37]$ is sorted in non-descending order (and it is sorted).

In the fifth test case, Monocarp could perform the following sequence of queries:

* add the integer $3$;
* add the integer $2$;
* check that the current array $[3, 2]$ is sorted (it is not);
* remove the last element;
* add the integer $3$;
* check that the current array $[3, 3]$ is sorted (it is);
* remove the last element;
* add the integer $-5$;
* check that the current array $[3, -5]$ is sorted (it is not).

In all other test cases of the example test, it is impossible for Monocarp to write the sequence $s$ when performing the queries according to the statement.



#### Tags 

#1600 #OK #data_structures #dfs_and_similar #implementation #strings #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_154_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
