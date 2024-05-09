#include <iostream>
#include <string> 
using namespace std;


class Fueltank {
	private:
		int m_FueltankCapacity;
		int m_Gas_grade;
	public: 
		Fueltank(int FueltankCapacity=3000, int Gas=98){
			m_FueltankCapacity = FueltankCapacity;
			m_Gas_grade = Gas;
		}
		int fuel_up(int v, int gas){
			if(v<m_FueltankCapacity && gas==m_Gas_grade){
				return 1;
			}
			else if(v>m_FueltankCapacity && gas!=m_Gas_grade){
				return 4;
			}
			else if(v<m_FueltankCapacity && gas!=m_Gas_grade){
				return 2;
			}
			else if(v>m_FueltankCapacity && gas==m_Gas_grade){
				return 3;
			}
			
		}
		int set_Gas_grade(int Gas_grade){
			m_Gas_grade = Gas_grade;
		}
		int get_Gas_grade(){
			return m_Gas_grade;
		}
};

class Car{
	protected:
		Fueltank m_Fueltank;
		string m_DriveMode;
		string m_brand;
	private:
//		Engine m_Engine;
		
		int m_MaxSeating;
		int m_price;
		int m_base;
		
		string m_model;
		int m_year;
		void m_UpdatePrice(int base = 50000){
			m_price = m_MaxSeating * base;
		}
	public:
		int get_MaxSeating() {
	        return m_MaxSeating;
	    }
	    int get_price() {
	        return m_price;
	    }
	    void set_base(int n) {
	        m_base = n;
	    }
	    string get_brand() {
	        return m_brand;
	    }
	    bool get_EngineStatus() {
	        // Add implementation here
	    }
	    bool startEngine() {
	        // Add implementation here
	    }
	    bool stopEngine() {
	        // Add implementation here
	    }
	    int get_Gas_grade() {
	        return m_Fueltank.get_Gas_grade();
	    }
	    int set_Gas_grade(int gas = 98) {
	        return m_Fueltank.set_Gas_grade(gas);
	    }
	    int fuel_up(int v, int gas = 98) {
	        return m_Fueltank.fuel_up(v, gas);
	    }
	    Car(string x, string y, int z, int s) {
	    	get_brand();
	        m_UpdatePrice();
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
//		m_DriveMode = "Front-wheel";
		m_brand = "Audi";
	} 
		 
//	string get_DriveMode(){
//		return m_DriveMode;
//	}
	string get_brand(){
		return m_brand;
	}
	
	int get_Gas_grade(){
		return m_Fueltank.get_Gas_grade();
	}
	int set_Gas_grade(int gas){
		m_Fueltank.set_Gas_grade(gas);
		cout << "Set Gas_grade = " << gas << endl;
	}
	
	int fuel_up(int v, int gas){
		int boolean = m_Fueltank.fuel_up(v, gas);
		if(boolean == 1){
			cout << "fuel_up: " << v << " Gas_grade: " << gas <<endl;
		}
		else if(boolean == 2){
			cout << "Error: " << " Gas_grade: " << gas << " Correct Gas_grade:  " << get_Gas_grade() <<endl;
		}
		else if(boolean == 3){
			cout << "Error: " << " FueltankCapacity: 3000 but fuel up: " << v <<endl;
			cout << "fuel_up: " << v << " Gas_grade: " << gas <<endl;
		}
		else{
			cout << "Error: " << " FueltankCapacity: 3000 but fuel up: " << v <<endl;
			cout << "fuel_up: " << gas << " Gas_grade: " << gas <<endl;
		}
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
//	BMW_Car car_0("X5", 2023, 6);
//	cout << car_0.m_brand;
//	cout << " : Drive Mode = " << car_0.get_DriveMode() << endl;
	
//	Audi_Car car_1("X5", 2023, 6);
//	cout << car_1.m_brand;
//	cout << " : Drive Mode = " << car_1.get_DriveMode() << endl;
//	
//	Benz_Car car_2("X5", 2023, 6);
//	cout << car_2.m_brand;
//	cout << " : Drive Mode = " << car_2.get_DriveMode() << endl;
	Audi_Car car_2("A1", 2021, 2);
	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.set_Gas_grade(95);
	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.fuel_up(300, 99); 
	return 0;
}
