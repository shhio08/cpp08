#include "MutantStack.hpp"

int main() {
    // std::vectorを内部コンテナとして使用するMutantStack
    MutantStack<int, std::vector<int> > mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl; // 出力: 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // 出力: 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // イテレータを使用して要素を反復処理
    MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
    MutantStack<int, std::vector<int> >::iterator ite = mstack.end();

    std::cout << "Stack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
