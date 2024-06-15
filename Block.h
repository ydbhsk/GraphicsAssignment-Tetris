//
// Created by dell on 2024/6/14.
//

#ifndef PROJECT_BLOCK_H
#define PROJECT_BLOCK_H

#include <cstdio>
#include <graphics.h>

#define BLOCK_SIZE 4
#define TYPE_NUM 7
#define DIR_NUM 4
#define GRID_WIDTH 12
#define GRID_HEIGHT 24
#define LOAD_HEIGHT 4
#define SLIDER_PX 30 // 滑块的宽度: 30px

enum BlockType
{
    BLOCK_EMPTY = 0,
    BLOCK_SQUARE = 1,
    BLOCK_LINE = 2,
    BLOCK_T = 3,
    BLOCK_L = 4,
    BLOCK_J = 5,
    BLOCK_S = 6,
    BLOCK_Z = 7
};

typedef struct PointStruct{
    int row;
    int col;
    PointStruct(int r, int c) : row(r), col(c){}
    PointStruct& operator=(const PointStruct &point){
        row = point.row;
        col = point.col;
        return *this;
    }
}Point;

typedef struct BlockStruct{
    BlockType type;
    int dir;
    Point blockStart;
    BlockStruct(BlockType t, int d, Point p) : type(t), dir(d), blockStart(p) {}
    BlockStruct& operator=(const BlockStruct &block){
        type = block.type;
        dir = block.dir;
        blockStart = block.blockStart;
        return *this;
    }
}Block;

const Point PointStart(0, 4);
const int BlockData[TYPE_NUM+1][DIR_NUM][BLOCK_SIZE][BLOCK_SIZE]
{
    {// BLOCK_EMPTY
        {// DIR_0
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },{// BLOCK_SQUARE
        {// DIR_0
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        }
    },{// BLOCK_LINE
        {// DIR_0
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {2, 2, 2, 2},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0},
            {0, 0, 2, 0}
        }
    },{// BLOCK_T
        {// DIR_0
            {0, 0, 0, 0},
            {0, 3, 0, 0},
            {3, 3, 3, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 3, 0, 0},
            {0, 3, 3, 0},
            {0, 3, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {3, 3, 3, 0},
            {0, 3, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 3, 0},
            {0, 3, 3, 0},
            {0, 0, 3, 0},
            {0, 0, 0, 0}
        }
    },{// BLOCK_L
        {// DIR_0
            {0, 0, 0, 0},
            {0, 4, 4, 4},
            {0, 4, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 4, 0},
            {0, 0, 4, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {0, 0, 4, 0},
            {4, 4, 4, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 4, 0, 0},
            {0, 4, 0, 0},
            {0, 4, 4, 0},
            {0, 0, 0, 0}
        }
    },{// BLOCK_J
        {// DIR_0
            {0, 0, 0, 0},
            {5, 5, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 5, 0},
            {0, 0, 5, 0},
            {0, 5, 5, 0},
            {0, 0, 0, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {0, 5, 0, 0},
            {0, 5, 5, 5},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 0, 0},
            {0, 5, 5, 0},
            {0, 5, 0, 0},
            {0, 5, 0, 0}
        }
    },{// BLOCK_S
        {// DIR_0
            {0, 0, 0, 0},
            {0, 0, 6, 6},
            {0, 6, 6, 0},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 0, 0},
            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {0, 6, 6, 0},
            {6, 6, 0, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 0}
        }
    },{// BLOCK_Z
        {// DIR_0
            {0, 0, 0, 0},
            {0, 7, 7, 0},
            {0, 0, 7, 7},
            {0, 0, 0, 0}
        },{// DIR_1
            {0, 0, 0, 0},
            {0, 0, 7, 0},
            {0, 7, 7, 0},
            {0, 7, 0, 0}
        },{// DIR_2
            {0, 0, 0, 0},
            {7, 7, 0, 0},
            {0, 7, 7, 0},
            {0, 0, 0, 0}
        },{// DIR_3
            {0, 0, 7, 0},
            {0, 7, 7, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0}
        }
    }
};
const Point BlockCover[TYPE_NUM+1][DIR_NUM][BLOCK_SIZE]
{
    {
        {
            Point(0,0), Point(0,0), Point(0,0), Point(0,0)
        },{
             Point(0,0), Point(0,0), Point(0,0), Point(0,0)
        },{
             Point(0,0), Point(0,0), Point(0,0), Point(0,0)
        },{
             Point(0,0), Point(0,0), Point(0,0), Point(0,0)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(2,1), Point(2,2)
        },{
             Point(1,1), Point(1,2), Point(2,1), Point(2,2)
        },{
             Point(1,1), Point(1,2), Point(2,1), Point(2,2)
        },{
             Point(1,1), Point(1,2), Point(2,1), Point(2,2)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(1,0)
        },{
             Point(0,2), Point(1,2), Point(2,2), Point(3,2)
        },{
             Point(1,1), Point(1,2), Point(1,3), Point(1,0)
        },{
             Point(0,2), Point(1,2), Point(2,2), Point(3,2)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,2)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(3,1)
        },{
             Point(1,1), Point(1,2), Point(1,3), Point(2,2)
        },{
             Point(1,2), Point(2,1), Point(2,2), Point(2,3)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,1)
        },{
             Point(1,1), Point(2,1), Point(3,1), Point(3,2)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(2,3)
        },{
             Point(1,3), Point(2,1), Point(2,2), Point(2,3)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,3)
        },{
             Point(1,2), Point(2,2), Point(3,1), Point(3,2)
        },{
             Point(1,1), Point(1,2), Point(1,3), Point(2,1)
        },{
             Point(1,1), Point(2,1), Point(3,1), Point(3,2)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,1)
        },{
             Point(1,2), Point(2,1), Point(2,2), Point(3,2)
        },{
             Point(1,2), Point(1,3), Point(2,1), Point(2,2)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(3,1)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,2)
        },{
             Point(1,2), Point(2,1), Point(2,2), Point(3,1)
        },{
             Point(1,1), Point(1,2), Point(1,3), Point(2,2)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(3,1)
        }
    }
};

