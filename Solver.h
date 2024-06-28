#include "Parser.cpp"



struct node{
    double sum_value, sum_weight;
    std::vector<bool> prev_vec;
    node *right, *left;
    node();
};



class Solver{
    std::vector<item> items;
    double max_weight;
    node* root;
    std::vector<bool> ans;
    double ans_value = 0;
public:
    Solver(std::pair<double, std::vector<item>>);
    void add_left(node&);
    void add_right(node&);
    void create_tree();
    void search_answer(node);
    void delete_tree(node *root);
    std::vector<bool> solve();
};


