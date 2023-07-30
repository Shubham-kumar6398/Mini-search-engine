#include <windows.h>
#include "database.cpp"
using namespace std;
vector<string>input()
{
    vector<string>v;
    string str;
    cout<<"Enter your query"<<endl;
    getline(cin,str);
    for(auto&i : str)
    {
        i = tolower(i);
    }
    string a;
    for(int i = 0;i<=str.size();i++)
    {
        if(i == str.size()||str[i] == ' ')
        {
            v.push_back(a);
            a = "";
        }
        else
        {
            a = a + str[i];
        }
    }
    return v;
}
void openURL(char link[])
{
    ShellExecute(NULL, NULL, link, NULL, NULL, SW_SHOWNORMAL);
    return;
}
int main(){
    unordered_map<string,string>map_database = mapping();
    unordered_map<string,string>output;
    vector<string>query = input();
    
    for(auto i : query)
    {
        if(map_database.find(i)!= map_database.end())
        output[i] = map_database[i];
    }
    int size = output.size();
    if(size==0)
    {
        cout<<"Sorry no data available in my database\nRedirecting to Google database";
        char link[1000] = "https://www.google.com/";
        openURL(link);
    }
    for(auto i : output)
    {
        char link[1000];
        int a = 0;
        for(auto j : i.second)
        {
            link[a]= j;
            a++;
        }
        openURL(link);
        if(size>1){
            cout<<"Press 'n' for next result or any other key to exit"<<endl;
            char c;
            cin>>c;
            if(c=='n'||c=='N')
            {
                size--;
                continue;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}