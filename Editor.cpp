#include "Editor.h"

void Editor::loop(){
  bool writing = false;
  string s = "";
  vector<string> v1;
  while(s!="Q" || writing){
    getline(cin,s);
    v1.push_back(s);
    if(writing && s=="."){
      writing = false;
    }
    if(s=="a" || s=="i" || s=="c"){
      writing = true;
    }
  }
  doc.setVect(v1);
  cout<<doc.getVect().size();
  doc.printVect();





  // while(writing || notEmpty){
  //
  //
  //   if(writing && s=="."){
  //     writing = false;
  //     cout<<s<<endl;
  //   }
  //   else if(writing){
  //     cout<<s<<endl;
  //   }
  //   if(s == "a"){
  //     writing = true;
  //   }
  //   else if(s=="i"){
  //     writing = true;
  //   }
  //   else if(s=="c"){
  //     writing = true;
  //   }
  //   else{
  //     cout<<s<<endl;
  //   }
  //   if(s=="" && !writing){
  //     notEmpty = false;
  //   }
  // }

}
