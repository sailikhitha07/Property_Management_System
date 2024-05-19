#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<string.h>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<sstream>

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "Your SQL password";

int qstate,qstate1;
MYSQL mysql,* conn;
MYSQL_ROW row;
MYSQL_RES* res;

class database_connection
{	
	public :
		static void toconnect()
		{
			if(!(conn = mysql_init(0)))
				 {
				 	cout << "ERROR:MySQL object could not be created" << endl;
				 }
			 else
		 		{
		 			if(!mysql_real_connect(conn,HOST,USER,PASS,"oopproj",3306,NULL,0))
			 		{
			 		cout << "ERROR:DataBase doesn't exist" << endl;
			 		cout << mysql_error(conn) << endl;
					}
					else
					{
						cout << "database connected to mysql :) "<< endl;	
					}
				}	
		}	
};

class signUp{
	private:
    char name[50], userName[50], password[20], emailID[30], AorC;
    long long int mobileNo;
    string sentence_aux ;
            char* consult;
			char* sentence;
			int nQueryState = 0;
			
	public :
    char getSignUpData(){

        cout << "Enter your name : \n";
        cin >> name ;
    
        try{
            cout << "Enter your mobile number : \n";
            cin >> mobileNo; 
            
            if(mobileNo < 1000000000 || mobileNo > 9999999999)
            throw mobileNo;

            cout << "Enter a username : \n";
            cin >> userName;
               
            cout << "Enter the password (Remember this password) : \n";
            cin >> password;
            
            cout << "Enter your Email ID : \n";
            cin >> emailID;

            cout << "Would you like to sell properties ( Enter Y/N ): \n";
            cin >>  AorC;
			
            switch(AorC)
            {
            	case 'Y':
            		
					sentence_aux="INSERT INTO admin(adminName,adminPhNo,adminUserName,adminPassword,adminEmailId) VALUES('%s','%llu','%s','%s','%s')";
            		sentence=new char[sentence_aux.length()+1];
					strcpy(sentence,sentence_aux.c_str());
					consult=new char[strlen(sentence)+strlen(name)+sizeof(long long int)+strlen(userName)+strlen(password)+strlen(emailID)];
					sprintf(consult,sentence,name,mobileNo,userName,password,emailID);            		
					cout << "Data added successfully"<< endl;

					cout<<"Signed Up as ADMIN"<<endl;
					
					
					break;

            		
	            case 'N':
					sentence_aux="INSERT INTO customer(Name,Ph_No,userName,password,emailId) VALUES('%s','%llu','%s','%s','%s')";
            		sentence=new char[sentence_aux.length()+1];
					strcpy(sentence,sentence_aux.c_str());
					
					consult=new char[strlen(sentence)+strlen(name)+sizeof(long long int)+strlen(userName)+strlen(password)+strlen(emailID)];
					sprintf(consult,sentence,name,mobileNo,userName,password,emailID);            		

					if(mysql_query(conn,consult)){
						cout<<"error:"<<mysql_error(conn)<<endl;
						rewind(stdin);
						getchar();
					}
					else{
						cout<<"\nSigned Up as a CUSTOMER"<<endl;
					} 
	            	break;
	            	
	            default:
	            		cout << "\nGive an appropriate Y/N input" << endl;
			}
        }

        catch(long long int num)
        {
            cout << "\nThe mobile number that you have entered " << num << " is invalid. Kindly check it again. \n";
            return 0;
        }
        
        return AorC;
    }
};

