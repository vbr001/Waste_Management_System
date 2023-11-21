#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<windows.h>
#include<map>
#include <sstream>
 
using namespace std;
void welcome();
void product();
void sell();
int k=0;
void modify_amount();
const string red= "\033[31m";
const string green= "\033[32m";
const string reset= "\033[0m";
const string yellow = "\033[33m";
const string blue = "\033[34m";
int main();
void welcome();
static string cuserId=" ";

string gUserid = "";



struct Customer {
    string userId;
    string WasteProduct;
    int quantity;
};


const string white = "\033[37m";
 int total1=0;
 int total2=0;
 int total3=0;
 void government_login();
 void g1();

class customer
{
    public:
    
   friend  void  login(customer);
   
    void registration();
    void forgot();
    void customer_function();
     void storeWasteItems();

};
void contractor_function();
class contractor
{
    private:
    string userId;
    string password;
    
    public:
    contractor():contractor("","")
   {
    
   }
   contractor(const string& userId, const string& password) : userId(userId), password(password) {}
    
    
};

class AbstractUser {
public:
    
    virtual bool login() = 0;         // Pure virtual function  // we can't implement any function in abstract class
};

int varify;
class contractor1 : public AbstractUser {
private:
    string userId;
    string password;

public:
    // Implementation of pure virtual function
   

    // Implementation of pure virtual function
    bool login() override {
        cout << "contractor Login" << std::endl;
        string inputUserId, inputPassword;
        cout << "Enter the username: ";
        cin >> inputUserId;
        cout << "Enter the password: ";
        cin >> inputPassword;

        
        ifstream file("contractor_records.txt");
        string storedUserId, storedPassword;
        while (file >> storedUserId >> storedPassword) {
            if (inputUserId == storedUserId && inputPassword == storedPassword) {
                cout << "Login successful!" << std::endl;
                 contractor_function();

                
                file.close();
                return true;
            }
        }

        std::cout << "Login failed. Please check your username and password." << std::endl;
        varify=1;
        file.close();
        return false;
    }
};



class government
{

    public:
 static int initial_total;      
 int  total_amount1;
 int total_amount2;
 int total_amount3;
 government(int a,int b,int c):total_amount1(a),total_amount2(b),total_amount3(c)
 {
    string name;
    cout<<"***Enter the name of the contractor*** \n";
    cin>>name;
    
    if(name=="group")
    {
    
     
    cout <<blue << "\t\t\n\t\tTotal amount for purchasing the product from the customer is " << green << total_amount1 << reset << endl;
    cout << blue<< "\n\t\tTotal amount from the customer is " << green << total_amount2 << reset << endl;
    cout << blue << "\t\t\n\t\tTotal amount from the company is " << green << total_amount3 << reset << endl;
            //all the variables are initialised in constructor so use this pointer
            auto initial_total1=[this]()->int {
                return total_amount2+total_amount3;
            };
            cout << blue << "\t\t\n\t\tTotal amount from the company and customer is" << green<<initial_total1()<< reset << endl;


    }
    else
    {
    cout<<"enter the valid name\n";
    g1();
    }
 }

  
   // void government_function();
   
};
int government::initial_total=0;//static member
class government1:public government
{
 
    
    public:

    government1(int total_amount1,int total_amount2,int total_amount3):government(total_amount1,total_amount2,total_amount3)
    {
        
        
    }
};
 

namespace company
{
   
    void company_login();
}

class company1
{
    
    public:
     void company_registration();
    void company_function();
};
struct WasteProduct
{
    string name;
    string type;
    double price;
    WasteProduct(const string &n,const string &t,double p):name(n),type(t),price(p)
    {}
};

