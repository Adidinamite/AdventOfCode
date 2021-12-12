#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int mat[12][12];
const int DIM = 10;
bool valid(int sti, int stj)
{
    return (sti >=1 && sti <=DIM && stj>=1 && stj<=DIM);
}
void update(int i, int j)
{
    mat[i][j] ++;
    if(mat[i][j] == 10)
    {
        for(int sti = i-1; sti <= i+1; sti++)
        {
            for(int stj = j-1; stj <= j+1; stj++)
            {
                if(valid(sti,stj))
                    update(sti,stj);
            }
        }
    }
}
int p1()
{
    int flashes = 0;
    for(int step = 1; step <= 100; step++) {
        for (int i = 1; i <= DIM; i++) {
            for (int j = 1; j <= DIM; j++) {
                update(i, j);
            }
        }
        for (int i = 1; i <= DIM; i++) {
            for (int j = 1; j <= DIM; j++) {
                if (mat[i][j] >= 10) {
                    flashes++;
                    mat[i][j] = 0;
                }
            }
        }
    }
    return flashes;
}
int p2()
{
    bool sync = false;
    int step;
    for(step = 101; !sync; step++)
    {
        int cate_flashuri=0;
        for (int i = 1; i <= DIM; i++) {
            for (int j = 1; j <= DIM; j++) {
                update(i, j);
            }
        }
        for (int i = 1; i <= DIM; i++) {
            for (int j = 1; j <= DIM; j++) {
                if (mat[i][j] >= 10) {
                    cate_flashuri++;
                    mat[i][j] = 0;
                }
            }
        }
        if(cate_flashuri==100)
            sync = true;
    }
    return step-1;
}
int main(){
    string line;
    for(int i = 1; i<=DIM; i++)
    {
        cin >> line;
        int size = line.size();
        for(int j = 0; j< size; j++)
        {
            mat[i][j+1] = (line[j] - '0');
        }
    }
    //part 1
    cout<<p1()<<endl;
    //part 2
    cout<<p2();

}
