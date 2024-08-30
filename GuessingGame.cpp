#include <iostream>
#include <ctime>

using namespace std;

int main() {

  // generates random seed
  srand(time(NULL));

  // generates random number for user to guess
  int number = rand()%101;

  // keeps track of if the user still is playing or not
  bool playing = true;

  // counts the number of guesses made by the user
  int numberOfGuesses = 0;
  while (playing == true) {

    // prompts the user to enter a guess and stores the guess
    cout << "Guess a Number:" << endl;
    int guess = 0;
    cin >> guess;

    // Tracks the number of guesses made by user
    numberOfGuesses++;

    // If the user guesses the number
    if (guess == number) {

      // Let user know how many guesses they took
      cout << "You guessed the target number in " << numberOfGuesses << " attempt(s)" << endl;
      cout << "Would you like to play again? Enter y or n." << endl;
      char keepPlaying = 'a';
      cin >> keepPlaying;
      // If the user inputs they want to keep playing we reset all variables and generate new random number
      if (keepPlaying == 'y') {
        playing == true;
	srand(time(NULL));
        number = rand()%101;
	numberOfGuesses = 0;
      }
      // else we set playing to false which ends the loop and program
      else {
	playing = false;
      }
    }
    // if the users guess is less than the target we print out the following messages
    else if (guess < number) {
      cout << "Your guess is less than the target number" << endl;
    }
    // if the users guess is greater than the target we print out the following messages
    else {
      cout << "Your guess is greater than the target number" << endl;
    }
  }
  return 0;
}