int main()
{
    

    
    contractor obj1;
    company1 obj2;

    
  
    
    int c;
    cout<<green<<"\t\t*****WELCOME TO WASTESYSTEM MANAGEMENT****\n\n";
    cout<<red<<"\t\t  Press 1 for customer               "<<endl;
    cout<<red<<"\t\t  Press 2 for contractor             "<<endl;
    cout<<red<<"\t\t  Press 3 for government            "<<endl;
    cout<<red<<"\t\t  Press 4 for company               "<<endl;
    cout<<red<<"\t\t  Press 5 for exit                  "<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
        {
            welcome();
        }
        break;
        case 2:
        {
            AbstractUser* contractor = new contractor1();
            contractor->login();
            while(1)
            {
           if(varify==1)
            contractor->login();
            
            }
            
        }
        
        break;
        case 3:
            government_login();
            
            break;
        case 4:
        {
            int n;
            cout<<"1.Registration\n\n";
            cout<<"2.login\n";
            cin>>n;
            if(n==1)
                obj2.company_registration();
            else if(n==2)
                company::company_login();
            else
                cout<<"choice correct option\n";
        }
        break;

        
        case 5:
        {
            exit(1);
            break;
        }
        default:
        cout<<"choice correct option\n";

    }
  

}
void welcome()
{
    int c;
    
    cout<<blue<<"\t\t\t*********Welcome to the login page**********\n\n\n";
    cout<<yellow<<"\t\t  Press 1 to LOGIN                "<<endl;
    cout<<yellow<<"\t\t  Press 2 to REGISTER             "<<endl;
    cout<<yellow<<"\t\t  Press 3 if you forget your PASSWORD            "<<endl;
    cout<<yellow<<"\t\t  Press 4 to EXIT                 "<<endl;
    cout<<yellow<<"\n\n\t\t  Please enter your choice  : ";
    cin>>c;
    cout<<endl;
    customer obj;
    switch(c)
    {
        case 1:
        login(obj);
        break;
        
        case 2:
            obj.registration();
            break;
        
        case 3:
           obj.forgot();
            break;
        case 4:
            cout<<"\t\t\t Thankyou!\n\n";
            welcome();
            break;

        default:
            system("cls");
            cout<<"\t\t\t Please select form the option given above\n\n"<<endl;
            main();
    }
}
void customer:: registration()
{
    customer obj;
    string ruserId,rpassword,rid,rpass;
    system("cls");
    
    cout<<blue<<"\t\t Enter the username: ";
    cin>>ruserId;
    cout<<blue<<"\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f("records.txt",ios::app);//to write inside the file
    //f1 is object name and in app informtion add at the end
    //ios means input output stream
    f<<ruserId<<' '<<rpassword<<endl;//print inside the file
   
    cout<<"\n\n\t\t Registration is successull ! \n";
   
    cout<<"\n\n login page\n";
    login(obj);
    
}


void login(customer obj)
{
   
    int count;
   string password,id,pass;

    cout<<"\t\t\t Please Enter the username and password :"<<endl;
    cout<<"\t\t\t  USERNAME ";
    cin>>cuserId;
    cout<<"\t\t\t  PASSWORD  ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==cuserId && pass==password)
        {
            count=1;
            system("cls");//clear the screen

        }
    }
    input.close();//to close the file
    if(count==1)
    {
        cout<<cuserId<<"\n \t\tYour LOGIN is successfull \n\t\t  ***Thanks for logging in !***\n";
        obj.customer_function();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        cout<<"\n if u not login please register\n";
        welcome();
    }
}

void  customer:: forgot()
{

    int option;
   
    cout<<"\t\t\t You forgot the password? No worries\n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to main menu "<<endl;
    cout<<"\t\t\t Enter your choice";
    cin>>option;


    switch (option)
    {
    case 1:
    {
        int count=0;
        string suserId,sId,spass;
        cout<<"\n\t\t Enter the username which you remembered: ";
        cin>>suserId;

        ifstream f2("records.txt");
        while(f2>>sId>>spass)
        {
            
            if(sId==suserId)
            {
                count=1;
            }
            
            
            
        }
        f2.close();
        if(count==1)
        {
            cout<<"\n\n Your accout is found!\n";
            cout<<"\n\n Your password is :"<<spass;
            main();

        }
        if(count==0)
        {
            try{
                throw "username not found";
            }catch(const char *error)
            {
                cerr<<"error is "<<error<<endl;
                 forgot();

            }
        }
    }
        break;
        case 2:
        {
            main();
            
        }
        break;

        default:
        {
        cout<<"\t\t Wrong choice ! Please try again "<<endl;
        forgot();
        }
        break;


    
    
    
    }
}



