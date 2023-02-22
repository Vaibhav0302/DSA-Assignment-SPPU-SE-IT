# include<iostream>
using namespace std;

class graph{
    int source,vertex,edge;
    int mat[20][20];
    int infinite=999;
    public:
        void getGraph();
        void displayMatrix();
        void display(int [],int [],int);
        int minimum(int [],bool []);
        void dijkstra();
};
void graph::getGraph()
{
    int s,d,w;
    cout<<"Enter the total no. of vertices : ";
    cin>>vertex;
    cout<<"Enter the total no. of edges : ";
    cin>>edge;
    for(int i=0;i<vertex;i++)
	{
        for(int j=0;j<vertex;j++)
		{
            mat[i][j]=0;
        }
    }
    for(int i=0;i<edge;i++)
	{
        cout<<"Enter the vertex u:";
        cin>>s;
        
        cout<<"Enter the vertex v: ";
        cin>>d;
        cout<<"Enter the weight of edge: ";
        cin>>w;
        mat[s][d]=w;
        mat[d][s]=w;
    }
}
void graph ::display(int a[],int b[],int c)
{
    int d[vertex]={0},n=0,e;
    cout<<"Vertex\tDistance\tPath\n";
    for(int i=0;i<vertex;i++)
	{
        cout<<i<<"\t"<<a[i]<<"\t";
        e=i;
        n=0;
        while(e!=c)
		{
            d[n]=e;
            e=b[e];
            n++;
        }
        d[n]=e;
        for(int j=n;j>0;j--)
		{
            cout<<d[j]<<"-";
        }  
        cout<<d[0];
        cout<<"\n";
    }
}
void graph ::displayMatrix()
{
    for(int i=0;i<vertex;i++)
	{
        for(int j=0;j<vertex;j++)
		{
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
int graph ::minimum(int a[],bool b[])
{
    int min,max=infinite;
    for(int i=0;i<vertex;i++)
	{
        if(b[i]==false && a[i]<max)
		{
            max=a[i];
            min=i;
        }
    }
    return min;
}
void graph ::dijkstra()
{
    int parent[vertex],dist[vertex],s;
    bool visit[vertex];
    for(int i=0;i<vertex;i++)
	{
        parent[i]=i;
        dist[i]=infinite;
        visit[i]=false;
    }
    cout<<"Enter the source vertex";
    cin>>s;
    source=s;
    dist[s]=0;
    for(int i=0;i<vertex;i++)
	{
        s=minimum(dist,visit);
        visit[s]=true;
        for(int j=0;j<vertex;j++)
		{
            if(mat[s][j]!=0 && visit[j]==false && dist[s]+mat[s][j]<dist[j])
			{
                dist[j]=dist[s]+mat[s][j];
                parent[j]=s;
            }
        }
    }
    display(dist,parent,source);
}

int main()
{
	graph g;
	g.getGraph();
	cout<<"\n\n";
	g.displayMatrix();
	cout<<"\n\n";
	g.dijkstra();

}