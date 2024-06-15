#include <ctime>
#include "Block.h"
#include "Move.h"

#define RUNNING     1
#define MOVE_DELAY   800 // Block下落延迟
#define INPUT_DELAY  100 // 输入延迟

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
            if(TryMove(curBlock, MOVE_DOWN)){
                Move(curBlock,MOVE_DOWN);
            }
            else{
                CaptureBlock(curBlock);
                curBlock = GenNextBlock();
            }
        }else if(GetAsyncKeyState(VK_LEFT)){
            if(TryMove(curBlock, MOVE_LEFT)){
                Move(curBlock,MOVE_LEFT);
            }
        }else if(GetAsyncKeyState(VK_RIGHT)){
            if(TryMove(curBlock, MOVE_RIGHT)){
                Move(curBlock,MOVE_RIGHT);
            }
        }else if(GetAsyncKeyState(VK_SPACE)){
            TryTurnAndTurn(curBlock);
        }else if(GetAsyncKeyState(VK_ESCAPE)){
            break;
        }
        if(waitTime >= MOVE_DELAY){
            waitTime = 0;
            if(TryMove(curBlock, MOVE_DOWN)){
                Move(curBlock,MOVE_DOWN);
            }
            else{
                CaptureBlock(curBlock);
                curBlock = GenNextBlock();
            }
        }
        DrawGrid();
        DrawBlock(curBlock);
        FlushBatchDraw();
        Sleep(INPUT_DELAY);
        waitTime += INPUT_DELAY;
    }
    EndBatchDraw();
    closegraph();
    return 0;
}