class checkCCredentials
{
    protected:
    string userCheck;
    string passCheck;
    public:
    int checkCData()
    {
        cout << "Hii welcome again !! " << endl;
        cout << "Enter your username : \n";
        cin >> userCheck;

        cout << "Enter the password :\n";
        cin >> passCheck;
        
        string sentence_aux1 = "SELECT password FROM customer WHERE userName = '" +userCheck + "' AND password= '" +passCheck + "'";
        
	    const char* qn = sentence_aux1.c_str();
	    qstate = mysql_query(conn, qn);	

		if(!qstate)
		{	
			res = mysql_store_result(conn);	
			    			
	        while(row = mysql_fetch_row(res))
	        {
	        	cout << "\nCORRECT PASSWORD\n" << endl;
				return 1;	        	
	    	}
		}                                 
		if(qstate)
		{
			cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
		}
		
		return 0;
	}
};

class checkACredentials
{
    protected:
    string checkUser1;
    string checkPass1;
    public:
    int checkAData()
    {
        cout << "Enter your username : \n";
        cin >> checkUser1;

        cout << "Enter the password :\n";
        cin >> checkPass1;
        
        string sentence_aux1 = "SELECT adminPassword FROM admin WHERE adminUserName = '" +checkUser1 + "' AND adminPassword= '" +checkPass1 + "'";
        
	    const char* qn = sentence_aux1.c_str();
	    qstate = mysql_query(conn, qn);	

		if(!qstate)
		{	
			res = mysql_store_result(conn);	
			    			
	        while(row = mysql_fetch_row(res))
	        {
	        	cout << "\nCORRECT PASSWORD...\n" << endl;
				return 1;	        	
	    	}
		}                                 
		if(qstate)
		{
			cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
		}
		
		return 0;
	}
};



class property : public checkACredentials
{
	private:
	char adminName[50],propType[30],price[10],location[100],propDimensions[20], propName[20];
		string sentence_aux ;
	    char* consult;
		char* sentence;
		int nQueryState = 0;	
	public:
	void getPropertyData()
	{
		cout << "Enter the user name of the admin : \n";
		cin >> adminName;
		
		cout << "Enter type of the property : \n";
		cout << "Specify the property as following types \n->Normal house (with 3,4,5,6 rooms)\n->Apartment \n->Flat in an apartment \n->Villa \n->Hut \n->Land\n";
		cin >> propType;
		
		cout << "Enter the price of the property: \n";
		cin >> price;
		 
		cout << "Enter the location of the property : \n";
		cin >> location;
		
		cout << "Enter the name of the property : \n";
		cin >> propName;
		
		cout << "Enter the dimensions of the property : \n";
		cin >> propDimensions;
		

		
		sentence_aux="INSERT INTO property(adminName,propType,price,location,propName,propDimensions) VALUES('%s','%s','%s','%s','%s','%s')";
            		sentence=new char[sentence_aux.length()+1];
					strcpy(sentence,sentence_aux.c_str());
					
					
					consult=new char[strlen(sentence)+strlen(adminName)+strlen(propType)+strlen(price)+strlen(location)+strlen(propName)+strlen(propDimensions)];
					sprintf(consult,sentence,adminName,propType,price,location,propName,propDimensions);            		
					cout << "Data added successfully"<< endl;
					
					if(mysql_query(conn,consult)){
						cout<<"error:"<<mysql_error(conn)<<endl;
					}
					else
					{
						cout<<"Property data added under the name of " << adminName <<endl;
					}		
	}
};

