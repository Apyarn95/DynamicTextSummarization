#include<bits/stdc++.h>
using namespace std;

// Use expected value 

vector<vector<int> >sequence;
vector<vector<pair<int,double> > > graph;

void recur(int u,vector<int> &vis,vector<int>&seq)
{
  if(vis[u]==1) return ;	
  seq.push_back(u);
  vis[u] = 1;
  vector<pair<double,int> > choice;
  for(auto x:graph[u])
  if(!vis[x.first])
  {
    choice.push_back({x.second,x.first});
  }
  
  sort(choice.begin(),choice.end());
  
  for(auto x:choice)
  {
  	recur(x.second,vis,seq);
  }

}

void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("graph_10.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

vector<int>dict;
vector<int> contract(int alp,int n)
{
   dict.assign(n+1,0);	
   for(int i=0;i<sequence.size();i++)
   {
   	for(int j=0;j<alp;j++)
   	{
   		dict[sequence[i][j]]++;
   	}
   }

   vector<pair<int,int> > seq;

   for(int i=1;i<=n;i++)
   {
   	cout<<dict[i]<<" ";
   	seq.push_back({dict[i],i});
   }
   cout<<"\n";

   sort(seq.begin(),seq.end(),greater<pair<int,int> >());
   
   vector<int>res;
   for(int i=0;i<alp;i++)
   { 
      res.push_back(seq[i].second);
   }
   return res;
}
int main()
{

    pr_init();

    int n = 10;

    graph.assign(n+1,vector<pair<int,double> >());
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		double w;
    		cin >> w;
    		graph[i].push_back({j,w});
    	}
    }
    
    int alpha = 7;

    for(int i=1;i<=n;i++)
    {
      vector<int>vis(n+1,0),cur_seq;	
      recur(i,vis,cur_seq);
      sequence.push_back(cur_seq);
    }
    
    vector<int>res = contract(alpha,n);
    for(auto x: res) cout<<x<<" ";

	return 0;
}