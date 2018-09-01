//
// Created by rafal.manka on 26/07/2018.
//

#ifndef BULLCOWGAME_BULLCOWGAME_H

#define BULLCOWGAME_BULLCOWGAME_H

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
    bool IsWon = false;
};

enum class EGuessStatus {
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame();

    int32 GetMaxTries() const;

    int32 GetCurrentTry();

    bool IsGameWon();

    EGuessStatus GetValidity(FString);

    std::string GetGuess();

    int32 GetWordLength() const;

    void Reset();

    FBullCowCount SubmitGuess(FString);

private:
    int32 CurrentTry;
    int32 MaxTries;
    FString MyHiddenWord;

    bool IsIsogram(FString basic_string);

    bool isCorrectLength(FString basic_string);

    bool isLowercase(FString basic_string);
};


#endif //BULLCOWGAME_BULLCOWGAME_H
