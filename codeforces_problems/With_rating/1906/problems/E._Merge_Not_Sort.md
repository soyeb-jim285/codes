<h1 style='text-align: center;'> E. Merge Not Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are currently researching the Merge Sort algorithm. Merge Sort is a sorting algorithm that is based on the principle of Divide and Conquer. It works by dividing an array into two subarrays of equal length, sorting each subarrays, then merging the sorted subarrays back together to form the final sorted array.

You are particularly interested in the merging routine. Common merge implementation will combine two subarrays by iteratively comparing their first elements, and move the smaller one to a new merged array. More precisely, the merge algorithm can be presented by the following pseudocode.


```text
  
    Merge(A[1..N], B[1..N]):  
        C = []  
        i = 1  
        j = 1  
        while i <= N AND j <= N:  
            if A[i] < B[j]:  
                append A[i] to C  
                i = i + 1  
            else:  
                append B[j] to C  
                j = j + 1   
        while i <= N:  
            append A[i] to C  
            i = i + 1   
        while j <= N:  
            append B[j] to C  
            j = j + 1   
        return C  

```
During your research, you are keen to understand the behaviour of the merge algorithm when arrays $A$ and $B$ are not necessarily sorted. For example, if $A = [3, 1, 6]$ and $B = [4, 5, 2]$, then $\text{Merge}(A, B) = [3, 1, 4, 5, 2, 6]$.

To further increase the understanding of the merge algorithm, you decided to work on the following problem. You are given an array $C$ of length $2 \cdot N$ such that it is a permutation of $1$ to $2 \cdot N$. Construct any two arrays $A$ and $B$ of the same length $N$, such that $\text{Merge}(A, B) = C$, or determine if it is impossible to do so.

##### Input

The first line consists of an integer $N$ ($1 \leq N \leq 1000$).

The following line consists of $2 \cdot N$ integers $C_i$. The array $C$ is a permutation of $1$ to $2 \cdot N$.

##### Output

If it is impossible to construct two arrays $A$ and $B$ of length $N$ such that $\text{Merge}(A, B) = C$, then output -1.

Otherwise, output the arrays $A$ and $B$ in two lines. The first line consists of $N$ integers $A_i$. The second line consists of $N$ integers $B_i$. If there are several possible answers, output any of them.

## Examples

##### Input


```text
3
3 1 4 5 2 6
```
##### Output


```text
3 1 6
4 5 2
```
##### Input

```text

4
1 2 3 4 5 6 7 8

```
##### Output


```text
2 3 5 7
1 4 6 8
```
##### Input

```text

2
4 3 2 1

```
##### Output


```text

-1
```
## Note

Explanation for the sample input/output #1

The solution $A = [3, 1, 4]$ and $B = [5, 2, 6]$ is also correct. 

Explanation for the sample input/output #2

The solution $A = [1, 2, 3, 4]$ and $B = [5, 6, 7, 8]$ is also correct. 



#### Tags 

#1900 #NOT OK #constructive_algorithms #dp 

## Blogs
- [All Contest Problems](../2023-2024_ICPC,_Asia_Jakarta_Regional_Contest_(Online_Mirror,_Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
