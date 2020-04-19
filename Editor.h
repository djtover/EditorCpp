#include <iostream>
#include "Document.h"
using namespace std;

class Editor{
  private:
    Document doc;
  public:
    Editor(){
      cout<< "E"<<endl;
    }
    void loop();
};
