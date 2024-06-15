//
// Created by dell on 2024/6/15.
//

#ifndef PROJECT_MOVE_H
#define PROJECT_MOVE_H

#include "Block.h"

enum MoveType{
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

bool TryMove(Block block, MoveType mtype);
bool CheckValid(int row, int col, MoveType mtype);
void Move(Block &block, MoveType mtype);

/**
 * 尝试移动方块
 * @param block 方块
 * @param row 方块起始行
 * @param col 方块起始列
 * @return 是否移动成功
 * 判断是否存在冲突、是否越界
 */
bool TryMove(Block block, MoveType mtype){
    for(int i = 0;i < BLOCK_SIZE;i++){
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        if (!CheckValid(row,col,mtype))return false;
    }
    return true;
}

bool CheckValid(int row, int col, MoveType mtype){
    switch(mtype){
        case MOVE_DOWN:
            return row >= 0 && row < GRID_HEIGHT - 1
            && col >= 0 && col < GRID_WIDTH && Grid[row + 1][col] == BLOCK_EMPTY;
        case MOVE_LEFT:
            return row >= 0 && row < GRID_HEIGHT
            && col > 0 && col < GRID_WIDTH && Grid[row][col - 1] == BLOCK_EMPTY;
        case MOVE_RIGHT:
            return row >= 0 && row < GRID_HEIGHT
            && col >= 0 && col < GRID_WIDTH - 1 && Grid[row][col + 1] == BLOCK_EMPTY;
    }
}

void Move(Block &block, MoveType mtype){
    switch(mtype){
        case MOVE_DOWN:
            block.blockStart.row++;
            break;
        case MOVE_LEFT:
            block.blockStart.col--;
            break;
        case MOVE_RIGHT:
            block.blockStart.col++;
            break;
    }
}

bool TryTurnAndTurn(Block &block){
    int nextDir = (block.dir + 1) % 4;
    for(int i = 0;i < BLOCK_SIZE;i++){
        int row = block.blockStart.row + BlockCover[block.type][nextDir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][nextDir][i].col;
        if(!CheckValid(row,col,MOVE_DOWN))return false;
    }
    block.dir = nextDir;
    return true;
}

#endif //PROJECT_MOVE_H
