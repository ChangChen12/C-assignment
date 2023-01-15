#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <memory>
using std::unique_ptr;

using std::vector;
using std::set;
using std::cout;
using std::endl;

// TODO: Your Sudoku class goes here:

class Sudoku : public Searchable{

private:
    vector<vector<set<int>>> board;


public:

    Sudoku(const int &size) {
        for (int i = 0; i < size; ++i) {
            vector<set<int>> temp;
            for (int j = 0; j < size; ++j) {
                set<int> store;
                for (int k = 1; k <= size; ++k) {
                    store.insert(k);
                }
                temp.push_back(store);
            }
            board.push_back(temp);
        }
    }

    Sudoku(const Sudoku &other){
        board= other.board;
    }

    int getSquare(int row, int col) const{
        if (board[row][col].size() == 1) {
            return *board[row][col].begin();
        } else {
            return -1;
        }

    }

    bool setSquare(int Row, int Col, int value) {


        board[Row][Col].clear();
        board[Row][Col].insert(value);

  
        int subBoardSize = sqrt(board.size());
        int end =0;
        int BoardSize;
        bool condition = true;
        vector<vector<set<int>>> tempBoard = board;
        while(condition){
            BoardSize = 0;

            for (int row = 0; row < board.size(); row++) {
                for (int col = 0; col < board.size(); col++) {
                    BoardSize+=board[row][col].size();
                    if (board[row][col].size() == 1) {
                        for (int i = 0; i < board.size(); i++) {
                            if (i!=col) {
                                board[row][i].erase(getSquare(row, col));
                            }
                            if (i!=row) {
                                board[i][col].erase(getSquare(row, col));
                            }
                        }

                            int subBoardRow = row - (row % subBoardSize);
                            int subBoardCol = col - (col % subBoardSize);

                            int subBoardEndRow = subBoardRow + (subBoardSize - 1);
                            int subBoardEndCol = subBoardCol + (subBoardSize - 1);

                                for (int tempRow = subBoardRow; tempRow <= subBoardEndRow; tempRow++) {
                                    for (int tempCol = subBoardCol; tempCol <= subBoardEndCol; tempCol++) {
                                        if (row != tempRow && col != tempCol) {
                                            board[tempRow][tempCol].erase(getSquare(row, col));
                                        }
                                    }
                                }
                    }else if(board[row][col].size()==2){

                        set<int> keep = board[row][col];
                        vector<int> values;
                        for(auto &e: board[row][col]){
                            values.push_back(e);
                        }

                        int subBoardRow = row - (row % subBoardSize);
                        int subBoardCol = col - (col % subBoardSize);

                        int subBoardEndRow = subBoardRow + (subBoardSize - 1);
                        int subBoardEndCol = subBoardCol + (subBoardSize - 1);

                        int rowCheck = 0;
                        int colCheck = 0;
                        int BoardCheck = 0;

                        for(int i=0; i<board.size(); ++i){
                            if(keep==board[row][i]){
                                rowCheck++;
                            }
                            if(keep==board[i][col]){
                                colCheck++;
                            }
                        }

                        for (int tempRow = subBoardRow; tempRow <= subBoardEndRow; tempRow++) {
                            for (int tempCol = subBoardCol; tempCol <= subBoardEndCol; tempCol++) {
                                if (keep==board[tempRow][tempCol]) {
                                    BoardCheck++;
                                }
                            }
                        }

                        for(int i=0; i<board.size(); ++i){
                            if(keep!=board[row][i] && rowCheck==2){
                                board[row][i].erase(values[0]);
                                board[row][i].erase(values[1]);
                            }
                            if(keep!=board[i][col] && colCheck==2){
                                board[i][col].erase(values[0]);
                                board[i][col].erase(values[1]);
                            }
                        }


                        for (int tempRow = subBoardRow; tempRow <= subBoardEndRow; tempRow++) {
                            for (int tempCol = subBoardCol; tempCol <= subBoardEndCol; tempCol++) {
                                if (keep!=board[tempRow][tempCol] && BoardCheck==2) {
                                    board[tempRow][tempCol].erase(values[0]);
                                    board[tempRow][tempCol].erase(values[1]);
                                }
                            }
                        }

                    }
                    else if(board[row][col].size() ==3){
                        set<int> keep = board[row][col];
                        vector<int> values;
                        for(auto &e: board[row][col]){
                            values.push_back(e);
                        }

                        int subBoardRow = row - (row % subBoardSize);
                        int subBoardCol = col - (col % subBoardSize);
						int subBoardEndRow = subBoardRow + (subBoardSize - 1);
                        int subBoardEndCol = subBoardCol + (subBoardSize - 1);
						int rowCheck = 0;
                        int colCheck = 0;
                        int BoardCheck = 0;
						for(int i=0; i<board.size(); i++){
                            if(keep==board[row][i]){
                                rowCheck++;
                            }
                            if(keep==board[i][col]){
                                colCheck++;
                            }
                        }

                        for (int tempRow = subBoardRow; tempRow <= subBoardEndRow; tempRow++) {
                            for (int tempCol = subBoardCol; tempCol <= subBoardEndCol; tempCol++) {
                                if (keep==board[tempRow][tempCol]) {
                                    BoardCheck++;
                                }
                            }
                        }

                        for(int i=0; i<board.size(); ++i){
                            if(keep!=board[row][i] && rowCheck==3){
                                board[row][i].erase(values[0]);
                                board[row][i].erase(values[1]);
                            }
                            if(keep!=board[i][col] && colCheck==3){
                                board[i][col].erase(values[0]);
                                board[i][col].erase(values[1]);
                            }
                        }


                        for (int tempRow = subBoardRow; tempRow <= subBoardEndRow; tempRow++) {
                            for (int tempCol = subBoardCol; tempCol <= subBoardEndCol; tempCol++) {
                                if (keep!=board[tempRow][tempCol] && BoardCheck==3) {
                                    board[tempRow][tempCol].erase(values[0]);
                                    board[tempRow][tempCol].erase(values[1]);
                                }
                            }
                        }
                    }
                    else if (board[row][col].size()==0){
                        board=tempBoard;
                        return 0;
                    }
                }
            }
            if (BoardSize == end){
                condition=false;
            }else{
                end =BoardSize;
            }
        }
		return true;
    }

    bool isSolution() const {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if(getSquare(i,j)==-1){
                    return 0;
                }
            }
        }
        return 1;
    }

    void write(ostream & o) const{
        for (int i = 0; i < board.size();i++) {
            for (int j = 0; j < board.size(); j++) {
                set<int> one = board[i][j];
                for (set<int>::iterator y = one.begin(); y != one.end(); y++) {
                    o << *y;
                }

                o << " ";
            }
            o << "" << endl;
        }
        o << endl;

    }

	

    vector<unique_ptr<Searchable> > successors() const{
        


   }

    int heuristicValue() const {
        int get =0;
        for(int i=0; i<board.size();++i){
            for(int j=0; j<board.size();++j){
              if (getSquare(i,j)==-1){
                  ++get;}
			}
        }
        return get; }

};

#endif