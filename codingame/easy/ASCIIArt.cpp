#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    
    char** Line = new char*[H];
    for (int height = 0; height < H; height++) {
        string ROW;
        getline(cin, ROW);
        
        Line[height] = new char[ROW.length()+1];
        for( int width = 0; width < ROW.length(); width++ ) {
            Line[height][width] = ROW[width];
        }
    }
    // 全て大文字へ変換
    transform(T.begin(), T.end(), T.begin(), ::toupper);
    
    // ASCII(A~Z)%(65~90), @は64
    for( int height = 0; height < H; height++ ) {
        for( int idx = 0; idx < T.length(); idx++ ) {
            int num = T[idx] - 65;      // Aをintにすると65
            if( num < 0 || 26 <num ) num = 26;
            for( int width = L*num; width < L*num + L; width++ ) {
                cout << Line[height][width];
            }
        }
        cout << endl;
    }
    
    for( int height = 0; height < H; height++ ) {
        delete[] Line[height];
    }
    delete[] Line;
}