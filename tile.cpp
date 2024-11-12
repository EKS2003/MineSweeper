#include "tile.h"
using namespace std;


// Accessors

bool Tile::IsMine() const {
    return mine;
}

short Tile::GetValue() const {
    return value;
}

bool Tile::IsFlagged() const {
    return flagged;
}

bool Tile::IsRevealed() const {
    return revealed;
}

vector<Tile*> Tile::GetAdjacent() const {
    return adjacent;
}


//Mutators
void Tile::SetMine() {
    value = -1;
    mine = true;
}

void Tile::SetValue(short value) {
    this->value = value;
}

bool Tile::Flag() {
    flagged = !flagged;
    return flagged;
}

bool Tile::Reveal(int& count) {

    // base case
    if (mine || flagged || revealed) {
        if (mine) {
            revealed = true;
        }
        return true;
    }

    revealed = true;
    count--;

    // recursive call
    if (value == 0) {
        for (Tile* tile : adjacent) {
            tile->Reveal(count);
        }
    }

    return true;
}

void Tile::AddAdjacent(Tile* t) {
    adjacent.push_back(t);
}