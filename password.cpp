#include <iostream>
#include <string>
#include <array>
#include <sodium.h>
#include <cstddef>
#include <fstream>

using namespace std;

int main()
{
  if(sodium_init()<0)
  {
    cerr<<"Sodium init did not work\n";
    return 1;
  }

  constexpr array<char, 78> data=
    {
        'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z',
        '0','1','2','3','4','5','6','7','8','9',
        '!','@','#','$','%','^','&','*','(',')','-','_','+','=','?'
    };

  cout<<"          ==================================="<<endl;
  cout<<"          =============WELCOME==============="<<endl;
  cout<<"          ==================================="<<endl;

  cout<<"\n";
  cout<<"\n";

  cout<<"        DPassword is an educational project which"<<endl;
  cout<<"    creates random, secured, and encrypted passwords"<<endl;
  cout<<"                         for you.             "<<endl;

  cout<<"\n";
  cout<<"\n";

  cout<<       "Enter the length you wish for your password\n";
  size_t len=0;
  cin>>len;
  if(len==0&&len<<0&&len>>100)
  {
    cerr<<"   Your password's length should be between 1 and 100"<<endl;
    return 1;
  }

  string password(len, 0);
  randombytes_buf(password.data(), len);

  for(size_t i=0; i<len; i++)
  {
    unsigned char byte=static_cast<unsigned char>(password[i]);
    password[i]=data[byte%data.size()];
  }

  cout<<"Your password is:"<<endl;
  cout<<password<<endl;

  cout<<"\n";
  cout<<"\n";

  cout<<"Would you like to save this password on a .txt file? (y/n):"<<endl;
  char answer;
  cin>>answer;
  if(answer=='y'||'Y')
  {
    ofstream save("passwords.txt");
    save<<password;
  } else if(answer=='n'||'N')
  {
    return 0;
  } else 
  {
    cerr<<"Wrong Input"<<endl;
    return 1;
  }

  return 0;
}
