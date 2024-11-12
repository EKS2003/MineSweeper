#pragma once
#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

class Tile {
private:
    bool mine { false };
    short value { 0 };
    bool flagged { false };
    bool revealed { false };
    vector<Tile*> adjacent;

public:
    bool IsMine() const;
    short GetValue() const;
    bool IsFlagged() const;
    bool IsRevealed() const;
    vector<Tile*> GetAdjacent() const;
    void SetMine();
    void SetValue(short value);
    bool Flag();
    bool Reveal(int& count);
    void AddAdjacent(Tile* t);
};