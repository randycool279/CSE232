Grade Received: 98%
Why: "Long lines like these should be avoided. You can use nested if conditions wherever possible" --> 
"if (pos + word.length() < word_list.length() && word_list[pos + word.length()] != ',')"
Inputs
All inputs will be provided through standard input (that is, std::cin). The first two lines of these inputs will each contain a single "keyword". The remaining lines will each contain a full word list. Word lists are one or more words that are separated by commas, with no spaces or any other symbols.
For example:
  Kansas
  Virginia
  Virginia,Wyoming,Vermont
  NewMexico,Kansas,Alabama,Virginia,NewYork,WestVirginia,Arkansas,Virginia,Utah,Virginia
  Alaska
In this case, the keywords are “Kansas” and "Virginia", and then there are three lines of word lists. The word lists will never contain spaces or any characters other than letters (capital or lowercase) and numbers.
Outputs
For each word list provided, you must output (to standard out, std::cout) which of the two keywords comes first, or “N/A” if neither one is in the word list at all. You should then output (on the same line) a count of how many times each word appeared, in order. Note that you should NOT count words that are merely a substring of another word.
For the input example above, you should output:
   Virginia 0 1
   Kansas 1 3
   N/A 0 0
There are three lines, one for each word list. In the first word list Virginia appears first (as indicated on the first line of output) and only once. Kansas never appears at all. So the word counts are 0 Kansas and 1 Virginia.
The second line has Virginia appearing three times and Kansas only once, but Kansas appears first so it is the name that begins the line, followed by the two counts. Since a word should not be counted if it is just a substring of another word, “Virginia” should NOT be counted four times just because it is part of "WestVirginia".
The final word list has neither state name in it, so “N/A” is printed in the field for which came first, and then zeros are printed for both counts since neither one was actually present.
Implementation
You should implement this program using four functions, described below, plus the main() function. You may, additionally create any number of extra functions that you believe will help you to efficiently produce the needed output.
We recommend that you implement these required functions in the order described. The first function may be helpful to you in implementing the second function, and the second function will be helpful in implementing the third and fourth functions. All four functions will be tested in unit tests to help you craft them correctly.
Finally, you must implement the main() function to produce the desired output for the program, as described above.
Notes on parameter and return types:
Whenever you are talking about a position in a string, you should use the type size_t to be consistent with the standard library.
When you create a function, if an input is a string that is not changed by the function, you should pass that string as a "const reference". The reference ensures that the whole string does not need to be copied (a time saver for strings!) and the const lest a user know that the string won’t be altered by the function even though it’s being passed by reference.
You should almost never return a reference from a stand-alone function. There are rare circumstance where this might be the right thing to do, but usually only under much more advanced use conditions. Likewise you should almost never mark a return type as const.
Function: AtListPosition
The AtListPosition function should take three arguments: a word list (as a string), a word (as a string), and a position. It should return a Boolean value indicating whether or not the provided word begins at the specified position in the word list. Remember, a match that is actually just a part of a longer string should NOT count as having the word at that position of the word list.
Function FindInList
The FindInList function should have two to three parameters, very similar to the previous function: a word list (as a string), a word (as a string), and a start position (which should default to 0 if only two arguments are provided). It should return the first position in the word list where the provided word is found, starting its search from the start position.
Remember, making good use of AtListPosition will likely simplify your implementation of this function.
Function: GetFirstInList
The GetFirstInList function should take three arguments: word list and pointers to two strings, word1 and word2. It should return a regular string equal to the contents of word1 or word2, whichever word appears first in the word list. Clearly FindInList will be very helpful in allowing you to identify which one comes first.
Why are the inputs to this function supposed to be pointers to strings? Is it just to make your life more difficult? Yes, in an sense it is. There are few simple problems where pointers are needed to implement a solution, so we are simply going to require you use pointers in this question so that you can get some (light) experience trying them out.
Function: CountInList
The CountInList function has two parameters: a word list and a word (both strings). This function should return a simple count of how many times the word appears in the word list.