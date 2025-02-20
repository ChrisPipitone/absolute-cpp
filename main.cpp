#include<iostream>
using namespace std;

class Counter {
  private :
    int count = 0;
    int maxCount = 0;
  public:
    Counter(int chosenMaxCount){
      maxCount = chosenMaxCount;
    };  
  
    void reset() { count = 0;}
    
    //detects overflow
    bool overflow(){
      if(count > 0 && maxCount > 0 && count >= maxCount) return true;
      else return false;
    }
  
    //accounting for any carrying when incrementing should require no 
    //further action than adding an appropriate number to the private 
    //data variable

    //an optimization might be to have each increment function
    //return a bool telling if the operation caused an overflow?

    //increment units the units digit by 1
    void incr1(){ count++;}
  
    //increment units the tens digit by 1
    void incr10(){ count = count + 10; }
  
    //increment units the hundreds digit by 1
    void incr100(){ count = count + 100; }
    
    //increment units the thousands digit by 1
    void incr1000(){ count = count + 1000; }

    //even though the display is an integer, in the simulation, the 
    //rightmost (lower order) two digits are alwayus thought of as 
    //cents and tens of cents, the next digit is dollars and the 
    //fourth digit is tens of dollars
   
    //$99.99 is meant to be the ceiling of the application
    
    //Input 
    //use the keys asdfo
    //a for cents, followed by a digit 1-9
    //s for dimes, followed by a digit 1-9
    //d for dollars, followed by a digit 1-9
    //f for tens of dollars, followed by a digit 1-9
    //each entry (one of asdf followed by 1-9) is followed by pressing 
    //the Return key. any overflow is reported after each operation
    //overflow can be requested by pressing the o key
    
    //Let the user know overflow has occured and give them the chance
    //to start over 

};


int main () {
  //instanciate counter
  Counter counter(100);
  bool exit = false;
  string input = "";

  //counter loop
  while(!exit){
    //exit if q key is pressed
    if(input == "q"){
      exit = true;
    }
    //user enter values
  

    //calc those values into counter
  }

  return 0;
}
