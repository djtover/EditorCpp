#include "Document.h"

vector<string> Document::getVect(){
  return vect;
}
void Document::setVect(vector<string> v){
    vect.assign(v.begin(),v.end());
}
void Document::printVect(){
  for(auto i = vect.begin();i!=vect.end();++i){
    cout<<*i<<endl;
  }
}
