#include <iostream>
#include <ctime>

void PrintIntroduction (int Level = 2)
{
    std::cout << "You've stolen an ATM card!" << std::endl;
    std::cout << "To see if you can get some beer money, you visit" << std::endl;
    std::cout << "a horribly designed ATM." << std::endl;
    std::cout << "Its security level is only " << Level << std::endl;
    std::cout << "Enter the correct PIN to continue:" << std::endl;
}

int PlayGame (int Difficulty, int Score)
{
    PrintIntroduction(Difficulty);
    int Reward = Difficulty * 10;

    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print the Code Sum and Code Product to the terminal
    std::cout << "The code numbers sum to: " << CodeSum << "." << std::endl;
    std::cout << "The product of the code numbers is: " << CodeProduct << ".\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << GuessSum << std::endl;
    std::cout << GuessProduct << std::endl;

    if( GuessA == CodeA && GuessB == CodeB && GuessC == CodeC)
    {
        std::cout << "Correct! You Stole $" << Reward << "!" << std::endl;
        std::cout << "You have $" << Score + Reward << "." << std::endl;
        return Reward;
    }
    else
    {
        std::cout << "Wrong! The machine ate the card, and the security guards are coming." << std::endl;
        std::cout << "Escape with the $" << Score << " you have!" << std::endl;
        return 0;
    }   
}

int main ()
{
    srand(time(NULL));
    int Score = 10;
    const int MaxDifficulty = 5;
    int DifficultyLevel = 1;
    bool HaveCard = true;

    while(HaveCard)
    {
        int Success = PlayGame(DifficultyLevel, Score);
        if(Success >0)
        {
            Score = Score + Success;
            ++DifficultyLevel;
        }
        else
        {
            HaveCard = false;
        }
        
        std::cin.clear();
        std::cin.ignore();
    }
    
        
    return 0;
}