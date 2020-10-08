#include <iostream>
#include <sstream>
#include <map>
#include <ctype.h>
#include <string>
#include <iomanip>

using namespace std;


int main() {

    float cont;
    string palavra;
    map <string, int> texto;



    while (cin>>palavra){

        texto[palavra] ++;
        cont++;

    }

        for (map <string, int> :: iterator it = texto.begin(); it != texto.end(); it++){

            cout << it->first << " " << it->second<< " ";
            cout << fixed<< std::setprecision(2)<<(it->second/cont)<<endl;
            break;

        }


    return 0;
}

