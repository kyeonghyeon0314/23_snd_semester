#define GoMsg1 gotoxy(3,26)
#define GoMsg2 gotoxy(3,27)
#define SPEED 20

struct posSnake {
	int x,y;
	int speed;
};


struct BM {
	int mine;   // 지뢰 설치 여부. 0:설치안됨. 1:설치됨. 2:맵이 아님. 
	int flag;   //flag	 0: 안열림 1: 열림 2: 체크됨 
	int num;    // 지뢰가 아닐 경우, 주위 지뢰 갯수. 
};


void PrintString(int x,int y,char * string){
	unsigned int len;
	go to xy(x,y);
	printf("%s",string);
	Sleep(20);
	for (len=0;len<strlen(string);len++)printf("\b");
	for (len=0;len<strlen(string);len++)printf("  ");
}

void ResizeScreen(){
	system("mode con cols=100 lines=30");
	system("color F0");
	//	printf("Test color");
}


void MsgBox(){
	char msg[20]="MessageBox";
	char owner[30]=" Andwill.tistory.com";
	//char map[5][100];
	
	int i,j;
	
	for (i=0;i<100;i+=2)
	{
		for (j=25;j<29;j++)
		{
			gotoxy(i,j);
			if (i==0||i==98||j==25||j==28)
			{
				printf("□");
			}
			
		}
	}
	gotoxy(4,25);
	printf("%s",msg);
	gotoxy(70,25);
	printf("%s",owner);
}

void DrawTitle(){
	int x,y;
	char menu[100]=" Welcome to GameCenter v.1";
	char game1[20]=" 1. Snake";
	char game2[20]=" 2. Search Mine";
	
	for (x=0,y=7;x<30;x++)
	{
		gotoxy(x,y);
		printf("%s",menu);
		Sleep(10);
	}
	for (x=0,y=9;x<40;x++)
	{
		gotoxy(x,y);
		printf("%s",game1);
		Sleep(5);
	}
	for (x=0,y=10;x<40;x++)
	{
		gotoxy(x,y);
		printf("%s",game2);
		Sleep(5);
	}
	
	
	MsgBox();
	GoMsg1;printf("행복한 하루 되세요~");
}

void ClearMsgBox(){
	int i,j;
	
	for (i=2;i<98;i+=2)
	{
		for (j=26;j<28;j++)
		{
			printf("  ");
		}
	}
}


