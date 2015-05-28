#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 文字列をdivで分割しvectorで返す
vector<string> split(const string &str, char div) {
    vector<string> v;
    string buff;
    for (char c: str) {
        if (c == div) {
            if (!buff.empty()) { v.push_back(buff); }
            buff.clear();
        }
        else {
            buff += c;
        }
    }
    if (!buff.empty())
        v.push_back(buff);
    return v;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    string TEMPS; // the N temperatures expressed as integers ranging from -273 to 5526
    getline(cin, TEMPS);

    int lowest = 9999;
    vector<string> v = split(TEMPS, ' ');
    for( int i = 0; i < N; i++ ) {
        int tmp = stoi(v[i]);
        // INPUTの絶対値を比較しもっとも低いものを採用
        if( abs(lowest) > abs(tmp) ) {
            lowest = tmp;
        }
        else if(abs(lowest) == abs(tmp)) {
            if( tmp > 0 ) {
                lowest = abs(tmp);
            }
        }
    }
    if( N == 0 ) {
        cout << 0 << endl;
    }
    else {
        cout << lowest << endl;
    }
}