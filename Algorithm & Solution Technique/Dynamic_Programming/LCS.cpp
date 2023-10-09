#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<vector<vector<int>>, vector<vector<string>>> LCS_LENGTH(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<string>> b(m + 1, vector<string>(n + 1, " "));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = " \\ ";
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = " | ";
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = " ㅡ ";
            }
        }
    }
    
    return {c, b};
}

void PRINT_LCS(const vector<vector<string>>& b, const string& X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    
    if (b[i][j] == " \\ ") {
        PRINT_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == " | ") {
        PRINT_LCS(b, X, i - 1, j);
    } else {
        PRINT_LCS(b, X, i, j - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string X = "ABCBDAB";
    string Y = "BDCAB";
    
    auto result = LCS_LENGTH(X, Y);
    
    vector<vector<string>> b = result.second;
    
    int i = X.length();
    int j = Y.length();
    
    cout << "Length of LCS: " << result.first[i][j] << endl;
    cout << "Longest Common Subsequence (LCS): ";
    PRINT_LCS(b, X, i, j);
    cout << endl;
    
    return 0;
}