char SnakePlay2(){
	char map[25][30]={
		{"111111111111111111111111111111"},
		{"111100000000000000000000001111"},
		{"111100000000000000000000001111"},
		{"111100000000000000000000001111"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000001100000000000001"},
		{"100000000000001100000000000001"},
		{"100000000000001100000000000001"},
		{"100000000001111111100000000001"},
		{"100000000001111111100000000001"},
		{"100000000000001100000000000001"},
		{"100000000000001100000000000001"},
		{"100000000000001100000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"111100000000000000000000001111"},
		{"111100000000000000000000001111"},
		{"111100000000000000000000001111"},
		{"111111111111111111111111111111"}};
		
		char tmp;
		char key;
		int x,y,z,i,j;
		int dead=0;
		int len=3;
		int score=0;
		int frnum=0;
		int speed;
		int lentmp=3;
		
		static int bestScore;
		
		struct posSnake head,tail;
		struct posSnake curve[1000];
		
		for (i=0;i<100;i++)
		{
			curve[i].x=0;
		}
		CLS;
		for(i=0;i<25;i++){
			for (j=0;j<30;j++)
			{
				gotoxy(j*2,i);
				if (map[i][j]=='1')
				{
					printf("■");
				}
			}
		}
		MsgBox();
		
		for (i=0;i<100;i++)
		{
			curve[i].x=0;
			curve[i].y=0;
		}
		
		head.x=3;	head.y=3;	speed=SPEED;
		tail.x=1;	tail.y=3;
		
		gotoxy(head.x*2,head.y);
		printf("◎");
		gotoxy(tail.x*2,tail.y);
		printf("◇◇");
		key=RIGHT;
		
		curve[0]=tail;
		curve[1].x=2;
		curve[1].y=3;
		curve[2]=head;
		gotoxy(32*2,6); 	printf("◎ <- 머리  ◇ <- 몸  ■ <-벽 ");
		gotoxy(32*2,7); 	printf("머리가 몸이나 벽에 닿지 않게 하면서");
		gotoxy(32*2,8); 	printf("점수를 높히면 됩니다. ");
		gotoxy(32*2,10); 	printf("한칸씩 이동할때 마다 +1 점");
		gotoxy(32*2,11);	printf("♧를 먹으면   +10점");
		gotoxy(32*2,12);	printf("♤를 먹으면  +100점");
		gotoxy(32*2,13);	printf("★를 먹으면 +1000점");
		gotoxy(32*2,15); printf("생성된 과일은 랜덤한 시간이 지나면");
		gotoxy(32*2,16); printf(" ' * ' 로 변하게 됩니다. ");
		gotoxy(32*2,17); printf(" ' * ' 를 먹으면 -300점. ");
		gotoxy(32*2,18); printf("!!!갑자기 ■ 이 생기니 조심!!!");
		gotoxy(32*2,20); printf("최고 기록 : %d ",bestScore);
		
		
		for (;;)
		{
			//FUS;
			if (kbhit())
			{
				tmp=getch();
				FUS;
				switch(tmp){
				case UP:
				case DOWN:
				case RIGHT:
				case LEFT:
					key=tmp;
					break;
				default :
					break;
				}
				
			}
			
			speed--;
			Sleep(10);
			GoMsg1; printf("길이:%3d           스피드:%3d",len, SPEED+(frnum/3));   
			//printf("Head (%2d,%2d)        Tail (%2d,%2d)",head.x,head.y,tail.x,tail.y);
			GoMsg2; printf("점수:%10d ",score);
			//printf("Curve[0] (%2d,%2d)  Curve[1](%2d,%2d)",curve[0].x,curve[0].y,curve[1].x,curve[1].y);
			
			if (speed==0)
			{
				speed=SPEED-(frnum/3);
				switch(key)
				{
				case UP:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(head.x*2,--head.y);
					printf("◎");
					break;
					
				case DOWN:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(head.x*2,++head.y);
					printf("◎");
					break;
					
				case RIGHT:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(++head.x*2,head.y);
					printf("◎");
					break;
					
				case LEFT:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(--head.x*2,head.y);
					printf("◎");
					break;
				}
				score++;
				
				curve[len]=head;
				
				if (map[head.y][head.x]=='1')
				{
					dead=1;
				}
				
				
				
				if (map[head.y][head.x]=='3'){
					score+=10;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='4'){
					score+=100;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='5'){
					score+=1000;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='6'){
					score-=300;
					map[head.y][head.x]='0';
				}
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<20)
				{
					map[y][x]='3';
					gotoxy(x*2,y);
					printf("♧");
				}			
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<5)
				{
					map[y][x]='4';
					gotoxy(x*2,y);
					printf("♤");
				}		
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<3)
				{
					map[y][x]='5';
					gotoxy(x*2,y);
					printf("★");
				}
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<3)
				{
					map[y][x]='1';
					gotoxy(x*2,y);
					printf("■");
				}	
				
				x=baserand(1,29);
				y=baserand(1,24);
				
				for(i=0;i<10;i++){
					if (map[y][x]=='3'||map[y][x]=='4'||map[y][x]=='5')
					{
						gotoxy(x*2,y);
						printf("＊");
						map[y][x]='6';
					}
				}
				
				gotoxy(tail.x*2,tail.y);
				printf("  ");
				map[tail.y][tail.x]='0';
				curve[len]=head;
				
				if(len==lentmp){
					for(i=0;i<len;i++)
					{
						curve[i]=curve[i+1];
					}
				}else{
					lentmp=len;	
				}
				
				tail=curve[0];
				
			}
			
			if (dead==1)
			{
				if(score>bestScore){
					bestScore=score;
				}
				
				for(;key!='n'&&key!='q'&&key!='y';)
				{
					GoMsg1;printf("충돌!!!! 끝!!!!          기록:%d",score);
					GoMsg2;printf("계속 하시겠습니까? (y or n) ?              ");
					key=getch();
				}
				return key;
				break;
			}
		}		
}


