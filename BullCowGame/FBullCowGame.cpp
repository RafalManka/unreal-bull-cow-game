#include <utility>

//
// Created by rafal.manka on 26/07/2018.
//

#include <iostream>
#include <set>
#include "FBullCowGame.h"

#define TSet std::set

using FString = std::string;
using int32 = int;

void FBullCowGame::Reset() {
    CurrentTry = 1;
    MaxTries = 5;
    MyHiddenWord = "cat";
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

EGuessStatus FBullCowGame::GetValidity(FString guess) {
    if (!this->IsIsogram(guess)) {
        // if guess is not isogram return error
        return EGuessStatus::Not_Isogram;
    } else if (!this->isLowercase(guess)) {
        // if guess is not lowercase return error
        return EGuessStatus::Not_Lowercase;
    } else if (!this->isCorrectLength(guess)) {
        // if the guess is wrong, return error
        return EGuessStatus::Wrong_Length;
    } else {
        // otherwise return ok
        return EGuessStatus::OK;
    }
}

int32 FBullCowGame::GetCurrentTry() { return CurrentTry; }

bool FBullCowGame::IsGameWon() { return isGameWon; }

FString FBullCowGame::GetGuess() {
    FString Guess;
    getline(std::cin, Guess);
    return Guess;
}

FBullCowGame::FBullCowGame() { Reset(); }

FBullCowCount FBullCowGame::SubmitValidGuess(FString guess) {
    CurrentTry++;
    int32 Bulls = 0;
    int32 Cows = 0;
    for (int32 i = 0; i < MyHiddenWord.length(); i++) {
        for (int32 j = 0; j < guess.length(); j++) {
            if (MyHiddenWord[i] == guess[j]) {
                if (i == j) {
                    Bulls++;
                } else {
                    Cows++;
                }
            }
        }
    }

    FBullCowCount BullCowCount = FBullCowCount();
    BullCowCount.Bulls = Bulls;
    BullCowCount.Cows = Cows;
    isGameWon = Bulls == MyHiddenWord.length();
    return BullCowCount;
}

int32 FBullCowGame::GetWordLength() const {
    return static_cast<int32>(MyHiddenWord.length());
}

bool FBullCowGame::IsIsogram(FString Word) {
    TSet<char> LettersSeen;
    for (char Letter : Word) {
        Letter = static_cast<char>(tolower(Letter));
        if (LettersSeen.find(Letter) != LettersSeen.end()) {
            return false;
        }
        LettersSeen.insert(Letter);
    }
    return true;
}

bool FBullCowGame::isCorrectLength(FString basic_string) {
    return basic_string.length() == this->GetWordLength();
}

bool FBullCowGame::isLowercase(FString Word) {
    for (const char Character : Word) {
        if (!islower(Character)) {
            return false;
        }
    }
    return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) {
    if (!IsIsogram(guess)) {
        return EGuessStatus::Not_Isogram;
    }
    if (!isLowercase(guess)) {
        return EGuessStatus::Not_Lowercase;
    }
    return EGuessStatus::OK;
}




