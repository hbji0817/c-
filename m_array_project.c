#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종료
//총 실패 횟수 알려주기

int arrayAnimal[4][5]; // 카드 지도 (20장)
char * strAnimal[10];

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);

int main()
{
    srand(time(NULL));

    initAnimalArray();

    initAnimalName();

    shuffleAnimal();



    return 0;
}

void initAniamlArray()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName()
{
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";

    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ
    //ㅁㅁㅁㅁㅁ

    for( int i = 0 ; i < 10; i++)
    {
        for(int j=0;j<2;j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    while(1)
    {
        int randPos = rand() % 20;
        // 19 -> [3][4]
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if(arrayAnimal[x][y] == -1)
        {
            return randPos;
        }

    }
    return 0;
}

int conv_pos_x(int x)
{
    //19 -> [3][4]
    return x / 5;
}
int conv_pos_y(int y)
{
    return y % 5;
}