<h1 style='text-align: center;'> A. Fill in the Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an empty matrix $M$ of size $n\times m$.

Zhongkao examination is over, and Daniel would like to do some puzzle games. He is going to fill in the matrix $M$ using permutations of length $m$. That is, each row of $M$ must be a permutation of length $m^\dagger$.

Define the value of the $i$-th column in $M$ as $v_i=\operatorname{MEX}(M_{1,i},M_{2,i},\ldots,M_{n,i})^\ddagger$. Since Daniel likes diversity, the beauty of $M$ is $s=\operatorname{MEX}(v_1,v_2,\cdots,v_m)$.

You have to help Daniel fill in the matrix $M$ and maximize its beauty.

$^\dagger$ A permutation of length $m$ is an array consisting of $m$ distinct integers from $0$ to $m-1$ in arbitrary order. For example, $[1,2,0,4,3]$ is a permutation, but $[0,1,1]$ is not a permutation ($1$ appears twice in the array), and $[0,1,3]$ is also not a permutation ($m-1=2$ but there is $3$ in the array).

$^\ddagger$ The $\operatorname{MEX}$ of an array is the smallest non-negative integer that does not belong to the array. For example, $\operatorname{MEX}(2,2,1)=0$ because $0$ does not belong to the array, and $\operatorname{MEX}(0,3,1,2)=4$ because $0$, $1$, $2$ and $3$ appear in the array, but $4$ does not.

### Input

The first line of input contains a single integer $t$ ($1\le t\le 1000$) — the number of test cases. The description of test cases follows.

The only line of each test case contains two integers $n$ and $m$ ($1\le n,m\le 2\cdot 10^5$) — the size of the matrix.

It is guaranteed that the sum of $n\cdot m$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, in the first line output a single integer — the maximum beauty of $M$.

Then output the matrix $M$ of size $n\times m$ — the matrix you find.

If there are multiple solutions, you may output any of them.

## Example

### Input


```text
44 31 166 62 1
```
### Output

```text

3
1 0 2
0 2 1
1 0 2
0 2 1
2
14 7 15 4 10 0 8 6 1 2 3 5 9 11 12 13 
6
3 0 1 4 2 5 
5 2 1 0 4 3 
1 3 2 4 5 0 
4 1 3 2 5 0 
4 2 5 3 0 1 
2 4 0 5 1 3
0
0
0
```
## Note

In the first test case:

* $v_1=\operatorname{MEX}(1,0,1,0)=2$;
* $v_2=\operatorname{MEX}(0,2,0,2)=1$;
* $v_3=\operatorname{MEX}(2,1,2,1)=0$.

Therefore, $s=\operatorname{MEX}(2,1,0)=3$. 

It can be shown that $3$ is the maximum possible beauty of $M$.

In the second test case, any permutation will make $s=2$.

In the third test case:

* $v_1=\operatorname{MEX}(3,5,1,4,4,2)=0$;
* $v_2=\operatorname{MEX}(0,2,3,1,2,4)=5$;
* $v_3=\operatorname{MEX}(1,1,2,3,5,0)=4$;
* $v_4=\operatorname{MEX}(4,0,4,2,3,5)=1$;
* $v_5=\operatorname{MEX}(2,4,5,5,0,1)=3$;
* $v_6=\operatorname{MEX}(5,3,0,0,1,3)=2$.

Therefore, $s=\operatorname{MEX}(0,5,4,1,3,2)=6$. 



#### Tags 

#1300 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_896_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
