#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <process.h>
#include <assert.h>
using namespace std;
#define ll long long int
#define max_tckts 50
int counter_v[6]={0},counter_sv[6]={0},counter_n[6]={0};


/*class Exception : public exception
{
    //char* a;
    string a;
 public:

    //Exception(char* b)
    Exception(string b)
    {
        //strcpy(a,b);
        a=b;
    }

    //const char * get_cout()
    virtual const string get_cout() const throw()
    {
        return a;
    }
};*/

class payment
{
    string name;
    string card_number;
    string exp_date;
    int cvv;
    string d_o_b;

public:

    payment() {}
    void get_details()
    {
        int choice;
        //cout<<"\n\n\n\t\t\t";
        cout<<"\n\n\n\t\t\tName as on card:";
        cin>>name;
        cout<<"\t\t\t";
        cout<<"Card Number:";
        cin>>card_number;
        cout<<"\t\t\t";
        cout<<"Expiry Date:";
        cin>>exp_date;
        cout<<"\t\t\t";
        cout<<"CVV:";
        cin>>cvv;
        cout<<"\t\t\t";
        cout<<"Date of Birth:";
        cin>>d_o_b;
        //cout<<"\n\n\n";
        //system("pause");
        //cout<<"\n\n\n\n\t";
        //cout<<"Your payment is successfull"<<"\n"<<" Thank You For Booking Tickets";
        //cout<<"\t\t\t";
        cout<<"\n\n\nPress 1 to submit and 0 to exit:";
        cin>>choice;
        if(choice)
            cout<<"\n\n\t\tYour payment is successfull"<<"\n\t\t"<<"Thank You For Booking Tickets\n\n\n\n";
        else
            cout<<"\n\n\n\n\t\t\tOOPS!!....\n\t\t\tYour card details are wrong\n\n\n\n";
    }
    /*
    void for_submiting(int choice)
    {
        //cout<<"Press 1 to submit and 0 to exit:";
        //cin>>choice;                          to be taken inside main for clrscr()
        if(check(card_number) && choice)
            cout<<"Your payment is successfull";
        else
            cout<<"Your card details are wrong";
    }*/
};

class seat
{
    int num_of_tckts;
    ll amount;
    payment p;

public:

    virtual void type()=0;     //abstract class overidding    //polymor
    ll get_final_amount()
    {
        return amount;
    }

    void set_amount(ll j)
    {
        amount=j;
    }

    payment get_p()
    {
        return p;
    }
    /*virtual void chq_tckt()
    {
        if(num_of_tckts<=max_tckts)
            return true;
            //counter+=num_of_tckts;
        else if(counter==50)
        {
            cout<<"No more ticktts are available";
            return false;
        }
        else
        {
            cout<<"Only few tickets are left and out of 50";//<<counter<<" are booked already";
            return false;
        }
    }*/
};

template<class T>
bool check(int num,T* t)
{
    if(t->total>=num)
        return true;
    else
        return false;
}

template<class T>
void delete_from_static(int num,T* t)
{
    //int toto;
    //toto = t->get_total();
    t->total-=num;
}

class vip_box : public seat
{
    vip_box()   {}
    ll amount;

public:

    static int total;
    static vip_box* instance;
    static vip_box* getinstance();
    friend bool check(int num,vip_box* t);
    friend void delete_from_static(int num,vip_box* t);
    void type()
    {
    cout<<"\n\t\tEnjoy the match in this special box\n\t\taccompanied by our special celeb's\n\t\twith unlimited drinks and food";
    }
    void get_amount(int no_tickt)
    {
        amount = 50000*no_tickt;                //OVERRIDING used
        seat::set_amount(amount);
    }
};
int vip_box :: total = 15;
vip_box* vip_box::instance = NULL;
vip_box* vip_box::getinstance()
{
    if(instance==NULL)
        instance = new vip_box;
    return instance;
}

class semivip_box : public seat
{
    //static int total;
    semivip_box()   {}
    ll amount;

public:

    static int total;
    static semivip_box* instance;
    static semivip_box* getinstance();
    friend bool check(int num,semivip_box* t);
    friend void delete_from_static(int num,semivip_box* t);
    void type()
    {
    cout<<"\n\t\tEnjoy the match in this special box\n\t\twith unlimited drinks and food";
    }
    void get_amount(int no_tickt)
    {
        amount = 25000*no_tickt;                //OVERRIDING used
        seat::set_amount(amount);
    }
};
int semivip_box::total = 15;
semivip_box* semivip_box::instance= NULL;
semivip_box* semivip_box::getinstance()
{
    if(instance==NULL)
        instance = new semivip_box();
    return instance;
}

