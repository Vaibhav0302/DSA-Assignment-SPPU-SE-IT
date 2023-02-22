# include<iostream>
using namespace std;


int cqueue[5];
int front =-1, rear=-1, n=5;

void enqueue(int val)
{
	if((front == 0 && rear ==n-1) ||(front == rear+1))
	{
		cout<<"Queue Overflow"<<endl;
		return;
	}
	if(front==-1)
	{
		front = 0;
		rear = 0;
	}
	else{
		if(rear==n-1)
		rear=0;
		else
		rear=rear+1;
	}
	cqueue[rear]=val;
}
void dequeue()
{
	if(front==-1)
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	cout<<"Element deleted from queue is: "<<cqueue[front]<<endl;
	
	if(front == rear)
	{
		front=rear=-1;
	}
	else{
		if(front==n-1)
			front = 0;
			else
			front=front+1;
	}
}

void display()
{
	int f=front, r=rear;
	if(front==-1)
	{
		cout<<"Queue is empty: "<<endl;
		if(f<=r)
		{
			while(f<=r)
			{
				cout<<cqueue[f]<<" ";
				f++;
			}
		}
		else
		{
			while(f<=n-1)
			{
				cout<<cqueue[f]<<" ";
				f++;
			}
			f=0;
			while(f<=r)
			{
				cout<<cqueue[f]<<" "<<endl;
			}
		}
	}
}

int main()
{
	int ch , val;
	cout<<"\n1.Enque\n2.Dequeue\n3.Display\n4.Exit"<<endl;
	do{
	cout<<"Enter your choice: "<<endl;
	cin>>ch;
	
	switch(ch)
	{
		case 1:
			cout<<"Enter element in queue: "<<endl;
			cin>>val;
			enqueue(val);
			break;
		case 2:
			cout<<"Deleted element from queue is: "<<endl;
			cin>>val;
			dequeue();
			break;
		case 3:
			cout<<"The queue is: "<<endl;
			display();
			break;
		case 4:
			cout<<"Exit"<<endl;
			break;
		default:cout<<"Invalid choice: "<<endl;	
	}
	
	}while(ch!=4);
	return 0;
}
/*class CQ
{
	int front,rear,n;
	public:
		CQ()
		{
			front=rear=-1;
		}
		enqueue(int[],int);
		dequeue(int[]);
};

int CQ::enqueue(int queue[], int item )
{
	if(front==-1)
	front++;
	rear=(rear+1)%n;
	queue[rear]=item;
}

int CQ::dequeue(int queue[])
{
	int item;
	item=queue[front];
	front=(front+1)%n;
	return item;
}

int main()
{
	int queue[20];
	CQ q;
	int element,item;
	cout<<"Enter the element to inserted in queue:";
	cin>>element;
	q.enqueue(queue,element);
	item=q.dequeue(queue);
	cout<<"Deleted element is:"<<item;
}*/