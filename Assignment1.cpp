# include<iostream>
# include<string.h>
using namespace std;


struct student
{
    int rno;
    char name[20];
    float sgpa;
};

void accept(struct student list[],int size);
void display(struct student list[80]);
void bubblesort(struct student list[]);
void insertsort(struct student list[]);
void search(struct student list[]);
void binarysearch(struct student list[]);
void Quicksort(struct student list[]);

void accept( struct student list[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        cout<< " Enter rollno, name and sgpa:";
        cin>> list[i].rno >> list[i].name >> list[i].sgpa;
    }
}

void display ( struct student list[],int size)
{
    int i;
    cout <<"\nRollno \t Name \t sgpa \n";
    for(i=0; i<size; i++)
    {
        cout <<"\n" <<list[i].rno<<"\t"<< list[i].name <<"\t" <<list[i].sgpa;
    }
}

void bubblesort ( struct student list[],int size)
{
    int i,j;
    struct student temp;
    for(i=0; i<size-1; i++)
    {
      for (j=0; j<(size-1-i); j++) 
      {
          if (list[j].rno>list[j+1].rno)
          {
              temp = list[j];
              list[j]=list[j+1];
              list[j+1]=temp;
          }
      } 
    }
}

void insertsort(struct student list[],int size)
{
    int k,j;
    struct student temp;

    for(k=1;k<size;k++)
    {
        temp= list[k];
        j=k-1;
        while(strcmp(list[j].name,temp.name)>0 && j>0)
        {
            list[j+1]=list[j];
            --j;
        }
        list[j+1]=temp;
    }
}

void search(struct student list[],int size)
{
    float sgpa;
    int i;
    cout<<"\n enter sgpa: ";
    cin>>sgpa;

    cout<<"\n Rollno\t Name\t SGPA\n";
    for(i=0;i<size;i++)
    {
        if(sgpa==list[i].sgpa)
        {
            cout<<"\n" <<list[i].rno<<"\t"<< list[i].name <<"\t" <<list[i].sgpa;
        }
    }
}

void binarysearch (struct student list[],int size)
{
	int k, upper, lower, mid;
	char search[80];
	cout<<"Enter the name of student";
	cin>>search;
	
	lower=0;
	upper=size-1;
	mid=(lower+upper)/2;
	
	while(lower <= upper)
	{
		if(strcmp(list[mid].name,search)<0)
		{
			lower=mid+1;
	}
			else if(strcmp(list[mid].name,search)==0)
			{
				cout<<"\n"<<list[mid].rno<<"\t"<<list[mid].name<<"\t"<<list[mid].sgpa;
				break;
			}
			else
			{
				upper=mid-1;
				mid=(lower+upper)/2;
			}
			if(lower > upper)
			{
				cout<<search<<"Not found in the list";
			}
		
	}
}

int partition(struct student list[], int left, int right)
{
    int pivot = list[left].sgpa;
    int i = left + 1;
    int j = right;
    do
    {
        while (list[i].sgpa <= pivot && i <= right)
        {
            i++;
        }
        while (list[j].sgpa > pivot)
        {
            j--;
        }
        if (i < j)
        {
            struct student o = list[i];
            list[i] = list[j];
            list[j] = o;
        }
    }while (i < j);
    struct student temp = list[left];
    list[left] = list[j];
    list[j] = temp;
    return j;
}

void QuickSort(struct student list[], int left, int right)
{
    if (left < right)
    {
        int partitionIndex = partition(list, left, right);
        QuickSort(list, left, partitionIndex - 1);
        QuickSort(list, partitionIndex + 1, right);
    }
}

int main()
{
	int ch, i, size;
    struct student data[20];
    
    cout<<"Enter the number of records: ";
    cin>>size;
    accept (data,size);

    cout <<"\n 1: Bubble sort";
    cout <<"\n 2: Insertion sort";
    cout <<"\n 3: Search";
    cout <<"\n 4: Binary Search";
    cout <<"\n 5; Select your choice";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
        bubblesort(data);
        display(data);
        break;

        case 2:
        insertsort(data);
        display(data);
        break;

        case 3:
        search(data);
        display(data);
        break;

        case 4:
        binarysearch(data);
        display(data);
        break;
        
        case 5:
        QuickSort(data,0,size-1);
		display(data);
		break;	

        default:
        cout << " Invalid choice ";
        return 0;
    }
}