char SnakePlay1(){
	char map[25][30]={
		{"111111111111111111111111111111"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"100000000000000000000000000001"},
		{"111111111111111111111111111111"}};
		
		char tmp;
		char key;
		int x,y,z,i,j;
		int dead=0;
		int len=3;
		int score=0;
		int frnum=0;
		int speed;
		int lentmp=3;
		
		static int bestScore;
		
		struct posSnake head,tail;
		struct posSnake curve[1000];
		
		for (i=0;i<100;i++)
		{
			curve[i].x=0;
		}
		CLS;
		for(i=0;i<25;i++){
			for (j=0;j<30;j++)
			{
				gotoxy(j*2,i);
				if (map[i][j]=='1')
				{
					printf("■");
				}
			}
		}
		MsgBox();
		
		for (i=0;i<100;i++)
		{
			curve[i].x=0;
			curve[i].y=0;
		}
		
		head.x=3;	head.y=1;	speed=SPEED;
		tail.x=1;	tail.y=1;
		
		gotoxy(head.x*2,head.y);
		printf("◎");
		gotoxy(tail.x*2,tail.y);
		printf("◇◇");
		key=RIGHT;
		
		curve[0]=tail;
		curve[1].x=2;
		curve[1].y=1;
		curve[2]=head;
		gotoxy(32*2,6); 	printf("◎ <- 머리  ◇ <- 몸  ■ <-벽 ");
		gotoxy(32*2,7); 	printf("머리가 몸이나 벽에 닿지 않게 하면서");
		gotoxy(32*2,8); 	printf("점수를 높히면 됩니다. ");
		gotoxy(32*2,10); 	printf("한칸씩 이동할때 마다 +1 점");
		gotoxy(32*2,11);	printf("♧를 먹으면   +10점");
		gotoxy(32*2,12);	printf("♤를 먹으면  +100점");
		gotoxy(32*2,13);	printf("★를 먹으면 +1000점");
		gotoxy(32*2,15); printf("생성된 과일은 랜덤한 시간이 지나면");
		gotoxy(32*2,16); printf(" ' * ' 로 변하게 됩니다. ");
		gotoxy(32*2,17); printf(" ' * ' 를 먹으면 -300점. ");
		gotoxy(32*2,20); printf("최고 기록 : %d ",bestScore);
		
		
		for (;;)
		{
			//FUS;
			if (kbhit())
			{
				tmp=getch();
				FUS;
				switch(tmp){
				case UP:
				case DOWN:
				case RIGHT:
				case LEFT:
					key=tmp;
					break;
				default :
					break;
				}
				
			}
			
			speed--;
			Sleep(10);
			GoMsg1; printf("길이:%3d           스피드:%3d",len, SPEED+(frnum/5));   
			//printf("Head (%2d,%2d)        Tail (%2d,%2d)",head.x,head.y,tail.x,tail.y);
			GoMsg2; printf("점수:%10d ",score);
			//printf("Curve[0] (%2d,%2d)  Curve[1](%2d,%2d)",curve[0].x,curve[0].y,curve[1].x,curve[1].y);
			
			if (speed==0)
			{
				speed=SPEED-(frnum/5);
				switch(key)
				{
				case UP:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(head.x*2,--head.y);
					printf("◎");
					break;
					
				case DOWN:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(head.x*2,++head.y);
					printf("◎");
					break;
					
				case RIGHT:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(++head.x*2,head.y);
					printf("◎");
					break;
					
				case LEFT:
					gotoxy(head.x*2,head.y);
					printf("◇");
					map[head.y][head.x]='1';
					gotoxy(--head.x*2,head.y);
					printf("◎");
					break;
				}
				score++;
				
				curve[len]=head;
				
				if (map[head.y][head.x]=='1')
				{
					dead=1;
				}
				
				
				
				if (map[head.y][head.x]=='3'){
					score+=10;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='4'){
					score+=100;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='5'){
					score+=1000;
					len++;
					frnum++;
					map[head.y][head.x]='0';
				}
				
				if (map[head.y][head.x]=='6'){
					score-=300;
					map[head.y][head.x]='0';
				}
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<20)
				{
					map[y][x]='3';
					gotoxy(x*2,y);
					printf("♧");
				}			
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<5)
				{
					map[y][x]='4';
					gotoxy(x*2,y);
					printf("♤");
				}		
				
				x=baserand(1,29);
				y=baserand(1,24);
				z=baserand(1,200);
				
				if (map[y][x]=='0' && z<3)
				{
					map[y][x]='5';
					gotoxy(x*2,y);
					printf("★");
				}			
				
				x=baserand(1,29);
				y=baserand(1,24);
				if (map[y][x]=='3'||map[y][x]=='4'||map[y][x]=='5')
				{
					gotoxy(x*2,y);
					printf("＊");
					map[y][x]='6';
				}
				
				gotoxy(tail.x*2,tail.y);
				printf("  ");
				map[tail.y][tail.x]='0';
				curve[len]=head;
				
				if(len==lentmp){
					for(i=0;i<len;i++)
					{
						curve[i]=curve[i+1];
					}
				}else{
					lentmp=len;	
				}
				
				tail=curve[0];
				
			}
			
			if (dead==1)
			{
				if(score>bestScore){
					bestScore=score;
				}
				
				for(;key!='n'&&key!='q'&&key!='y';)
				{
					GoMsg1;printf("충돌!!!! 끝!!!!          기록:%d",score);
					GoMsg2;printf("계속 하시겠습니까? (y or n) ?              ");
					key=getch();
				}
				return key;
				break;
			}
		}		
}


void DisplayMenu(char menu[6][30]){
	int x,y;
	
	for (x=0,y=7;x<35;x++)
	{
		gotoxy(x,y);
		printf("%s",menu[0]);
		Sleep(10);
	}
	for (x=0,y=9;x<40;x++)
	{
		gotoxy(x,y);
		printf("%s",menu[1]);
		Sleep(5);
	}
	for (x=0,y=10;x<40;x++)
	{
		gotoxy(x,y);
		printf("%s",menu[2]);
		Sleep(5);
	}
	for (x=0,y=11;x<40;x++)
	{
		gotoxy(x,y);
		//printf("%s",menu[3]);
		Sleep(5);
	}
	for (x=0,y=12;x<40;x++)
	{
		gotoxy(x,y);
		//printf("%s",menu[4]);
		Sleep(5);
	}
	for (x=0,y=13;x<40;x++)
	{
		gotoxy(x,y);
		printf("%s",menu[5]);
		Sleep(5);
	}
}


