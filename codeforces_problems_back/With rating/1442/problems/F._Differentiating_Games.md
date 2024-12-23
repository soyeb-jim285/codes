<h1 style='text-align: center;'> F. Differentiating Games</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem

Ginny is taking an exam on game theory. The professor is tired of hearing the same answers over and over again, so he offered Ginny to play a game instead of a standard exam. 

As known from the course, a combinatorial game on a graph with multiple starting positions is a game with a directed graph and multiple starting vertices holding a token each. Two players take turns moving one of the tokens along the graph edges on each turn. The player who can't make a move loses the game. If both players can play an infinitely long game without losing, a draw is called.

For the exam, the professor drew an acyclic directed graph and chose one of its vertices. Ginny needs to guess the vertex the professor chose. To do so, Ginny can choose a multiset of vertices $S$ several times and ask the professor: "If I put one token in each vertex of the given graph for each occurrence of the vertex in the multiset $S$, and then one more in the selected vertex, what would be the result of the combinatorial game?". 

Having given the task, the professor left the room to give Ginny some time to prepare for the game. Ginny thinks that she's being tricked because the problem is impossible to solve. Therefore, while the professor is away, she wants to add or remove several edges from the graph. Even though the original graph was acyclic, edges could be added to the graph to make cycles appear.

## Interaction

In this task, interaction consists of several phases.

In the first phase, the interactor gives as an input to your program three integers $N$ ($1 \le N \le 1000$), $M$ ($0 \le M \le 100\,000$), $T$ ($1 \le T \le 2000$): the number of vertices and edges in the initial graph, and the number of times Ginny has to guess the chosen vertex. The next $M$ lines contain pairs of vertices $a_i$ $b_i$ ($1 \le a_i, b_i \le N$): beginning and end of corresponding graph edges. The graph is guaranteed to be acyclic and all of its edges to be distinct.

The solution should print an integer $K$ ($0 \le K \le 4242$): the number of edges to change in the graph. The next $K$ lines should contain either "+ $a_i$ $b_i$" or "- $a_i$ $b_i$": the beginning and the end of an edge that Ginny has to add or remove accordingly. You are allowed to add preexisting edges to the graph. Operations are performed in the order of appearance, so Ginny is allowed to remove an edge added by the solution. You can only remove an existing edge. The operations can create cycles in the graph. 

The next $T$ phases are dedicated to guessing the chosen vertices. In each phase, the solution can make at most 20 queries and then print the answer. To query a multiset $S$, the solution should print "? $|S|~S_1~S_2~\dots~S_{|S|}$". The total size of all multisets in a single phase should not exceed 20. The interactor will reply with one of the following words: 

* "Win", if the winner of a combinatorial game with tokens in multiset $S$ and the selected vertex is the first player.
* "Lose", if the winner of a combinatorial game with tokens in multiset $S$ and the selected vertex is the second player.
* "Draw", if a combinatorial game with tokens in multiset $S$ and selected vertex ends in a draw.
* "Slow", if the solution made a 21-st request, or the total size of all multisets in a single phase exceeded 20. In this case, the solution should terminate and receive Wrong Answer verdict.

As soon as the selected vertex is guessed, that solution should print "! v". If the chosen vertex is guessed correctly, the interactor will print Correct and the solution should either move on to the next phase of guessing or finish its execution if it's the last phase. Otherwise, the interactor will print Wrong, which means that the solution should terminate and will receive the Wrong Answer verdict. 

The interactor can change the chosen vertex based on graph changes and solution actions, but at every given moment of time, at least one vertex that corresponds to all given interactor answers will exist. 

Hack format

Hacks have the following extra limitations: 

* $T = 1$
* you need to specify a single vertex, chosen by the interactor.

Hack test format. The first line of input contains three integers $N~M~1$. The next $M$ lines on input contain edge description in the same format as in the input. The next line contains a single integer $v$: the number of the chosen vertex. The hack will be successful even if the solution guesses the vertex right, but the vertex will not be the single one to match all performed queries.

## Example

Input
```

3 2 3
1 2
2 3

Lose

Correct

Win

Correct

Draw

Correct
```
Output
```

6
+ 2 2
- 1 2
+ 2 3
- 2 2
+ 3 1
+ 2 2
? 0

! 1

? 1 2

! 3

? 5 1 3 1 3 1

! 2
```
## Note

In the sample test, the empty lines represent waiting for the input by the other side of the interaction. The real interactor will not print empty lines, and the solution should not print them either. 

 ![](images/8df35feeaefb9caf3364e8bd7315ef9ff2eaed84.png) The image above illustrates the sample test. Added edges are coloured in red, and the removed edges are drawn with a dotted line. Three guessing phases denote different ways of getting the answer. 

* If the solution will query just the chosen vertex, the interactor will return the result of the game in that vertex. The first player loses only if the chosen vertex has the number $1$.
* If we add a single vertex $2$ to the chosen vertex, then if the chosen vertex is either $1$ or $2$, the game should end in a draw. If vertex number $3$ is chosen, then the first player wins.
* If we place three tokens in vertex $1$ and two tokens in vertex $3$, then the game will end in a draw only if vertex $2$ is chosen. If the professor chose vertex $3$, the first player will win, if the professor chose vertex $1$, then the second player will win.

In the first test, the interactor will behave as if the chosen vertices are the same as those in the example above. However, if you will try to guess the answer before it limits the options to one single vertex, the solution will get "Wrong Answer", even if you print the same answers. That's because the interactor is allowed to change the chosen vertex if it's consistent with the previous query answers.



#### tags 

#3400 #games #interactive 