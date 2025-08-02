// https://www.naukri.com/code360/problems/toggle-k-bits_973006?leftPanelTabValue=PROBLEM
/*
If ‘N’ = 12 and ‘K’ = 2:
The binary representation of 12 is ‘1100’, after toggling rightmost 2 bits, it becomes ‘1111’ i.e. 15. Hence, the answer is 15. 
*/

int toggleKBits(int n, int k) {
    for (int i = 0; i < k; i++) {
        n = n ^ (1 << i);  // Toggle the i-th bit (0-based index)
    }
    return n;
}
