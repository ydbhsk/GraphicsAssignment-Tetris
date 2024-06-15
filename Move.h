#ifndef PROJECT_MOVE_H
#define PROJECT_MOVE_H

#include "Block.h"

enum MoveType{
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
}; /** 移动方向 */

bool TryMove(Block &block, MoveType mtype); /** 尝试移动方块 */
bool CheckValid(int row, int col, MoveType mtype); /** 检查是否可以移动 */
bool TryTurn(Block &block); /** 尝试旋转方块 */

/**
 * 尝试移动方块
 * @param block 方块
 * @param row 方块起始行
 * @param col 方块起始列
 * @return 是否移动成功
 * 判断是否存在冲突、是否越界
 */
bool TryMove(Block &block, MoveType mtype){
    for(int i = 0;i < BLOCK_SIZE;i++){
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        if (!CheckValid(row,col,mtype))return false;
    }
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
    return true;
}

/**
 * 检查是否可以移动
 * @param row 行
 * @param col 列
 * @param mtype 移动类型
 * @return 是否可以移动
 */
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

/**
 * 尝试旋转方块
 * @param block 方块
 * @return 是否旋转成功
 */
bool TryTurn(Block &block){
    int nextDir = (block.dir + 1) % 4;
    for(int i = 0;i < BLOCK_SIZE;i++){
        int row = block.blockStart.row + BlockCover[block.type][nextDir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][nextDir][i].col;
        if(!CheckValid(row,col,MOVE_DOWN))return false;
    }
    block.dir = nextDir;
    return true;
}

/**
 * 判断方块是否超出边界
 * @param block 方块
 * @return 是否超出边界
 */
bool GoOver(Block &block){
    for(int i = 0;i < BLOCK_SIZE;i++){
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        if(row <= LOAD_HEIGHT - 1)return true;
    }
    return false;
}

#endif //PROJECT_MOVE_H
