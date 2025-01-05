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


    // 追加テスト1: コピーコンストラクタのテスト
    std::cout << "\nTesting copy constructor:" << std::endl;
    MutantStack<int, std::vector<int> > copiedStack(mstack);
    it = copiedStack.begin();
    ite = copiedStack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // 追加テスト2: 代入演算子のテスト
    std::cout << "\nTesting assignment operator:" << std::endl;
    MutantStack<int, std::vector<int> > assignedStack;
    assignedStack = mstack;
    it = assignedStack.begin();
    ite = assignedStack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // 追加テスト3: 逆イテレータのテスト
    std::cout << "\nTesting reverse iteration:" << std::endl;
    MutantStack<int, std::vector<int> >::iterator rit = mstack.end();
    while (rit != mstack.begin()) {
        --rit;
        std::cout << *rit << std::endl;
    }

    // 追加テスト4: 空のスタックのテスト
    std::cout << "\nTesting empty stack:" << std::endl;
    MutantStack<int, std::vector<int> > emptyStack;
    if (emptyStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    }


    return 0;
}
