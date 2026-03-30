#include <cstring>
#include <iostream>
using namespace std;

class String{

private:
  char* data;

public:
  String(){data = nullptr;}


  String(const char* str){
    if (str != nullptr){
      data = new char[strlen(str)+1];
      strcpy(data, str);
    } else {data = nullptr;}
  }


  String(const String& str){
    if (str.data != nullptr){
      data = new char[strlen(str.data)+1];
      strcpy(data, str.data);
    } else {
      data = nullptr;
    }
  }

  void print(){
    if (data != nullptr){
      cout << data << endl;
    } else {cout << "data is empty" << endl;}
  }

  ~String(){
    cout << "String cleared" << endl;
    delete [] data;
  }
};

int main() {
  String s1("hi");
  String s2;
  String s3 = s1;

  s1.print();
  s2.print();
  s3.print();
}
