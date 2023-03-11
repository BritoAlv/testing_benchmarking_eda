#include<bits/stdc++.h>
using namespace std;
class Graph
{
    private:
    vector<int> *A;

    public:
        int n_vertex, n_edgess;
        Graph(int n_vertex, int n_edges);
        void BFS(int start, int* d);
        void DFS(int start, bool *visited);
        void Mostrar();
};
int Generar_Grafo_Conexo(vector<int> *A, int n_vertex, int n_edges);




int main()
{
    srand(time(NULL));
    int n_vertex = 5, n_edges = 7;
    int d[n_vertex];
    bool visited[n_vertex];
    fill(d, d + n_vertex, 0);
    Graph J(n_vertex, n_edges);
              J.Mostrar();
    J.BFS(3, d);
              cout<<"BFS distances:\n";
              for(int i = 0; i < n_vertex; i++)
                    cout<<d[i]<<' ';
    J.DFS(3, visited);
}



Graph::Graph(int n_vertex, int n_edges)        
{
    Graph::n_vertex = n_vertex;
    Graph::n_edges = n_edges;
    A = new vector<int>[n_vertex];
    Graph::n_edges += Generar_Grafo_Conexo(A, n_vertex, n_edges);
}
void Graph::BFS(int start, int* d)
{
    queue<int> q;
    d[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        for(int vecino : A[q.front()])
            if((d[vecino] == 0)&&(vecino != start))
            {
                d[vecino] = d[q.front()] + 1;
                q.push(vecino);
            }
        q.pop();
    }
}
void Graph::DFS(int start, bool *visited)
{
    visited[start] = true;
    for(int vecino : A[start])
        if(!visited[vecino])
            DFS(vecino, visited);
}
void Graph::Mostrar()
{
    for(int i = 0; i < n_vertex; i++)
    {
        for(int x : A[i])
            cout<<x<<' ';
        cout<<'\n';
    }
}
int Generar_Grafo_Conexo(vector<int> *A, int n_vertex, int n_edges)
{
    bool B[n_vertex];
    pair<int, int> aux[n_vertex*(n_vertex-1)/2 + 1];
    for(int i = 1, k = 0; i < n_vertex; i++)
        for(int j = 0; j < i; j++)
            aux[k++] = make_pair(i, j);
    random_shuffle(aux, aux + n_vertex*(n_vertex-1)/2 + 1);
    for (int i = 0; i < n_edges; i++)
    {
        A[aux[i].first].push_back(aux[i].second);
        A[aux[i].second].push_back(aux[i].first);
        B[aux[i].first] = true;
        B[aux[i].second] = true;
    }
    //A continuacion hacemos q el grafo sea conexo, adding a few vertices
    int added = 0;
    for (int i = 0; i < n_vertex; i++)
        if(!B[i])
        {
            int k = rand()%n_vertex;
            A[i].push_back(k);
            A[k].push_back(i);
            added++;
        }
    //En el futuro aqui insertare un algoritmo q elimine aristas sin vender
    //la conexidad hasta quedarnos en el numero de aristas que fue pasado
    //por parametros
    //Mientras tanto, tan solo retorno el valor d aristas d mas q debi add
    return added;
}