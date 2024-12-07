#include <iostream>
#include <list>
using namespace std;

void printLots(const list<int>& L, const list<int>& P) {
    auto i = L.begin(); 
    int currentPos = 0;

    for (int pos : P) {
        while (currentPos < pos && i != L.end()) {
            ++i;
            ++currentPos;
        }

        if (i != L.end()) {
            cout << *i << " ";
        } else {
            break;  
        }
    }
    cout << endl;
}

int main() {       
    list<int> L = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> P = {1, 3, 4, 6};

    printLots(L, P);
    return 0;
}

