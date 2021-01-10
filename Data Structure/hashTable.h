
#define		MODE_VALUE			256
#define		MAX_NAME_LENGTH		100

#define alloc(X)	malloc(sizeof(X));

struct Node {
	char			str[MAX_NAME_LENGTH];
	int				value;
	struct Node*	prevNode;
	struct Node*	nextNode;
};

struct HashTable {
    int             size;
    struct Node*	header;
};

struct HashTable* initHashTable();
struct Node* createNewNode(char* str, int value);
int getHashValue(char* nameString);
