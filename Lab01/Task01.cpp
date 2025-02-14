#include<iostream>
#include<string>
using namespace std;

class Wallet {
    string ownername;
    float totalbalance;
    int transactionhistory[100];
    int count;

    public:

    Wallet(string name, float inibal){
        ownername=name;
        totalbalance=inibal;
        count = 0;
    }

    void addmoney(float money){

if(money > 0){
        totalbalance += money;
        if(count < 100){
            transactionhistory[count] = money;
            count++;
        }
        cout << "Amount  added successfully "<<money<<endl;
}     
else{
    cout<< "Invalid amount"<<endl;

}
    }


    void spendmoney(float money){
     
        if(money > 0 && money <= totalbalance){

            totalbalance -= money;
            if(count < 100){
                transactionhistory[count] = -money;
                count++;
                }
                cout << "Amount spent successfully "<<money<<endl;
                }else{
                    cout<< "Invalid amount"<<endl;
                    }
                }

        
void displaytransaction (){

    cout<<"Transaction History for :"<<ownername<<endl;
    for(int i=0; i<count ;i++){
        cout<< "Transaction "<< i+1 <<": "<< transactionhistory[i]<<endl;
    }
    cout<<"Total balance:"<<totalbalance<<endl;


}



};


int main(){
    string name; 
    float bal;
    cout<<"Enter intital balance:";
    cin>>bal;
    Wallet saad("Saad",bal);
    saad.addmoney(4000); 
    saad.displaytransaction();
    saad.spendmoney(200);
    saad.displaytransaction();

}
