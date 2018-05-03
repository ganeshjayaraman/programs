#include<iostream>
#include<list>
#include<stack>

using namespace std;

class graph {
	int v;
	list<int> *adj;
	bool *visited;

	public :
		graph(int v) {
			this->v = v;
			adj = new list<int>[v];
		}

		void addEdge(int v,int w) {
			cout<<v<<"  "<<w<<endl;
			adj[v].push_back(w);
		}

		void dfsUtil(int v, list<int> &l) {
			visited[v] = true;

			list<int>:: iterator i;

			for(i=adj[v].begin(); i!= adj[v].end(); i++)
				if(visited[*i] == false){
					//cout<<"val : "<<*i<<endl;
					dfsUtil(*i,l);
					l.push_back(*i);
				}			

		} 

		void dfs(int start) {
			int i;
			list<int> l;

			visited = new bool[this->v];

			for(i=0;i<this->v;i++)
				visited[i] = false;

			if(visited[start] == false) {				
				dfsUtil(start,l);
				l.push_back(start);
			}

			for(i=0;i<this->v;i++) {
				if(visited[i] == false) {
					dfsUtil(i,l);
					l.push_back(i);			
				}
			}

			while(!l.empty()) {
				cout<<l.front()<<" ";
				l.pop_front();
			}
		}
};

int main() {
	graph g(6);

	g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.dfs(5);
}