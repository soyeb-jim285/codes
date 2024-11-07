# Tutorial_(en)

All problems were created and prepared by me and [magnus.hegdahl](https://codeforces.com/profile/magnus.hegdahl "Candidate Master magnus.hegdahl"). Thanks to [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato"), [Monogon](https://codeforces.com/profile/Monogon "Grandmaster Monogon"), and [Priyam2k](https://codeforces.com/profile/Priyam2k "Expert Priyam2k") for valuable feedback and testing. Special thanks to [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") for coming up with the idea and preparing the unique checker for [1663H - Cross-Language Program](../problems/H._Cross-Language_Program.md "April Fools Day Contest 2022"). I hope you enjoyed the contest, and found it to be an interesting series of puzzles.

Example solution code written by [Agnimandur](https://codeforces.com/profile/Agnimandur "Master Agnimandur") is provided for each problem.

### [1663A - Who Tested?](../problems/A._Who_Tested_.md "April Fools Day Contest 2022")

 **Clue 1**The problem statement is the title of the problem.

 **Clue 2**Re-read the original announcement blog.

 **Solution**If you carefully read [the announcement blog](Announcement_(en).md), you will notice that I especially thanked [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") for testing. Just print "BucketPotato".

 **Solution Code (Python)**
```cpp
print("bucketpotato")
```
### [1663B - Mike's Sequence](../problems/B._Mike's_Sequence.md "April Fools Day Contest 2022")

 **Clue 1**Did you notice the peculiar constraints on the variable rr?

 **Clue 2**"Mike" is of course [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"). "Mike's sequence" has to do with Codeforces ratings.

 **Clue 3**3000 is the cutoff for the highest rating: Legendary Grandmaster.

 **Solution**Mike's sequence are the Codeforces rating thresholds: [1200,1400,1600,1900,2100,2300,2400,2600,3000]. Your task is simply to print the threshold immediately above the provided rating rr.

 **Solution Code (Python)**
```cpp
R = int(input())
ratings = [1200,1400,1600,1900,2100,2300,2400,2600,3000]
higher = [r for r in ratings if r > R]
print(higher[0])
```
### [1663C - Pōja Verdon](../problems/C._Pōja_Verdon.md "April Fools Day Contest 2022")

 **Clue 1**[Aenar Targaryen](https://codeforces.com/https://awoiaf.westeros.org/index.php/Aenar_Targaryen) was a dragonlord of Old Valyria.

 **Clue 2**The main clue is the title: "Pōja Verdon".

 **Solution**Aenar Targaryen was a dragonlord of Valyria (an empire from a *A Song of Ice and Fire*) who moved his family to Westeros right before Valyria was destroyed.

`pōja` means `their` and `verdon` means `sum` (or `amount` based on context) in High Valyrian (you can easily translate this on [Duolingo](https://codeforces.com/https://www.duolingo.com/dictionary/hv)).

In a nutshell: Print the sum of the array.

 **Solution Code (Python)**
```cpp
n = int(input())
nums = list(map(int,input().strip().split()))
print(sum(nums))
```
### [1663D - Is it rated - 3](../problems/D._Is_it_rated_-_3.md "April Fools Day Contest 2022")

 **Clue 1**Did you notice that the problem had a special "constraints" section? That's highly unusual for a *Codeforces* problem.

 **Clue 2**The length of S is 3. Are there any famous three letter programming contests?

 **Solution**The capital variable letters and the "constraints" section are designed to mimic how [atcoder.jp](https://codeforces.com/http://atcoder.jp) formats their problem statements.

The problem is asking whether the [Atcoder contest](https://codeforces.com/https://atcoder.jp) (ABC,ARC,AGC) is rated for a rating XX. (Note that the judge ignores Atcoder heuristic contests for simplicity).

 * ABC's are rated for [0,1999][0,1999]
* ARC's are rated for [0,2799][0,2799]
* AGC's are rated for [1200,∞][1200,∞]
 **Solution Code (Python)**
```cpp
s = input().strip()
x = int(input().strip())
if (s=="ABC" and x<2000) or (s=="ARC" and x<2800) or (s=="AGC" and x>=1200):
    print('yes')
else:
    print('no')
```
### [1663E - Are You Safe?](../problems/E._Are_You_Safe_.md "April Fools Day Contest 2022")

 **Clue 1**Do you recognize the story of the Minotaur?

 **Clue 2**The problem is a word search, but not for the word "minotaur".

 **Solution**Perhaps you recognize the story of the minotaur? Less known is the hero who saved the kids from the minotaur: his name was Theseus [thee-see-us].

The problem is just a word search (horizontal, vertical, diagonal) for `theseus`. You should only go in the forward direction when you search for a word.

 **Bonus Clues (for other problems)**The grid contains other clues embedded in it. Perhaps you can find `esoteric`, `java`, and `script` (hints for problem G). You might be able to find `atcoder` (hint for problem D). Also `hero` (hinting at Theseus for this problem).

There are also some red herring words out there.

 **Solution Code (C++)**
```cpp
#include <bits/stdc++.h>
using namespace std;

void good() {
    cout << "YES";
    exit(0);
}

int main() {
    int N; cin >> N;
    char grid[N][N];
    for (int i = 0; i < N; i++) {
        string row; cin >> row;
        for (int j = 0; j < N; j++) grid[i][j] = row[j];
    }

    string word = "theseus";
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i+k][j];
				if (w == word) good();
			}
			if (j < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i][j+k];
				if (w == word) good();
			}
			if (i < N-7 && j < N-7) {
				string w = "";
				for (int k = 0; k < 7; k++) w += grid[i+k][j+k];
				if (w == word) good();
			}
		}
    }
    cout << "NO";
}
```
### [1663F - In Every Generation...](../problems/F._In_Every_Generation....md "April Fools Day Contest 2022")

 **Clue 1**Where is the quote from?

 **Clue 2**"buffy", "the", "vampire", "slayer"

 **Clue 3**"buffy" (length 5), "the" (length 3), "vampire" (length 7), "slayer" (length 6). Remember how 3≤|s|≤73≤|s|≤7? Now go back to the sample and see what you can do.

 **Solution**The quote is from the well known TV series [Buffy the Vampire Slayer](https://codeforces.com/https://en.wikipedia.org/wiki/Buffy_the_Vampire_Slayer).

Perhaps you notice the lengths of the words `buffy`, `the`, `vampire`, `slayer` are unique integers in the set {3,5,6,7}.

Given the string ss, simply "add" that string with the target word of the same length.

Here's how adding two letters work:

 1. Convert both letters to numbers in [0,25][0,25].
2. Add the two numbers up modulo 26.
3. Convert the number back into a letter.

You can verify your addition algorithm is correct by checking whether "tourist" + "vampire" = "ooggqjx" (as provided in the sample).

Finally, if the length of ss is 44, the answer is "none", because there is no word of length 4 in Buffy the Vampire Slayer.

 **Solution Code (Python)**
```cpp
s = input().strip()
words = ["","","","the","","buffy","slayer","vampire"]
if len(s)==4:
    print("none")
else:
    target = words[len(s)]
    ans = ""
    for i in range(len(s)):
        a = ord(s[i])-ord('a')
        b = ord(target[i])-ord('a')
        ans += chr((a+b)%26 + ord('a'))
    print(ans)
```
### [1663G - Six Characters](../problems/G._Six_Characters.md "April Fools Day Contest 2022")

 **Clue 1**Input is a normal string of letters, but output consists of non-letter *characters*?

 **Clue 2**Think of an esoteric programming language.

 **Clue 3**[JSF](https://codeforces.com/https://en.wikipedia.org/wiki/JSFuck) (an esoteric programming language equivalent to Javascript that only uses 6 characters).

 **Solution**The April Fool's Contests love of esoteric programming languages, combined with the reference to "six characters", will eventually lead you to JSFuck.

The six characters is a pun: the input is a string of length 6 like "abcdef", but the output is a string \textit{consisting} of only 6 characters: `[ ] ( ) ! +`.

Brief research will demonstrate a mapping from each english letter to a JSFuck string. Two letters can be concatenated with "+".Note that the optimal mapping will make your solution file approximately 12KB in size, well within the 64KB requirement of Codeforces.

However, the mapping from each letter to javascript is not unique! However, the legend mentions that Aenar needs to go to the string's "home". JSFuck's home website is [here](https://codeforces.com/https://jsfuck.com), which is where the jury's mapping is created from.

Alternatively, instead of hardcoding the generated strings, you can simply use the encoding algorithm provided in the [Github](https://codeforces.com/https://github.com/aemkei/jsfuck).

 **Solution Code (Python and Javascript)**Hard-coding strings: [152393980](https://codeforces.com/contest/1663/submission/152393980 "Submission 152393980 by Agnimandur")

Algorithmically generating strings (in Javascript): [152398972](https://codeforces.com/contest/1663/submission/152398972 "Submission 152398972 by BigDelta") (credit to [BigDelta](https://codeforces.com/profile/BigDelta "Master BigDelta"))

### [1663H - Cross-Language Program](../problems/H._Cross-Language_Program.md "April Fools Day Contest 2022")

 **Solution**Google research into how Pascal and C++ work will eventually lead you to a solution like this. Many people used the fact that `` can be used to continue single line comments to the next line in C++ but not in Pascal.

 
```cpp
// 
begin end.
int main() {}
```
