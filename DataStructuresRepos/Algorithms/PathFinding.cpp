// C++ program to represent undirected and weighted graph
// using STL. The program basically prints adjacency list
// representation of graph
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
const int INF= 1e9;
// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}


int shortestPath(vector<pair<int, int> > graph[5], int dest){
    int* pathTo = new int[5];//distance from the source to the given index
    int* parent  = new int[5];//the parent that comes right before a the index
    pathTo[0] = 0;
    parent[0] = -1;
    for(int i = 1;i < 5;i++){
        pathTo[i] = INF;
        parent[i] = -1;
    }
    int curr = 0;//the current index we are going to 
    bool visited[5] = {false,false,false,false,false};//keeping track of the places we have soon
    while(curr != dest && curr != -1){
        visited[curr] = true;//
        int minPath = INF;//the distance value for the shortest path 
        int minIndex = -1;//the index parent that reaches that shortest path
        /*
        The goal of this for loop is to figure out the shortest path of the incoming vertexes
        */
        for(int i = 0 ;i < graph[curr].size();i++){
            int v = graph[curr][i].first;//the position we are currently comparing the current to
            int w = graph[curr][i].second;//the weight to get to that that child
            //checking if the current path is shorter than path to that vertext we have already seen
            //makiing sure we have not already visited that place as a parent
            if(!visited[v] && pathTo[curr]+w < pathTo[v]){
                pathTo[v] = pathTo[curr]+w;
                parent[v] = curr;
            }
        }
        /*
        The goal of this for loop is to figure out where we are going next
        */
        for(int i = 0;i < 5;i++){
            //determining the next postion to go to by chekcing which out of the 
            //incoming vertecies we on track to visit is the shortest distance
            if(!visited[i] && pathTo[i] < minPath){
                minPath = pathTo[i];
                minIndex = i;
            }
        }
        curr = minIndex;
    }
    
    return pathTo[dest];
}
// Driver code
int main()
{
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    cout<<"The shortest path to 4 is: "<<shortestPath(adj,3);
    return 0;
}