class normal_box : public seat
{
    //static int total;
    normal_box()    {}
    ll amount;

public:

    static int total;
    static normal_box* instance;
    static normal_box* getinstance();
    friend bool check(int num,normal_box* t);
    friend void delete_from_static(int num,normal_box* t);
    void type()
    {
        cout<<"\n\t\tEnjoy the match\n\t\twith limited drinks and food";
    }
    void get_amount(int no_tickt)
    {
        amount = 10000*no_tickt;                //OVERRIDING used
        seat::set_amount(amount);
    }
};
int normal_box::total = 20;
normal_box* normal_box::instance=NULL;
normal_box* normal_box::getinstance()
{
    if(instance==NULL)
        instance = new normal_box();
    return instance;
}


class team
{
public:

    team(int n)
    {
        switch(n)
        {
            case 1: cout<<"\n\t\t\t";
                    cout<<"  Liverpool\t  Newcastle\n";
                    cout<<"\t\t\t1.Jones\t1.Krul\n\t\t\t2.Mignolet\t2.Santon\n\t\t\t3.Ward\t3.Good\n\t\t\t4.Johnson\t4.Anita\n\t\t\t5.Jose Enrique\t5.Cabella\n";
                    cout<<"\t\t\t6.Lovren\t6.Vuckic\n\t\t\t7.Sakho\t7.Satka\n\t\t\t8.Gerrard\t8.Williamson\n\t\t\t9.Coutinho\t9.Haidara\n\t\t\t10.Lucas\t10.Taylor\n";
                  //  cout<<"All players of Newcastle:\n";
                   // cout<<"1.Krul\t2.Santon\t3.Good\t4.Anita\t5.Cabella\n";
                   // cout<<"6.Vuckic\t7.Satka\t8.Williamson\t9.Haidara\t10.Taylor\n";
                    break;
            case 2: cout<<"\n\t\t\t";
                    cout<<"  Chelsea\t  Liverpool\n";
                    cout<<"\t\t\t1.Cech\t1.Jones\n\t\t\t2.Benneney\t2.Mignolet\n\t\t\t3.Boga\t3.Ward\n\t\t\t4.Salah\t4.Johnson\n\t\t\t5.Remy\t5.Jose Enrique\n";
                    cout<<"\t\t\t6.Courtuis\t6.Lovren\n\t\t\t7.Ake\t7.Sakho\n\t\t\t8.Cahill\t8.Gerrard\n\t\t\t9.Hazard\t9.Coutinho\n\t\t\t10.Oscar\t10.Lucas\n";
                    //cout<<"All players of Liverpool:\n";
                    //cout<<"1.Jones\t2.Mignolet\t3.Ward\t4.Johnson\t5.Jose Enrique\n";
                    //cout<<"6.Lovren\t7.Sakho\t8.Gerrard\t9.Coutinho\t10.Lucas\n";
                    break;
            case 3: cout<<"\n\t\t\t";
                    cout<<"  Monaco\t  Zenith St P";
                    cout<<"\t\t\t1.Cech\t1.Jones\n\t\t\t2.Benneney\t2.Mignolet\n\t\t\t3.Boga\t3.Ward\n\t\t\t4.Salah\t4.Johnson\n\t\t\t5.Remy\t5.Jose Enrique\n";
                    cout<<"\t\t\t6.Courtuis\t6.Lovren\n\t\t\t7.Ake\t7.Sakho\n\t\t\t8.Cahill\t8.Gerrard\n\t\t\t9.Hazard\t9.Coutinho\n\t\t\t10.Oscar\t10.Lucas\n";
                    //cout<<"All players of Zenith St P:\n";
                    //cout<<"1.Victor\t2.Milan\t3.Yuri\t4.Anatoilly\t5.Luis\n";
                    //cout<<"6.Andrey\t7.Javi Garcia\t8.Axel Witsel\t9.Danny\t10.Hulk\n";
                    break;
            case 4: cout<<"\n\t\t\t";
                    cout<<"  Lincoln City\t  Nuneaton";
                    cout<<"\t\t\t1.Cech\t1.Jones\n\t\t\t2.Benneney\t2.Mignolet\n\t\t\t3.Boga\t3.Ward\n\t\t\t4.Salah\t4.Johnson\n\t\t\t5.Remy\t5.Jose Enrique\n";
                    cout<<"\t\t\t6.Courtuis\t6.Lovren\n\t\t\t7.Ake\t7.Sakho\n\t\t\t8.Cahill\t8.Gerrard\n\t\t\t9.Hazard\t9.Coutinho\n\t\t\t10.Oscar\t10.Lucas\n";
                    //cout<<"All players of Nuneaton:\n";
                    //cout<<"1.Fowler\t2.Brown\t3.Armson\t4.Richards\t5.Wren\n";
                    //cout<<"6.Dawson\t7.Walker\t8.Sodje\t9.Gash\t10.Forsdick\n";
                    break;
            case 5: cout<<"\n\t\t\t";
                    cout<<"  Monaco\t  Chelsea";
                    cout<<"\t\t\t1.Cech\t1.Jones\n\t\t\t2.Benneney\t2.Mignolet\n\t\t\t3.Boga\t3.Ward\n\t\t\t4.Salah\t4.Johnson\n\t\t\t5.Remy\t5.Jose Enrique\n";
                    cout<<"\t\t\t6.Courtuis\t6.Lovren\n\t\t\t7.Ake\t7.Sakho\n\t\t\t8.Cahill\t8.Gerrard\n\t\t\t9.Hazard\t9.Coutinho\n\t\t\t10.Oscar\t10.Lucas\n";
                    //cout<<"All players of Chelsea:\n";
                    //cout<<"1.Cech\t2.Benneney\t3.Boga\t4.Salah\t5.Remy\n";
                    //cout<<"6.Courtuis\t7.Ake\t8.Cahill\t9.Hazard\t10.Oscar\n";
                    break;
        }

    }
};

