#include <iostream>
using namespace std;

void ClearScreen()
{
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

int main() {
    ClearScreen();
    int a=3;
    cout << a <<endl;
    cin >>a;
    system("clear");
    cout<< a;
}