#ifndef __SCORE_H__
#define __SCORE_H__

#include <iostream>

class Score {

private:
    static long compteur;
private:
    long ID;
    std::string login;
    long score;
public:

    Score (long le_score) {
        this->score = le_score;
        Score::compteur++;
        this->ID = Score::compteur;
    }

    Score(long le_score, std::string le_login) {
        this->score = le_score;
        Score::compteur++;
        this->ID = Score::compteur;
        this->login = le_login;
    }

    Score(long le_score, std::string le_login, long le_ID) {
        this->score = le_score;
        Score::compteur++;
        this->ID = Score::compteur;
        this->login = le_login;
    }

    long getID() const { return this->ID; }

    std::string getLogin() const { return this->login; }

    long getScore() const { return this->score; }



    Score& operator=(const Score& a) {
        this->score = a.score;
        this->ID = a.ID;
        this->login = a.login;

        return *this;
    }

    // Nécessaire pour faire fonctionner le tas.
    bool operator<(const Score& a) const {
        if (this->score < a.score) return true;
        return false;
    }
};


#endif // __SCORE_H__