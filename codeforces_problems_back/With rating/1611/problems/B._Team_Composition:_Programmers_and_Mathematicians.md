<h1 style='text-align: center;'> B. Team Composition: Programmers and Mathematicians</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The All-Berland Team Programming Contest will take place very soon. This year, teams of four are allowed to participate.

There are $a$ programmers and $b$ mathematicians at Berland State University. How many maximum teams can be made if:

* each team must consist of exactly $4$ students,
* teams of $4$ mathematicians or $4$ programmers are unlikely to perform well, so the decision was made not to compose such teams.

Thus, each team must have at least one programmer and at least one mathematician.

Print the required maximum number of teams. Each person can be a member of no more than one team.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) —the number of test cases.

This is followed by descriptions of $t$ sets, one per line. Each set is given by two integers $a$ and $b$ ($0 \le a,b \le 10^9$).

## Output

Print $t$ lines. Each line must contain the answer to the corresponding set of input data — the required maximum number of teams.

## Example

## Input


```

6
5 5
10 1
2 3
0 0
17 2
1000000000 1000000000

```
## Output


```

2
1
1
0
2
500000000

```
## Note

In the first test case of the example, two teams can be composed. One way to compose two teams is to compose two teams of $2$ programmers and $2$ mathematicians.

In the second test case of the example, only one team can be composed: $3$ programmers and $1$ mathematician in the team.



#### tags 

#800 #binary_search #constructive_algorithms #math 