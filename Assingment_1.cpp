#include<bits/stdc++.h>
using namespace std;

#define mod 100000007



// ticket class having the n:number of guest in group,
// ticketId:a unique ticketId for every ticket to validate,
// price: total price based on the age of every group member,
// arr:array to store the age of all the guest in group.


class ticket{
  
  public:
    int n;
    int *arr;
    int ticketId;
    int price;
   
    
    ticket(int n)
    {
        price=0;
        this->n=n;
        arr=new int[n];
        
        // for now I'm just taking a simple way to declare 
        // a unique ticketId(so the ticketId can be same)
        // later we can use different way to get different unique ticketId.
        
        ticketId=(n+price)%mod;
    }
    
    void getAges(int age[])
    {
        for(int i=0;i<n;i++)
        {
            if(age[i]<=2)
            {
                price+=0;
            }
            else if(age[i]>2 && age[i]<18)
            {
                price+=100;
            }
            else if(age[i]>=18 && age[i]<60)
            {
                price+=500;   
            }
            else
            {
                price+=300;
            }
            
            arr[i]=age[i];
        }
        
    }
    
    void ShowTicketDetails(){
        cout<<"ticketId: "<<ticketId<<endl;
        cout<<"Number of guest: "<<n<<endl;
        for(int i=0;i<n;i++)
	    {
	        cout<<"Guest "<<i+1<<" "<<"(age:"<<this->arr[i]<<")"<<endl;
	    }
    }

};




// using map as a database to validate 
// if the ticket has been already used or not
// we will validate it by using ticketId which 
// will be unique for every ticket if the ticketId is 
// present in database means it has been used 
// and a warning has to be generated else it is 
// valid and push it in database for future validation.

map<int,ticket>database;



int main()
{
    
    cout<<"!!!------------WELCOME TO ZOO------------!!!!"<<endl;
    
    ticket g1(5);
	int arr[]={10,2,30,14,25};
	g1.getAges(arr);
    	
    cout<<"Your ticketid:"<<g1.ticketId<<" TicketPrice: "<<g1.price<<endl;
	
	auto it=database.find(g1.ticketId);
	if(it==database.end())
	{
	   // if ticketId is not found means valid ticketId then show ticket details
	   // and add ticket in database
	    int id=g1.ticketId;
	    database.insert({id,g1});
	    g1.ShowTicketDetails();
	}
	else 
	{
	   // if ticketId is already present in database then warning generated 
	   
	    cout<<"!!!!  Please get a Valid Ticket  !!!!"<<endl;
	}

    return 0;
    
    
    // Written by: Omjee
    // Email id: singhomjee123@gmail.com
}