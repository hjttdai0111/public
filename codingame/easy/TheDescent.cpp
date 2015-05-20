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

    // game loop
    while (1) {
        int SX;
        int SY;
        cin >> SX >> SY; cin.ignore();
        unsigned int mh[8] = {};    // 山の高さ
        for (int i = 0; i < 8; i++) {
            int MH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
            cin >> MH; cin.ignore();
            mh[i] = MH;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        //cout << "FIRE" << endl; // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
        int highest = 0;    // 一番高い山の高さ
        int index = 0;      // 一番高い山の位置
        for( int i = 0; i < 8; i++ ) {
            if( highest <= mh[i] ) {
                highest = mh[i];
                index = i;
            }
        }
        // 一番高い山にたどり着いた時にFIRE
        if( index == SX ) {
            cout << "FIRE" << endl;
        }
        else {
            cout << "HOLD" << endl;
        }
        
    }
}