<h1 style='text-align: center;'> A. Colors</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Linda likes to change her hair color from time to time, and would be pleased if her boyfriend Archie would notice the difference between the previous and the new color. Archie always comments on Linda's hair color if and only if he notices a difference — so Linda always knows whether Archie has spotted the difference or not.

There is a new hair dye series in the market where all available colors are numbered by integers from $1$ to $N$ such that a smaller difference of the numerical values also means less visual difference.

Linda assumes that for these series there should be some critical color difference $C$ ($1 \le C \le N$) for which Archie will notice color difference between the current color $\mathrm{color}_{\mathrm{new}}$ and the previous color $\mathrm{color}_{\mathrm{prev}}$ if $\left|\mathrm{color}_{\mathrm{new}} - \mathrm{color}_{\mathrm{prev}}\right| \ge C$ and will not if $\left|\mathrm{color}_{\mathrm{new}} - \mathrm{color}_{\mathrm{prev}}\right| < C$.

Now she has bought $N$ sets of hair dye from the new series — one for each of the colors from $1$ to $N$, and is ready to set up an experiment. Linda will change her hair color on a regular basis and will observe Archie's reaction — whether he will notice the color change or not. Since for the proper dye each set should be used completely, each hair color can be obtained no more than once.

Before the experiment, Linda was using a dye from a different series which is not compatible with the new one, so for the clearness of the experiment Archie's reaction to the first used color is meaningless.

Her aim is to find the precise value of $C$ in a limited number of dyes. Write a program which finds the value of $C$ by experimenting with the given $N$ colors and observing Archie's reactions to color changes.

## Interaction

This is an interactive task. In the beginning you are given a single integer $T$ ($1 \leq T \leq 100$), the number of cases in the test.

For each test case, the input first contains a single integer — the value of $N$ ($1 < N \le 10^{18}$). The value of $C$ is kept secret by the grading system.

Then your program should make queries writing output in the following format: "? $P$", where $P$ is an integer ($1 \le P \le N$) denoting the next color used. For each query the grading system gives an answer in the next line of the input. The answer is $1$ if Archie notices the color difference between the last two colors and $0$ otherwise. No two queries should have the same $P$ value.

When your program determines $C$, it should output its value in the following format: "= $C$". The grading system will not respond to this output and will proceed with the next test case.

Your program may use at most 64 queries "?" for each test case to find the correct value of $C$.

To establish proper communication between your program and the grading system, you should flush the output stream after each query.

 $$\begin{array}{ll} \text{Language} & \text{Command} \\\ \hline \text{C++} & \texttt{std::cout }\texttt{<}\texttt{<}\texttt{ std::endl;} \\\ \text{Java} & \texttt{System.out.flush();} \\\ \text{Python} & \texttt{sys.stdout.flush()} \end{array}$$ Flush commands ## Note

 that std::endl writes a newline and flushes the stream.

It is possible to receive an "Output isn't correct" outcome even after printing a correct answer, if task constraints were violated during the communication. Violating the communication protocol itself may result in an "Execution killed" outcome.

Submitting user tests requires specifying an input file with the testcase parameters. The format of the input file is "$T$" in the first line, and then "$N$ $C$" on a single line for each of the $T$ cases.

## Scoring

Subtasks: 

1. (9 points) $N \le 64$
2. (13 points) $N \le 125$
3. (21 points) $N \le 1000$
4. (24 points) $N \le 10^9$
5. (33 points) No further constraints.
## Example

Input
```

1

7

1

1

0

0

1

```
Output
```


? 2

? 7

? 4

? 1

? 5

= 4
```
## Note

Comments to the example input line by line: 

1. $N = 7$.
2. Answer to the first query is meaningless (can also be $0$).
3. $C \leq 5$.
4. $3 < C \leq 5$. It would be wise to check difference $4$. However, this can not be done in the next query since $4 + 4 = 8$ and $4 - 4 = 0$ both are outside the allowed interval $1 \le P \le 7$.
5. $3 < C \leq 5$.
6. $3 < C \leq 4$. Therefore, $C = 4$.


#### tags 

#2700 #*special #binary_search #constructive_algorithms #interactive 