void government_login()
{
    
    int count;
    string userId,password,id,pass;
   
   
    cout<<"\t\t\t Please Enter the username and password :"<<endl;
    cout<<"\t\t\t  USERNAME ";
    cin>>userId;
    cout<<"\t\t\t  PASSWORD  ";
    cin>>password;

    ifstream input("government_records.txt");
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");//clear the screen

        }
    }
    input.close();//to close the file
    if(count==1)
    {
        cout<<userId<<"\n Your LOGIN is successfull \n  Thanks for logging in !\n";
        g1();


        
        
        
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}
void g1()
{
    int n;
        cout<<"press 1 for information\n";
        cin>>n;
        int total_amount1;
        int total_amount2;
        int total_amount3;

        if(n==1)
        {
        ifstream totalFile("total_amount1.txt");
    if(totalFile.is_open())
    {
        totalFile>>total_amount1>>total_amount2>>total_amount3;
        totalFile.close();
    }
        government1 obj(total_amount1,total_amount2,total_amount3);
        }
        else
        {
            main();
        }
}


void company::company_login()
{
    int count;
    company1 obj1;
    string userId,password,id,pass;
 
 
    cout<<"\t\t\t Please Enter the username and password :"<<endl;
    cout<<"\t\t\t  USERNAME ";
    cin>>userId;
    cout<<"\t\t\t  PASSWORD  ";
    cin>>password;

    ifstream input("company_records.txt");
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");//clear the screen

        }
    }
    input.close();//to close the file
    if(count==1)
    {
        cout<<userId<<"\n Your LOGIN is successfull \n  Thanks for logging in !\n";
        obj1.company_function();
        
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}

void company1:: company_registration()
{
    company1 obj;
    string ruserId,rpassword,rid,rpass;
    
    
    cout<<"\t\t Enter the username: ";
    cin>>ruserId;
    cout<<"\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f("company_records.txt",ios::app);//to write inside the file
    //f1 is object name and in app informtion add at the end
    //ios means input output stream
    f<<ruserId<<' '<<rpassword<<endl;//print inside the file
   
   
    cout<<"\n\n\t\t Registration is successull ! \n";
    company::company_login();
}


