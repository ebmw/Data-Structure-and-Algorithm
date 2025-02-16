#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool guess(int n, int b);

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;  
    int attempts = 10; 
    //This progam is game to guess random number 
    if (!guess(attempts, secretNumber)) {
        cout << "You ran out of attempts! The number was " << secretNumber << endl;
    }

    return 0;
}
































bool guess(int n, int b)
{
    if (n < 0) return false;

    int a;
    cout << "Please guess the number: ";
    cin >> a;

    if (a == b) {
        cout << "Congratulations!"<<endl;
        return true;
    } else {
        cout << "Wrong guess Try again.\n";
        return guess(n - 1, b); 
    }
}
while(true){
    printf()
}