class info
{
public:

    info(int n)
    {
        switch(n)
        {
            case 1: cout<<"\n\t\t\t";
                    cout<<"You have choose : Liverpool  vs  Newcastle\n";
                    cout<<"\t\t\t";
                    cout<<"Venue:My stadium\n";
                    cout<<"\t\t\t";
                    cout<<"Date:19/12/2015\n";
                    cout<<"\t\t\t";
                    cout<<"Timings:9:00 pm\n";
                    break;
            case 2: cout<<"\n\t\t\t";
                    cout<<"You have choose : Chelsea  vs  Liverpool \n";
                    cout<<"\t\t\t";
                    cout<<"Venue:My stadium\n";
                    cout<<"\t\t\t";
                    cout<<"Date:20/12/2015\n";
                    cout<<"\t\t\t";
                    cout<<"Timings:9:00 pm\n";
                    break;
            case 3: cout<<"\n\t\t\t";
                    cout<<"You have choose : Monaco  vs  Zenit St P \n";
                    cout<<"\t\t\t";
                    cout<<"Venue:My stadium\n";
                    cout<<"\t\t\t";
                    cout<<"Date:21/12/2015 \n";
                    cout<<"\t\t\t";
                    cout<<"Timings:9:00 pm\n";
                    break;
            case 4: cout<<"\n\t\t\t";
                    cout<<"You have choose : Lincoln City  vs  Nuneaton \n";
                    cout<<"\t\t\t";
                    cout<<"Venue:My stadium\n";
                    cout<<"\t\t\t";
                    cout<<"Date:25/12/2015\n";
                    cout<<"\t\t\t";
                    cout<<"Timings:9:00 pm\n";
                    break;
            case 5: cout<<"\n\t\t\t";
                    cout<<"You have choose : Monaco  vs  Chelsea \n";
                    cout<<"\t\t\t";
                    cout<<"Venue:\n";
                    cout<<"\t\t\t";
                    cout<<"Date:\n";
                    cout<<"\t\t\t";
                    cout<<"Timings:\n";
                    break;
            default: cout<<"You have entered an invalid choice\n";
                     break;
        }
    }
};

class matches
{
    int choose;

public:

    team *teams;
    info *information;
    vip_box *v[6];
    semivip_box *sv[6];
    normal_box *nor[6];
    //ticket ticket_book_match[5];
    //seat seats[6];

    /*void create_all_seats()         // shd be called once in order to create objects for all matches seat for a particular user
    {
        for(int i=1;i<6;i++)
            seats[i] = new seat();
    }*/