void customer::customer_function()
{
    
    cout<<"Enter Your Choice\n\n ";
    cout<<"1.To sell the product\n\n";
    cout<<"2.To purchase the product\n\n";
    cout<<"3.exit\n\n";

    int a;
    cin>>a;
    switch(a)
    {
        case 1:
        sell();
        break;
        case 2:
         product();
        break;
        case 3:
        welcome();
        default:
        cout<<"choice the correct option\n\n";
    }
}
void modify_amount()
{
    int a,b,c;
    ifstream totalFile("total_amount1.txt");
    if(totalFile.is_open())
    {
        totalFile>>a>>b>>c;
        totalFile.close();
    }
    
            total1 += a;
            total2 += b;
            total3 += c;
     
            ofstream updatedTotalFile("total_amount1.txt");
                
                {
                if(updatedTotalFile.is_open())
                {
                updatedTotalFile<<total1<<" "<<total2<<" "<<total3;
                }
            }

}
void product()
{
    customer obj;
    //wasteprodcts stores the items of the wasteproprouct
    if(k==0)
    {
  	  cout<<"Enter userId:"<<endl;
   	  cin>>gUserid;
    }
    vector<WasteProduct>WasteProducts=
    {
        WasteProduct("Plastic Bottle", "Recyclable", 10),
        WasteProduct("Organic Waste", "Organic", 0.30),
        WasteProduct("Glass Bottle", "Recyclable", 0.70),
        WasteProduct("Paper Waste", "Recyclable", 0.40),
        WasteProduct("E-Waste", "Hazardous", 1.20),
    };
    cout<<"Waste products availabel for purchase:\n\n";
    for(int i=0;i<WasteProducts.size();i++)
    {
        cout<<"~~Name: "<<WasteProducts[i].name<<", Type: "<<WasteProducts[i].type<<",Price: "<<WasteProducts[i].price<<"~~"<<endl;

    }
    int q;
    cout<<"\n\n---which one you have to buy---\n\n";
    cout<<"\t\t\t0.Plastic Bottle\n";
    cout<<"\t\t\t1.Organic Waste\n";
    cout<<"\t\t\t2.Glass Bottle\n";
    cout<<"\t\t\t3.Paper Waste\n";
    cout<<"\t\t\t4.E-Waste\n";
    cout<<"\t\t\t5.exit\n";
    int n;
    cout<<"-----Enter Your choice-----\n";
    cin>>n;
    if(n==5)
    {
        cout<<"your purchasing is cancelled";
        main();
    }
    cout<<"quantity(in terms of kg)\n\n";
    cin>>q;
    
      
     total2=total2+(q)*(WasteProducts[n].price);
    int b;
    
    cout<<"\n1.buy more products \n\n2.payment \n\n 3.exit\n";
    cin>>b;
    if(b==1)
    {
    system("cls");
    product();
    }
    else if(b==2)
    {
    

    cout<<"total amount is \n\n"<<total2;
    if(total2>0)
    {
        cout<<"payment method\n\n";
        cout<<"1.online\n\n";
        cout<<"2.cash and delivery\n\n";
        cout<<"3.go back\n\n";
        int m;
        cin>>m;
        switch(m)
        {
            case 1:
            {
                int p;
                int cardno,pass;
                cout<<"card no \n\n";
                cin>>cardno;
                cout<<"password\n\n";
                cin>>pass;
                cout<<"payment is done\n\n";

                cout<<"if u want to purchase more press 1\n\n";
                
                int i;
                cin>>i;
                if(p==1)
                    product();
                else
                {
                cout<<"Thankyou for purchasing\n\n";
               
                }
            }
            break;
            case 2:
            {
                cout<<"Thankyou for purchasing\n\n";
                
            }
        }
    }
    }
    else
    main();

        modify_amount();
        ofstream customerData("customer_data.txt", ios::app);
    if (customerData.is_open()) {
     	   customerData << gUserid << " " << WasteProducts[n].name << " " << q << " P" << "purchaser"<<endl;
           customerData.close();
           cout << "Waste item data stored successfully." << endl;
    } else {
           cout << "Unable to open the customer data file for writing." << endl;
    } 
 
    total2=total2+(q)*(WasteProducts[n].price);
   
    
        cout<<"do you want to exit press 1\n";
        int t;
        cin>>t;
        if(t==1)
        exit(1);
        else
        main();
    
    
}

