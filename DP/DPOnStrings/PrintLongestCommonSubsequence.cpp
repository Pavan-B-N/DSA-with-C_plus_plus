// https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=SUBMISSION
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void printDPTable(vector<vector<int>> dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

string findLCS(int n, int m, string &s, string &t) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table using the technique of finding the length of LCS
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // shift index method
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    printDPTable(dp);

    // Reconstruct the LCS string
    int len = dp[n][m];
    string ans(len, ' ');  // Create a string of length `len` filled with spaces

    int index = len - 1;
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans[index] = s[i - 1];
            index--;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            // if string is not matching then go to the place from where they have came
            i--;
        } else {
            j--;
        }
    }

    return ans;
}

int main() {
    string s = "acd";
    string t = "ced";
    int n = s.length();
    int m = t.length();

    string lcs = findLCS(n, m, s, t);
    cout << "LCS: " << lcs << endl;

    return 0;
}