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
    int R; // the length of the road before the gap.
    cin >> R; cin.ignore();
    int G; // the length of the gap.
    cin >> G; cin.ignore();
    int L; // the length of the landing platform.
    cin >> L; cin.ignore();

    cerr << R << endl;
    cerr << G << endl;
    cerr << L << endl;
    bool isJumpFinished = false;    // 
    
    // game loop
    while (1) {
        int S; // the motorbike's speed.
        cin >> S; cin.ignore();
        int X; // the position on the road of the motorbike.
        cin >> X; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        // cout << "SPEED" << endl; // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
        // ジャンプ後は減速で停止
        if( isJumpFinished == true ) {
            cout << "SLOW" << endl;
        }
        else {
            // ジャンプに必要な距離
            int jumpLength = G + 1;
            if( jumpLength <= S ) {
                if( X + S > R ) {
                    cout << "JUMP" << endl;
                    isJumpFinished = true;
                }
                else {
                    if( jumpLength + 1 <= S ) {
                        // ジャンプに必要な距離よりスピードが早いので減速させる
                        cout << "SLOW" << endl;
                    }
                    else {
                        // ジャンプに必要十分な速度なのでそのまま
                        cout << "WAIT" << endl;
                    }
                }
            }
            else {
                // 速度が足りないので加速
                cout << "SPEED" << endl;
            }
        }
        
    }
}