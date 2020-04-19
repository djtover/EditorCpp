#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Document{
  private:
    vector<string> vect;
  public:
    Document(){
      cout<<"Document"<< endl;
    }
    vector<string> getVect();
    void setVect(vector<string> v);
    void printVect();
};
