#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "cursor.h"		// gotoxy(), delay() 함수 사용 위한 헤더
#include <assert.h>
#include <iostream>
using namespace std;

// 1. 게임 구성을 위한 클래스

// 게임 전체에 적용 되는 네 개의 주요 상수
const int MaxCard = 48;			// 전체 화투패의 개수
const int CardGap = 4;			// 카드간 간격
const int Speed = 1000;			// 카드 낼때 대기 시간 -> 전체적인 게임 진행을 천천히 보기 위한
const int PromptSpeed = 2000;	// 메시지 출력 대기 시간

// 게임에 등장하는 사물
struct SCard
{
	char Name[4];
	SCard() { Name[0] = 0; }	// 초기화시 쓰레기 값 청소 -> 이름 없는 빈 카드 생성
	SCard(const char* pName) 
	{	// 카드 이름을 받아 초기화
		strcpy(Name, pName);
	}

	int GetNumber() const 
	{		// 화투의 숫자 체크
		if (isdigit(Name[0])) return Name[0] - '0';
		if (Name[0] == 'J') return 10;
		if (Name[0] == 'D') return 11;
		return 12;
	}

	int GetKind() const 
	{		// 화투의 종류 체크
		if (strcmp(Name + 1, "광") == 0) return 0;
		else if (strcmp(Name + 1, "십") == 0) return 1;
		else if (strcmp(Name + 1, "오") == 0) return 2;
		else return 3;
	}

	// 카드 출력을 위한 << 재정의
	friend ostream& operator <<(ostream& c, const SCard& C) 
	{
		return c << C.Name;
	}

	// 두 카드가 같은지 조사를 위한 == 재정의
	bool operator ==(const SCard& Other) const 
	{
		return (strcmp(Name, Other.Name) == 0);
	}

	// 두 카드의 대소를 비교하는 < 재정의
	bool operator <(const SCard& Other) const 
	{
		if (GetNumber() < Other.GetNumber()) return true;
		if (GetNumber() < Other.GetNumber()) return false;
		if (GetKind() < Other.GetKind()) return true;
		return false;
	}
};

// 화투의 초기 카드 목록
SCard HwaToo[MaxCard] = {
	"1광","1오","1피","1피","2십","2오","2피","2피","3광","3오","3피","3피",
	"4십","4오","4피","4피","5십","5오","5피","5피","6십","6오","6피","6피",
	"7십","7오","7피","7피","8광","8십","8피","8피","9십","9오","9피","9피",
	"J십","J오","J피","J피","D광","D쌍","D피","D피","B광","B십","B오","B쌍"
};

// 카드의 집합을 관리하는 클래스
class CCardSet
{
protected:
	SCard Card[MaxCard];
	int Num;				// 집합에 포함된 카드의 현재 개수
	const int sx, sy;		// 카드 집합의 화면상 좌표
	CCardSet(int asx, int asy) : sx(asx), sy(asy) { Num = 0; }

public:
	int GetNum() { return Num; }

	SCard GetCard(int idx) { return Card[idx]; }

	void Reset() 
	{
		for (int i = 0; i < MaxCard; i++)
		{
			Card[i].Name[0] = 0;
		}
		Num = 0;
	}

	// 카드 집합을 관리하는 함수
	void InsertCard(SCard C);
	SCard RemoveCard(int idx);
	int FindSameCard(SCard C, int* pSame);
	int FindFirstCard(const char* pName);
};

// 빈 카드 삽입 거부 및 유효 카드의 정렬된 위치 삽입
void CCardSet::InsertCard(SCard C)
{
	int i;

	if (C.Name[0] == 0) return;

	for (i = 0; i < Num; i++)
	{
		if (C < Card[i]) break;
	}

	memmove(&Card[i + 1], &Card[i], sizeof(SCard) * (Num - i));
	Card[i] = C;
	Num++;
}

// 해당 인덱스의 카드 제거 및 리턴
SCard CCardSet::RemoveCard(int idx)
{
	assert(idx < Num);
	SCard C = Card[idx];
	memmove(&Card[idx], &Card[idx + 1], sizeof(SCard) * (Num - idx - 1));
	Num--;
	return C;
}

// C카드와 일치하는 카드 탐색
int CCardSet::FindSameCard(SCard C, int* pSame)
{
	int i, num;
	int* p = pSame;

	for (i = 0, num = 0; i < Num; i++)
	{
		if (Card[i].GetNumber() == C.GetNumber())
		{
			num++;
			*p++ = i;
		}
	}
	*p = -1;
	return num;
}

