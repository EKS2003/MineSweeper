#include "board.h"
using namespace std;

Board::Board(int cols, int rows, int mines) {
    this->cols = cols;
    this->rows = rows;
    this->mines = mines;
    remaining = mines;
    tiles = new Tile[rows * cols];
    GenerateMines();
    AddAdjacencies();
}

Board::~Board() {
    delete[] tiles;
}

Tile& Board::operator[](int index) {
    return tiles[index];
}


// helper function
void Board::GenerateMines() {
    set<int> indices;

    // use current time to provide a seed
    srand((unsigned) time(NULL));

    while (indices.size() < mines) {
        int index = rand() % (rows * cols);
        indices.insert(index);
    }

    for (auto i : indices) {
        tiles[i].SetMine();
    }

    for (auto i : indices) {
        // increment value of adjacent tiles
        int x = i % cols;
        int y = (i - x) / cols;

        for (int i = y - 1; i <= y + 1; i++) {
            for (int j = x - 1; j <= x + 1; j++) {
                if ((0 <= j && j < cols) && (0 <= i && i < rows)) {

                    int index = j + (cols * i);

                    if (!tiles[index].IsMine() && index != i) {

                        tiles[index].SetValue(tiles[index].GetValue() + 1);
                    }
                }
            }
        }
    }
}


void Board::AddAdjacencies() {
    for (int i = 0; i < rows * cols; i++) {

        int x = i % cols;
        int y = (i - x) / cols;

        for (int j = y - 1; j <= y + 1; j++) {
            for (int k = x - 1; k <= x + 1; k++) {
                if ((0 <= k && k < cols) && (0 <= j && j < rows)) {

                    int index = k + (cols * j);

                    if (index != i) {
                        tiles[i].AddAdjacent(&tiles[index]);
                    }
                }
            }
        }
    }
}



// accessors
int Board::GetFlagCount() const {
    return flags;
}

int Board::GetRemainingMines() const {
    return remaining;
}


// mutators
void Board::Replace() {
    delete[] tiles;
    tiles = new Tile[rows * cols];
    GenerateMines();
    AddAdjacencies();
    remaining = mines;
    flags = 0;
}

void Board::SetFlagCount(int count) {
    flags = count;
    remaining = mines - flags;
}

void Board::Reduce(int count) {
    remaining -= count;
}
