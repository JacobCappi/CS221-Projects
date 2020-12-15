#include "PlayerList.h"


/* ------------------------------------------
    Default constructor for Node(Player), 
        sets data to Player,
        sets all pointers to null;
------------------------------------------ */ 
Node::Node(const Player &p){
    m_item = p;
    p_left = NULL;
    p_right = NULL;
}

/* ------------------------------------------
    Default Constructor, sets root to null
------------------------------------------ */ 
PlayerList::PlayerList(){
    p_root = NULL;
}

/* ------------------------------------------
    Default Destructor, calls free()
------------------------------------------ */ 
PlayerList::~PlayerList(){
    free();
}

//Wrappers

/* ------------------------------------------
    public wrapper for add()
------------------------------------------ */ 
void PlayerList::insert(Player p){
    add(p_root, p);
}

/* ------------------------------------------
    Public wrapper for uproot()
------------------------------------------ */ 
void PlayerList::free(){
    uproot(p_root);
}

//My Methods that need root

/* ------------------------------------------
    add(Node, Player)
        creates a new Node(p) once it 
        recursively finds where it belongs
------------------------------------------ */ 
void PlayerList::add(Node *&root, Player p){

    if(!root){
        root = new Node(p);
    } else if(p > root->m_item){
        add(root->p_right, p);
    } else if(p < root->m_item){
        add(root->p_left, p);
    } else{
        return;
    }

}

/* ------------------------------------------
    uproot(Node):
        Recurrsively calls left and right.
        Base case:  return on null;

        deletes after deleting all left
        and right nodes (until left and right
        are returns)
------------------------------------------ */ 
void PlayerList::uproot(Node *root){
    
    if(!root){ return; }

    if(root->p_left){ uproot(root->p_left); };

    if(root->p_right) { uproot(root->p_right);};

    delete root;
    return;
}

/* ------------------------------------------
    public wrapper for counting()
------------------------------------------ */ 
int PlayerList::count(){
    return counting(p_root);
}

/* ------------------------------------------
    counting(Node *)
        recurrsively counts all nodes in list
------------------------------------------ */ 
int PlayerList::counting(Node *root){
    if(root){
        return 1 + counting(root->p_left) + counting(root->p_right);
    }
    return 0;
}

/* ------------------------------------------
    public wrapper for inOrder()
------------------------------------------ */ 
void PlayerList::printInOrder(std::ostream &o){
    inOrder(p_root, o);
}

/* ------------------------------------------
    public wrapper for reverseOrder()
------------------------------------------ */ 
void PlayerList::printReverseOrder(std::ostream &o){
    reverseOrder(p_root, o);
}

/* ------------------------------------------
    public wrapper for overallBattinAvg

    error testing, forgot to divide by count(),
    so done here.
------------------------------------------ */ 
float PlayerList::teamAverage(){
    return (overallBattingAvg(p_root) / (float)count());

}

/* ------------------------------------------
    inOrder(Node *, ostream &)
        iterates inorder, and asks Node to 
        call print method of data to output
        stream.
------------------------------------------ */ 
void PlayerList::inOrder(Node *root, std::ostream &o){
    if(root){
        inOrder(root->p_left, o);
        root->m_item.printToOutputFile(o);
        inOrder(root->p_right, o);
    }
}

/* ------------------------------------------
    reverseOrder(Node *, ostream &)
        iterates in reverse (right, node, left)
        and calls print method of the Node data.
------------------------------------------ */ 
void PlayerList::reverseOrder(Node *root, std::ostream &o){
    if(root){
        reverseOrder(root->p_right, o);
        root->m_item.printToOutputFile(o);
        reverseOrder(root->p_left, o);
    }
}

/* ------------------------------------------
    overallBattingAverage(Node *)
        Count method but instead runs the Player
        method .getBattingAvg() and returns all the floats
        Base case 0.0.
------------------------------------------ */ 
float PlayerList::overallBattingAvg(Node *root){
    if(root){
        return root->m_item.getBattingAvg() + overallBattingAvg(root->p_left) + overallBattingAvg(root->p_right);
    }
    return 0.0;
}

/* ------------------------------------------
    printHeader(ostrea &)
        Little header for formatting.
        could not call print(o) inside to make
        it a 'report' method, so driver calls
        printHeader and the other 'print' methods
------------------------------------------ */ 
void PlayerList::printHeader(std::ostream &o){
    o << "\n\n------------------------------------\n\n";
    o << "Baseball Team Report \n\nSize: " << count() << "\nOverall Batting AVG: " << std::setprecision(4) << teamAverage() << "\n\n\n";
    o << std::setw(21) << "Name : ";
    o << std::setw(15) << "Bat AVG   OBS\n";
    o << "------------------------------------\n";
}

