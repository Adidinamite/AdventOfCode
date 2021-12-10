#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("adv1.in");
ofstream cout("adv1.out");
char delimiter, code2[10];
map<char, char>alfabet;
int uniq[] = {2, 3, 4, 7};
int cnt_unique= 0;
int freq[80];
void wipe()
{
    for(int i = (int)'a' ;i <= (int)'g';i++)
    {
        freq[i] =0;
        alfabet[(char)i] = 0;
    }
}
vector<string>numbers(11, "");
vector<string>cifre(5, "");
void change_word(string &x)
{
    for(int i = 0; i< x.size(); i++)
    {
        for(auto it = alfabet.begin(); it != alfabet.end(); it++)
        {
            if(x[i] == it->second)
            {
                x[i] = it->first;
                //break;
            }
        }
    }
    sort(x.begin(),x.end());
}
vector<string>initial{"abcef","cf","acdeg","acdfg","bcdf","abdfg","adbefg","acf","abcdefg","abcdfg"};
int main(){
    
    while(cin >> numbers[1] >> numbers[2] >> numbers[3]>> numbers[4] >> numbers[5] >> numbers[6]>> numbers[7] >> numbers[8] >> numbers[9]>>numbers[10]>>delimiter)
    {
        int digitnr=0;
        string one="", four="";
        char freq8[3];
        char freq7[3];
        freq8[0]= freq8[1] = freq7[0] = freq7[1] = 0;
        int freq8_cnt = -1, freq7_cnt=-1;
        wipe();
        for(int it = 1; it<= 10; it++)
        {
            if(numbers[it].size() == 2)
                one = numbers[it];
            if(numbers[it].size() == 4)
                four = numbers[it];
            for(int i = 0; i< numbers[it].size();i++)
            {
                freq[numbers[it][i]]++;
            }
        }
        for(int i = (int)'a' ;i <= (int)'g';i++)
        {
            //cout << (char)i << " "<< freq[i] << endl;// b = 6, e = 4, f = 9,aparitii unice
            if(freq[i] == 6)
                alfabet['b'] = char(i);
            else if(freq[i] == 4)
                alfabet['e'] = char(i);
            else if(freq[i] == 9)
                alfabet['f'] = char(i);
            else if(freq[i] == 8)
                freq8[++freq8_cnt] = char(i);
            else if(freq[i] == 7)
                freq7[++freq7_cnt] = char(i);
        }
        for(int i = 0; i<=1; i++)
        {
            if(one[i]!= alfabet['f'])
            {
                alfabet['c'] = one[i]; // unique number of letters
            }
        }
        for(int i = 0; i<=1; i++)
        {
            if(freq8[i] != alfabet['c'])
                alfabet['a'] = freq8[i];
        }
        for(int i = 0; i<=3; i++)
        {
            if(four[i]!= alfabet['f'] && four[i]!= alfabet['c'] && four[i]!=alfabet['b'])
            {
                alfabet['d'] = four[i]; // unique number of letter
            }
        }
        for(int i = 0; i<=1; i++)
        {
            if(freq7[i] != alfabet['d'])
                alfabet['g'] = freq7[i];
        }

        cin>>cifre[1]>>cifre[2]>>cifre[3]>>cifre[4];
        for(int i = 1; i<=4; i++)//first part
        {
            int size = cifre[i].size();
            for(int j = 0; j< 4; j++)
            {
                if(size == uniq[j])
                    cnt_unique++;
            }
        }
        for(int i = 1; i<=4; i++)
        {
            change_word(cifre[i]);
            for(int j = 0; j<initial.size(); j++)
            {
                if(cifre[i] == numbers[j])
                {
                    digitnr = 10 * digitnr + j;
                    //break;
                }
            }
        }
        cout<<digitnr<<endl;
    }
    cout << cnt_unique<<endl;//first part
}