void Snake(){
//	int x,y,i,j;
	char key;
	char tmp;
	int set=0;
	char menu[6][30];
	strcpy(menu[0]," @___지_렁_이___@") ;
	strcpy(menu[1]," 1. 중 수 ");
	strcpy(menu[2]," 2. 고 수 ");
	strcpy(menu[3]," 3. 고 수");
	strcpy(menu[4]," 4. 최고기록");
	strcpy(menu[5]," 5. 돌아가기");
	
	// ResizeScreen(); // Resize Console Screen
	// DrawTitle();
	
	CLS;
	MsgBox();
	DisplayMenu(menu);
	
	key='n';
	
	for(;;){
		if (kbhit()||key=='n')
		{
			key=getch();
			if(key==0xE0)key=getch();
			FUS;
		}
		Sleep(50);
		switch(key){
		case '1':
			GoMsg1;
			printf("중 수 를 골랐습니다.                 ");
			key = SnakePlay1();
			if (key=='y')
			{
				MsgBox();
				tmp='1';
				
			}
			break;
		case '2':
			GoMsg1;
			printf("고 수 를 골랐습니다.                 ");
			key = SnakePlay2();
			if (key=='y')
			{
				MsgBox();	
				tmp='2';
			}
			break;
			//case '3':
			//	GoMsg1;
			//	printf("고수를 골랐습니다.                 ");
			//SnakePlay3(key);
			//	break;
			//case '4':
			//	GoMsg1;
			//	printf("최고기록을 골랐습니다.             ");
			//SnakePlay4(key);
			//	break;
		case '5':
			GoMsg1;
			printf("끝내기를 골랐습니다.               ");
			set=1;
			break;
		default:
			GoMsg1;
			printf("알맞은 번호를 눌러주세요.     ");
			
			continue;
		}
		if (set==1) break;
		if (key=='y')
		{
			key=tmp;
		}else{
			CLS;
			MsgBox();
			DisplayMenu(menu);
		}
	}
}


void openZero2(struct BM map[22][22],int posX, int posY)
{
	if (map[posY][posX-1].mine==0 && 
		map[posY][posX-1].num==0 && map[posY][posX-1].flag==0)
	{
		posX--;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero2(map,posX,posY);
		posX++;
	}else if (map[posY][posX-1].mine==0)
	{
		posX--;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posX++;
	}
	
	if (map[posY-1][posX].mine==0 && 
		map[posY-1][posX].num==0 && map[posY-1][posX].flag==0)
	{
		posY--;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero2(map,posX,posY);
		posY++;
	}else if (map[posY-1][posX].mine==0)
	{
		posY--;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posY++;
	}
	
	
	if (map[posY][posX+1].mine==0 && 
		map[posY][posX+1].num==0 && map[posY][posX+1].flag==0)
	{
		posX++;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero2(map,posX,posY);
		posX--;
	}else if (map[posY][posX+1].mine==0)
	{
		posX++;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posX--;
	}
	
	
	if (map[posY+1][posX].mine==0 && 
		map[posY+1][posX].num==0 && map[posY+1][posX].flag==0)
	{
		posY++;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero2(map,posX,posY);
		posY--;
	}else if (map[posY+1][posX].mine==0)
	{
		posY++;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posY--;
	}

	if (map[posY+1][posX+1].mine==0&&map[posY+1][posX+1].num!=0)
	{
		gotoxy((posX+1)*2,posY+1);
		printf("%2d",map[posY+1][posX+1].num);
	}
	
	if (map[posY-1][posX-1].mine==0&&map[posY-1][posX-1].num!=0)
	{
		gotoxy((posX-1)*2,posY-1);
		printf("%2d",map[posY-1][posX-1].num);
	}

	
	if (map[posY+1][posX-1].mine==0&&map[posY+1][posX-1].num!=0)
	{
		gotoxy((posX-1)*2,posY+1);
		printf("%2d",map[posY+1][posX-1].num);
	}

	
	if (map[posY-1][posX+1].mine==0&&map[posY-1][posX+1].num!=0)
	{
		gotoxy((posX+1)*2,posY-1);
		printf("%2d",map[posY-1][posX+1].num);
	}
}



void openZero(struct BM map[12][12],int posX, int posY)
{
	if (map[posY][posX-1].mine==0 && 
		map[posY][posX-1].num==0 && map[posY][posX-1].flag==0)
	{
		posX--;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero(map,posX,posY);
		posX++;
	}else if (map[posY][posX-1].mine==0)
	{
		posX--;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posX++;
	}
	
	if (map[posY-1][posX].mine==0 && 
		map[posY-1][posX].num==0 && map[posY-1][posX].flag==0)
	{
		posY--;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero(map,posX,posY);
		posY++;
	}else if (map[posY-1][posX].mine==0)
	{
		posY--;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posY++;
	}
	
	
	if (map[posY][posX+1].mine==0 && 
		map[posY][posX+1].num==0 && map[posY][posX+1].flag==0)
	{
		posX++;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero(map,posX,posY);
		posX--;
	}else if (map[posY][posX+1].mine==0)
	{
		posX++;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posX--;
	}
	
	
	if (map[posY+1][posX].mine==0 && 
		map[posY+1][posX].num==0 && map[posY+1][posX].flag==0)
	{
		posY++;
		gotoxy(posX*2,posY);
		printf("  ");
		map[posY][posX].flag=1;
		openZero(map,posX,posY);
		posY--;
	}else if (map[posY+1][posX].mine==0)
	{
		posY++;
		gotoxy(posX*2,posY);
		if (map[posY][posX].num==0)
		{
			printf("  ");
		}else{
			printf("%2d",map[posY][posX].num);
		}
		map[posY][posX].flag=1;
		posY--;
	}

	if (map[posY+1][posX+1].mine==0&&map[posY+1][posX+1].num!=0)
	{
		gotoxy((posX+1)*2,posY+1);
		printf("%2d",map[posY+1][posX+1].num);
	}
	
	if (map[posY-1][posX-1].mine==0&&map[posY-1][posX-1].num!=0)
	{
		gotoxy((posX-1)*2,posY-1);
		printf("%2d",map[posY-1][posX-1].num);
	}

	
	if (map[posY+1][posX-1].mine==0&&map[posY+1][posX-1].num!=0)
	{
		gotoxy((posX-1)*2,posY+1);
		printf("%2d",map[posY+1][posX-1].num);
	}

	
	if (map[posY-1][posX+1].mine==0&&map[posY-1][posX+1].num!=0)
	{
		gotoxy((posX+1)*2,posY-1);
		printf("%2d",map[posY-1][posX+1].num);
	}
}