void sell()
{
    
    if(k==0)

    {
    cout<<"Enter userId:"<<endl;
    cin>>gUserid;
    }
    if(gUserid==cuserId)
    {

    
    
    
    cout<<"this is the list of product ";vector<WasteProduct>WasteProducts=
    {
        WasteProduct("Plastic-Bottle", "Recyclable", 10),
        WasteProduct("Organic-Waste", "Organic", 30),
        WasteProduct("Glass-Bottle", "Recyclable", 70),
        WasteProduct("Paper-Waste", "Recyclable", 20),
        WasteProduct("E-Waste", "Hazardous", 50),
    };
    cout<<"Waste products availabel for sale:\n\n";
    for(int i=0;i<WasteProducts.size();i++)
    {
        cout<<"~Name: "<<WasteProducts[i].name<<", Type: "<<WasteProducts[i].type<<",Price: "<<WasteProducts[i].price<<"~"<<endl;

    }
    cout<<"which product you want to sell\n\n";
    cout<<"\t\t\t0.Plastic Bottle\n";
    cout<<"\t\t\t1.Organic Waste\n";
    cout<<"\t\t\t2.Glass Bottle\n";
    cout<<"\t\t\t3.Paper Waste\n";
    cout<<"\t\t\t4.E-Waste\n";
    cout<<"\t\t\t5.exit\n";
    int n;
    int q;
    cout<<"-----Enter Your choice-----\n";
    cin>>n;
    if(n==5)
    {
        cout<<"your sell is cancelled";
        main();
    }
    cout<<"quantity(in terms of kg)\n\n";
    cin>>q;
    
    
     total1=total1+(q)*(WasteProducts[n].price);
    int b;
    cout<<"\n1.sell  more products \n\n2.payment \n\n 3.exit\n";
    cin>>b;
    if(b==1)
    {
         k=1;
    sell();
    
   
    }
    
    else if(b==2)
    {
    
    if(total1>0)
    {
        cout<<"total amount for selling the product is : "<<total1<<endl;
        cout<<"\n\npayment is after  selling the product only  ";
        cout<<"payment method\n\n";
        cout<<"1.online\n\n";
        cout<<"2.cash and delivery\n\n";
        cout<<"3.go back\n\n";
        int m;
        cin>>m;
        switch(m)
        {
            case 1:
            {
                int p;
                int cardno,pass;
                string branch ,name;
                cout<<"name of the bank\n";
                cin>>name;
                cout<<"branch name";
                cin>>branch;

                cout<<"account no \n\n";
                cin>>cardno;
                cout<<"isfc code\n\n";
                cin>>pass;
                
                cout<<"payment is done\n\n";

                cout<<"if u want to sell  more product press 1\n\n";
                if(p==1)
                    sell();
                else
                {
                cout<<"Thankyou for selling\n\n";
                
               
                }
                break;
            }
            
            case 2:
            {
                cout<<"Thankyou for selling\n\n";
                break;
                
            }
            case 3:
            {
                cout<<"your order is cancelled";
                sell();
                break;
            }

        }
        
    }
    }
    
    else
    {
    
     main();

    }
    ofstream customerData("customer_data.txt", ios::app);

    if (customerData.is_open()) {
        customerData << gUserid << "  " << WasteProducts[n].name << " " << q << " kg" <<"seller"<< endl;
        customerData.close();
        cout << "Waste item data stored successfully." << endl;
    } else {
        cout << "Unable to open the customer data file for writing." << endl;
    }
    modify_amount();
        exit(1);
        

}
else
{
    cout<<"invalid userId"<<endl;
    sell();
}
}
  
  



