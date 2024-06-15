#ifndef PROJECT_BLOCK_H
#define PROJECT_BLOCK_H

#include <cstdio>
#include <graphics.h>

#define BLOCK_SIZE 4    /** 方块大小 */
#define TYPE_NUM 7      /** 方块种类 */
#define DIR_NUM 4       /** 方块方向 */
#define GRID_WIDTH 12   /** 网格宽度 */
#define GRID_HEIGHT 24  /** 网格高度 */
#define LOAD_HEIGHT 4   /** 预留高度 */
#define SLIDER_PX 30    /** 滑块的宽度 */

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
}; /** 方块类型 */
typedef struct PointStruct{
    int row;
    int col;
    PointStruct(int r, int c) : row(r), col(c){}
    PointStruct& operator=(const PointStruct &point){
        row = point.row;
        col = point.col;
        return *this;
    }
}Point; /** 坐标点 */
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
}Block; /** 方块 */

const Point PointStart(0, 4); /** 方块起始位置 */
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
             Point(1,2), Point(2,2), Point(2,1), Point(3,2)
        },{
             Point(2,1), Point(1,2), Point(2,3), Point(2,2)
        },{
             Point(0,1), Point(1,1), Point(1,2), Point(2,1)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,1)
        },{
             Point(1,1), Point(1,2), Point(2,2), Point(3,2)
        },{
             Point(1,2), Point(2,2), Point(2,1), Point(2,0)
        },{
             Point(0,1), Point(1,1), Point(2,1), Point(2,2)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(1,3), Point(2,3)
        },{
             Point(1,2), Point(2,2), Point(3,2), Point(3,1)
        },{
             Point(1,1), Point(2,2), Point(2,3), Point(2,1)
        },{
             Point(1,1), Point(1,2), Point(2,1), Point(3,1)
        }
    },{
        {
             Point(1,2), Point(1,3), Point(2,2), Point(2,1)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(3,2)
        },{
             Point(1,2), Point(1,3), Point(2,2), Point(2,1)
        },{
             Point(1,1), Point(2,1), Point(2,2), Point(3,2)
        }
    },{
        {
             Point(1,1), Point(1,2), Point(2,3), Point(2,2)
        },{
             Point(1,2), Point(2,1), Point(2,2), Point(3,1)
        },{
             Point(1,1), Point(1,2), Point(2,3), Point(2,2)
        },{
             Point(1,2), Point(2,1), Point(2,2), Point(3,1)
        }
    }
}; /** 每种方块每个方向的覆盖点 */
BlockType Grid[GRID_HEIGHT][GRID_WIDTH]; /** 网格 */
extern int Score; /** 分数 */

/**
 * 初始化网格
 */
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

/**
 * 生成下一个方块
 * @return 下一个方块
 */
Block GenNextBlock()
{
    BlockType NextBlockType = BlockType(rand() % TYPE_NUM + 1);
    int dir = rand() % DIR_NUM;
    return Block(NextBlockType, dir, PointStart);
}

/**
 * 判断是否到达底部
 * @param block 方块
 * @return 是否到达底部
 */
void MySetFillColor(BlockType type)
{
    switch (type) {
        case BLOCK_SQUARE:
            setfillcolor(RGB(113, 201, 206));
            break;
        case BLOCK_LINE:
            setfillcolor(RGB(203, 241, 245));
            break;
        case BLOCK_T:
            setfillcolor(RGB(166, 227, 233));
            break;
        case BLOCK_L:
            setfillcolor(RGB(227, 253, 253));
            break;
        case BLOCK_J:
            setfillcolor(RGB(185, 215, 234));
            break;
        case BLOCK_S:
            setfillcolor(RGB(171, 237, 216));
            break;
        case BLOCK_Z:
            setfillcolor(RGB(70, 205, 207));
            break;
        default:
            setfillcolor(RGB(61, 132, 168));
            break;
    }
}

/**
 * 绘制网格
 */
void DrawGrid()
{
    setlinecolor(RGB(61, 132, 168));
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++) {
            MySetFillColor(Grid[row][col]);
            fillrectangle(col * SLIDER_PX, (row - LOAD_HEIGHT) * SLIDER_PX, (col + 1) * SLIDER_PX,
                          (row + 1 - LOAD_HEIGHT) * SLIDER_PX);
        }
    }
}

/**
 * 绘制方块
 * @param block 方块
 */
void DrawBlock(Block block)
{
    setlinecolor(RGB(61, 132, 168));
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        MySetFillColor(block.type);
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        fillrectangle(col * SLIDER_PX, (row - LOAD_HEIGHT) * SLIDER_PX, (col + 1) * SLIDER_PX,
                      (row + 1 - LOAD_HEIGHT) * SLIDER_PX);
    }
}

/**
 * 将方块嵌入网格
 * @param block 方块
 * @return 最大行
 */
int CaptureBlock(Block block)
{
    int maxRow = 0;
    for (int i = 0; i < BLOCK_SIZE; i++)
    {
        int row = block.blockStart.row + BlockCover[block.type][block.dir][i].row;
        int col = block.blockStart.col + BlockCover[block.type][block.dir][i].col;
        Grid[row][col] = block.type;
        maxRow = (maxRow>row)?maxRow:row;
    }
    return maxRow;
}

/**
 * 清除所有整行
 * @param row 最大行
 */
void ClearLine(int row)
{
    bool clearFlag,continueFlag;
    for (int i = row; i > 0; i--)
    {
        clearFlag = true;
        continueFlag = false;
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            if(Grid[i][j] == BLOCK_EMPTY)
            {
                clearFlag = false;
                break;
            }
            else{
                continueFlag = true;
            }
        }
        if(clearFlag)
        {
            for(int j = i;j > 0;j--)
            {
                for(int k = 0;k < GRID_WIDTH;k++)
                {
                    Grid[j][k] = Grid[j-1][k];
                }
            }
            Score += 10;
            i++;
        }
        if(!continueFlag)break;
    }
}

/**
 * 绘制信息
 */
void DrawInfo()
{
    settextcolor(RGB(255, 255, 255));
    setfont(20, 0, "Times New Roman");
    // 设置无底色
    setbkmode(TRANSPARENT);
    char str[20];
    sprintf(str, "Score: %d", Score);
    outtextxy(0, 0, str);
}

#endif //PROJECT_BLOCK_H
