#include "Solver.h"



node::node(){
    sum_value = 0;
    sum_weight = 0;
    right = 0;
    left = 0;
}


Solver::Solver(std::pair<double, std::vector<item>> data){
    root = 0;
    items = data.second;
    max_weight = data.first;
    ans_value = 0;
}

void Solver::add_left(node& vert){
    std::cout << "left " << vert.prev_vec.size() << std::endl;
    if(vert.prev_vec.size() < items.size()){
        std::cout << "left creating\n";
        node *tmp = new node;
        tmp -> sum_value = vert.sum_value;
        tmp -> sum_weight = vert.sum_weight;
        tmp -> prev_vec = vert.prev_vec;
        tmp -> prev_vec.push_back(false);
        vert.left = tmp;
        add_left(*tmp);
        add_right(*tmp);
    }

    return;
}


void Solver::add_right(node& vert){
    std::cout << "right " << vert.prev_vec.size() << std::endl;
    if(vert.prev_vec.size() < items.size() && vert.sum_weight + items[vert.prev_vec.size()].second <= max_weight){
        std::cout << "right creating\n";
        node *tmp = new node;
        tmp -> sum_value = vert.sum_value + items[vert.prev_vec.size()].first;
        tmp -> sum_weight = vert.sum_weight + items[vert.prev_vec.size()].second;
        tmp -> prev_vec = vert.prev_vec;
        tmp -> prev_vec.push_back(true);
        vert.right = tmp;
        add_left(*tmp);
        add_right(*tmp);
    }

    return;
}


void Solver::create_tree(){
    std::cout << "Creating\n";
    root = new node;
    add_left(*root);
    add_right(*root);
    std::cout << "Created\n";
}

void Solver::search_answer(node root){
    
    if(ans_value < root.sum_value){
        ans = root.prev_vec;
        ans_value = root.sum_value;
    }
    std::cout << "Searching\n";
    if(root.left) search_answer(*root.left);
    if(root.right) search_answer(*root.right);
    return;
}

void Solver::delete_tree(node *root){
    if(!root) return;
    delete_tree(root -> left);
    delete_tree(root -> right);
    if (root) delete root;
    return;
}

std::vector<bool> Solver::solve(){
    create_tree();
    search_answer(*root);
    int n = ans.size();
    ans.resize(items.size());
    for(int i = n; i < ans.size(); i++) ans[i] = false;

    delete_tree(root);
    root = 0;
    std::cout << ans_value << std::endl;
    return ans;
}