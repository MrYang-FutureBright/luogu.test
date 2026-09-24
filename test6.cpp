#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
 
// 核心修改：尺寸改为51×51（必须为奇数）
#define Height 51
#define Width 51
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
 
// 数组随尺寸同步适配，无需额外修改
int map[Height+2][Width+2];
 
// 移动控制台光标位置
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
// 隐藏控制台光标（避免闪烁）
void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}
 
// 随机生成迷宫（递归算法，适配51×51尺寸）
void create(int x,int y)
{
	// 右、下、左、上 四个方向
	int c[4][2] = {0,1,1,0,0,-1,-1,0};
	int i,j,t;
	// 打乱方向，实现随机路径
	for (i=0;i<4;i++) {
		j=rand()%4;
		t=c[i][0];
		c[i][0]=c[j][0];
		c[j][0]=t;
		t=c[i][1];
		c[i][1]=c[j][1];
		c[j][1]=t;
	}
	map[x][y]=Road;
	// 隔一格挖路（算法核心，保证奇数尺寸迷宫连通）
	for (i=0;i<4;i++)
		if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall) {
			map[x+c[i][0]][y+c[i][1]]=Road;
			create(x+2*c[i][0],y+2*c[i][1]);
		}
}
 
// 接收按键（方向键/ESC，兼容51×51尺寸）
int get_key()
{
	char c;
	while(c=getch()) {
		if(c==27) return Esc;        // ESC键退出
		if(c!=-32)continue;          // 过滤方向键前置字节
		c=getch();
		if(c==72) return Up;         // 上方向键
		if(c==80) return Down;       // 下方向键
		if(c==75) return Left;       // 左方向键
		if(c==77) return Right;      // 右方向键
	}
	return 0;
}
 
// 绘制迷宫单个位置（适配51×51的显示比例）
void paint(int x,int y)
{
	gotoxy(2*y-2,x-1);  // ×2保证迷宫横向方正，51尺寸下显示均衡
	switch(map[x][y]) {
		case Start: printf("入"); break;  // 入口标识
		case End:   printf("出"); break;  // 出口标识
		case Wall:  printf("▇"); break;  // 墙（实心方块）
		case Road:  printf(" "); break;  // 路径（空白）
	}
}
 
// 游戏核心逻辑（适配51×51，提示位置自动居中）
void game() {
	int x=2,y=1;  // 玩家初始位置（入口处，固定无需改）
	int c;        // 按键接收
 
	while(1) {
		gotoxy(2*y-2,x-1);
		printf("A");  // 玩家标识
		// 通关判断：到达出口
		if(map[x][y]==End) {
			// 提示位置在迷宫右侧居中，51尺寸下不会遮挡
			gotoxy(Width*2 + 10, Height/2);
			printf("?? 到达终点，通关成功！按任意键结束 ??");
			getch();
			break;
		}
		// 按键处理
		c=get_key();
		if(c==Esc) {  // ESC退出游戏
			gotoxy(0, Height+5);
			printf("?? 已退出游戏！");
			getch();
			break;
		}
		// 方向移动+撞墙检测（适配51×51）
		switch(c) {
			case Up: if(map[x-1][y]!=Wall) {paint(x,y);x--;} break;
			case Down: if(map[x+1][y]!=Wall) {paint(x,y);x++;} break;
			case Left: if(map[x][y-1]!=Wall) {paint(x,y);y--;} break;
			case Right: if(map[x][y+1]!=Wall) {paint(x,y);y++;} break;
		}
	}
}
 
int main() {
	int i,j;
	// 初始化随机种子，保证每次迷宫不同
	srand((unsigned)time(NULL));
	// 隐藏光标
	hidden();
	// 第一步：初始化迷宫（边界先设路，内部全墙）
	for (i=0;i<=Height+1;i++)
		for (j=0;j<=Width+1;j++)
			if(i==0||i==Height+1||j==0||j==Width+1)
				map[i][j]=Road;
			else
				map[i][j]=Wall;
	// 第二步：随机生成迷宫路径（行列必为偶数，算法要求）
	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1));
	// 第三步：封闭迷宫边界（设为墙，防止玩家出界）
	for (i=0;i<=Height+1;i++) {
		map[i][0]=Wall;
		map[i][Width+1]=Wall;
	}
	for (j=0;j<=Width+1;j++) {
		map[0][j]=Wall;
		map[Height+1][j]=Wall;
	}
	// 第四步：设置固定入口和出口（随51尺寸自动适配）
	map[2][1] = Start;        // 入口：左侧上方
	map[Height-1][Width] = End;  // 出口：右侧下方
	// 第五步：绘制整个51×51迷宫
	for (i=1;i<=Height;i++)
		for (j=1;j<=Width;j++)
			paint(i,j);
	// 启动游戏
	game();
	// 游戏结束，恢复光标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=1;
	SetConsoleCursorInfo(hOut,&cci);
	return 0;
}