    void display_team_details()
    {
        teams = new team(choose);
    }

    void display_match_details()
    {
        information = new info(choose);
    }

    /*void no_of_tckts(int n)      // after getting number of seats user wants to book
    {
        //seats = new seat();
        seat[choose].num_of_tckts=n;
    }*/
    void choose_seat_no(int no_tickts)
    {
        nor[choose] = normal_box::getinstance();
            nor[choose]->type();
            if(::check(no_tickts,nor[choose]))
            {
                ::delete_from_static(no_tickts,nor[choose]);
                nor[choose]->get_amount(no_tickts);
                cout<<"\n\t\tTotal amount to be paid:";
                cout<<nor[choose]->get_final_amount();
                nor[choose]->get_p().get_details();
            }
            else
                cout<<"\n\t\tThe Tickts are not available";

    }
    void choose_seat_no(char s,int no_tickts)
    {
        //seat_row=s;
        if(s=='A' || s=='B' || s=='C')
        {
            v[choose] = vip_box::getinstance();
            v[choose]->type();
            if(::check(no_tickts,v[choose]))
            {
                ::delete_from_static(no_tickts,v[choose]);
                v[choose]->get_amount(no_tickts);
                cout<<"\n\t\tTotal amount to be paid:";
                cout<<(v[choose]->get_final_amount());
                v[choose]->get_p().get_details();
            }
            else
                cout<<"\n\t\tThe Tickts are not available";
        }
        else if(s=='D' || s=='E' || s=='F')
        {
            sv[choose] = semivip_box::getinstance();
            sv[choose]->type();
            if(::check(no_tickts,sv[choose]))
            {
                ::delete_from_static(no_tickts,sv[choose]);
                sv[choose]->get_amount(no_tickts);
                cout<<"\n\t\t\tTotal amount to be paid:";
                cout<<sv[choose]->get_final_amount();
                sv[choose]->get_p().get_details();
            }
            else
            {
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t";
                cout<<"\n\t\tThe Tickts are not available";
            }
        }
        else
        {
            nor[choose] = normal_box::getinstance();
            nor[choose]->type();
            if(::check(no_tickts,nor[choose]))
            {
                ::delete_from_static(no_tickts,nor[choose]);
                nor[choose]->get_amount(no_tickts);
                cout<<"\n\t\t\tTotal amount to be paid:";
                cout<<nor[choose]->get_final_amount();
                nor[choose]->get_p().get_details();
            }
            else
                cout<<"\n\t\tThe Tickts are not available";
        }
    }

    int get_choose()
    {
        return choose;
    }

    void set_choose(int k)
    {
        choose=k;
    }

    matches()                                          // default constructor
    {}

    void disp()
    {
        cout<<"\n\n\n\n\t\t\t";
        cout<<"1:Liverpool  vs  Newcastle \n";
        cout<<"\t\t\t";
        cout<<"2:Chealsea  vs  Liverpool \n";
        cout<<"\t\t\t";
        cout<<"3:Monaco  vs  Zenit St P \n";
        cout<<"\t\t\t";
        cout<<"4:Lincoln City  vs  Nuneaton \n";
        cout<<"\t\t\t";
        cout<<"5:Forest Green  vs  Woking \n";
    }
};

class user
{
    string user_name;
    string email_id;
    string name;
    int age;
    ll phone_num;
    matches *m;                    // for association and then it chooses which match to be selected

public:                         // make a function regarding email to check it

    void set_match(matches* l)
    {
        m=l;
    }

    matches* get_match()
    {
        return m;
    }

    bool chq(int age)           // to check whthr person is 18 or above
    {
        if(age<18)
            return false;
        else
            return true;
    }

    user()                      // default constructor
    {}

    user(string a,string b,string c,int age,ll num)
    {
        user_name=a;
        email_id=b;
        name=c;
        age=age;
        phone_num=num;
        if(!chq(age))
        {
            assert(chq(age));
                cout<<"\nAssertion invoked and program terminates";
        }
            //throw("You are not eligible as your age is less than 18");
        if(!email_check(email_id))
            //cout<<"Your email id is not correct:";
            throw("\nYour email id is not correct:");
        //m = new matches;
        cout<<"\n\t\t";
        system("pause");
        system("cls");
        m->disp();
    }

