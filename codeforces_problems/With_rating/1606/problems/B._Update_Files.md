<h1 style='text-align: center;'> B. Update Files</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland State University has received a new update for the operating system. Initially it is installed only on the $1$-st computer.

Update files should be copied to all $n$ computers. The computers are not connected to the internet, so the only way to transfer update files from one computer to another is to copy them using a patch cable (a cable connecting two computers directly). Only one patch cable can be connected to a computer at a time. Thus, from any computer where the update files are installed, they can be copied to some other computer in exactly one hour.

Your task is to find the minimum number of hours required to copy the update files to all $n$ computers if there are only $k$ patch cables in Berland State University.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

Each test case consists of a single line that contains two integers $n$ and $k$ ($1 \le k \le n \le 10^{18}$) — the number of computers and the number of patch cables.

### Output

For each test case print one integer — the minimum number of hours required to copy the update files to all $n$ computers.

## Example

### Input


```text
4
8 3
6 6
7 1
1 1
```
### Output


```text
4
3
6
0
```
## Note

Let's consider the test cases of the example:

* $n=8$, $k=3$:
	1. during the first hour, we copy the update files from the computer $1$ to the computer $2$;
	2. during the second hour, we copy the update files from the computer $1$ to the computer $3$, and from the computer $2$ to the computer $4$;
	3. during the third hour, we copy the update files from the computer $1$ to the computer $5$, from the computer $2$ to the computer $6$, and from the computer $3$ to the computer $7$;
	4. during the fourth hour, we copy the update files from the computer $2$ to the computer $8$.
* $n=6$, $k=6$:
	1. during the first hour, we copy the update files from the computer $1$ to the computer $2$;
	2. during the second hour, we copy the update files from the computer $1$ to the computer $3$, and from the computer $2$ to the computer $4$;
	3. during the third hour, we copy the update files from the computer $1$ to the computer $5$, and from the computer $2$ to the computer $6$.
* $n=7$, $k=1$:
	1. during the first hour, we copy the update files from the computer $1$ to the computer $2$;
	2. during the second hour, we copy the update files from the computer $1$ to the computer $3$;
	3. during the third hour, we copy the update files from the computer $1$ to the computer $4$;
	4. during the fourth hour, we copy the update files from the computer $4$ to the computer $5$;
	5. during the fifth hour, we copy the update files from the computer $4$ to the computer $6$;
	6. during the sixth hour, we copy the update files from the computer $3$ to the computer $7$.


#### Tags 

#1100 #OK #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_116_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
