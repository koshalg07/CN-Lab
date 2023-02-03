#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int bellman_ford(int G[20][20], int V, int E, int edge[20][2]){
    int i,u,v,k,distance[20],parent[20],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000 , parent[i] = -1 ;
    cout<<("Enter source: ");
    cin>>S;
    distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<V;i++)
                cout<<"Vertex "<<(i+1)<<" -> cost = "<<distance[i]<<" parent = "<<parent[i]<<endl;

        return flag;
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    cout<<("BELLMAN FORD\n");
    cout<<("Enter no. of vertices: ");
    cin>>V;
    cout<<("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            cin>>G[i][j];
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    if(bellman_ford(G,V,k,edge))
        cout<<("\nNo negative weight cycle\n");
    else 
        cout<<("\nNegative weight cycle exists\n");
    return 0;
}