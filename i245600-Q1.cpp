#include <iostream>
using namespace std;

void ChangeLocation (char *Array, int b1, int b2) 
{

    if (b1 >= b2) return;
    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;
    ChangeLocation(Array, b1 + 1, b2 - 1);

}

void PrintPattern(int &n) 
{

    if (n <= 0) return;
    cout << n << " ";
    int temp = n - 2;
    PrintPattern(temp);

    if (n > 1) 
    {
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
    }
}

int main() 
{
    char arr[] = {'C','O','M','P','U','T','E','R'};
    ChangeLocation(arr, 3, 7);
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    
    cout << endl;
    int num = 4;
    PrintPattern(num);
    
    return 0;
}