//Krushal's Algorithm

# include<iostream>
using namespace std;

class graph
{
	int source, dest, weight;
	public:
		void accept();
		void display();
		void sort(graph *[], int);
		int findparent(int, int*);
};
void graph::accept()
{
	cout<<"\nEnter source vertex: ";
	cin>>source;
	cout<<"\nEnter Destination vertex: ";
	cin>>dest;
	cout<<"\nEnter the weight ofmthe edge: ";
	cin>>weight;
}