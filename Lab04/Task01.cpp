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
			
			if( check() == true ){
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
			model=m;
		}
	
	void update(){
		string bran;
		string mod;
		setb("Toyota");
		
		setm("Aqua");
		
		
		
	}
	
	
};




int main(){
	Car c1;
	c1.update();
}