void ShowBomb2(struct BM map[22][22]){
	
	int i,j;
	
	
	for (i=0;i<22;i++)
	{
		for (j=0;j<22;j++)
		{
			gotoxy(i*2+44,j);
			if (map[j][i].mine==1)
			{
				printf("◈");
			}else if (map[j][i].mine==2)
			{
				printf("□");
			}else {
				printf("%2d",map[j][i].num);
			}
		}
		printf("\n");
	}
}

void ShowBomb(struct BM map[12][12]){
	
	int i,j;
	
	
	for (i=0;i<12;i++)
	{
		for (j=0;j<12;j++)
		{
			gotoxy(i*2+25,j);
			if (map[j][i].mine==1)
			{
				printf("◈");
			}else if (map[j][i].mine==2)
			{
				printf("□");
			}else {
				printf("%2d",map[j][i].num);
			}
		}
		printf("\n");
	}
}

char MinePlay2(){
	
	struct BM map[22][22];
	int x,y,i,j,ii,jj;
	int num=0;
	char key;
	int posX,posY;
	char tmp;
	int flag;
	int bombnum;
	int mineNum =50;
	int flagCount=0;
	int xx,yy;
	int setFlag=0;

	//	printf("Operate minePlay1\n");
	
	for (i=0;i<22;i++)     // Init Array
	{
		for (j=0;j<22;j++)
		{
			map[j][i].mine=0;
			map[j][i].num=0;
			map[j][i].flag=0;
		}
	}
	//	printf("Complete initialize\n");
	
	for (i=0;i<mineNum;i++)   // 지뢰 랜덤 생성 
	{
		x=baserand(1,20);
		y=baserand(1,20);
		if (map[y][x].mine==1)
		{
			i--;
			continue;
		}
		map[y][x].mine=1;
	}
	
	
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			printf("%s",(map[j][i].mine==1)?"M":"O");
		}
		printf("\n");
	}
	
	//	printf("Making Mine\n");
	num=0;
	
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			if (map[j][i].mine==0)
			{
				for (ii=-1;ii<2;ii++)
				{
					for (jj=-1;jj<2;jj++)
					{
						if (map[jj+j][ii+i].mine==1)
						{
							num++;
							//printf("(%d,%d)+(%d,%d) num : %d\n",i,j,ii,jj,num);
						}
					}
				}
				map[j][i].num=num;
				num=0;
			}
			
		}
	}
	
	printf("\n");
	//printf("Complete Put nums\n");
	
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			if (map[j][i].mine==1)
			{
				printf("M");
			}else{
				printf("%d",map[j][i].num);
			}
		}
		printf("\n");
	}
	
	
	for (i=0;i<22;i++)     // Init Array
	{
		for (j=0;j<22;j++)
		{
			if (i==0||j==0||i==21||j==21)
			{
				map[j][i].mine=2;
			}
			
		}
	}
	
	printf("\n");
	
	for (i=0;i<22;i++)
	{
		for (j=0;j<22;j++)
		{
			if (map[j][i].mine==1)
			{
				printf("M");
			}else if (map[j][i].mine==2)
			{
				printf("B");
			}else {
				printf("%d",map[j][i].num);
			}
		}
		printf("\n");
	}
	
	CLS;
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			gotoxy(i*2,j);
			printf("■");			
		}
	}
	
	MsgBox();
	num=0;
	gotoxy(32*2,5); printf(" 지 뢰 찾 기 ");
	gotoxy(32*2,7); printf("숨겨진 지뢰를 모두 찾으면 게임 승리!");
	gotoxy(32*2,8); printf("====================================");
	gotoxy(32*2,10);printf("주어진 숫자는 ");
	gotoxy(32*2,11);printf("주위 8개의 블럭에 숨어 있는");
	gotoxy(32*2,12);printf("지뢰의 갯수를 의미 합니다. ");
	gotoxy(32*2,13);printf("====================================");
	gotoxy(32*2,15);printf("예를 들어 ■■■ 라면 8개의 ■중");
	gotoxy(32*2,16);printf("          ■ 2■      2개는 지뢰");
	gotoxy(32*2,17);printf("          ■■■      입니다.   ");
	gotoxy(32*2,19);printf("<사용키>");
	gotoxy(32*2,20);printf("방향키를 사용하여 커서 이동");
	gotoxy(32*2,21);printf("'F'키를 눌러 체크 표시를 합니다.");
	gotoxy(32*2,22);printf("'SpaceBar'를 눌러 블럭을 열어봅니다.");

	//gotoxy(32*2,20);printf("최고 기록 : %d ",bestScore);
	
	for (i=1;i<21;i++)
	{
		for (j=1;j<21;j++)
		{
			if (map[j][i].mine==1)
			{
				num++;
			}
		}
	}
	GoMsg1;printf(" 총 지뢰 갯수 : %d ",num);
	gotoxy(1*2,1);
	posX=posY=1;
	
	for (;;)
	{
		xx=posX;
		yy=posY;
		GoMsg2;printf("  깃발의 갯수 : %2d",flagCount );
		bombnum=0;
		posX=xx;
		posY=yy;
		gotoxy(posX*2,posY);
		if (setFlag==0)
		{
			gotoxy(1*2,1);
			posX=posY=1;
			setFlag=1;
		}
		for (i=1;i<21;i++)
		{
			for (j=1;j<21;j++)
			{
				if (map[j][i].mine==1&&map[j][i].flag==2)
				{
					bombnum++;
				}
			}
		}
		if (num==bombnum && num==flagCount)
		{
			gotoxy(65,5);printf("FINISH!!!!!!!!!!!");
			tmp='k';
			x=3,y=26;
			for (;tmp!='y'&&tmp!='n';)
			{
				Sleep(60);
				if (x!=70&&flag==0)
				{
					gotoxy(x++,y);printf("  Your Are Best !!!!! "); 
				}
				if (x==70)
				{
					flag=1;
				}
				if (x!=3&&flag==1)
				{
					gotoxy(x--,y);printf("  V I C T O R Y !    "); 
				}
				if (x==3)
				{
					flag=0;
				}
				
				GoMsg2;printf("다시 도전 하시겠습니까? (y or n) ");
				if (kbhit())
				{
					tmp=getch();
					FUS;
				}		
			}
			return tmp;
		}
		key=getch();
		if (key==0xE0) key=getch();
		
		switch(key){
		case UP:
			if (posY!=1)
			{
				posY--;
			}
			break;
		case DOWN:
			if (posY!=20)
			{
				posY++;
			}
			break;
		case RIGHT:
			if (posX!=20)
			{
				posX++;
			}
			break;
		case LEFT:
			if (posX!=1)
			{
				posX--;
			}
			break;
		case 'f':
			if (map[posY][posX].flag==0){
				printf("¶");
				map[posY][posX].flag=2;
				flagCount++;
			}else if (map[posY][posX].flag==2){
				printf("■");
				map[posY][posX].flag=0;
				flagCount--;
			}
			break;
			
		case SPACE:
			if (map[posY][posX].flag==2)
			{
				continue;
			}
			if (map[posY][posX].mine==1)
			{
				//printf("%s"," M");
				//printf("THE END");
				//showAll();
				ShowBomb2(map);
				tmp='k';
				x=3,y=26;
				for (;tmp!='y'&&tmp!='n';)
				{
					Sleep(60);
					if (x!=70&&flag==0)
					{
						gotoxy(x++,y);printf("  G A M O V E R  "); 
					}
					if (x==70)
					{
						flag=1;
					}
					if (x!=3&&flag==1)
					{
						gotoxy(x--,y);printf("  G A M O V E R  "); 
					}
					if (x==3)
					{
						flag=0;
					}
					
					GoMsg2;printf("다시 도전 하시겠습니까? (y or n) ");
					if (kbhit())
					{
						tmp=getch();
						FUS;
					}				    
				}
				return tmp;
				break;
			}
			if (map[posY][posX].num>0)
			{
				printf("%2d",map[posY][posX].num);
			}
			
			if (map[posY][posX].num==0)
			{
				printf("  ");
				map[posY][posX].flag=1;
				openZero2(map,posX,posY);
			}
			
			break;
			
		}
		gotoxy(posX*2,posY);
	}
		
	
}





