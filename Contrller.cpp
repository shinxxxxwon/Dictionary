#include "stdafx.h"
#include "Contrller.h"
#include <memory>

Contrller::Contrller(void)
{
}


Contrller::~Contrller(void)
{
}

Info* Contrller::NewNode(Info* root, char* word, char* mean)
{
	Info* node = (Info*)malloc(sizeof(Info));	
	char* pword = (char*)malloc(sizeof(char)*strlen(word));
	char* pmean = (char*)malloc(sizeof(char)*strlen(mean));

	memset(pword, NULL, sizeof(pword));
	memset(pmean, NULL, sizeof(pmean));

	strcpy(pword,word);
	strcpy(pmean,mean);

	node->szWord = pword;
	node->szMean = pmean;
	node->left = NULL;
	node->right = NULL;

	//free(pword);
	//free(pmean);

	return node;
}

Info* Contrller::InsertNode(Info* root, char* word, char* mean)
{
	if(root == NULL)
	{
		return NewNode(root, word, mean);
	}
		
	if(strcmp(word ,root->szWord) < 0)
	{
		root->left = InsertNode(root->left, word, mean);
	}
	else if(strcmp(word, root->szWord) > 0)
	{
		root->right = InsertNode(root->right,word,mean);
	}
	else
	{
		printf("이미 등록된 단어\n");
	}
	return root;
}


Info* Contrller::Delete(Info* root, char* word)
{
	if(root == NULL)
	{
		return root;
	}

	if(strcmp(word, root->szWord) < 0)
	{
		root->left = Delete(root->left, word);
	}
	else if(strcmp(word, root->szWord) > 0)
	{
		root->right = Delete(root->right, word);
	}
	else if(strcmp(word, root->szWord) == 0)
	{
		if(root->left == NULL)
		{
			Info *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Info *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			Info *temp = FindSuccessor(root->right);
			root->szWord = temp->szWord;
			root->szMean = root->szMean;
			root->right = Delete(root->right, temp->szWord);
		}
	}
	else
	{
		printf("검색한 단어가 없습니다.\n");
	}
	return root;
}

Info* Contrller::FindSuccessor(Info *root)
{
	Info *temp = root;

	while(temp != NULL && temp->left != NULL)
	{
		temp = root->left;
	}
	return temp;
}

Info* Contrller::Search(Info *root, char* word)
{
	if(root == NULL)
	{
		return root;
	}
	if(strcmp(word, root->szWord) < 0)
	{
		root->left = Search(root->left, word);
	}
	else if(strcmp(word, root->szWord) > 0)
	{
		root->right = Search(root->right, word);
	}
	else
		return root;
}

void Contrller::Save(Info *root, FILE* file)
{
	if(root != NULL)
	{
		Save(root->left, file);
		fprintf(file,"%s\t%s\n",root->szWord,root->szMean);
		Save(root->right, file);
	}
}

Info* Contrller::Load(Info *root, FILE* in)
{
	if(in != NULL)
	{
	
		int dcount=-1;
		int lcnt=-1;

		char **szWord = (char**)malloc(sizeof(char*)*100000);
		char **szMean = (char**)malloc(sizeof(char*)*100000);


		while(!feof(in))
		{
			dcount++;
			lcnt++;
			char pWord[100];
			char pMean[100];
			fscanf(in,"%s\t%s\n",pWord, pMean);
			//szWord[dcount] = StrWord(pWord, TRUE);
			//szMean[dcount] = StrMean(pMean, TRUE);
			szWord[dcount] = StrWord(pWord, TRUE);
			szMean[dcount] = StrMean(pMean, TRUE);
			//root = InsertNode(root, szWord[dcount], szMean[dcount]);
		}
		root = LoadInsert(root, szWord, szMean, lcnt);

		for(int n = 0; n < dcount; n++)
		{
			free(szWord[n]);
			free(szMean[n]);
		}

		free(szWord);
		free(szMean);
	}
	return root;
}

char* Contrller::StrWord(char *word, BOOL flag)   
{
	char *pword;
	pword=(char *)malloc(sizeof(char) * strlen(word) + 1);
	if(pword != NULL)
		strcpy(pword,word);
	/*if(!flag)
	{
		free(pword);
		return "END_LOAD";
	}*/
	return pword;         
}

char* Contrller::StrMean(char *mean, BOOL flag)   
{
	char *pmean;
	pmean=(char *)malloc(sizeof(char) * strlen(mean) + 1);
	if(pmean != NULL)
		strcpy(pmean,mean);  
	/*if(!flag)
	{
		free(pmean);
		return "END_LOAD";
	}*/
	return pmean;         
}

Info* Contrller::LoadInsert(Info* root, char** pword, char** pmean, int nCnt)
{
	int nowMid = 0;

	if(nCnt%2 == 0)
	{
		nowMid = nCnt/2;
	}
	else
	{
		nowMid = (nCnt/2)+1;
	}

	if(nCnt >= 0)
	{
		root = InsertNode(root, pword[nowMid], pmean[nowMid]);
	}
	else if(nCnt < 0)
	{
		return root;
	}

	char **szLWord = (char**)malloc(sizeof(char*) * (nCnt/2 + 1));
	char **szLMean = (char**)malloc(sizeof(char*) * (nCnt/2 + 1));
	char **szRWord = (char**)malloc(sizeof(char*) * (nCnt/2 + 1));
	char **szRMean = (char**)malloc(sizeof(char*) * (nCnt/2 + 1));

	for(int i=0;i<nowMid;i++)
	{
		szLWord[i] = pword[i];
		szLMean[i] = pmean[i];
	}


	for(int i = nowMid; i < nCnt; i++)
	{
		szRWord[i-nowMid] = pword[i+1];
		szRMean[i-nowMid] = pword[i+1];
	}

	int nLLength = nowMid - 1;
	int nRLength = nCnt - nowMid - 1;

	LoadInsert(root, szLWord, szLMean, nLLength);
	LoadInsert(root, szRWord, szRMean, nRLength);



	free(szLWord);
	free(szLMean);
	free(szRWord);
	free(szRMean);
	return root;
}


void Contrller::ChangeNode(Info* root, char* word, char* mean)
{
	char arrWord[100];
	char arrMean[100];

	strcpy(arrWord, word);
	strcpy(arrMean, mean);
	strcpy(root->szWord, arrWord);
	strcpy(root->szMean, arrMean);
}