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

    // reverse_iterator を使用して要素を反復処理
    std::cout << "Stack elements (reverse iteration):" << std::endl;
    MutantStack<int, std::vector<int> >::reverse_iterator rit = mstack.rbegin();
    MutantStack<int, std::vector<int> >::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
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

    // 追加テスト3: 空のスタックのテスト
    std::cout << "\nTesting empty stack:" << std::endl;
    MutantStack<int, std::vector<int> > emptyStack;
    if (emptyStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    }


    // ===== std::string型のテスト =====
    std::cout << "\n---Testing MutantStack with std::string---" << std::endl;
    MutantStack<std::string, std::deque<std::string> > stringStack;

    // 要素を追加
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("MutantStack");
    stringStack.push("Test");

    // 先頭要素の確認
    std::cout << "Top element: " << stringStack.top() << std::endl; // 出力: Test

    // 全要素を順番に出力
    MutantStack<std::string, std::deque<std::string> >::iterator sit = stringStack.begin();
    MutantStack<std::string, std::deque<std::string> >::iterator site = stringStack.end();
    std::cout << "String stack elements:" << std::endl;
    while (sit != site) {
        std::cout << *sit << std::endl;
        ++sit;
    }

    // 全要素を逆順に出力
    std::cout << "String stack elements (reverse iteration):" << std::endl;
    MutantStack<std::string, std::deque<std::string> >::reverse_iterator srit = stringStack.rbegin();
    MutantStack<std::string, std::deque<std::string> >::reverse_iterator srite = stringStack.rend();
    while (srit != srite) {
        std::cout << *srit << std::endl;
        ++srit;
    }

    return 0;
}
