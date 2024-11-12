#pragma once
#include <set>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tile.h"

class Board {
private:
    int cols { 0 };
    int rows { 0 };
    int mines { 0 };
    int flags { 0 };
    int remaining { 0 };
    Tile* tiles { nullptr };

    void GenerateMines();
    void AddAdjacencies();

public:
    Board(int cols, int rows, int mines);
    ~Board();
    Tile& operator[](int index);
    int GetFlagCount() const;
    int GetRemainingMines() const;
    void Replace();
    void SetFlagCount(int count);
    void Reduce(int count);
};