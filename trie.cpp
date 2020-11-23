
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define module 1000000007
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);                        
#define bs binary_search
#define mp make_pair
#define endl '\n'
#define Endl '\n'
#define vll vector<long long>
#define ss string

#define map1 map<char,node*> 

struct node{
	map<char,node*>m1;
	int x;
};
	
node* getnode()
{
	node* t=(node*)malloc(sizeof(node));
	t->x=0;
	return t;	
}	
void insert1(node* t,string s)
{
	node* temp,*h=t; int i=0,n=s.length();
	map1 m;
	for(i=0;i<s.length();i++)
	{
		m =h->m1;
		if(m.count(s[i]) > 0)   
		{
			// if given character is already present 
			h=m[s[i]];
		}
		else
		{    
			// else create node and insert in map
			temp=getnode();
			m.insert({s[i],temp});
			h->m1=m; 
			h=temp;		
		}
	}
	h->x=1;
}
		
void print_suggestions(node* p,string s)
{
	
	//  printing using DFS (recursion)
	// prints the suggestions if prefix is found
	node* h=p;
	map1 m=h->m1;
	
	
	if(m.size()==0)
	{
		// base condition
		cout<<s<<endl;
		return;
	}
	else if(h->x==1)
	{
		//if a word is a prefix of another present word
		// means if a word is ended at its parent index , that's why current x is 1 (h->x = 1)

		cout<<s<<endl;
	}
	
	auto it=m.begin();
	while(it!=m.end() )
	{
		// dfs for printing 
		print_suggestions(it->second,s + it->first);
		it++;
	}
	
}
int search(node* t,string s)
{
	// this function searches for the given string
	// if string is found then call print_suggestions() for printing the suggestions
	// else return;
	
	node* h=t;
	map1 m; string s1="";
	int i,n=s.length();
	
	for(i=0;i<n;i++)
	{
		m=h->m1;
		if(m.count(s[i]) > 0) 
		{
			 // if current character is present 
			h=m[s[i]];
			s1+=s[i];
		}
		else
		{
			return -1;
		}
	}
	
	// if prefix is found then calling print_suggestions() for printing suggestions
	node* p=h; 
	print_suggestions(p,s1);
		
}
int main()
{
	int i=0,n,q,f;
	string s="";
	node* head=new node;
	head->x=0;
	cout<<"Enter no. of words for Insertion : ";
	cin>>n;
	cout<<"Enter "<<n<<" words : \n";
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert1(head,s);
	}
	cout<<"Enter no. of Queries : ";
	cin>>q;
	i=0;
	while(i < q)
	{
		cout<<"Enter "<<i+1<<"  prefix : ";
		cin>>s;
		f= search(head,s);
		if(f==-1)
			cout<<"No Word Found\n";
			
		i++;	
	}
//	insert1(head,"pakdf");
//	insert1(head,"pa");	
//	insert1(head,"dada");
//	insert1(head,"paka");
//	insert1(head,"daja");
//	insert1(head,"d");	
//	search(head,"pa");
//	search(head,"pak");
}
