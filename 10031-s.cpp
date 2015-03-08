#include<iostream>
#include<string>


using namespace std;

#define DEBUG
#ifdef DEBUG
string EOL = "\n";
string SP = " ";
string TAB = "\t";
#else
string SP = "";
string EOL = "";
string TAB = "";
#endif

int main()
{
  cout 
    << "int cnt,i,j,n,nn,q,qq,buf[10000],mem[10000001];" << EOL
    << "main()" << EOL
    << "{" << EOL
    << TAB << "scanf(\"%d\",&n);" << EOL
    << TAB << "nn = n / 10000;" << EOL
    << TAB << "for(i=0;i<nn;i++)" << EOL
    << TAB << "{" << EOL
    << TAB << TAB << "scanf(\"";

  for(int i = 0; i < 10000; i++)
    cout << "%d";
  cout << "\"";
  for(int i = 0; i < 10000; i++)
    cout << ",buf+" << i;
  cout << ");" << EOL; 
    
  cout
    << TAB << TAB << "for(j=0;j<10000;j++)" << EOL
    << TAB << TAB << "{" << EOL
    << TAB << TAB << TAB << "mem[i*10000+j]=1;" << EOL
    << TAB << TAB << "}" << EOL
    << TAB << "}" << EOL
    << TAB << "scanf(\"%d\",&q);" << EOL
    << TAB << "qq = q / 1000;" << EOL
    << TAB << "for(i=0;i<qq;i++)" << EOL
    << TAB << "{" << EOL
    << TAB << TAB << "scanf(\"";
  
  for(int i = 0; i < 1000; i++)
    cout << "%d";
  cout << "\"";
  for(int i = 0; i < 1000; i++)
    cout << ",buf+" << i;
  cout << ");" << EOL;

  cout
    << TAB << TAB << "for(j=0;j<1000;j++)" << EOL
    << TAB << TAB << "{" << EOL
    << TAB << TAB << TAB << "cnt+=mem[i*1000+j];" << EOL
    << TAB << TAB << "}" << EOL
    << TAB << "}" << EOL; 
    
    cout 
    << TAB << "printf(\"%d\\n\", cnt);" << EOL
    << "}" << EOL;
    
}
