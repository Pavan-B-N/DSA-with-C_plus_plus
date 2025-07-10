// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// https://www.naukri.com/code360/problems/longest-common-substring_1235207?leftPanelTabValue=SUBMISSION
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string lcs(string &str1, string &str2){
    // build dp table
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int maxi=0;
    int maxj=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                // diagonal
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>=dp[maxi][maxj]){
                    maxi=i;
                    maxj=j;
                }
            }
        }
    }

    int len=dp[maxi][maxj];
    string lcSubstring(len,' ');
    int index=len-1;
    while(maxi>0 && maxj>0){
        // maxi is 1-based, and str1 is 0-based indexed. You should use str1[maxi - 1].
        lcSubstring[index--]=str1[maxi-1];
        maxi--;
        maxj--;
    }

    return lcSubstring;
}

// optmized way
string lcs(string &str1, string &str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;
    int endPos = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos = i;  // end index in str1
                }
            }
        }
    }

    return str1.substr(endPos - maxLen, maxLen);
}


int main() {
    string str1 = "abcd";
    string str2 = "abed";
    string ans = lcs(str1, str2);
    cout << ans << endl;
    return 0;
}