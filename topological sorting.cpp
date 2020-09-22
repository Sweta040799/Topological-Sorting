/*******************************************
********* Code By Sweta ********************
********************************************/


/************************************************************
*******Code of Topological Sorting for directed Graph********
*****Through Adjaency List Method****************************
************************************************************/

#include<bits/stdc++.h>
using namespace std;

class graph{
	int vertex;
	list <int> *a;
	topo_recur(int r,int visit[],stack <int> &s);
	public:
		graph(int v);
		add_to_list(int x,int y);
		topo();
};
graph::graph(int v){
	this->vertex=v;
	a=new list <int> [v];
}
graph::add_to_list(int x,int y){
	a[x].push_back(y);
}
graph::topo_recur(int r,int visit[],stack <int> &s){
	
	visit[r]=1;
	

	
	list <int>::iterator it;
	for(it=a[r].begin();it!=a[r].end();it++){
		int temp=*it;
		if(!visit[temp])
		topo_recur(temp,visit,s);
	}
	s.push(r);
	
}

graph::topo(){
	stack <int> s;
	int *visit=new int[vertex];
	
	for(int i=0;i<vertex;i++)
	  visit[i]=0;
	for(int i=0;i<vertex;i++){
		if(visit[i]==0)
		topo_recur(i,visit,s);
	}
	
	while(s.empty()==false){
		cout<<s.top()<<" ";
		s.pop();
	}
}


int main(){
	int v,e;
	cin>>v>>e;
	graph ob(v);
	while(e--){
		int u,v;
		cin>>u>>v;
		ob.add_to_list(u,v);
	}
	ob.topo();
}

/***********************************************
***************OUTPUT***************************
***********************************************/

/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
5 4 2 3 1 0
--------------------------------
Process exited after 43.48 seconds with return value 0
Press any key to continue . . .
*/
