// Hard problem
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
/*
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. 
In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
*/
// Goal: Maximum number of allocated pages should be minimum for a student

#include <vector>
using namespace std;
//o(n)
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int stu = 1, pages = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedPages) {
            return false;
        }
        
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            stu++;
            pages = arr[i];
        }
    }
    
    if (stu > m) {
        return false;
    }
    
    return true;
}

// o(logn*n)
// m is the number students for whom we need to allocate the book
// m=k
int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) {
        return -1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {  // O(n)
        sum += arr[i];
    }
    
    int ans = -1;
    int st = 0, end = sum; // range of possible answers
    
    while (st <= end) { // O(logn)
        int mid = st + (end - st) / 2;
        
        if (isValid(arr, n, m, mid)) { // left
            ans = mid;
            end = mid - 1;// since we need to find the minimum pages allocated to a student
        } else { // right
            st = mid + 1;
        }
    }
    
    return ans;
}