class signin:public property,public checkCCredentials
{
	private:
		int searchChoice;
		string loc;
		string propID;	
		int p;
		int bookch;	
	public :
		void viewProp()
		{
			string sentence_aux2 = "SELECT * FROM property ";
        
		    const char* qn1 = sentence_aux2.c_str();
		    qstate = mysql_query(conn, qn1);	
	
			if(!qstate)
			{
		        res= mysql_store_result(conn); 
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------\n"; 
		        printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", "ADMIN NAME" ,"PROPERTY TYPE" ,"PRICE OF PROPERTY", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS","PROPERTY ID");
				cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";			    			
		        while(row = mysql_fetch_row(res))
		        {
					printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", row[0], row[1], row[2], row[3], row[4], row[5],row[6]);
				}
			}
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
				cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
		}
		
		void searchProp()
		{

			cout << "Enter the way by which you want to search the property : \n" ;
			cout << "1.By location :\n"
				<< "2.By property ID : \n";
			cin >> searchChoice; 
				
				switch(searchChoice)
				{
					case 1 :
						locationSearch();
						break;
					case 2:
						pIDSearch();
						break;
				}
		}
		
		void locationSearch()
		{
			
			cout << "Enter the location to search : " << endl;
			cin >> loc;
			string searchLoc = "SELECT * FROM property WHERE location = '" +loc + "'";
			const char* searchLocArray = searchLoc.c_str();
			qstate = mysql_query(conn,searchLocArray );	

			if(!qstate)
			{	
				res = mysql_store_result(conn);	
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------\n"; 
		        printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", "ADMIN NAME" ,"PROPERTY TYPE" ,"PRICE OF PROPERTY", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS","PROPERTY ID");
			   	cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 		
		        while(row = mysql_fetch_row(res))
		        {
		        	printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", row[0], row[1], row[2], row[3], row[4], row[5],row[6]);		        	
		    	}
		    	
			}                                 
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 	
		}
		
		void pIDSearch()
		{

			cout << "Enter the property ID to search : " << endl;
			cin >> propID;
			string searchLoc = "SELECT * FROM property WHERE propertyID = '" +propID + "'";
			const char* searchLocArray = searchLoc.c_str();
			qstate = mysql_query(conn,searchLocArray );	

			if(!qstate)
			{	
				res = mysql_store_result(conn);	
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------\n"; 
		        printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", "ADMIN NAME" ,"PROPERTY TYPE" ,"PRICE OF PROPERTY", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS","PROPERTY ID");
			   	cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 		
		        while(row = mysql_fetch_row(res))
		        {
		        	printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", row[0], row[1], row[2], row[3], row[4], row[5],row[6]);		        	
		    	}
		    	
			}                                 
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 
		}
		
		void bookProp()
		{
			const char * array;
			char * sentence,*consult;
			cout << "Enter the property ID to book : \n" ;
			cin >> p;
			string pID = to_string(p);
			cout << "Check whether the details of the property you want to buy are these : \n" ;
			string pIDsearch ="SELECT * FROM property WHERE propertyID = '" +pID + "'";
			const char* pidarray =pIDsearch.c_str();
	
			qstate=mysql_query(conn,pidarray);
			
			if(!qstate)
			{	
				res = mysql_store_result(conn);	
				cout << "\n-----------------------------------------------------------------------------------------------------------------------\n"; 
		        printf("| %11s| %-15s| %-17s| %-10s| %-25s| %-15s| %-10s|\n", "PROPERTY ID" ,"ADMIN NAME" ,"PROPERTY TYPE" ,"PRICE", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS");
			   	cout << "-----------------------------------------------------------------------------------------------------------------------\n"; 		
		        while(row = mysql_fetch_row(res))
		        {
		        	printf("| %11s| %-15s| %-17s| %-10s| %-25s| %-15s| %-10s |\n", row[6], row[0], row[1], row[2], row[3], row[4], row[5]);	
		        	array = row[0];	   	
		    	}
			}                             
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			cout << "-----------------------------------------------------------------------------------------------------------------------\n"; 	
		
		
			
			
			cout << "DO YOU WANT TO BOOK THE PROPERTY ? \n";
			cout << "<< 1 >> YES \n";
			cout << "<< 2 >> NO \n";
			cin >> bookch;
			string m_num,e_id;
				if(bookch==1)
					{
						cout << "ENTER YOUR MOBILE NUMBER FOR THE ADMIN TO CONTACT YOU : \n";
						cin >> m_num;
						cout << "ENTER YOUR email ID FOR THE ADMIN TO CONTACT YOU : \n";
						cin >> e_id;
											
					char * sentence1;
					char * consult1;
					string pIDsearch ="SELECT * FROM property WHERE propertyID = '" +pID + "'";
					const char* pidarray =pIDsearch.c_str();
			
					qstate=mysql_query(conn,pidarray);
					
					if(!qstate)
					{	
						res = mysql_store_result(conn);	
			
				        while(row = mysql_fetch_row(res))
				        {	
				        	string row1=row[0];
				        	string row2=row[1];
				        	string row3=row[2];
				        	string row4=row[3];
				        	string row5=row[4];
				        	string row6=row[5];
				        	string row7=row[6];
				        	
				        	const char * user = userCheck.c_str();
				        	const char * m_num1 = m_num.c_str();
				        	const char * e_id1= e_id.c_str();
							string sentence_aux2="INSERT INTO booked(adminName,bookedCustName,propType,price,location,propNmae,propDimensions,propertyID,cust_num,cust_id) VALUES('" +row1+"','" +userCheck + "','" +row2 + "','" +row3 + "','" +row4 + "','" +row5 +"','" +row6 + "','" +row7 + "','" +m_num +"','" +e_id +"')";
		            		char * sentence1=new char[sentence_aux2.length()+1];
		            		
							strcpy(sentence1,sentence_aux2.c_str());                                        
							
							consult1=new char[strlen(sentence1)+strlen(row[0])+strlen(user)+strlen(row[1])+strlen(row[2])+strlen(row[3])+strlen(row[4])+strlen(row[5])+strlen(row[6])+strlen(m_num1)+strlen(e_id1)];
							sprintf(consult1,sentence1,row[0],user,row[1],row[2],row[3],row[4],row[5],row[6],m_num1,e_id1); 
							
								if(mysql_query(conn,consult1))
								{
								cout<<"error:"<<mysql_error(conn)<<endl;
								rewind(stdin);
								getchar();
							}      		
							cout << "\nData booked successfully"<< endl;
							
							string sentence_aux4 = "DELETE FROM property WHERE propertyID ='" + pID + "'";
							const char* qn1 = sentence_aux4.c_str();
						    qstate = mysql_query(conn, qn1);
							
							if(!qstate)
							{
						        res= mysql_store_result(conn);	        
							}
							if(qstate)
							{
								cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
							}
						
						}
			    	
				}                                 
				if(qstate)
				{
					cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
				} 

				}
						
			else if(bookch==2)
			{
				cout << "\nThe property is not booked \n";
			}			
			}
			
		
				
};

