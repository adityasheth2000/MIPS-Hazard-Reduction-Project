#include"Algorithm.cpp"
#include<bits/stdc++.h>
using namespace std;

/*
    Statement type: add w1 w2 w3
*/

vector<string> Split_into_words(string str) 
{ 
    vector<string> v;
    string word = ""; 
    for (auto x : str) 
    { 
        if (x == ' ') 
        { 
            v.push_back(word); 
            word = ""; 
        } 
        else
        {
            word = word + x;
        }
    }
    v.push_back(word);
    return v;
}

bool check_dependency(string i1, string i2)
{
    vector<string> s1,s2;
    s1 = Split_into_words(i1);
    s2 = Split_into_words(i2);
    int i,j,k;
    for(i=1;i<s1.size();i++)
    {
        if(s2[1]==s1[i])
        {
            return true;
        }
    }

    for(i=1;i<s2.size();i++)
    {
        if(s1[1]==s2[i])
        {
            return true;
        }
    }
    return false;    
}
int main()
{
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    vector<string> instructions;
    while(true)
    {
        string cur;
        getline(cin,cur);
        if(cur=="end")
        {
            break;
        }
        instructions.push_back(cur);
    }
    int n=instructions.size();
    vector<set<int>> in(n),out(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(check_dependency(instructions[i],instructions[j]))
            {
                out[i].insert(j);
                in[j].insert(i);
            }
        }
    }
    vector<int> ans=reorder_instructions(out,in);
    for(int i=0;i<ans.size();i++)
    {
        cout<<instructions[ans[i]]<<endl;
    }
}
