<h1 style='text-align: center;'> F. Fancy Stack</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Little Fiona has a collection of $n$ blocks of various sizes $a_1, a_2, \ldots, a_n$, where $n$ is even. Some of the blocks can be equal in size. She would like to put all these blocks one onto another to form a fancy stack.

Let $b_1, b_2, \ldots, b_n$ be the sizes of blocks in the stack from top to bottom. Since Fiona is using all her blocks, $b_1, b_2, \ldots, b_n$ must be a permutation of $a_1, a_2, \ldots, a_n$. Fiona thinks the stack is fancy if both of the following conditions are satisfied: 

* The second block is strictly bigger than the first one, and then each block is alternately strictly smaller or strictly bigger than the previous one. Formally, $b_1 < b_2 > b_3 < b_4 > \ldots > b_{n-1} < b_n$.
* The sizes of the blocks on even positions are strictly increasing. Formally, $b_2 < b_4 < b_6 < \ldots < b_n$ (remember that $n$ is even).

 ![](images/78acc006a228335ffd70a90ec720877d66ee165b.png) Two stacks are considered different if their corresponding sequences $b_1, b_2, \ldots, b_n$ differ in at least one position.

Fiona wants to know how many different fancy stacks she can build with all of her blocks. Since large numbers scare Fiona, find this number modulo $998\,244\,353$.

### Input

Each input contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 2500$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ — the number of blocks at Fiona's disposal ($2 \le n \le 5000$; $n$ is even). The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ — the sizes of the blocks in non-decreasing order ($1 \le a_1 \le a_2 \le \dotsb \le a_n \le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5000$.

### Output

For each test case, print the number of ways to build a fancy stack, modulo $998\,244\,353$.

## Example

### Input


```text
241 2 3 481 1 2 3 4 4 6 7
```
### Output

```text

2
4

```


#### Tags 

#2200 #NOT OK #combinatorics #dp #implementation 

## Blogs
- [All Contest Problems](../2021-2022_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement #2 (en)](../blogs/Announcement_2_(en).md)
