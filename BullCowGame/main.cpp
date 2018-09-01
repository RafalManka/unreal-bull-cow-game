/* This is the console executable, that makes use of the BullCow class.
 * This acts like a view of MVC pattern.
 *
 * */
//
//  main.cpp
//  FBullCowGame
//
//  Created by rafal.manka on 22/07/2018.
//  Copyright © 2018 Rafal Manka. All rights reserved.
//

#include <iostream>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

auto *BCGame = new FBullCowGame();

bool AskToPlayAgain();

int32 PrintBanner() {
    std::cout << "Welcome to \"Bulls and Cows\"" << std::endl;
    std::cout << "Can you guess the " << BCGame->GetWordLength() << " letter I'm thinking of?" << std::endl;
    return 0;
}

FString GetValidGuess() {
    FString Guess = BCGame->GetGuess();
    EGuessStatus Status = BCGame->GetValidity(Guess);
    switch (Status) {
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame->GetWordLength() << " word length." << std::endl;
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter a word without repeating letters" << std::endl;
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter a lowercase words" << std::endl;
            break;
        default:
            break;
    }
    return Guess;
}

int32 PlayGame() {
    for (int32 count = 0; count < BCGame->GetMaxTries(); count++) {
        std::cout << "Enter your guess: ";
        FString Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame->SubmitGuess(Guess);
        std::cout << "Bulls= " << BullCowCount.Bulls << ". Cows= " << BullCowCount.Cows << std::endl;
        if (BullCowCount.IsWon) {
            std::cout << "The game is over. You won. Thank you";
            break;
        }
    }
    return 0;
}

FString Uppercase(FString &str) {
    std::locale settings;
    FString converted;
    for (char i : str) {
        converted += (toupper(i, settings));
    }
    return converted;
}

bool AskToPlayAgain() {
    std::cout << "Would you like to play again? Y/N";
    FString Choice;
    getline(std::cin, Choice);
    Choice = Uppercase(Choice);
    return Choice == "Y" || Choice == "YES";
}

int main(int argc, const char *argv[]) {
    PrintBanner();
    do {
        PlayGame();
    } while (AskToPlayAgain());
    return 0;
}