#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int main()
{
    int x1, x2, cnt=0;
    cin >> x1;
    while(cin >> x2)
    {
        if(x2 > x1)
            cnt++;
        x1 = x2;
    }
    cout << cnt;
}
// R : 1475
