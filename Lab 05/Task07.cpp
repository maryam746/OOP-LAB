#include<iostream>
using namespace std;

class Product{
    int id;
    string name;
    int quantity;


    public:

    string getName(){
        return name;
    }
    void storeproducts(int i, string n, int q){
        id = i;
        name = n;
        quantity = q;
    }

   static void sortproductsalphabetically(Product *p, int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(p[j].name > p[j+1].name){
                    Product temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    void searchproductbyid(Product *p, int ID, int n){
        for(int i=0;i<n;i++){
            if(p[i].id == ID){
                cout<<"Product found: "<<p[i].name<<endl;
                cout<<"Quantity: "<<p[i].quantity<<endl;
                return;
            }
        }
        cout<<"Product not found"<<endl;
    }
};
int main(){
    Product p[3];

    p[0].storeproducts(1, "Laptop", 10);
    p[1].storeproducts(2, "Mobile", 20);
    p[2].storeproducts(3, "Tablet", 30);

    Product :: sortproductsalphabetically(p, 3);
    p[0].searchproductbyid(p, 2, 3);
    return 0;





}
