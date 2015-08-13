#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ファイル名から拡張子以降の部分を取得
string getExtension(string fname)
{
    int index = -1;
    int length = fname.length();
    for(int i = length - 1; i >= 0; i--) {
        char moji = fname.at(i);
        if( moji == '.') {
            index = i;
            break;
        }
    }
    if( index == -1 ) return "";
    fname.erase(0, index+1);
    return fname;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    vector<string> extList;
    vector<string> mtList;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::toupper);  // 大文字に変換
        
        extList.push_back(EXT);
        mtList.push_back(MT);
    }
    
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        string ext = getExtension(FNAME);
        if( ext.length() == 0 ) {
            // 拡張子がない
            cout << "UNKNOWN" << endl;
            continue;
        }
        transform(ext.begin(), ext.end(), ext.begin(), ::toupper);  // 大文字に変換
        
        bool isFind = false;
        for(int j = 0; j < N; j++) {
            
            if( ext.compare(extList.at(j)) == 0 ) {
                // 拡張子が一致するものがある
                isFind = true;
                cout << mtList.at(j) << endl;
                break;
            }
        }
        if( isFind == false ) {
            // 拡張子がリストに存在しない
            cout << "UNKNOWN" << endl;    
        }
    }
}