#include <iostream>
#include <string> 
using namespace std;

class Car{
	protected:
	string m_DriveMode;
	private:
	int m_MaxSeating;
	int m_price;
	void m_UpdatePrice(int base = 50000){
		m_price = m_MaxSeating * base;
	}
	public:
	string m_brand;
	string m_model;
	int m_year;

	Car(string x, string y, int z, int s){
		m_brand = x;
		m_model = y;
		m_year = z;
		m_MaxSeating = s;
		m_UpdatePrice();
		
	}
	int get_Price(){
		return m_price;
	}
};
class BMW_Car : public Car {
	public:
	BMW_Car(string y, int z, int s) : Car("BMW", y, z ,s){
		cout << "Constructing BMW_Car\n";
		m_DriveMode = "Rear-wheel";
	} 
		 
	string get_DriveMode(){
		return m_DriveMode;
	}
};

class Audi_Car : public Car {
	public:
	Audi_Car(string y, int z, int s) : Car("Audi", y, z ,s){
		cout << "Constructing Audi_Car\n";
		m_DriveMode = "Front-wheel";
	} 
		 
	string get_DriveMode(){
		return m_DriveMode;
	}
};

class Benz_Car : public Car {
	public:
	Benz_Car(string y, int z, int s) : Car("Benz", y, z ,s){
		cout << "Constructing Benz_Car\n";
		m_DriveMode = "Front-wheel";
	} 
		 
	string get_DriveMode(){
		return m_DriveMode;
	}
};

int main(){
	BMW_Car car_0("X5", 2023, 6);
	cout << car_0.m_brand;
	cout << " : Drive Mode = " << car_0.get_DriveMode() << endl;
	
	Audi_Car car_1("X5", 2023, 6);
	cout << car_1.m_brand;
	cout << " : Drive Mode = " << car_1.get_DriveMode() << endl;
	
	Benz_Car car_2("X5", 2023, 6);
	cout << car_2.m_brand;
	cout << " : Drive Mode = " << car_2.get_DriveMode() << endl;
	return 0;
}
