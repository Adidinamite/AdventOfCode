#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>;
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
char delimiter, code[10], code2[10];
int uniq[] = {2, 3, 4, 7};
int cnt_unique= 0;
int main(){
    while(cin >> code >> code >> code>> code >> code >> code>> code >> code >> code>>code>>delimiter)
    {for(int i = 1; i<=4; i++)
        {
            cin >> code2;
            int size = strlen(code2);
            for(int j = 0; j< 4; j++)
            {
                if(size == uniq[j])
                    cnt_unique++;
            }
        }
    }
    cout << cnt_unique<<endl;
}