BlockType Grid[GRID_HEIGHT][GRID_WIDTH];

void InitGrid()
{
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            Grid[row][col] = BLOCK_EMPTY;
        }
    }
}

Block GenNextBlock()
{
    BlockType NextBlockType = BlockType(rand() % TYPE_NUM + 1);
    int dir = rand() % DIR_NUM;
    return Block(NextBlockType, dir, PointStart);
}

void MySetFillColor(BlockType type)
{
    switch (type) {
        case BLOCK_SQUARE:
            setfillcolor(RGB(255, 255, 0));
            break;
        case BLOCK_LINE:
            setfillcolor(RGB(0, 255, 255));
            break;
        case BLOCK_T:
            setfillcolor(RGB(255, 0, 255));
            break;
        case BLOCK_L:
            setfillcolor(RGB(255, 165, 0));
            break;
        case BLOCK_J:
            setfillcolor(RGB(0, 0, 255));
            break;
        case BLOCK_S:
            setfillcolor(RGB(0, 255, 0));
            break;
        case BLOCK_Z:
            setfillcolor(RGB(255, 0, 0));
            break;
        default:
            setfillcolor(RGB(0, 0, 0));
            break;
    }
}

void DrawGrid()
{
    setlinecolor(RGB(255, 255, 255));
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++) {
            MySetFillColor(Grid[row][col]);
            fillrectangle(col * SLIDER_PX, (row - LOAD_HEIGHT) * SLIDER_PX, (col + 1) * SLIDER_PX,
                          (row + 1 - LOAD_HEIGHT) * SLIDER_PX);
        }
    }
}

void DrawBlock(Block block)
{
    setlinecolor(RGB(255, 255, 255));
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        MySetFillColor(block.type);
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        fillrectangle(col * SLIDER_PX, (row - LOAD_HEIGHT) * SLIDER_PX, (col + 1) * SLIDER_PX,
                      (row + 1 - LOAD_HEIGHT) * SLIDER_PX);
    }
}

void CaptureBlock(Block block)
{
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        Grid[row][col] = block.type;
    }
}

#endif //PROJECT_BLOCK_H