    bool email_check(string email_id)
    {
        int i,len;
        bool flag = false;
        len=email_id.length();
        for(i=0;i<len;i++)
            if(email_id[i]=='@')
            {
                flag = true;
                break;
            }
            else
                flag = false;
        return flag;
    }
    // when users enter any number 1 to 5 regarding match to display its full information
    void choose_match(int k)
    {
        m->set_choose(k);            //defining match ka choose here from main
    }

    // to display all the information regarding the match selected
    void match_details()
    {
        m->display_match_details();            //to show from match stream which has been choose
    }

    // if users wants the information of match players name
    void display_teams()
    {
        m->display_team_details();
    }

    // all get function to get all the values off class which are private
    string get_name()
    {
        return name;
    }

    string get_email()
    {
        return email_id;
    }

    string get_username()
    {
        return user_name;
    }

    int get_phone()
    {
        return phone_num;
    }

    int get_age()
    {
        return age;
    }

};

int main()
{
    int everytime=1;
    while(everytime)
    {
    system("cls");
    string u,e,n;
    int a;
    ll p;
    int i=1;
    cout<<"\n\n\n\t\tIndian Super League\n\t\tEnter your credentials to proceed further :) ";
    while(i==1)
    {
    try{
    cout<<"\n\n\n\n\t\t\t";
    cout<<"Enter UserName:";
    cin>>u;
    cout<<"\t\t\t";
    //cout<<"\n\n\n\n\t\t";
    cout<<"Enter Email_Id:";
    cin>>e;
    //cout<<"\n\n\n\n\t\t";
    cout<<"\t\t\t";
    cout<<"Enter name:";
    cin>>n;
    //cout<<"\n\n\n\n\t\t";
    cout<<"\t\t\t";
    cout<<"Enter age:";
    cin>>a;
    //cout<<"\n\n\n\n\t\t";
    cout<<"\t\t\t";
    cout<<"Enter Phone no:";
    cin>>p;
    i=0;
    }
    catch(string l)
    {
        cout<<l;
        i=1;
    }
    }
    int abc;
    user us(u,e,n,a,p);
    matches* jhakas;
    jhakas = new matches();
    us.set_match(jhakas);
    //system("cls");
    cout<<"\n";
    cout<<"Choose the match you want to select:";
    cin>>i;
    us.get_match()->set_choose(i);
    int lo=1;
    cout<<"\n\n\n";
    system("pause");
    system("cls");
    while(lo!=0)
    {
        //system("cls");
        cout<<"\n\n\t\t\t";
        cout<<"Enter 1 to view match details\n";
        cout<<"\t\t\t";
        cout<<"Enter 2 to view team details\n";
        cout<<"\t\t\t";
        cout<<"Enter 3 to book ticket\n";
        cout<<"\t\t\t";
        cout<<"Enter 0 to exit\n";
        cout<<"\n";
        cout<<"Enter your choice:";
        cin>>lo;
        switch(lo)
        {
            case 1 : us.get_match()->display_match_details();
                     break;

            case 2 : us.get_match()->display_team_details();
                     break;

            case 3 : lo=0;
                     abc=2;
                     break;

            case 0 : lo=0;
                     abc=1;
                     break;

            default : cout<<"\t\t\t";
                      cout<<"Entered wrong value";
        }
        cout<<"\n\n\n";
        system("pause");
        system("cls");
    }
    if(abc==2)
    {
    char we;
    int rt;
    system("cls");
    cout<<"\n\n\t\t";
    cout<<"Choose block A B C for VIPBOX tickets @50000\n";
    cout<<"\t\t";
    cout<<"Choose block D E F for SEMIVIPBOX tickets @25000\n";
    cout<<"\t\t";
    cout<<"Choose block G H I J for NORMALBOX tickets @10000\n";
    cout<<"\n";
    cout<<"Block you want to choose:";
    cin>>we;
    cout<<"\t\t\nEnter no of tickets you want to book : ";
    cin>>rt;
    cout<<"\n\n\n";
    system("pause");
    system("cls");
    cout<<"\n\n\n\n\n\t";
    cout<<"You are being processed to secure password area....";
    cout<<"\n\n\n\n";
    system("pause");
    system("cls");
    if(we<=72)
    us.get_match()->choose_seat_no(we,rt);
    else
    us.get_match()->choose_seat_no(rt);
    }
    system("cls");
    cout<<"\n\n\tEnter 1 to continue booking and press any other key to exit:";
    cin>>everytime;
    }
    return 0;
}
