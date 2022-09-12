#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cctype>
#include <string>     // Allows using the tolower() function
#include <vector>     //allow using vectors
using namespace std;


//function opening the ConstitutionAndBillOfRights.txt file
void openFile(vector<string> &myFile){                
  ifstream inStream;              
  inStream.open( "ConstitutionAndBillOfRights.txt");  
  if( !inStream.is_open()) {
    cout << "Could not find ConstitutionAndBillOfRights.txt.  Exiting..." << endl;
    exit( -1);                     //exit if file not found
  }
  string words;                   //phrase to be found in the text file which user inputs               
  while( getline(inStream, words)) {
      if(words.length()>1){

          myFile.push_back(words);
      }//while loop which checks if the word is present or not in the dictionary.
  }
  inStream.close();
}


//makes the user input into lower case
string toLower(string userChoice1)   
{                                   
  for(int i=0; i<userChoice1.length();i++){
      userChoice1[i] = tolower(userChoice1[i]);
  }
  return userChoice1;
}//end of the function


//function for searching the user input in the text file given
void searchPhrase(vector<string> &myFile,string &words, int &index, string &lineFound) 
{
  cout<<"Enter word or phrase: ";
  getline(cin, words);  // taking input using get line
  
  cout<<endl;
  string c;            
  c = toLower(words); 
  
  for(int i=0;i<myFile.size();i++){  //making all the words in the text file lower case while searching for the word
    string line=myFile[i];
    line=toLower(line);
      if(line.find(c)!=string::npos){
        index=i;
        lineFound=myFile[i];
        
        break;
      }
  }
}//end of the function


//checks for all the occurances of the word in the text file and print them
void allOccurences(vector<string> &myFile,string words, int &index, string &lineFound)
{                                
  
  string c;                     
  c = toLower(words);                //converting the input into lower case    
  
  for(int i=0;i<myFile.size();i++){  //looping through the contents of the file
    string line=myFile[i];
    line=toLower(line);         //convert to lower case while searching 
      if(line.find(c)!=string::npos){
        index=i;               //index is the line number
        lineFound=myFile[i];
        cout<<"Line "<<index<<':'<<endl;
        cout<<myFile[index]<<endl;
        
      }
  }
}//end of the function

int main() {                 //defining all the variables in main
   char userChoice1;        //user input options
    vector<string> myFile; //copy of the text file into a vector 
    openFile(myFile);      
    string words;         //phrase inputed by user
    int index;            //line number 
    string lineFound;     //the found line
    char returnCharacter;
   
  cout << "Select from the following choices: \n"
        << "    W  Enter word or phrase to find, and display enclosing text \n"
        << "    X  Exit program \n"
        <<"Your choice: "<<endl;
        cin>>userChoice1;//taking first input from the user for the above options
        returnCharacter=cin.get(); // Separately store the return character so cin.getline does not consider it the next user input
        
        if (userChoice1=='W'|| userChoice1=='w'){//If user choice is W or w print the first occurance
          searchPhrase(myFile, words, index,lineFound); //calling out the search function
          cout<<"Line "<<index<<':'<<endl;
          cout<<myFile[index]<<endl;
        }
        else if(userChoice1=='X' || userChoice1=='x'){//else exit the program
            cout<<"Exiting program.";
            exit(0);//exiting the program
        }
        
    while(true){//the main loop
      //printing out the options
      cout << "Select from the following choices: \n"
            << "    W  Enter word or phrase to find, and display enclosing text \n"
            << "    P  Display previous text \n"
            << "    F  Display following text \n"
            << "    A  Display all occurrences of found word or phrase  \n"
            << "    X Exit program  \n"
            << "Your choice: "<<endl;
      
        cin>>userChoice1;                          //taking input
        returnCharacter=cin.get();
        cout<<endl;
            
        if(userChoice1=='W' || userChoice1 == 'w'){//finding the first occurance of the phrase or word input by user
        searchPhrase(myFile, words, index,lineFound);
        cout<<"Line "<<index<<':'<<endl;
        cout<<myFile[index]<<endl;
        continue;
       }
       
       else if(userChoice1=='P' || userChoice1 == 'p'){//finding the previous file contents of the input taken by user
        if(lineFound.size()>1){ //the line size should be greater than 1
            index--;
            if(index>=0){ //only prints the previous text when the index is greater than or equal to 0
              cout<<"Line "<<index<<':'<<endl;
              cout<<myFile[index]<<endl;
            }
            else{//if index is smaller than zero
            cout<<"There is no previous file contents."<<endl;
            index=0;//set the index number to zero again
          }
           }
           continue;
       }
       
       else if(userChoice1=='F' || userChoice1 == 'f'){//printing out the following file contents
          if(lineFound.size()>1){//lines should be greater than 1
            index++; //printing the next line
            if(index<251){//index sould be less than 251 lines 
              cout<<"Line "<<index<<':'<<endl;
              cout<<myFile[index]<<endl;
            }
            else{//if more than or equal to 251 lines
            cout<<"There is no following file contents."<<endl;
            index=250; //set the index to 251st line
          }
           }
           continue;
       }
       
       else if(userChoice1=='A' || userChoice1 == 'a'){//printing out all occurances of the word found in the text file
         allOccurences(myFile, words, index, lineFound); //calling out the function for finding all occurances
         continue;
       }

       else if (userChoice1 == 'x' || userChoice1 == 'X'){//exits the program
            cout << "Exiting program." << endl;
            exit(0);
            
   }
    }
   return 0;
}
         