// 숫자나 종류가 일치하는 최초의 카드 탐색 및 인덱스 리턴
int CCardSet::FindFirstCard(const char* pName)
{
	int i;

	for (i = 0; i < Num; i++)
	{
		if (strstr(Card[i].Name, pName) != NULL)
		{
			return i;
		}
	}

	return -1;
}

// 데크 in 중앙 담요
class CDeck : public CCardSet
{
public:
	CDeck(int asx, int asy) : CCardSet(asx, asy) { ; }

	// 무작위 섞기
	void Shuffle()
	{
		int i, n;

		for (i = 0; i < MaxCard; i++)
		{
			do
			{
				n = random(MaxCard);
			} while (Card[n].Name[0] != NULL);
			Card[n] = HwaToo[i];
			Num++;
		}
	}

	SCard Pop() { return RemoveCard(Num - 1); }
	bool IsEmpty() { return Num == 0; }
	bool IsNotLast() { return Num > 1; }

	// 화면에 데크 그리기
	void Draw(bool bFlip)
	{
		gotoxy(sx, sy);
		cout << "???" << (bFlip ? Card[Num - 1].Name : " ");
	}
};

// 게임을 진행하는 플레이어
class CPlayer : public CCardSet
{
public:
	CPlayer(int asx, int asy) : CCardSet(asx, asy) { ; }

	void Draw(bool MyTurn)
	{
		int i, x;

		for (i = 0, x= sx; i < Num; i++, x += CardGap)
		{
			gotoxy(x, sy);
			cout << Card[i];
			if (MyTurn)
			{
				gotoxy(x, sy + 1);
				cout << '[' << i + 1 << ']';
			}
		}
	}
};

// 중앙 담요
class CBlanket : public CPlayer
{
public:
	CBlanket(int asx, int asy) : CPlayer(asx, asy) { ; }

	void Draw()
	{
		CPlayer::Draw(false);
	}

	void DrawSelNum(int* pSame)
	{
		int n;
		int* p;
		for (n = 1, p = pSame; *p != -1; p++, n++)
		{
			gotoxy(sx + *p * CardGap, sy - 1);
			cout << '[' << n << ']';
		}
	}

	void DrawTempCard(int idx, SCard C)
	{
		gotoxy(sx + idx * CardGap, sy + 1);
		cout << C;
	}
};

// 플레이어가 가지고 있는 카드의 집합
class CPlayerPae : public CCardSet
{
private:
	int nGo;

public:
	int OldScore;
	CPlayerPae(int asx, int asy) : CCardSet(asx, asy) { OldScore = 6; nGo = 0; }
	void Reset() { CCardSet::Reset(); OldScore = 6; nGo = 0; }
	int GetGo() { return nGo; }
	void IncreaseGo() { nGo++; }
	void Draw();
	SCard RemovePee();
	int CalcScore();
};

// 가지고 있는 패를 화면에 종류별로 출력
void CPlayerPae::Draw() 
{
	int i, kind;
	int x[4] = { sx,sx,sx,sx }, py = sy + 3;

	for (i = 0; i < Num; i++) 
	{
		kind = Card[i].GetKind();

		if (kind < 3) 
		{
			gotoxy(x[kind], sy + kind);
			x[kind] += CardGap;
		}
		else 
		{
			gotoxy(x[3], py);
			x[3] += CardGap;
			if (x[3] > 75) 
			{
				x[3] = sx;
				py++;
			}
		}

		cout << Card[i];
	}
	gotoxy(sx + 23, sy);
	cout << "점수:" << CalcScore() << "점, " << nGo << "고";
}

// 상대방이 세 장을 한꺼번에 먹거나 싹쓸이했을 경우
// 피 한 장을 제거하여 상대방에게 상납
SCard CPlayerPae::RemovePee() 
{
	int idx;

	idx = FindFirstCard("피");
	if (idx != -1) {
		return RemoveCard(idx);
	}
	return SCard();	// 리턴된 카드는 상대방의 먹은 패에 들어간다
}

