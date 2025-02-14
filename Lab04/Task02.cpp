#include<iostream>
using namespace std;

class Car{
	string brand;
	string model;
	float rentalprice;
	bool availability;
	
	public:
		Car(){
			brand = "Unknown";
			model = "Generic";
			rentalprice=0.0;
			availability = true;
		
		}
		
		void rentalrequest(){
			string c;
			
			cout<<"Enter car name for rent:"<<endl;
			getline(cin,c);
			if(check == true ){
				cout<<"Car is avaiable for rent";
				availability = false; 
				
			}
		
			}
			
		
		
		bool check(){
			if(availability == true){
				cout<<"Car is available"<<endl;
				return true;
				
			}
			else{
				cout<<"Car is not available"<<endl;
		        return false;
			}
			
		}
		
		void setb(string b){
			brand=b;
		}
		
		void setm(string m){
			mod=m
		}
	
	void update(){
		string bran;
		string mod;
		setb("Toyota");
		
		setm("Aqua");
		
		
		
	}
	
Car (string b , string m){
	brand = b;
	mod=m;
}	

void applydis(int days,int rent){
	float discount;
	if(days > 5){
		discount = 0.05 * rent;
		
	}
	else if(days > 10){
		discount = 0.1 * rent;
	}
}



	
	
	
	
};




int main(){
	Car c1;
	c1.update();
	c1.applydis(7,1000);
}