class a_signin:public property
{
	private:
		string checkUser;
	    string checkPass;
	    int propertyID;
	public :	    
	    int checkAdmin()
	    {
	        cout << "Enter your username : \n";
	        cin >> checkUser;
	
	        cout << "Enter the password :\n";
	        cin >> checkPass;
	        
	        string sentence_aux1 = "SELECT adminPassword FROM admin WHERE adminUserName = '" +checkUser + "' AND adminPassword= '" +checkPass + "'";
	        
		    const char* qn = sentence_aux1.c_str();
		    qstate = mysql_query(conn, qn);	
	
			if(!qstate)
			{	
				res = mysql_store_result(conn);	
				    			
		        while(row = mysql_fetch_row(res))
		        {
		        	cout << "\nCORRECT PASSWORD..." << endl;
					return 1;	        	
		    	}
			}                                 
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			
		return 0;
		}
		void viewAProp()
		{
			string sentence_aux4 = "SELECT * FROM property WHERE adminName='" +checkUser +"' ";
        
		    const char* qn1 = sentence_aux4.c_str();
		    qstate = mysql_query(conn, qn1);	
	
			if(!qstate)
			{
		        res= mysql_store_result(conn); 
				cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 
		        printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %11s|\n", "ADMIN NAME" ,"PROPERTY TYPE" ,"PRICE OF PROPERTY", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS","PROPERTY ID");
				cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 			    			
		        while(row = mysql_fetch_row(res))
		        {
					printf("| %-20s| %-15s| %-17s| %-25s| %-15s| %-15s| %-11s|\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
				}
			}
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			cout << "------------------------------------------------------------------------------------------------------------------------------------\n"; 

		}
		int bookedAProp(){
			string sentence_aux2 = "SELECT * FROM booked WHERE adminName='"+checkUser+"'";
			const char* qn1 = sentence_aux2.c_str();
		    qstate = mysql_query(conn, qn1);	
			cout << "Contact customer mobile number and email ID for further details about booking\n";
			if(!qstate)
			{
		        res= mysql_store_result(conn); 
				cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; 	
		        printf("| %-10s| %-16s| %-15s| %-17s| %-25s| %-15s| %-15s| %-11s| %-11s|%-20s|\n", "ADMIN NAME" ,"BOOKED CUST NAME","PROPERTY TYPE" ,"PRICE OF PROPERTY", "LOCATION OF PROPERTY", "PROPERTY NAME", "DIMENSTIONS","PROPERTY ID","CUST PH NO.","CUST EMAIL ID");
				cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; 	
				
		        while(row = mysql_fetch_row(res))
		        {
					printf("| %-10s| %-16s| %-15s| %-17s| %-25s| %-15s| %-15s|%-11s |%-11s |%-20s|\n", row[0], row[1], row[2], row[3], row[4], row[5],row[6], row[7],row[8],row[9]);		     
				}
			}
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"; 	
		
				return 0;
		}
		void deleteAProp(){
			
			cout<<"Enter property ID to delete: ";
			cin>>propertyID;
			string pID = to_string(propertyID);
		
			string sentence_aux3 = "delete from property where propertyID ='" + pID + "'";
			const char* qn1 = sentence_aux3.c_str();
		    qstate = mysql_query(conn, qn1);
		    
		    
			{
		        res= mysql_store_result(conn); 
				cout<<"\nData deleted successfully";	
		        
			}
			if(qstate)
			{
				cout << "Query Execution Problem : " << mysql_errno(conn) << endl;
			}	
		}			
};

