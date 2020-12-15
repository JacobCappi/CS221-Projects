
#include "Player.h"

/* ------------------------------------------
PlayerList() [Uses Node]: Binary Search Tree
    p_root: pointer to root
    Contains Constructor and Deconstructor

    insert() is wrapper for add()
    free() is wrapper for uproot()
    count() is wrapper for counting()

    add() adds Player to tree
    free() deletes all Players in tree
    counting() returns number of Nodes 
------------------------------------------ */ 
class PlayerList;

/* ------------------------------------------
Nodes for the PlayerList class:
    m_item: data: Player (requires Player.h)
    2 pointers: p_left, p_right (it's a BST)

    Constructor requires Player to be passed
------------------------------------------ */ 
class Node {
private:
    Player m_item;
    Node *p_left, *p_right;
    friend PlayerList;
public:
    Node(const Player &item);
};

class PlayerList {
private:
    Node *p_root;

    // Observers

    int counting(Node *root);
    float overallBattingAvg(Node *);

    // Transformers

    void uproot(Node *root);
    void add(Node *&root, Player);

    // Iterator

    void inOrder(Node *root, std::ostream &);
    void reverseOrder(Node *root, std::ostream &);


public:
    PlayerList();
    ~PlayerList();

// Observer Wrappers
    
    int count();
    float teamAverage();

// Transformer Wrappers
    
    void free();
    void insert(Player);

// Iterator Wrappers

    void printInOrder(std::ostream &);
    void printReverseOrder(std::ostream &);

// Generate Reports

    void printHeader(std::ostream &);
};
