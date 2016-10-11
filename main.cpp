#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("??.stl");//Here is your .stl file's name.
    fout.open("result.txt");//result is stored in result.txt
    char ch;
    do{
        fin.get(ch);
    }while(ch!='\n');

    while(!fin.eof()){
        while(ch==' '||ch=='\n'){
            fin.get(ch);
        }

        if(ch=='e')break;

        fout<<"glBegin(GL_LINE_LOOP);"<<endl;
        while(ch!='l'){
            fin.get(ch);
        }

        fin.get(ch);
        fin.get(ch);
        fout<<"glNormal3f(";
        while(ch!=' '){
            fout<<ch;
            fin.get(ch);
        }
        fout<<',';
        fin.get(ch);
        while(ch!=' '){
            fout<<ch;
            fin.get(ch);
        }
        fout<<',';
        fin.get(ch);
        while(ch!='\n'&&ch!='\r'){
            fout<<ch;
            fin.get(ch);
        }
        fout<<");"<<endl;
        fin.get(ch);
        while(ch!='\n'&&ch!='\r'){
            fin.get(ch);
        }

        for(int i=0;i<3;i++){
        while(ch!='x'){
            fin.get(ch);
        }

        fin.get(ch);
        fin.get(ch);
          fout<<"glVertex3f(";
          while(ch!=' '){
            fout<<ch;
            fin.get(ch);
          }
          fout<<',';
          fin.get(ch);
          while(ch!=' '){
            fout<<ch;
            fin.get(ch);
          }
          fout<<',';
          fin.get(ch);
          while(ch!='\n'&&ch!='\r'){
            fout<<ch;
            fin.get(ch);
          }
          fout<<");"<<endl;
        }
        fin.get(ch);
        while(ch!='\n'&&ch!='\r'){
            fin.get(ch);
          }
        fin.get(ch);
        while(ch!='\n'&&ch!='\r'){
            fin.get(ch);
          }
        fout<<"glEnd();"<<endl;

    }
    fin.close();
    fout.close();
    return 0;
}
