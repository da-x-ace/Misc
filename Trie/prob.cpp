#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct trie_node trie_node_t;
typedef struct trie_tree trie_t;

struct trie_node{
	int value;
	struct trie_node* nextCharacter[26];
};


struct trie_tree{
	int count;
	trie_node_t* root;
};

trie_node_t* getNode(void)
{
	trie_node_t *temp;
	temp = (struct trie_node*) malloc(sizeof(struct trie_node));
	
	temp->value=0;
	for (int i=0; i<26; i++)
	{
		temp->nextCharacter[i] = NULL;
	}
	
	return temp;
}

void initialize(trie_t *trie)
{
	trie->count = 0;
	trie->root = getNode();
}

void insert(trie_t *trie, char *key)
{
	trie->count++;
	int length = strlen(key);
	trie_node_t *temp;
	temp = trie->root;
	int index;
	
	for(int i=0; i<length; i++)
	{
		index = key[i]-'a';
		if(temp->nextCharacter[index] == NULL)
		{
			temp->nextCharacter[index] = getNode();
		}
		temp = temp->nextCharacter[index];
	}
	
	temp->value = trie->count;
}

int search(trie_t *trie, char *key)
{
	int length = strlen(key);
	trie_node_t *temp = trie->root;
	int index=0;
	for(int i=0; i<length; i++)
	{
		index = key[i]-'a';
		if(temp->nextCharacter[index] == NULL)
			return 0;
		temp = temp->nextCharacter[index];
	}
	if(temp->value > 0)
	return 1;
	else return 0;
}

int main()
{
	char array[][32] = {"Hi", "This","is","me","the", "a", "there", "answer", "any", "by", "bye", "their"};
	trie_t  trie;
	initialize(&trie);
	int length = sizeof(array)/sizeof(array[0]);
	//cout<<length<<endl;
	for(int i=0; i<length; i++)
	{
		insert(&trie, array[i]);
	}
	int result = search(&trie, "byee");
	cout<<result<<endl;
}
