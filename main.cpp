#include "Solver.cpp"



int main(){

    std::string filename = "ks_19_0";
    Parser p;
    Solver s(p.parse(filename));
    std::vector<bool> ans = s.solve();

    for(int i = 0; i < ans.size(); i++) std::cout << ans[i] << " ";
    std::cout << std::endl;
    return 0;
}