char MinePlay1(){
	
	struct BM map[12][12];
	int x,y,i,j,ii,jj;
	int num=0;
	char key;
	int posX,posY;
	char tmp;
	int flag;
	int bombnum;
	int mineNum =10;
	int flagCount=0;
	int xx,yy;
	int setFlag=0;
	//	printf("Operate minePlay1\n");
	
	for (i=0;i<12;i++)     // Init Array
	{
		for (j=0;j<12;j++)
		{
			map[j][i].mine=0;
			map[j][i].num=0;
			map[j][i].flag=0;
		}
	}
	//	printf("Complete initialize\n");
	
	for (i=0;i<mineNum;i++)   // 지뢰 랜덤 생성 
	{
		x=baserand(1,10);
		y=baserand(1,10);
		if (map[y][x].mine==1)
		{
			i--;
			continue;
		}
		map[y][x].mine=1;
	}
	
	
	for (i=1;i<11;i++)
	{
		for (j=1;j<11;j++)
		{
			printf("%s",(map[j][i].mine==1)?"M":"O");
		}
		printf("\n");
	}
	
	//	printf("Making Mine\n");
	num=0;
	
	for (i=1;i<11;i++)
	{
		for (j=1;j<11;j++)
		{
			if (map[j][i].mine==0)
			{
				for (ii=-1;ii<2;ii++)
				{
					for (jj=-1;jj<2;jj++)
					{
						if (map[jj+j][ii+i].mine==1)
						{
							num++;
							//printf("(%d,%d)+(%d,%d) num : %d\n",i,j,ii,jj,num);
						}
					}
				}
				map[j][i].num=num;
				num=0;
			}
			
		}
	}
	
	printf("\n");
	//printf("Complete Put nums\n");
	
	for (i=1;i<11;i++)
	{
		for (j=1;j<11;j++)
		{
			if (map[j][i].mine==1)
			{
				printf("M");
			}else{
				printf("%d",map[j][i].num);
			}
		}
		printf("\n");
	}
	
	
	for (i=0;i<12;i++)     // Init Array
	{
		for (j=0;j<12;j++)
		{
			if (i==0||j==0||i==11||j==11)
			{
				map[j][i].mine=2;
			}
			
		}
	}
	
	printf("\n");
	
	for (i=0;i<12;i++)
	{
		for (j=0;j<12;j++)
		{
			if (map[j][i].mine==1)
			{
				printf("M");
			}else if (map[j][i].mine==2)
			{
				printf("B");
			}else {
				printf("%d",map[j][i].num);
			}
		}
		printf("\n");
	}
	
	CLS;
	for (i=1;i<11;i++)
	{
		for (j=1;j<11;j++)
		{
			gotoxy(i*2,j);
			printf("■");			
		}
	}
	
	MsgBox();
	num=0;
	gotoxy(32*2,5); printf(" 지 뢰 찾 기 ");
	gotoxy(32*2,7); printf("숨겨진 지뢰를 모두 찾으면 게임 승리!");
	gotoxy(32*2,8); printf("====================================");
	gotoxy(32*2,10);printf("주어진 숫자는 ");
	gotoxy(32*2,11);printf("주위 8개의 블럭에 숨어 있는");
	gotoxy(32*2,12);printf("지뢰의 갯수를 의미 합니다. ");
	gotoxy(32*2,13);printf("====================================");
	gotoxy(32*2,15);printf("예를 들어 ■■■ 라면 8개의 ■중");
	gotoxy(32*2,16);printf("          ■ 2■      2개는 지뢰");
	gotoxy(32*2,17);printf("          ■■■      입니다.   ");
	gotoxy(32*2,19);printf("<사용키>");
	gotoxy(32*2,20);printf("방향키를 사용하여 커서 이동");
	gotoxy(32*2,21);printf("'F'키를 눌러 체크 표시를 합니다.");
	gotoxy(32*2,22);printf("'SpaceBar'를 눌러 블럭을 열어봅니다.");

	//gotoxy(32*2,20);printf("최고 기록 : %d ",bestScore);
	
	for (i=1;i<11;i++)
	{
		for (j=1;j<11;j++)
		{
			if (map[j][i].mine==1)
			{
				num++;
			}
		}
	}
	GoMsg1;printf(" 총 지뢰 갯수 : %2d ",num);
//	GoMsg2;printf("  깃발의 갯수 : %d",flagCount );
// 	gotoxy(1*2,1);
 	posX=posY=1;
 	
	for (;;)
	{
		xx=posX;
		yy=posY;
		GoMsg2;printf("  깃발의 갯수 : %2d",flagCount );
		bombnum=0;
		posX=xx;
		posY=yy;
		gotoxy(posX*2,posY);
		if (setFlag==0)
		{
			gotoxy(1*2,1);
			posX=posY=1;
			setFlag=1;
		}
		for (i=1;i<11;i++)
		{
			for (j=1;j<11;j++)
			{
				if (map[j][i].mine==1&&map[j][i].flag==2)
				{
					bombnum++;
				}
			}
		}
		if (num==bombnum&& num==flagCount)
		{
			gotoxy(65,5);printf("FINISH!!!!!!!!!!");
			tmp='k';
			x=3,y=26;
			for (;tmp!='y'&&tmp!='n';)
			{
				Sleep(60);
				if (x!=70&&flag==0)
				{
					gotoxy(x++,y);printf("  Your Are Best !!!!! "); 
				}
				if (x==70)
				{
					flag=1;
				}
				if (x!=3&&flag==1)
				{
					gotoxy(x--,y);printf("  V I C T O R Y !    "); 
				}
				if (x==3)
				{
					flag=0;
				}
				
				GoMsg2;printf("다시 도전 하시겠습니까? (y or n) ");
				if (kbhit())
				{
					tmp=getch();
					FUS;
				}		
			}
			return tmp;
		}
		key=getch();
		if (key==0xE0) key=getch();
		
		switch(key){
		case UP:
			if (posY!=1)
			{
				posY--;
			}
			break;
		case DOWN:
			if (posY!=10)
			{
				posY++;
			}
			break;
		case RIGHT:
			if (posX!=10)
			{
				posX++;
			}
			break;
		case LEFT:
			if (posX!=1)
			{
				posX--;
			}
			break;
		case 'f':
			if (map[posY][posX].flag==0){
				printf("☆");
				map[posY][posX].flag=2;
				flagCount++;
			}else if (map[posY][posX].flag==2){
				printf("■");
				map[posY][posX].flag=0;
				flagCount--;
			}
			break;
			
		case SPACE:
			if (map[posY][posX].flag==2)
			{
				continue;
			}
			if (map[posY][posX].mine==1)
			{
				//printf("%s"," M");
				//printf("THE END");
				//showAll();
				ShowBomb(map);
				tmp='k';
				x=3,y=26;
				for (;tmp!='y'&&tmp!='n';)
				{
					Sleep(60);
					if (x!=70&&flag==0)
					{
						gotoxy(x++,y);printf("  G A M O V E R  "); 
					}
					if (x==70)
					{
						flag=1;
					}
					if (x!=3&&flag==1)
					{
						gotoxy(x--,y);printf("  G A M O V E R  "); 
					}
					if (x==3)
					{
						flag=0;
					}
					
					GoMsg2;printf("다시 도전 하시겠습니까? (y or n) ");
					if (kbhit())
					{
						tmp=getch();
						FUS;
					}				    
				}
				return tmp;
				break;
			}
			if (map[posY][posX].num>0)
			{
				printf("%2d",map[posY][posX].num);
			}
			
			if (map[posY][posX].num==0)
			{
				printf("  ");
				map[posY][posX].flag=1;
				openZero(map,posX,posY);
			}
			
			break;
			
		}
		gotoxy(posX*2,posY);
	}
}



