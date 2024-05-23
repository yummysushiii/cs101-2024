#include <iostream>
#include <string>
using namespace std;
#include <fstream>\
#include <cstring>

class myString{
	private:
		string m_str;
	public:
		myString(string s){
			m_str = s;
		}
};

class ReadClass{
	public:
		void showClass(){
			ifstream in;
			string line;
			in.open("main.cpp");
			int count = 0;
			string st[99];
			while (getline(in, line)){
				if(line.find("class") == 0){
					count = count + 1;
					st[count-1]=line.erase(line.find("{"), 1);
				}
			}
			in.close();
			
			cout<<count<<" class in main.cpp"<<endl;
			for(int i = 0; i < count; i++){
				cout<<st[i]<<endl;
			} 
			
		}
};

int main() {
	ReadClass rfile;
	rfile.showClass();
	return 0;
}
