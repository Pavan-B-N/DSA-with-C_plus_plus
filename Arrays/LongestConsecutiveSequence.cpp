/*
Longest Consecutive Subsequence

Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

nput: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

// All possible sequences are:-
1,2,3,4 = 5 doesn't exists so stopped
9,10 = 11 doesn't exist
3,4 = 5 missing
10 = 11 missing
4 = 5 missing
20 = 21 missing
2,3,4 = 5 missing 
hence longest consecutive subsequence is {1,2,3,4}
*/
