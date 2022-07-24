// MathModel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <random>
#include <iostream>
#include "Player.h"


#include <iostream>

class Player {
public:
    int health = 3;
    int ticket = 5;
    float points = 0.0;
    int atemNum = 15;
    int chanceWin = 50;
    int chanceHeart = 0;
    int MatchNum = 0;//for statistics
    std::string category = "";
    Player() {

    }
    Player(int t, int c, int h) {
        ticket = t;
        chanceWin = c;
        chanceHeart = h;
    }
    /*Считается количество побед без потери жизни - W.

    Рассчитываются очки по формуле : Points = округление от(W * 0.1 + 1.1)*/

    //попытка
    int Try() {
        std::random_device rd;
        int matchNum = 0; //количество побед без потери жизни
       // std::cout << "Start of attempt: \n";
        health = 3;
        for (atemNum > 0; atemNum;) {
            std::mt19937 rng(rd());
            std::uniform_int_distribution<int> uni(0, 99);
            auto win = uni(rng);
            //matchNum++;
            if (health > 0) {
                if (win < chanceWin) {//WON
                    matchNum++;
                    points += round((matchNum * 0.1 + 1.1));                  
                }
                else {//LOST
                    if (matchNum > 5) {
                        std::mt19937 rng(rd());
                        std::uniform_int_distribution<int> uni(0, 99);
                        auto heart = uni(rng);
                        if (heart < chanceHeart) {
                            //heart += 1;
                        }
                        else {
                            matchNum = 0;
                            health--;
                        }
                    }
                    else {
                        matchNum = 0;
                        health--;
                    }
                }
            }
            else {
                /*std::mt19937 rng(rd());
                std::uniform_int_distribution<int> uni(0, 99);
                auto heart = uni(rng);
                if (heart < chanceHeart) {
                    heart = 3;
                }
                else {
                    break;
                }*/
                break;
            }
            atemNum--;
        }
        //std::cout << "Matches: " << 20 - atemNum << "\n";
        //std::cout << "Points: " << points << "\n";
        return points;
    }
    void Match() {
        int p = 0;
        for (ticket > 0; ticket--;) {
            if (atemNum == 0 && health == 3) {
                category += "DOSROK";
                //std::cout << "The END";
                break;
                break;
            }
            atemNum =15;
            p = Try();
        }
        //std::cout << "Points:" << points << "\n";
    }
};
int main()
{
    std::cout << "Tournament starts\n";
    /*for (int x = 1; x < 21; x++) {
        std::cout << round( x * 0.1 + 1.1 )<< " ";
    }*/
    //Parameters
    int playerNum = 50;
    Player* p1 = new Player(5,50,0);
    std::vector <Player*> players;
    //p1->Match();
    //std::cout << "--Riches--\n";
    for (playerNum; playerNum > 40;) {
        p1 = new Player(10, 80,50);
        p1->category = "Rich";
        players.push_back(p1);
        //p1->Match();
        playerNum--;
    }
    //std::cout << "--Normal--\n";
    for (playerNum; playerNum > 30;) {
        p1 = new Player(7, 60, 20);
        p1->category = "Normal";
        players.push_back(p1);
        //p1->Match();
        playerNum--;
    }
   // std::cout << "--Skillovye--\n";
    for (playerNum; playerNum > 20;) {
        p1 = new Player(5, 75, 0);
        p1->category = "Skill";
        players.push_back(p1);
        //p1->Match();
        playerNum--;
    }
    //std::cout << "--Bomzh--\n";
    for (playerNum; playerNum > 0; ) {
        p1 = new Player(5, 50, 0);
        p1->category = "Bomzh";
        players.push_back(p1);
        //p1->Match();
        playerNum--;
    }
    std::cout << "--LEADERBOARD--\n";
    for (int i = 0; i < players.size(); i++) {
        
        players[i]->Match();
        //std::cout << players[i]->category << " " << players[i]->points;
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 49; j++) {
            if (players[j]->points < players[j + 1]->points) {
                Player* b = players[j]; // создали дополнительную переменную
                players[j] = players[j + 1]; // меняем местами
                players[j + 1] = b; // значения элементов
            }
        }
    }
    for (int i = 0; i < players.size(); i++) {
        std::cout << players[i]->category << " " << players[i]->points<<"\n";
        if (i == 9) {
            std::cout << "-------------------------------------------------\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
