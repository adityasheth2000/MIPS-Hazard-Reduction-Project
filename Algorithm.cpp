#include<bits/stdc++.h>
using namespace std;
vector<int> reorder_instructions(vector<set<int>> &out,vector<set<int>> &in)
{
	int n=out.size();
	set<int> candidate_nodes;// candidate nodes which can be removed at any stage, all the dependent instructions have been executed
	int dependancy[n];//0 means candidate node, -1 means already done, +ve number is trivial.
	// memset(dependancy,0,sizeof(dependancy));
	for(int i=0;i<n;i++)
	{
		dependancy[i]=in[i].size();
		if(dependancy[i]==0)
		{
			candidate_nodes.insert(i);
		}
	}
	
	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		assert(candidate_nodes.size()>0);
		if(i==0)
		{		
			auto v=candidate_nodes.begin();
			ans.push_back(*v);
			candidate_nodes.erase(v);
			dependancy[*v]=-1;
		}
		else if(i==1)
		{
			for(auto &x: candidate_nodes)
			{
				if(!out[ans[i-1]].count(x))
				{
					ans.push_back(x);
					dependancy[x]=-1;
					candidate_nodes.erase(x);
					break;
				}
			}
		}
		else
		{			
			for(auto &x: candidate_nodes)
			{
				if(!out[ans[i-1]].count(x) && !out[ans[i-2]].count(x))
				{
					ans.push_back(x);
					dependancy[x]=-1;
					candidate_nodes.erase(x);
					break;
				}
			}
		}
		if(ans.size()==i)
		{
			auto v=candidate_nodes.begin();
			ans.push_back(*v);
			candidate_nodes.erase(v);
			dependancy[*v]=-1;
		}
		for(auto x: out[ans[i]])
		{
			dependancy[x]--;
			if(dependancy[x]==0)
			{
				candidate_nodes.insert(x);
			}
		}
	}
	return ans;
}