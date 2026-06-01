#include<iostream>
#include<string.h>

using namespace std;

class Electronic_device{
  private:
      string device_id;
      string brand;
      double price;
  public:
      // Setters
    void setdevice(string id){
      device_id=id;
    }
    void setbrand(string b){
       brand=b;
    }
    void setprice(double p){
       price=p;
    }
    // Getters
    string getdevice() const {return device_id;}
    string getbrand() const {return brand;}
    double getprice() const {return price;}

    // Constructors
    Electronic_device(){
      device_id= "1001";
      brand= "Infinix";
      price= 80000;
    }
    // parameterized constructors
    Electronic_device(string id, string b, double p): device_id(id), brand(b), price(p){}
    // destructor
    ~ Electronic_device(){
       cout << "Object Distroyed" <<endl;
    }
};
class smartPhone: public Electronic_device{
   string cameraResolution;
};
class laptop: public Electronic_device{
   int ramsize;
};

class smartWatch: public smartPhone{
   int batteryLife;
};
class Warranty{
  public:
      // Version 1 accepts number of years
      void calculateWarranty(int years){
        cout << "First Warranty: "<<years<< "years"<<endl;
      }
      // Version 2 accepts number of years and time of purchase
      void calculateWarranty(int years, int yop){
          int expiryYear =yop + years;
          cout << "Warranty Period: "<< years << "years" <<endl;
          cout << "Year of Purchase: "<<yop<<endl;
          cout << "Warranty Exxpiry Year: " <<expiryYear <<endl;
      }

};

int main()
{
    Electronic_device E1;
    Electronic_device   E2("1002", "Techno", 70000);
    smartPhone sp;
    laptop lp;
    smartWatch sw;

    sp.setdevice("1001");
    sp.setbrand("Apple");
    sp.setprice(100000);

    lp.setdevice("1002");
    lp.setbrand("Apple");
    lp.setprice(600000);

    sw.setdevice("1003");
    sw.setbrand("Apple");
    sw.setprice(10000);

    cout << "-----------SMART PHONE----------\n"<<endl;
    cout << "ID: "<<sp.getdevice()<< "\nBrand: "<<sp.getbrand()<< "\nPrice:"<<sp.getprice()<<endl;
    cout << "\n-----------LAPTOP----------\n"<<endl;
    cout << "ID:"<<lp.getdevice()<< "\nBrand: "<<lp.getbrand()<< "\nPrice: "<<lp.getprice()<<endl;
    cout << "\n----------SMART WATCH----------\n"<<endl;
    cout << "ID: "<<sw.getdevice()<< "\nBrand: "<<sw.getbrand()<< "\nPrice: "<<sw.getprice()<<endl;

    Warranty W;

    // calling first overloading function
    W.calculateWarranty(4);
    // Calling second overloading function
    W.calculateWarranty(4, 2023);

    return 0;
}
