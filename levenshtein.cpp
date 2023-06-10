// The levenshtein-algorithm is painfully slow
// when written in python.
// Therefore I have created this c++ script.


#include <fstream>
#include <string>
//#include <iostream>

using namespace std;


int levenshtein(std::string s, std::string t, int s_length, int t_length)
{
    int p[s_length+1];
    int q[s_length+1];
    int* a;
    int* b;
    int* c;
    a = p;
    b = q;
    for(int m = 0; m <= s_length; m++)
    {
        a[m]=m;
    }
    for(int n = 0; n < t_length; n++)
    {
        b[0]=n+1;
        for(int m = 0; m < s_length; m++)
        {
            b[m+1] = min(
                min(a[m+1], b[m])+1, 
                a[m]+(s[m]!=t[n])
            );
        }
        c = a;
        a = b;
        b = c;
    }
    return a[s_length];
}

int main(int argc, char* argv[])
{
    if (argc!=3){return 1;}
    std::ifstream my_instream(argv[1]);
    std::ofstream my_outstream(argv[2]);
    string s, t;
    int s_length, t_length;
    while (getline(my_instream, s))
    {
        getline(my_instream, t);
        s_length = s.length();
        t_length = t.length();
        if (s_length < t_length)
        {my_outstream << levenshtein(s, t, s_length, t_length) << "\n";}
        else
        {my_outstream << levenshtein(t, s, t_length, s_length) << "\n";}
    }
    my_instream.close();
    my_outstream.close();
    return 0;
}