// 고스톱 규칙대로 점수 계산
int CPlayerPae::CalcScore() 
{
	int i, kind, n[4] = { 0, };
	int NewScore;
	static int gscore[] = { 0,0,0,3,4,15 };

	for (i = 0; i < Num; i++) 
	{
		kind = Card[i].GetKind();
		n[kind]++;
	}
	NewScore = gscore[n[0]];
	if (n[0] == 3 && FindFirstCard("B광") != -1) NewScore--;
	if (n[1] >= 5) NewScore += (n[1] - 4);
	if (n[2] >= 5) NewScore += (n[2] - 4);
	if (n[3] >= 10) NewScore += (n[3] - 9);
	if (FindFirstCard("8십") != -1 && FindFirstCard("5십") != -1 && FindFirstCard("2십") != -1) NewScore += 5;
	if (FindFirstCard("1오") != -1 && FindFirstCard("2오") != -1 && FindFirstCard("3오") != -1) NewScore += 3;
	if (FindFirstCard("4오") != -1 && FindFirstCard("5오") != -1 && FindFirstCard("7오") != -1) NewScore += 3;
	if (FindFirstCard("9오") != -1 && FindFirstCard("J오") != -1 && FindFirstCard("6오") != -1) NewScore += 3;
	return NewScore;
}

// 2. 게임 운영
// 게임의 전반적인 운영에 사용되는 전역 변수
CDeck Deck(18, 9);
CPlayer South(5, 20), North(5, 1);
CBlanket Blanket(5, 12);
CPlayerPae SouthPae(40, 14), NorthPae(40, 4);
bool SouthTurn;

// main의 게임 운영을 도와주는 도우미 함수
void Initialize();
void DrawScreen();
void OutPrompt(const char* Mes, int Wait = 0);
int InputInt(const char* Mes, int start, int end);

// 데크의 패를 무작위로 섞어 카드를 초기화하는 함수
void Initialize()
{
	int i;

	Deck.Shuffle();
	for (i = 0; i < 10; i++) 
	{
		South.InsertCard(Deck.Pop());
		North.InsertCard(Deck.Pop());
		if (i < 8) Blanket.InsertCard(Deck.Pop());
	}
}

// 화면을 지우고 모든 객체의 Draw 함수를 차례대로 호출하여 그리는 함수
void DrawScreen()
{
	clrscr();
	South.Draw(SouthTurn);
	North.Draw(!SouthTurn);
	Blanket.Draw();
	Deck.Draw(false);
	SouthPae.Draw();
	NorthPae.Draw();
}

// 사용자에게 메세지를 보여주고 잠시 대기
// 현재 상태 및 다음 행동 지시
void OutPrompt(const char* Mes, int Wait/*=0*/)
{
	gotoxy(5, 23);
	for (int i = 5; i < 79; i++) { cout << ' '; }
	gotoxy(5, 23);
	cout << Mes;
	delay(Wait);
}

// 지정된 범위안 숫자 하나를 받는 함수
int InputInt(const char* Mes, int start, int end)
{
	int ch;

	OutPrompt(Mes);
	for (;;) {
		ch = tolower(getch());
		if (ch == 0xE0 || ch == 0) 
		{
			ch = getch();
			continue;
		}
		if (!(isdigit(ch) || ch == 'a')) continue;
		if (ch == 'a') ch = 10; else ch = ch - '0';
		if (ch >= start && ch <= end) 
		{
			return ch;
		}
		OutPrompt("무효한 번호입니다. 지정한 범위에 맞게 다시 입력해 주세요.");
	}
}

// 본격적인 게임을 진행하는 main()
int main()
{
	int i, ch;
	int arSame[4], SameNum;
	char Mes[256];
	CPlayer* Turn;
	CPlayerPae* TurnPae, * OtherPae;
	int UserIdx, UserSel, DeckSel;
	SCard UserCard, DeckCard;
	bool UserTriple, DeckTriple;
	int nSnatch;
	int NewScore;

	randomize();	// 난수 발생
	Initialize();	// 카드 섞은 후 초기화

	// 게임 시작
	for (SouthTurn = true; !Deck.IsEmpty(); SouthTurn = !SouthTurn) 
	{
		DrawScreen();
		if (SouthTurn) 
		{
			Turn = &South;
			TurnPae = &SouthPae;
			OtherPae = &NorthPae;
		}
		else 
		{
			Turn = &North;
			TurnPae = &NorthPae;
			OtherPae = &SouthPae;
		}

		sprintf(Mes, "내고 싶은 화투를 선택하세요(1~%d,0:종료) ", Turn->GetNum());
		ch = InputInt(Mes, 0, Turn->GetNum());
		if (ch == 0) 
		{
			if (InputInt("정말 끝낼겁니까?(0:예,1:아니오)", 0, 1) == 0)
				return;
			else
				continue;
		}

		// 플레이어가 카드 한 장 냄
		UserTriple = DeckTriple = false;	// 초기상태
		UserIdx = ch - 1;
		UserCard

	return 0;
}