
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;
#pragma once
#define MAX_SIZE 255

typedef struct Head
{

}Head;

typedef struct Info
{
	char* szWord;
	char* szMean;

	struct Info* left;
	struct Info* right;
}Info;

class Contrller
{
public:
	Contrller(void);
	~Contrller(void);
	
	char* m_szWord;
	char* m_szMean;

	Info* NewNode(Info* root, char* word, char* mean);
	Info *InsertNode(Info* root, char* word, char* mean);
	Info* Delete(Info* root, char* word);
	Info *FindSuccessor(Info *root);
	Info *Search(Info *root, char* word);
	void Save(Info *root, FILE* file);
	Info* Load(Info *root, FILE* in);
	char* StrWord(char *word, BOOL flag);
	char *StrMean(char *mean, BOOL flag);
	Info* LoadInsert(Info* root, char** pword, char** pmean, int nCnt);
	void ChangeNode(Info* root, char* word, char* mean);
};

#endif