void company1::company_function()
{

   
    //wasteprodcts stores the items of the wasteproprouct
    vector<WasteProduct>WasteProducts=
    {
        WasteProduct("Plastic Bottle", "Recyclable", 10),
        WasteProduct("Organic Waste", "Organic", 30),
        WasteProduct("Glass Bottle", "Recyclable", 40),
        WasteProduct("Paper Waste", "Recyclable", 15),
        WasteProduct("E-Waste", "Hazardous", 50),
    };
    cout<<"Waste products availabel for purchase:\n\n";
    for(int i=0;i<WasteProducts.size();i++)
    {
        cout<<"~~Name: "<<WasteProducts[i].name<<", Type: "<<WasteProducts[i].type<<",Price: "<<WasteProducts[i].price<<"~~"<<endl;

    }
    int q;
    cout<<"\n\n---which one you have to buy---\n\n";
    cout<<"\t\t\t0.Plastic Bottle\n";
    cout<<"\t\t\t1.Organic Waste\n";
    cout<<"\t\t\t2.Glass Bottle\n";
    cout<<"\t\t\t3.Paper Waste\n";
    cout<<"\t\t\t4.E-Waste\n";
    cout<<"\t\t\t5.exit\n";
    int n;
    cout<<"-----Enter Your choice-----\n";
    cin>>n;
    if(n==5)
    {
        cout<<"your purchasing is cancelled";
        main();
    

}
    cout<<"quantity(in terms of kg)\n\n";
    cin>>q;
    
     total3=total3+(q)*(WasteProducts[n].price);
    int b;
    cout<<"\n1.buy more products \n\n2.payment \n\n 3.exit\n";
    cin>>b;
    if(b==1)
    {
    system("cls");
    product();


    }
    
    else if(b==2)
    {
    cout<<"total amount is \n\n"<<total3;
    if(total3>0)
    {
        cout<<"payment method\n\n";
        cout<<"1.online\n\n";
        cout<<"2.cash and delivery\n\n";
        cout<<"3.go back\n\n";
        int m;
        cin>>m;
        switch(m)
        {
            case 1:
            {
                int p;
                int cardno,pass;
                cout<<"card no \n\n";
                cin>>cardno;
                cout<<"password\n\n";
                cin>>pass;
                cout<<"payment is done\n\n";

                cout<<"if u want to purchase more press 1\n\n";
                if(p==1)
                    product();
                else
                {
                cout<<"Thankyou for purchasing\n\n";
                modify_amount();
                exit(1);
                }
            }
            break;
            case 2:
            {
                cout<<"Thankyou for purchasing\n\n";
                modify_amount();

                
                exit(1);
            }
            case 3:
            {
                cout<<"your order is cancelled";
                break;
            }
        }
        
    }
    }


    else
    main();
    
        
        cout<<"do you want to exit press 1\n";
        int t;
        cin>>t;
        if(t==1)
        exit(1);
        else
        main();
}

void customer::storeWasteItems() {
    string userId;
    cout << "Enter your username: ";
    cin >> userId;

    string WasteProduct;
    double quantity;

    cin.ignore(); // Consume newline character from the previous input operation

    cout << "Enter the type of the waste item: ";
    getline(cin, WasteProduct);

    cout << "Enter the quantity (in kg): ";
    cin >> quantity;

    // Open the file for appending if it exists, create it if it doesn't
    ofstream customerData("customer_data.txt", ios::app);

    if (customerData.is_open()) {
        customerData << userId << " " << WasteProduct << " " << quantity << " kg" << endl;
        customerData.close();
        cout << "Waste item data stored successfully." << endl;
    } else {
        cout << "Unable to open the customer data file for writing." << endl;
    }
}

void displayDashboard(map<string, vector<Customer>>&customers) {
   cout << "Customer Dashboard" << endl;
    cout << "-------------------" << endl;

    for (const auto& entry : customers) {
        cout << "Customer Name: " << entry.first << endl; // Use entry.first for userId
        for (const auto& customer : entry.second) {
            cout << "Waste Type: " << customer.WasteProduct << endl;
            cout << "Waste Quantity: " << customer.quantity << " kg" << endl;
            
        }
        cout << "-------------------" << endl;
    }
}


void contractor_function() {
    map<string,vector< Customer>> customers;
    ifstream customerfile("customer_data.txt");

    if (customerfile.is_open()) {
        string line;
        while (getline(customerfile, line)) {
            istringstream iss(line);
            Customer obj;
            if (iss >> obj.userId >> obj.WasteProduct >> obj.quantity) {
                customers[obj.userId].push_back(obj);
            }
        }
        customerfile.close();
    } else {
        cout << "Unable to open the customer data file for reading." << endl;
        return;
    }

  
    int choice;

    while (true) {
        cout << "Contractor Dashboard" << endl;
        cout << "1. Display Dashboard" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayDashboard(customers);
                break;
            case 2:
                cout << "Data saved. Goodbye!" << endl;
                exit(1);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}













