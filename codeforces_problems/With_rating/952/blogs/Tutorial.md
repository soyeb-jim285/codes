# Tutorial


#### [952A - Quirky Quantifiers](../problems/A._Quirky_Quantifiers.md "April Fools Contest 2018")

JAPE riddle generator is a program which can produce question-answer puns. This problem has been inspired by one of the witticisms produced by it:

What do you call a quirky quantifier? An odd number.

All you had to do was to check whether the given "quantifier" was "quirky".

#### [952B - A Map of the Cat](../problems/B._A_Map_of_the_Cat.md "April Fools Contest 2018")

This problem was inspired by the awesome book "Surely You're Joking, Mr. Feynman!" In one of his stories Feynman asks a librarian to fetch him a map of a cat, having a zoological chart in mind. Of course, such a serious interpretation was unsuitable for my purposes :-)

This was a perfectly straightforward problem: just pet the cat! If the reaction you get is "no", try a different spot, otherwise you can figure out what kind of a cat this is right away. Just make sure you're not carried away: both kinds of cats get bored after 7th attempt to pet them and send you away without letting you guess their kind.

One thing I didn't take into account was that interactive problems are very rare on Codeforces, so this problem turned out to be much harder than the next one.

#### [952C - Ravioli Sort](../problems/C._Ravioli_Sort.md "April Fools Contest 2018")

Let's call the row of stacks "stable" if each adjacent pair of stacks in it differs in height by at most one (so no ravioli are going to slide to a different stack). It is easy to show that if a row is stable, then after removal of the tallest stack the resulting row is also stable. Indeed, after removing stack *a**i* the only new pair of adjacent stacks is *a**i* - 1 and *a**i* + 1. The row was stable, so |*a**i* - *a**i* - 1| ≤ 1 and |*a**i* - *a**i* + 1| ≤ 1. But *a**i* was the tallest stack, so *a**i* - 1 ≤ *a**i* - 1, *a**i* + 1 ≤ *a**i*. Thus the difference in height between *a**i* - 1 and *a**i* + 1 is at most 1, and the resulting row is also stable.

This means that the output will be correct if and only if the original array was stable (obviously, if the original array was not stable, at least one of the stacks would change even before the first tallest stack is chosen, and once some stacks change it's impossible to fix all of them).

#### [952D - I'm Feeling Lucky!](../problems/D._I'm_Feeling_Lucky!.md "April Fools Contest 2018")

Do you know how an actual roulette works? Each time you play, the winning number is different (even if you bet on the same number). It was exactly the same in this problem: each time the solution runs, it needs to guess a different winning number. There were two tests, so you have to make a winning bet twice.

This problem required a little exploration and out-of-the-box thinking. It is really hard to win betting on a number or even on two numbers (although I've seen a submission which got 26 on both tests). But you don't need to win big, you need just to win — so why not try bets with higher probability of winning, like "red" or "even"? The checker supported a variety of bets as was shown on the picture, so you just had to explore a little.

#### [952E - Cheese Board](../problems/E._Cheese_Board.md "April Fools Contest 2018")

This problem was inspired by the first line of Wikipedia article [Chessboard](https://codeforces.com/https://en.wikipedia.org/wiki/Chessboard): "Not to be confused with cheese board". Indeed, cheese board, chess board, what's the difference really? :-)

The image in the statement showed a bunch of cheeses (from the first example) arranged in a chessboard pattern, with soft cheeses representing one "color" of the squares and hard cheeses representing the other. The task was to find out the smallest size of a square "chessboard" on which the given cheeses could be arranged in such a way that soft and hard cheeses would alternate, and cheeses of the same type would never occupy adjacent squares.

Once you've figured out the task, the solution is very straightforward. First, count the numbers of soft and hard cheeses. Iterate through the sizes of the chessboard, starting with 1, and for each size count the number of black and white cells on it. If the number of black cells is greater than or equal to the number of hard cheeses and the number of white cells is greater than or equal to the number of soft cheeses or vice versa, return this size of the board.

#### [952F - 2 + 2 != 4](../problems/F._2_+_2_!=_4.md "April Fools Contest 2018")

This problem is based on a real bug in the checker for problem [784G - BF Calculator](https://codeforces.com/contest/784/problem/G "April Fools Contest 2017"). Fortunately, we caught it before the contest, which is why I can laugh about it today :-) 

The checker successfully iterated through the characters of the expression and accumulated them into a "current number" variable to add it to the result or to subtract it from the result. But due to a missing check in current number accumulation plus and minus characters were also counted as digits of the number. In "2+2" example, the first number was correctly interpreted as 2, but for the second one the first digit was ('+'-'0') = -5, and so the second number was interpreted as (-5)*10 + 2 = -48. Minus sign would be interpreted as an extra leading ('-'-'0') = -3 "digit".

The solution follows:

 
```cpp
long long result = 0, cur = 0;
expr += "+";
int sign = +1;
for (char c : expr) {
    if (c == '+' || c == '-') {
        result += sign * cur;
        cur = 0;
    }
    if (c == '-')
        sign = -1;
    if (c == '+')
        sign = +1;
    // bug: + and - signs are accumulated into the number
    cur = cur * 10 + (c - '0');
}
```
#### [952G - Puzzling Language](../problems/G._Puzzling_Language.md "April Fools Contest 2018")

"Puzzling language" featured in this problem is Orthogonal Puzzlang (a less studied variant of [Puzzlang](https://codeforces.com/https://esolangs.org/wiki/Puzzlang)).

There are multiple ways to approach code generation in this language. 

The method shown in the example was not the easiest possible, and was chosen quite deliberately :-) But it is possible to develop it further — use triangular blocks of Xs to increment value in a cell and then carefully navigate to the right cell and print its contents. This requires a lot of care when dealing with multiple symbols, increments which are not square numbers (a triangular block of Xs corresponds to an increment by a square number, and yes, \$ sign in the example with ASCII code 36 was not a random choice) and so on.

My reference solution used a much easier approach. The simplest command to generate in Puzzlang is decrement — it is just a standalone 'X'. And due to the fact that memory cells in Brainfuck wrap around, you can get any value in a memory cell starting with any other value and decrementing it the right number of times. The generated program can have only 2 columns, with '-' (decrement) instruction implemented as ".." — newline — "X." and '.' (print) instruction implemented as "X.".

This approach can be optimized further without adding too much complexity: my actual reference solution still generated 2-column programs but encoded both decrement and print instructions as either ".X" or "X." depending on the previous instruction, so that decrement 'X's formed a chessboard pattern, and print 'X's were right below the 'X's of previous instructions. This reduced the size of the program by a factor of 2.

Another solution I implemented didn't use wrap around of memory cells, but instead relied on torus topology of the program. I used a program with 2 columns again, with the same implementation of decrement and print instructions as in the previous approach. A sequence of 2*N increment instructions could be represented as a block of N+1 "XX" lines. The first line of the block would be interpreted as ",,", but the interpreter is permissive enough to just ignore these instructions. Every line of the block after that is interpreted as "++". This approach typically generates shorter programs but requires a bit more care when implementing it — I got it quite right only on the fourth try :-)

