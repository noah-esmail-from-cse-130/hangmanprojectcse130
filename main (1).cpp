/*
CSE 130 Final Project
Noah Esmail, Christina Buenrosto, Richard Berman, Joeseph Sutton
2 Player Hangman Game
  */
#include <iostream>
#include <string>
using namespace std;
//global variables
string enteredWord; //this is the phrase entered by the player 1. There are rules for what can be entered. Player 1 will have to enter a phrase into enteredWord until it is correct.
string usedWord; //This is the phrase that will go into the function get hangman. It must be a valid phrase
int maxIndex=0;
//function prototypes
void prtWordDisp(char wordDisp[31]);
bool containsCapitalLetters(const std::string &str);
void playHangman(string word);
int main() {
  //Here is a while loop that will continue to prompt the user until they enter an appropriate resonse. 
  bool valid= false;
  while(valid==false){
    //here are the rules
  cout << "\n\n****** Rules for player 1 *******\n \n\n **Enter a word or phrase NO MORE THAN 30 characters.** \n\n ** End the word or sentence WITH A PERIOD ** \n\n ** NO SPACES BETWEEN THE LAST WORD AND THE PERIOD ** \n\n ** ONLY USE LOWER CASE LETTERS **\n\n*********************************\n\n";
  //obtain the phrase entered by the user
  getline(cin, enteredWord);
  cout << "\n\n You entered: \n\n " << enteredWord << "\n\n" << endl;
  if(enteredWord.length()<=30){
    valid=true;
  }
  else{
    cout << "Make the entry 30 characters or less. Try again.\n";
    continue;
  }
    if( containsCapitalLetters(enteredWord) ==true){
      cout << "Make sure to only use lower case letters. Try again.\n";
      valid=false;
      continue;
    }
    if(enteredWord[enteredWord.length()-1]!= '.'){ 
      cout << "Make sure to end the word or sentence with a period. Try again.\n";
      valid= false;
      continue;
      }
    if(enteredWord.substr(enteredWord.length()-2, 1)== " "){
      cout << "Make sure to not have any spaces between the last word and the period. Try again.\n";
      valid= false;
      continue;
    }
  }
  int j= 0; 
  while(enteredWord.substr(j) !="."){
    j++;
    maxIndex++;
    //maxIndex counts the number of characters in the phrase entered by the user
  }
  usedWord=enteredWord.substr(0,maxIndex);
  playHangman(usedWord);
}

void playHangman(string word){
  cout << "Rules for player 2: Try to guess the word or phrase. You have 7 fails to guess the word or phrase.\n";
  bool isCorrect=false; //this is the boolean that will be used to determine if the user has guessed the word or phrase correctly
  int fails=0;
  char wordDisp[31]; //this is the array that will be used to display the word or phrase with underscores and the correct guesses that the user has made
  char wordElem[31];
  //This for loop fills wordDisp with underscores corresponding to the word or phrase
  for(int i=0; i< word.length(); i++){
  if(word.substr(i,1)==" "){
    wordDisp[i]=' ';
  }
  else{
    if(i<word.length()-1){
      wordDisp[i]='_';
    }
    else{
      wordDisp[i]= '_';
    }
  }
  }
  wordDisp[word.length()] = '\0';
  for(int i=0; i< word.length(); i++){
    wordElem[i]=word[i];
  }
  wordElem[word.length()] = '\0';
  //make array that contains the correct entries of the word or phrase
while(fails<7 && isCorrect==false){
  //print gallows with no hanging man
  if(fails==0){
    cout<< "\n";
    cout << " ____\n";
    cout << " |  |\n";
    cout << " |  \n";
    cout << " | \n";
    cout << " | \n";
    cout << " |\n";
    cout << "_____\n\n";
    cout << "Time to Guess! \n\n";	
    prtWordDisp(wordDisp); //print underscores so player 2 can guess
  }
  bool failed=true; //assume that the user has not guessed the word or phrase correctly. Depending on the status of this boolean at the end of the guess, This is used to count the total number of fails the guesser has. 
  cout << "\n\n Please Enter Your Guess ";
  char guess;
  cin >> guess;
  //this for loops iterates through the word to see if the user has guessed a letter correctly
  for(int i=0; i<word.length(); i++){
  if(guess==wordElem[i]){
    wordDisp[i]=guess;
    failed=false; //if the user gets it right, then the boolean is set to false
  }
  }
  
  if(failed==true){
    fails++;
    //switch statement to print the correct hangman based on the number of fails
    switch(fails){
      case 1:
        cout<< "\n";
        cout << " ____\n";
        cout << " |  |\n";
        cout << " |  0\n";
        cout << " | \n";
        cout << " | \n";
        cout << " |\n";
        cout << "_____\n";
        cout << "6 fails remaining\n";
        break;
    
    case 2:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " |  |\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "5 fails remaining\n";
      break;
      
    case 3: 
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "4 fails remaining\n";
      break;
    case 4:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "3 fails remaining\n";
      break;
    case 5:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "2 fails remaining\n";
      break;
    case 6:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | / \n";
      cout << " |\n";
      cout << "_____\n";
      cout << "1 fail remaining\n";
      break;
      
    case 7:
      cout<< "\n";
      cout << " ____\n";
      cout << " |  |\n";
      cout << " |  0\n";
      cout << " | /|\\\n";
      cout << " |  |\n";
      cout << " | / \\\n";
      cout << " |\n";
      cout << "_____\n";
      cout << "Word Chooser, you win! Guesser, you Lose!\n";
      break;
    break;
  }
 
}
  //this is the function that prints the phrase with the correct guesses
prtWordDisp(wordDisp);
isCorrect=true; //assume the user will guess the word or phrase correctly
// this for loop checks to see if the guess of the guesser matches completely with the phrase picked by the chooser
for(int i=0; i<word.length(); i++){
  if(wordDisp[i]!=wordElem[i]){
    isCorrect=false;
  }
}
if(isCorrect==true){
  cout << " Guesser, You Win! Chooser, You Lose!\n";
}
}
}
//this function prints the phrase with the correct guesses and the missing letters
void prtWordDisp(char wordDisp[31]){
  int i=0;
  while(wordDisp[i] !='\0'){
    cout << wordDisp[i];
    i++;
  }
}
//this is used to chck if the user entered a word or phrase with capital letters. It helps determine if the user entered a valid input
bool containsCapitalLetters(const std::string &str) {
    for (char ch : str) {
        if (std::isupper(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}