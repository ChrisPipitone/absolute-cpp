#include <iostream>
#include <string.h>
using namespace std;

class Counter {
private:
  int count = 0;
  int maxCount = 0;

public:
  Counter(int chosenMaxCount) { maxCount = chosenMaxCount; };

  void reset() { count = 0; }

  // detects overflow
  bool overflow() {
    if (count > 0 && maxCount > 0 && count >= maxCount)
      return true;
    else
      return false;
  }
  float getCount() {
    // even though the display is an integer, in the simulation, the
    // rightmost (lower order) two digits are alwayus thought of as
    // cents and tens of cents, the next digit is dollars and the
    // fourth digit is tens of dollars
    return (float)count / 100;
  }
  // accounting for any carrying when incrementing should require no
  // further action than adding an appropriate number to the private
  // data variable

  // an optimization might be to have each increment function
  // return a bool telling if the operation caused an overflow?

  // increment units the units digit by 1
  void incr1() { count++; }

  // increment units the tens digit by 1
  void incr10() { count = count + 10; }

  // increment units the hundreds digit by 1
  void incr100() { count = count + 100; }

  // increment units the thousands digit by 1
  void incr1000() { count = count + 1000; }

  //$99.99 is meant to be the ceiling of the application

  // Input
  // use the keys asdfo
  // a for cents, followed by a digit 1-9
  // s for dimes, followed by a digit 1-9
  // d for dollars, followed by a digit 1-9
  // f for tens of dollars, followed by a digit 1-9
  // each entry (one of asdf followed by 1-9) is followed by pressing
  // the Return key. any overflow is reported after each operation
  // overflow can be requested by pressing the o key

  // Let the user know overflow has occured and give them the chance
  // to start over
};

int main() {
  // instanciate counter
  Counter counter(10000);
  string input = "";

  cout << "Guide:";
  cout << "Use the keys asdfo \n"
       << "a for cents, followed by a digit 1-9 \n"
       << "s for dimes, followed by a digit 1-9 \n"
       << "d for dollars, followed by a digit 1-9 \n"
       << "f for tens of dollars, followed by a digit 1-9 \n"
       << "each entry (one of asdf followed by 1-9) must be followed by \n"
       << "the Return key. any overflow will be reported after each "
          "operation \n"
       << "overflow can be requested by pressing the o key \n";
  // counter loop
  while (true) {
    // get user input
    cout << "\n ---------- \n Current count: " << counter.getCount() << endl;
    cin >> input;

    // exit if q key is pressed
    if (input.length() == 2 && isdigit(input[1])) {
      int times = input[1] - '0';
      switch (input[0]) {
        case 'a': for (int i = 0; i < times; ++i) counter.incr1(); break;
        case 's': for (int i = 0; i < times; ++i) counter.incr10(); break;
        case 'd': for (int i = 0; i < times; ++i) counter.incr100(); break;
        case 'f': for (int i = 0; i < times; ++i) counter.incr1000(); break;
        case 'q': break;
        default: cout << "Try Again.\n";
      }
    }
    
    // overflow is either caused or requested
    if (counter.overflow() || input[0] == 'o') {
      cout << "\n\n --- Overflow has occured! --- \n";
      cout << "Press q to exit or press r to reset the counter and start over "
              "\n";
      cin >> input;
      if (input[0] == 'r') {
        counter.reset();
      }
    }

    // calc those values into counter
  }

  return 0;
}
