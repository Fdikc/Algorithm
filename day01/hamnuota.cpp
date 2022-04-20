
#include <iostream>
using namespace std;
//
//汉诺塔
// Tower of Hanoi  
int ans=0;
void hanoi(int n, char a, char b, char c)
{

    if (n == 1)
    {
        cout << "Move disk 1 from " << a << " to " << c << endl;
        ans++;
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from " << a << " to " << c << endl;
    ans++;
    
    hanoi(n - 1, b, a, c);
}

int main(int argc, char const *argv[])
{
    //汉诺塔
    int n=3;

    hanoi(n,'A','B','C');
    cout << "Total steps: " << ans << endl;

    return 0;
}
