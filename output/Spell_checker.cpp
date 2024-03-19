//=======================================================================
// //======================= Eslam_Eed01 ================================
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

char lower_case[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                     'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int MissingCharacter (string input)
{
    string Einput, line, Sinput, Tline, Xline;
    int found = 0;
    ifstream words ("listof_words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            for (int i = 0; i < 26; i++)
            {
                int len = input.size(), flen = line.size();
                Einput = input;
                Xline = line;
                Einput.resize(len+1,'a');
                Einput[len] = lower_case[i];
                len = Einput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++)
                        Ninput.push_back(Einput[j]);
                    for (int j = 1; j <= flen; j++)
                        Nline.push_back(Xline[j]);
                    Einput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Sinput = Einput + Ninput;
                    Tline = Xline + Nline;
                    if (Sinput == Tline)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"error occurred\n";
    }
    return found;
}





int ExchangedCharacters (string input)
{
    string line, Einput;
    int found = 0;
    ifstream words ("listof_words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Einput = input;
                    Einput[i] = lower_case[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Einput == line)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                        Einput[i] = lower_case[j];
                    }
                    if (found == 1 ) break;
                    
                    else
                    
                    continue;
                }
            }
        }
        words.close();
    }
    
    else cout<<"error occurred"<<endl;
    return found;
}



int disarrangement(string input)
{
    string line;
    int found = 0;
    ifstream words ("listof_words.txt");
    if (words)
    {
        while(getline(words,line))
        {
            string Einput = input, Ninput, permutations, Sinput, Tline, Nline, Xline = line;
            int len = Einput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<(int)Einput.length(); i++)
                    Ninput.push_back(input[i]);
                for (int i = 1; i < flen; i++)
                    Nline.push_back(Xline[i]);
                Einput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Sinput = Einput + Ninput;
                Tline = Xline + Nline;
                if (Sinput == Tline)
                {
                    found = 1;
                    cout<<line<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<" error occurred "<<endl;
    }
    return found;
}


int ExtraCharacter (string input)
{
    string Einput, line, Ninput, Sinput;
    int found = 0;
    ifstream words ("listof_words.txt");
    if (words)
    {
        while (getline(words,line))
        {
             int len = input.size(), flen = line.size();
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     Einput = input;
                     Einput.erase(Einput.begin()+i);
                     if (Einput == line)
                     {
                         found = 1;
                         cout<<line<<endl;
                         break;
                     }

                 }
             }
        }
        words.close();
    }
    else
    {
        cout<<" error occurred \n";
    }
    return found;
}

int ExtraMissingCharacters (string input)
{
    string Einput, line, Xline;
    int found = 0;
    ifstream words ("listof_words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Einput = input; Xline = line;
                        Einput.erase(Einput.begin()+i);
                        Einput.resize(len, 'a');
                        Einput[len-1] = lower_case[j];
                        sort(Einput.begin()+1,Einput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Einput == Xline)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}

int main()
{
    while (1) {
        string input,line;
        int len,flen,correct=0;
        cout<<"Enter the word: "; getline(cin,input);
        len = input.length();
        for (int i=0; i < len; i++)
            input[i] = tolower(input[i]);
        ifstream words ("listof_words.txt");
        if(words)
        {
            while (getline(words,line))
            {
                flen = line.length();
                if (len==flen)
                {
                    if (line==input)
                    {
                        correct=1;
                    }
                    else continue;
                }
                else continue;
            }
            words.close();
            if (correct==1)
            {
                cout<<"Spelling is correct"<<endl;
            }
            if (correct==0)
            {
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                cout<<endl<<"Spelling is wrong. Possible right spellings are given below:- "<<endl;
                missing = MissingCharacter(input);
                extra = ExtraCharacter(input);
                mixed = ExtraMissingCharacters(input);
                incorrect = disarrangement(input);
                exchanged = ExchangedCharacters(input);
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    cout<<"No such word exist"<<endl;
                }
            }
        }
        else
        {
            cout<<"Not able to openlistof_words.txt"<<endl;
        }
        cout<<endl<<"Press any key to continue "<<endl;
    }
    return 0;

}