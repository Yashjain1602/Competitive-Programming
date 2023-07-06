#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
  //Creation
  unordered_map<string,int> m;

  //Insertion
  //Way One
  pair<string,int> p = make_pair("Yash",3);
  m.insert(p);

  //Way 2
  pair<string,int> pair2("Jain",2);
  m.insert(pair2);

  //Searching
  cout<<m["Yash"]<<endl;
  cout<<m.at("Jain")<<endl;

  //Way 3
  m["great"] = 1;
cout<<m["great"]<<endl;
  m["great"] = 4;//It will update the previous entry.
cout<<m["great"]<<endl;
  

 cout<<m["unknownKey"]<<endl;

  
  return 0;
}