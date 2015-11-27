#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* This is a recursive function to print permuted options.
*/
void PrintOption(vector<vector<string> >& optionGroups, unsigned int idx, vector<unsigned int>& pivots)
{
   vector<string> optionGroup = optionGroups[idx];
   if (pivots[idx] < optionGroup.size())
   {
      cout << optionGroup[pivots[idx]] << " ";
      if (idx < optionGroups.size() - 1)
      {
         idx++;
         PrintOption(optionGroups, idx, pivots);
      }
      else
      {
         cout << endl;
         pivots[idx]++;
         if (idx > 0)
         {
            int i = idx;
            while (i > 0)
            {
               if (pivots[i] == optionGroups[i].size())
               {
                  pivots[i - 1]++;
                  pivots[i] = 0;
               }
               i--;
            }
            idx = 0;
         }
         PrintOption(optionGroups, idx, pivots);
      }
   }
}

/*
* This is a function to split a string into a vector of splited strings.
*/
void Split(vector<string>& lst, string input, const string separators, bool remove_empty = true) 
{   
   while (true) 
   {
      unsigned int index = input.find(separators);
      if (index != string::npos) 
      {
         if (index == 0 && remove_empty) continue;
         lst.push_back(input.substr(0, index));
      }
      else 
      {
         lst.push_back(input);
         break;
      }

      if(input.size() < index) {
        break;
      }
      input = input.substr(index + separators.size());
   }
}


int main (int argc, char *argv[]) 
{
   int ret = 0;
   bool isContinued = true;
   vector<vector<string> > optionGroups;
   string debugStr = "";
   try
   {
      while (isContinued)
      {
         char buff[2048];
         string stdIn;
         cin.getline(buff, 2048);
         stdIn = buff;
         debugStr += stdIn + "\n";
         if (stdIn.length() > 0)
         {
            vector<string> options;
            Split(options, stdIn, "|");
            optionGroups.push_back(options);
         }
         else
         {
            isContinued = false;
         }
      }
      vector<unsigned int> pivots;
      for (unsigned int i = 0; i < optionGroups.size(); i++) pivots.push_back(0);
      PrintOption(optionGroups, 0, pivots);
   }
   catch (const string& errMsg)
   {
      cout << debugStr << endl;
      cerr << errMsg << endl;
   }

   return ret;
 }
