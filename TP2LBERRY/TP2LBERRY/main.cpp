#include <iostream>
#include <fstream>
#include <climits>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "Score.h"


int main() {

    //std::priority_queue<Score> scores;

    //std::vector<std::string> copieValeurs;

    std::ofstream Asterostorm("hiscore.txt");
    Asterostorm << "100023654" << std::endl;
    Asterostorm << "supergamer97" << std::endl;
    Asterostorm << "6554" << std::endl;
    Asterostorm << "100024082" << std::endl;
    Asterostorm << "olyolyoly" << std::endl;
    Asterostorm << "8422" << std::endl;
    Asterostorm << "1000256613" << std::endl;
    Asterostorm << "snazzy05" << std::endl;
    Asterostorm << "4325" << std::endl;
    Asterostorm << "1000290326" << std::endl;
    Asterostorm << "totolegrand" << std::endl;
    Asterostorm << "4605" << std::endl;

    Asterostorm.close();


    std::ifstream lecteur("hiscore.txt");
    std::vector<std::pair<long, std::string> > copieValeurs;
    long ID;
    std::string login;
    long score;

    while (lecteur.eof() == false) {
        lecteur >> ID;
        lecteur >> login;
        lecteur >> score;

        if (lecteur.eof() == false) {

            std::pair<long, std::string> copieVal(ID, login);

            copieValeurs.push_back(copieVal);
        }
    }

    lecteur.close();


    std::priority_queue<Score> scores;
    for (int i = 0; i < copieValeurs.size(); i++){

        scores.push(score);
    }
    scores.pop();

    // Création du fichier pour le nouveau jeu.

    std::ofstream nouveauJeu("asterostorm.txt");

    for (int i = 0; i < copieValeurs.size(); i++) {
        nouveauJeu << copieValeurs[i].first << std::endl;
        nouveauJeu << copieValeurs[i].second << std::endl;
        nouveauJeu << "Asterostorm=" << score << std::endl;
    }
    nouveauJeu.close();





    // Lecture du nouveau fichier Asterostorm

    for (int i = 0; i < copieValeurs.size(); i++) {
        std::cout << "Le joeur #" << i << " a un ID : ";
        std::cout << copieValeurs[i].first;
        std::cout << " son login est : ";
        std::cout << copieValeurs[i].second << std::endl;
        std::cout << " et son score est = ";
        std::cout << scores.top().getScore() << std::endl;
    }
}