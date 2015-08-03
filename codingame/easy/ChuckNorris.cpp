#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 10進数を2進数にする関数
string change10to2(int c)
{
    string retVal;
    while(c > 0) {
        int amari = c % 2;
        c /= 2;
        string temp = retVal;
        retVal = to_string(amari);
        retVal += temp;
    }
    // 短い分は0で埋める
    if( retVal.length() < 7 ) {
        string temp = retVal;
        retVal = "";
        for( int i = 0; i < 7 - temp.length(); i++ ) {
            retVal += "0";
        }
        retVal += temp;
    }
    return retVal;
}
// divで指定された文字が何連続続いているかを返す
int getConsecutiveValue(string parent, int idx, char div) 
{
    int consecutive = 0;
    char s = parent[idx];
    while(s == div){
        idx++;
        s = parent[idx];
        consecutive++;
    }
    return consecutive;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    cerr << MESSAGE << endl;
    
    string encodeStr;
    int length = MESSAGE.length();
    for( int i = 0; i < length; i++ ) {
        encodeStr += change10to2(MESSAGE[i]);
    }
    cerr << encodeStr << endl;
    
    string ans;
    int index = 0;
    while(index < encodeStr.length()) {
        if( index != 0 ) { ans += " "; }
        char s = encodeStr[index];
        if( s == '1' ) {
            int length = getConsecutiveValue(encodeStr, index, '1');
            index += length;
            ans += "0 ";
            for( int i = 0; i < length; i++ ) {
                ans += "0";
            }
        }
        else {
            int length = getConsecutiveValue(encodeStr, index, '0');
            index += length;
            ans += "00 ";
            for( int i = 0; i < length; i++ ) {
                ans += "0";
            }
        }
    }
    cout << ans << endl;
}