void Mine(){
	
//	int x,y,i,j;
	char key;
	char tmp;
	int set=0;
	char menu[6][30];
	
	printf("Operate MINE\n");
	CLS;
	MsgBox();
	
	strcpy(menu[0]," @___지뢰_찾기___@") ;
	strcpy(menu[1]," 1. 중 수 ");
	strcpy(menu[2]," 2. 고 수 ");
	strcpy(menu[3]," 3. 고 수");
	strcpy(menu[4]," 4. 최고기록");
	strcpy(menu[5]," 5. 돌아가기");
	
    CLS;
	MsgBox();
	DisplayMenu(menu);
	
	key='n';
	
	for(;;){
		if (kbhit()||key=='n')
		{
			key=getch();
			if(key==0xE0)key=getch();
			FUS;
		}
		Sleep(50);
		switch(key){
		case '1':
			GoMsg1;
			printf("중 수 를 골랐습니다.                 ");
			key = MinePlay1();
			if (key=='y')
			{
				MsgBox();
				tmp='1';
				
			}
			break;
		case '2':
			GoMsg1;
			printf("고 수 를 골랐습니다.                 ");
			key = MinePlay2();
			if (key=='y')
			{
				MsgBox();	
				tmp='2';
			}
			break;
			//case '3':
			//	GoMsg1;
			//	printf("고수를 골랐습니다.                 ");
			//SnakePlay3(key);
			//	break;
			//case '4':
			//	GoMsg1;
			//	printf("최고기록을 골랐습니다.             ");
			//SnakePlay4(key);
			//	break;
		case '5':
			GoMsg1;
			printf("끝내기를 골랐습니다.               ");
			set=1;
			break;
			
		default:
			GoMsg1;
			printf("알맞은 번호를 눌러주세요.     ");
			
			continue;
		}
		if (set==1) {
			CLS;
			MsgBox();
			DrawTitle();
			
			break;
		}
		if (key=='y')
		{
			key=tmp;
		}else{
			CLS;
			MsgBox();
			DisplayMenu(menu);
		}
	}
}

int main(){
	
	
	char sel;
	int menuOn=1;    // 메뉴를 보고 싶으면 1로 // 0은 테스트용  
//	int x,y;
//	int i,j;
	
	ResizeScreen(); // Resize Console Screen
	DrawTitle();
	
	for (;;)
	{
		//"♪"
		//"■" 
		if (menuOn==1)
		{
			
			//gotoxy(39,11);
			//for (i=0;i<30;i++) printf(" ");
			//gotoxy(39,11);
			//printf("> ");
			sel=getch();
			
			switch(sel)
			{
			case '1':
				printf("Call Snake");
				Snake();
				CLS;
				DrawTitle();
				break;
			case '2':
				printf("Call Mine");
				Mine();
				break;
				//case '3':
				//	break;
			default:
				printf("Call Error MsgBox");
				GoMsg1;
				printf("메뉴에 맞게 알맞은 번호를 골라주세요.        ");
				//MsgBox();
				break;
			}
		}else{
			Snake();
		}
		
		
	}
	
	return 0;
}