int main()
{
	char exitentry;
	char aorc='N';

	bool signUpFlag = true;
	int signUpChoice,signInChoice,a_signInChoice,adminChoice;
	int addChoice =1;
	
	database_connection::toconnect();   
	
	system("cls");
	system("COLOR 0E");
	
	cout <<"\n \n \n \n \n \n \n \n \n \n \n "<< endl;
	cout << "\t \t \t \t *--------------------------------*\n";
	cout << "\t \t \t \t | Welcome to Property Managament |\t \t \t\n" ;
	cout << "\t \t \t \t *--------------------------------*";
	
	
	cout<<"\n \n \n \n \n \n \n \n \n \n \n \n	 \n \n \n \n  " <<endl; 
	cout<<"Enter any key to continue................................"<<endl;
	getch();
	
	int choice;
	system("cls");

  
  	while(1){
  	system("COLOR 0A");
    cout<<"**************************************************************************\n\n\n";
    cout<<"                         Welcome to login Page                            \n\n\n";
    cout<<"**************************************************************************\n\n\n";
    cout<<"**********************          MENU        ********************************\n\n";
  
    cout<<"\n1 .SIGN UP"<<endl;
    cout<<"2. SIGN IN (ALREADY EXISTED ACCOUNT)"<<endl;
    cout<<"3. ADMIN SIGNIN"<<endl;
    cout<<"4. EXIT"<<endl;
    cout<<"\nEnter your choice :";
	cin>>choice;
    cout<<endl;	
		  
	switch(choice)
	{
		case 1 :
		{
			signUp obj;
			aorc=obj.getSignUpData();
			if(aorc=='Y')
			{
				cout << "Want to sell properties now?\n";
				cout << "1.YES \n0.NO\n" ;
				cin >> adminChoice;
				while(adminChoice)
				{	
					property obj1;
					int val1=obj1.checkAData();
					if(val1==1)
					{
					
						obj1.getPropertyData();
											
						cout <<"\nWant to sell another property ? " << endl;
						cout << "1.YES \n0.NO\n" ;
						cin >> adminChoice;
					}
					else if(val1==0)
					{
						cout << "\nWRONG PASSWORD...!!!\nTRY AGAIN...\n";
					}
					
				}
			}
			break;
		}
		
		
			
		case 2:
		{
			system("cls");
			system("COLOR 0A");
		    cout<<"**************************************************************************\n\n\n";
		    cout<<"                         Welcome to sign in Page                            \n\n\n";
		    cout<<"**************************************************************************\n\n\n";
			
			signin obj2;
			int val=obj2.checkCData();
			if(val==1)
			{
				while(1)	
				{		
				    cout<<"\n1. VIEW PROPERTY LIST"<<endl;
				    cout<<"2. SEARCH PROPERTY RECORD"<<endl;
				    cout<<"3. BOOK PROPERTY"<<endl;
				    cout<<"4. MAIN MENU"<< endl;
				    cout<<"5. EXIT "<<endl;
				    cout<<"\nEnter your choice :";
				    cin >> signInChoice;
					
					switch(signInChoice)
				    {
				    	case 1 :			    		
							{
							obj2.viewProp();
							break;
						}
				    	case 2 :
				    		{
							obj2.searchProp();
				    		break;
				    	}
				    	case 3 :
				    		{
							obj2.bookProp();
				    		break;
							}
						case 4:
							break;	
				    	case 5 :
				    		exit(0);
							break;		    		
					}
					if(signInChoice==4)
					break;		
				}
			}
			else if(val==0)
			{
				cout << "\nWRONG PASSWORD ENTERED...!!! \nTRY AGAIN...\n";
			}
	
			break;
		}	
			
		case 3:
			{
			
			system("cls");
			system("COLOR 0A");
		    cout<<"**********************************************************************************\n\n\n";
		    cout<<"                         Welcome to admin sign in Page                            \n\n\n";
		    cout<<"**********************************************************************************\n\n\n";
		    a_signin obj3;
			int a_val=obj3.checkAdmin();
			if(a_val==1)
			{
			
		    while(1){
			
		    cout<<"\n1. ADD DETAILS"<<endl;
		    cout<<"2. VIEW PROPERTIES LIST TO BE SOLD"<<endl;
		    cout<<"3. VIEW ALL BOOKINGS"<<endl;
		    cout<<"4. DELETE RECORD "<<endl;
		    cout<<"5. MAIN MENU" << endl;
		    cout<<"6. EXIT" << endl;
		    cout<<"\nEnter your choice :";
		    cin >> a_signInChoice;
		    switch(a_signInChoice)
		    {
		    	case 1 :
		    		{
						while(addChoice)
						{	
							obj3.getPropertyData();
												
							cout <<"\nWant to sell another property ? " << endl;
							cout << "1.YES \n0.NO\n" ;
							cin >> addChoice;
						
						}
						break;
				}
		    	case 2 :
		    		{
					obj3.viewAProp();
		    		break;
		    	}
		    	case 3 :
		    		{
					obj3.bookedAProp();
		    			break;
		    		}
		    	case 4 :
		    		{
					obj3.deleteAProp();
		    			break;
		    		}
		    	case 5:
		    		break;
		    		
		    	case 6 :
		    		{
						exit (0);
		    			break;
					}
			}
			if(a_signInChoice==5)
			break;
		
			}
		}
		else if(a_val==0)
		{
			cout << "\nWRONG PASSWORD ENTERED...!!!\nTRY AGAIN...\n";
		}
		break;
	}
		
	case 4:
 	{
		 	exit(0) ;
 		break;
 		
	}
}
	}
return  0 ;
}



