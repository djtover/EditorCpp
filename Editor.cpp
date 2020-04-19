#include "Editor.h"
Editor::Editor(){

}
void Editor::loop(){
  //Getting the input into the vector
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




  //Reading the vector in order to organize new vector
  bool after = false;
  bool before = false;
  bool change = false;
  int index = 0;
  vector<string> v2;
  for(auto i=v1.begin();i!=v1.end();++i){

    string line = *i;
    char end = line[line.length()-1];
    char beg = line[0];
    if(after || before || change){
      if(line == "."){
        after = false;
        before = false;
        change = false;
      }
      else{
        if(after){
          v2.insert(v2.begin()+index,line);

        }
        else if(before){
          v2.insert(v2.begin()+index-1,line);

        }
        else if(change){
          // v2.erase(v2.begin()+index);
          v2.insert(v2.begin()+index,line);

        }
        index++;
        // cout<<index<<endl;
      }
    }
    //No writing going on
    else{
      if(line == "a"){
        after = true;
      }
      else if(line == "c"){
        v2.erase(v2.begin()+index);
        change = true;
      }
      else if(line == "i"){
        before = true;
      }
      else if (beg=='?'){
        int k = index;
        string text = line.substr(1,line.length());
        index=0;
        for(auto j = v2.begin();j!=v2.begin()+k;++j){

          string sw = *j;
          size_t found = sw.find(text);
          if(found != string::npos){
            cout<<sw<<endl;
            break;
          }
          index++;


        }
      }
      else if(beg =='/'){
        int k = index;
        string text = line.substr(1,line.length());
        for(auto j = v2.begin()+k;j!=v2.end();++j){

          string sw = *j;
          size_t found = sw.find(text);
          if(found != string::npos){
            cout<<sw<<endl;
            break;
          }
          index++;

        }

      }
      else if(end == 'n'){
        int num = stoi(line.substr(0,line.length()-1));
        index = num-1;
        auto val = v2.begin()+index;
        cout<< num<<"\t"<<*val<<endl;
        index++;
      }
      else if(end == 'p'){
        for(auto j = v2.begin();j!=v2.end();++j){
          cout<<*j<<endl;
        }
        index = v2.size()-1;
      }
      else if(end == 'd'){
        int num = stoi(line.substr(0,line.length()-1));
        index = num-1;
        v2.erase(v2.begin()+index);

      }
      else if(end == '/'){
        string swap = line.substr(2,line.length()-1);
        size_t j = swap.find("/");
        string str1 = swap.substr(0,j);
        string str2 = swap.substr(j+1,swap.length()-1);
        str2 = str2.substr(0,str2.length()-1);
        auto val = v2.begin()+index;
        string star = *val;
        size_t found = star.find(str1);
        // cout<<star<<="=star"<<endl;
        // cout<<str1<<
        if(found!=string::npos){

          star.replace(found,str1.length(),str2);
          v2.erase(v2.begin()+index);
          v2.insert(v2.begin()+index,star);
        }
        index++;


      }
      else if(end == 'j'){
        string swap = line.substr(0,line.length()-1);
        size_t j = swap.find(",");
        string num1 = swap.substr(0,j);
        string num2 = swap.substr(j+1,swap.length());
        int n1 = stoi(num1)-1;
        int n2 = stoi(num2)-1;
        // n1--;
        // n2--;
        auto star1 = v2.begin()+n1;
        auto star2 = v2.begin()+n2;
        string starnum = *star1 + *star2;
        // cout<<*(v2.begin()+n1)<<"=starnum"<<endl;
        v2.erase(v2.begin()+n1);
        v2.erase(v2.begin()+n2-1);
        v2.insert(v2.begin()+n1,starnum);
        index = n1;


      }
      else if(end == 'Q'){
        break;
      }
    }
  }
}
