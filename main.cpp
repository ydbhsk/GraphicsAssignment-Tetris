#include <ctime>
#include "Block.h"
#include "Move.h"

#define RUNNING     1
#define MOVE_DELAY   500    // Block下落延迟
#define INPUT_DELAY  100    // 输入延迟
#define LEVEL       10      // 难度系数

int Score = 0;

int main() {
    srand(time(NULL));
    Block curBlock(BLOCK_EMPTY, 0, PointStart);
    InitGrid();
    curBlock = GenNextBlock();
    int waitTime = 0;
    initgraph(GRID_WIDTH * SLIDER_PX, (GRID_HEIGHT - LOAD_HEIGHT) * SLIDER_PX);
    BeginBatchDraw();
    while (RUNNING){
        if(GetAsyncKeyState(VK_DOWN)){
            if(TryMove(curBlock, MOVE_DOWN)){}
            else{
                if(GoOver(curBlock)){
                    break;
                }
                int curRow = CaptureBlock(curBlock);
                ClearLine(curRow);
                curBlock = GenNextBlock();
            }
        }else if(GetAsyncKeyState(VK_LEFT)){
            if(TryMove(curBlock, MOVE_LEFT)){}
        }else if(GetAsyncKeyState(VK_RIGHT)){
            if(TryMove(curBlock, MOVE_RIGHT)){}
        }else if(GetAsyncKeyState(VK_UP)){
            if(TryTurn(curBlock)){}
            Sleep(100);
        }else if(GetAsyncKeyState(VK_SPACE)){
            while(TryMove(curBlock, MOVE_DOWN)){}
            Sleep(100);
            if(GoOver(curBlock)){
                break;
            }
            int curRow = CaptureBlock(curBlock);
            ClearLine(curRow);
            curBlock = GenNextBlock();
        }
        else if(GetAsyncKeyState(VK_ESCAPE)){
            break;
        }
        if(waitTime >= MOVE_DELAY - Score * LEVEL){
            waitTime = 0;
            if(TryMove(curBlock, MOVE_DOWN)){}
            else{
                if(GoOver(curBlock)){
                    break;
                }
                int curRow = CaptureBlock(curBlock);
                ClearLine(curRow);
                curBlock = GenNextBlock();
            }
        }
        DrawGrid();
        DrawBlock(curBlock);
        DrawInfo();
        FlushBatchDraw();
        Sleep(INPUT_DELAY);
        waitTime += INPUT_DELAY;
    }
    cleardevice();
    settextcolor(RGB(255, 255, 255));
    int xStart = (GRID_WIDTH * SLIDER_PX - 100)/2;
    int yStart = ((GRID_HEIGHT - LOAD_HEIGHT) * SLIDER_PX - 70)/2;
    outtextxy(xStart, yStart, _T("GAME OVER!"));
    outtextxy(xStart-20, yStart+50, _T("SCORE:"));
    char *score = new char[10];
    _itoa(Score, score, 10);
    outtextxy(xStart+90, yStart+50, score);
    FlushBatchDraw();
    Sleep(2000);
    EndBatchDraw();
    closegraph();
    return 0;
}