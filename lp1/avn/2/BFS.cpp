#include<bits/stdc++.h> 
#include<omp.h>
using namespace std; 
  
class Graph 
{ 
    int V;    
    list<pair<int,int> > *adj;    
public: 
    Graph(int V);  
    void addEdge(int v, int w, int weight);
    void BFS(int s); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<pair<int,int> >[V]; 
} 
  
void Graph::addEdge(int v, int w,int weight) 
{ 
    adj[v].push_back(make_pair(w,weight)); 
} 
  
void Graph::BFS(int s) 
{ 
    vector<bool> visited(V, false); 
    priority_queue<int> stack; 
    stack.push(s); 
  
    while (!stack.empty()) 
    {  
        s = stack.top(); 
        stack.pop(); 
        if (!visited[s]) 
        { 
            cout << s << " "; 
            visited[s] = true; 
        } 
  		
  	//list<pair<int,int> > :: iterator i;	
  		#pragma omp single	
        for (list<pair<int,int> > :: iterator i = adj[s].begin(); i != adj[s].end(); ++i) 
            if (!visited[(*i).first]) 
                stack.push((*i).first); 
    } 
} 
  
int main() 
{ 
    Graph g(5);  
    g.addEdge(1, 0, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(2, 1, 2); 
    g.addEdge(0, 3, 9); 
    g.addEdge(1, 4, 4); 
  
    cout << "Following is Best First Traversal\n";
    #pragma omp parallel
    { 
    	g.BFS(2);
    } 
  	cout<<'\n';
    return 0; 
} 
