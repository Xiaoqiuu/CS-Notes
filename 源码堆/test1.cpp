#include <string>
#include <bits/stdc++.h>
using namespace std;

int search(string pat, string txt) {
    int M = pat.length;
    int N = txt.length;
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (pat[j] != txt[i+j])
                break;
        }
        // pat 全都匹配了
        if (j == M) return i;
    }
    // txt 中不存在 pat 子串
    return -1;
}

int main()
{
    search("a","abcdefghijklmnopqrstuvwxyzaaaabbbbbervgetbsrtbrshryilkuimjyhtgrvfec");
    return 0;
}