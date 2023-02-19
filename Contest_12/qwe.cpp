#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Colors{
    int color;
    int qty;
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    string str, temp;
    Colors COL[10];

    int color,total = 0, N, clr;
    while(getline(in, str)){
        for(int i = 0; i != 10; i++) {
            COL[i].color = i;
            COL[i].qty = 0;
        }
        istringstream iss(str);
        iss>>N;
        while (iss >> clr){
            //cout << clr << " ";
            for(int i = 0; i != 10; i++) {
                if(clr == COL[i].color){
                    COL[i].qty++;
                }
            }
        }
        for(int i = 0; i != 10; i++) {
            if( COL[i].qty > 1)
                total += COL[i].qty;

        }

        out <<total <<  endl;
        total = 0;

    }
    return 0;
}