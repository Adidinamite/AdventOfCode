#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
int most[33];
int least[33];
int main()
{
    char x[33];
    int size;
     vector <vector <int>> vec;
     int gr = 0;//oxygen generator rating
     int sr = 0;// co2 scrubber rating
     while(cin.getline(x, 32))
     {
         size = strlen(x);
         vector <int > line;
         for(int i = 0; i<size; i++)
         {
             int num = x[i] - '0';
             line.push_back(num);
         }
         vec.push_back(line);
     }
        int cnt1m = 0, cnt1l = 0, cnt0m = 0, cnt0l = 0, pos = 0;
        int modifm = -1, modifl = -1;
        for(pos =0; pos<size; pos++)
        {
            cnt1m = cnt1l = cnt0m = cnt0l = 0;
             for(int i =0; i< vec.size(); i++)
             {
                 if(pos!=0){
                     if(modifm != vec[i][pos-1])
                     {
                         most[i] = -1;
                     }
                    if(modifl != vec[i][pos-1])
                    {
                        least[i] = -1;
                    }
             }
                 if(most[i] == 0)
                 {
                     if(vec[i][pos] == 1)
                         cnt1m ++;
                     else
                         cnt0m ++;
                 }
                 if(least[i] == 0)
                 {
                     if(vec[i][pos] == 1)
                         cnt1l ++;
                     else
                         cnt0l ++;
                 }
             }
             if(cnt1m >= cnt0m)
             {
                 gr += (1 << size-1-pos);
                 modifm = 1;
             }
             else if(cnt1m < cnt0m)
             {
                 modifm = 0;
             }
             if((cnt1l < cnt0l) ||(cnt1l == 1 && cnt0l == 0))
             {
                 sr += (1 << size-1-pos);
                 modifl = 1;
             }
             else if(cnt1l >= cnt0l)
             {
                 modifl =0;
             }
             //cout << cnt1m << " "<<cnt0m<<" "<< cnt1l <<" "<< cnt0l<< endl;
            //cout << modifm << " "<<modifl<< endl;
        }
    cout << gr*(sr-1)<<endl;
    return 0;
}
