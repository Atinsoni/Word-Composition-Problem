# Word-Composition-Problem
To find the Longest and Second longest Compound Word from the given input .txt files.
# Input (files)
 [Input_01.txt](Input_01.txt)

. Input_02.txt
# Output
```
Longest Compound Word: ratcatdogcat
Second Longest Compound Word: catsdogcats
Time taken to process the file: 0 milliseconds

Longest Compound Word: ethylenediaminetetraacetates
Second Longest Compound Word: electroencephalographically
Time taken to process the file: 1352 milliseconds
```

# Approach
Strings are stored in a unique tree known as the Trie data structure. A node can have a maximum number of children equal to the size of the alphabet. Trie offers O(k)-time search, insert, and delete operations, where k is the key/word length. It is clear that this is quicker than BST and hashing. and Prefix search may be done effectively.

First we will read the input file then construct the Trie with all the strings present in the input file. For constructing the Trie insert() function is called which is present in the Trie class. 
Now we will take every string present in file and call the compoundWord() function which will tell us the word is compound or not. Function CompoundWord() will iterate over all the substrings of the word using find() function present in the Trie Class. 
If the word is compound then we will compare it with the largest word if the length of the new word is greater than longest word, then update the longest_word
now we will remove the longest word from the Trie and will repeat the same process to find the second longest word.





