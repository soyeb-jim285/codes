# Tutorial_(en)

Thank you for participating in our contest! We hope you enjoyed it.

Please let us know what you thought of the problems by voting!

[1812A - Are You a Robot?](../problems/A._Are_You_a_Robot_.md "April Fools Day Contest 2023")

Idea: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")  
Preparation: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Hint**Have you seen the "are you a robot" boxes on websites? 

 **Solution**
### [1812A - Are You a Robot?](../problems/A._Are_You_a_Robot_.md "April Fools Day Contest 2023")

You just need to output the word security that is distorted in the image.

 **Video Editorial**[Video Editorial](https://codeforces.com/https://www.youtube.com/watch?v=dQw4w9WgXcQ)

 **Feedback*** [*390*](https://codeforces.com/data/like?action=like "I like this")





 Amazing problem
* [*44*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*46*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812B - Was it Rated?](../problems/B._Was_it_Rated_.md "April Fools Day Contest 2023")

Idea: [BucketPotato](https://codeforces.com/profile/BucketPotato "Grandmaster BucketPotato")  
Preparation: [BucketPotato](https://codeforces.com/profile/BucketPotato "Grandmaster BucketPotato")

 **Hint****Was** it rated?

 **Solution**
### [1812B - Was it Rated?](../problems/B._Was_it_Rated_.md "April Fools Day Contest 2023")

The input to the problem represents a Codeforces contest ID. Out of the first $25$ Codeforces contests, the only unrated ones had IDs $15$, $20$, and $21$.

So we output NO if $n \in \{15, 20, 21\}$, and YES otherwise.

 **Feedback*** [*207*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*66*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*111*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812C - Digits](../problems/C._Digits.md "April Fools Day Contest 2023")

Idea: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")  
Preparation: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")

 **Hint 1**8, 7, and 30 all seem to be products of some numbers in the input.

 **Hint 2**The answer is to print the product of all numbers in a test case, but we don't know n.

 **Solution**
### [1812C - Digits](../problems/C._Digits.md "April Fools Day Contest 2023")

The answer is the product of $a_i$ in a test case. In other words, it is

$$\prod_{i=1}^n a_i.$$

But what is $n$? In the samples, the value of $n$ in each test case is either $[3, 2, 3]$ or $[3, 1, 4]$. The latter looks familiar – it is the digits of $\pi$! There are subtle hints about this in the problem, for example the problem name or the fact that Pi is the symbol for product. We may verify that $\pi$ is the answer by checking that its $32$ digits sum to $155$.

The full solution is: In the $k$-th test case, read $n$ numbers (where $n$ is the $k$-th digit of $\pi$), then print the product of those $n$ numbers.

 **Feedback*** [*151*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*38*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*55*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812D - Trivial Conjecture](../problems/D._Trivial_Conjecture.md "April Fools Day Contest 2023")

Idea: [AlperenT](https://codeforces.com/profile/AlperenT "Master AlperenT")  
Preparation: [AlperenT](https://codeforces.com/profile/AlperenT "Master AlperenT")

 **Hint 1**What is a conjecture? Is this problem really a conjecture?

 **Hint 2**The problem name is "Trivial Conjecture". Is it really trivial?

 **Hint 3**What are the most used words in the statement?

 **Solution**
### [1812D - Trivial Conjecture](../problems/D._Trivial_Conjecture.md "April Fools Day Contest 2023")

[A comic about the problem](https://codeforces.com/https://xkcd.com/710/)

The given function in the statement defines [Collatz Conjecture](https://codeforces.com/https://en.wikipedia.org/wiki/Collatz_conjecture). It is one of the most famous unsolved problems in mathematics. This is why the problem is actually harder to solve if you have a math background. 

Basically, the problem asks you to find a number such that it doesn't take less than $k$ steps to reach $1$ using the defined function. There are many numbers that take a high amount of steps, but they don't seem to get accepted.

Many people tried to find the value of $[REDACTED]$ and find a number that takes longer than it. However, doing so is very hard and wastes a lot of time. For people who tried to do so and interested in its value, it is $142023$ (01/04/2023).

The important thing here is to read the statement very carefully. Collatz Conjecture is defined on positive integers. However, the statement only says "Output a single integer $n$", which means it's possible to print a negative integer or $0$. Doing so solves the problem successfully because any integer $n \leq 0$ never becomes $1$. We don't know if this is the only solution. It's possible that there is a positive integer that takes longer than $142023$ steps. If you find a number that takes very long or actually takes longer than $142023$ steps, please write in the comments.

 **Feedback*** [*134*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*20*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*22*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812E - Not a Geometry Problem](../problems/E._Not_a_Geometry_Problem.md "April Fools Day Contest 2023")

Idea: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")  
Preparation: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")

 **Hint**Read the output constraint carefully!

 **Solution**Tutorial is loading... **Feedback*** [*159*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*14*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*13*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812F - Factorization](../problems/F._Factorization.md "April Fools Day Contest 2023")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")  
Preparation: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Hint**Factor the first number. What do you notice?

 **Solution**
### [1812F - Factorization](../problems/F._Factorization.md "April Fools Day Contest 2023")

If we factor the first number (using Wolfram|Alpha or some program you code), you can see that it is the product of two primes: $991999999999 \times 4201403994187$. This first prime is an example of a glitch prime: a prime whose digits are all the same, except one.

The conclusion is that the larger number should also be the product of two primes, one of which is a glitch prime. So you can test all glitch primes using a local program, which shouldn't take more than a few minutes (or you can even submit it directly to Codeforces and it should work).

We won't spoil the factorization here, you should try to figure it out ;)

 **Feedback*** [*65*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*27*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*36*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812G - Colour Vision](../problems/G._Colour_Vision.md "April Fools Day Contest 2023")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")  
Preparation: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Hint 1**Besides the sample, which doesn't provide much information, we have to continue based off of the image. How can we extract information from an image, given that we only have three rectangles in a shade of green?

 **Hint 2**Hex?

 **Solution**
### [1812G - Colour Vision](../problems/G._Colour_Vision.md "April Fools Day Contest 2023")

The rectangles are in the shape of the Codeforces logo. The only other information that the picture gives us is the fact that they are green, so if we want to get information from this shade of green, we can use hex codes! Extracting the hex code gives us #01722B.

What about Codeforces is related to 01722B? It looks suspiciously similar to a problem code, and indeed, if you go to https://codeforces.com/contest/1722/problem/B, you get the problem Colourblindness, which is clearly related to the title of this problem!

Looking at the sample, then, solution is simple: just solve the problem Colourblindness, and send the code to this problem.

 **Feedback*** [*105*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*11*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*12*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812H - Expected Twist](../problems/H._Expected_Twist.md "April Fools Day Contest 2023")

Idea: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")  
Preparation: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9")

 **Hint 1**Some details are suspiciously specific.

 **Hint 2**624 is a weird number. Google (or DuckDuckGo, Bing, etc.) the suspicious keywords like "624 random", "random number 624", "random twist" or something similar.

 **Solution**
### [1812H - Expected Twist](../problems/H._Expected_Twist.md "April Fools Day Contest 2023")

Doing the web searches in the hint above shows results about the Mersenne Twister (or more specifically, MT19937), which is a random number generator. With additional hint from the problem name, it is reasonable to assume that the array $a$ is generated by an MT19937 like this:


```cpp
mt19937 rng(seed);  
vector<uint32_t> a(n);  
for (auto &i : a) {  
    i = rng();  
}  

```
Searching more on the web shows the following fact: given the first 624 output values of an MT19937, its entire internal state can be recovered, and therefore we can know all its future outputs.

In fact, many top results from DuckDuckGo and Google, when given the keyword "624 random", show how to break the MT19937 generator, and many implementations are available online. We can use this to solve the problem. The full solution is:

1. For $i=1,2,\dots,624$, query $\texttt{?}\ i\ i$ to get the value of $a_i$.
2. Recover the state of the MT19937 used to generate $a$ using the first 624 values.
3. Generate the remaining values of $a$ with the recovered generator.
4. Output the minimum value of $a$ which we now know.
 **Feedback*** [*67*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*13*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*15*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812I - Mountain Climber](../problems/I._Mountain_Climber.md "April Fools Day Contest 2023")

Idea: [Ari](https://codeforces.com/profile/Ari "Grandmaster Ari")  
Preparation: [Ari](https://codeforces.com/profile/Ari "Grandmaster Ari")

 **Hint**How do mountains and the "YES"-words relate to each other?

 **Solution**
### [1812I - Mountain Climber](../problems/I._Mountain_Climber.md "April Fools Day Contest 2023")

This problem provides very little information, giving us only the samples, and minor confirmation in the form of the title.

By looking carefully at the accepted samples, particularly the shorter ones such as big and clump, we may notice that they have a similar "shape". As it turns out, this problem is related to the concept of [ascenders](https://codeforces.com/https://en.wikipedia.org/wiki/Ascender_(typography)) and [descenders](https://codeforces.com/https://en.wikipedia.org/wiki/Descender) in typography. The title of the problem provides a nice bit of confirmation for this idea. Ultimately, a string is accepted if and only if its sequence of ascenders of descenders is a regular bracket sequence, and we can implement this easily.

There is a little ambiguity regarding whether the dots on i and j count as ascenders, but the given samples are enough to disambiguate and conclude that j is considered to have a descender, whereas i is considered to have neither an ascender nor a descender.

 **Feedback*** [*59*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*12*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*15*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
[1812J - Unmysterious Language](../problems/J._Unmysterious_Language.md "April Fools Day Contest 2023")

Idea: [ScarletS](https://codeforces.com/profile/ScarletS "Master ScarletS"), [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9"), et al.  
Preparation: [ToxicPie9](https://codeforces.com/profile/ToxicPie9 "Candidate Master ToxicPie9"), ~~ChatGPT~~

 **Hint**Think of unmysterious languages.

 **Even Bigger Hint**[We literally told you.](Announcement_(en).md?#comment-1018014)

 **Solution**
### [1812J - Unmysterious Language](../problems/J._Unmysterious_Language.md "April Fools Day Contest 2023")

The unmysterious language is English. You just need to ask the checker nicely, i.e. have "please". However, our AI gets tired from reading long messages, so if your output is too long, it won't accept it either!

 **Feedback*** [*284*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*16*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
* [*24*](https://codeforces.com/data/like?action=like "I like this")




 Amazing problem
