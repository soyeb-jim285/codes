# https:_codeforces.com_blog_entry_126654

Yesterday, investigating [Strange TLE by cin using GNU C++20 (64)](https://codeforces.com/blog/entry/126573), I found an easy and reproducable way to trigger a slowdown bug that I believe has been plaguing Codeforces for some time now. So I'm making this blog to raise awarness of it. [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Штаб, MikeMirzayanov"), please take a look at this! 

Here is how to trigger the slowness bug:

 1. Take any problem with a relatively large input on Codeforces (2⋅105 ints is enough).
2. Take a random AC C++ submission that uses `std::cin`.
3. Add the line `vector<vector<int>> TLE(40000, vector<int>(7));` somewhere in global space.
4. Submit using either C++20(64 bit) or C++17(64 bit).
5. ???
6. TLE

For example take [tourist](https://codeforces.com/profile/tourist "Легендарный гроссмейстер tourist")'s solution to problem [1936-D - Битовый парадокс](https://codeforces.com/contest/1936/problem/D "Codeforces Round 930 (Div. 1)"). With the vector of death added to the code, it gets [TLE on TC5](https://codeforces.com/contest/1936/submission/249181295) (taking >5 s). While without the deadly vector, the submission takes [155 ms on TC5](https://codeforces.com/contest/1936/submission/248948695).

Here is a stand alone example with the slowdown (credit to [kostia244](https://codeforces.com/profile/kostia244 "Международный гроссмейстер kostia244")). It runs 100 times slower with the vector of death. 

 
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> TLE(40000, vector<int>(7));

int main() {
    string s;
    for(int i = 0; i < 17; i++) s += to_string(i) + " ";
    
    for (int j = 0; j < 60000; ++j) {
        istringstream ss(s);
        int x;
        while (ss >> x);
    }
}
```
 **What is causing this?**The short answer is, no one knows. Initially people suspected this had to do with cache misses. But as my example above shows, I get the slowdown using a tiny amount of memory. Also, even after countless attempts, no one has been able to reproduce this slowdown locally. So the issue is likely something on Codeforces' side.

 **Other ways to trigger the slowdown bug**There are lots of alternative ways to trigger the slowdown bug:

It doesn't have to be a vector of vectors [249329395](https://codeforces.com/contest/1936/submission/249329395 "Посылка 249329395 от pajenegod") (credit to [kostia244](https://codeforces.com/profile/kostia244 "Международный гроссмейстер kostia244")).

You can change the size slightly, and still get the slowdown bug. From testing 39999 and 40000, as well as 7,8,9,10 can all trigger the slowdown bug. See for example [249330544](https://codeforces.com/contest/1936/submission/249330544 "Посылка 249330544 от pajenegod"). But 40000 and 7 is the only combination I've found that consistently trigger it. 

Declaring the vector inside main also causes the slowdown bug [249330046](https://codeforces.com/contest/1936/submission/249330046 "Посылка 249330046 от pajenegod").

You can still trigger the slowdown with `vector<vector<char>>`, but you need to increase 7 to 4⋅7 [249331394](https://codeforces.com/contest/1936/submission/249331394 "Посылка 249331394 от pajenegod").

Submissions using `scanf` instead of `cin` seems to be less affected by the slowdown bug. But even `scanf` submissions typically run around a factor of 2 slower. For example, [Radewoosh](https://codeforces.com/profile/Radewoosh "Легендарный гроссмейстер Radewoosh")'s solution to problem [1936-D - Битовый парадокс](https://codeforces.com/contest/1936/problem/D "Codeforces Round 930 (Div. 1)") goes from taking [2168 ms](https://codeforces.com/contest/1936/submission/248943933) to [4336 ms](https://codeforces.com/contest/1936/submission/249332576).

 **Other blogs on this topic**Over the last couple of years, there has been many blogs about people getting TLE on Codeforces for no appearent reason. Here are a couple examples

[Strange TLE by cin using GNU C++20 (64), and some weird subtle changes to (surprisingly) fix it](https://codeforces.com/blog/entry/126573) by [-14](https://codeforces.com/profile/-14 "Гроссмейстер -14")

[Bizarre slowdown when using cin on a 64-bit compiler](https://codeforces.com/blog/entry/99038) by [defnotmee](https://codeforces.com/profile/defnotmee "Международный мастер defnotmee")

[Inconsistent times and TLE with C++17 (64bit) vs. C++17](https://codeforces.com/blog/entry/91474) by [OleschY](https://codeforces.com/profile/OleschY "Мастер OleschY")

Also if you dig around in these blogs, you will find comments that points to even more examples. What all of these weird TLEs seems to have in common is that

 1. Submitted using 64 bit C++ on Codeforces.
2. Uses `std::cin`.
3. Unable to be reproduced locally.

It is for this reason that I suspect that these unexplainable TLEs all stem from the same fundamental issue on Codeforces' side.

**Remark**: I'm no longer to reproduce the issue in [Inconsistent times and TLE with C++17 (64bit) vs. C++17](https://codeforces.com/blog/entry/91474). So that blog might be about a completely different issue that has now been fixed.

