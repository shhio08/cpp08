#include "Span.hpp"

int main() {
    // try {
    //     // 単一の数を追加するテスト
    //     Span sp = Span(5);
    //     sp.addNumber(6);
    //     sp.addNumber(3);
    //     sp.addNumber(17);
    //     sp.addNumber(9);
    //     sp.addNumber(11);

    //     std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // 出力: 2
    //     std::cout << "Longest Span: " << sp.longestSpan() << std::endl;  // 出力: 14

    //     // イテレータで複数の数を追加するテスト
    //     std::vector<int> vec;
    //     for (int i = 0; i < 10000; ++i) {
    //         vec.push_back(i * 2);
    //     }
    //     Span bigSpan(10000);
    //     bigSpan.addNumber(vec.begin(), vec.end());
    //     std::cout << "Shortest Span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
    //     std::cout << "Longest Span in bigSpan: " << bigSpan.longestSpan() << std::endl;
    // }
    // catch (const std::exception &e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }
	    try {
        // テストケース1: 正常なケース
        Span sp(5);  // 最大5個の要素を格納できるSpan
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // 2 (3と6の差)
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // 14 (17と3の差)

        // テストケース2: 例外処理 - Spanが満杯の場合
        try {
            sp.addNumber(15);  // 5個の要素を超えて追加しようとする
        } catch (const std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // テストケース3: 2つの数値でのケース
        Span sp2(2);
        sp2.addNumber(10);
        sp2.addNumber(20);

        std::cout << "Shortest Span (sp2): " << sp2.shortestSpan() << std::endl;  // 10 (20と10の差)
        std::cout << "Longest Span (sp2): " << sp2.longestSpan() << std::endl;    // 10 (20と10の差)

        // テストケース4: Spanのサイズが1のときの動作
        Span sp3(1);  // 最大1個しか格納できない
        sp3.addNumber(100);
        try {
            std::cout << "Shortest Span (sp3): " << sp3.shortestSpan() << std::endl;  // 例外が発生するはず
        } catch (const std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // テストケース5: Spanのサイズが0のとき
        Span sp4(0);  // 0個しか格納できない
        try {
            std::cout << "Shortest Span (sp4): " << sp4.shortestSpan() << std::endl;  // 例外が発生するはず
        } catch (const std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // テストケース6: addNumberに範囲を渡して追加
        Span sp5(10);
        std::vector<int> numbers;
        numbers.push_back(5);
        numbers.push_back(10);
        numbers.push_back(15);
        numbers.push_back(20);
        numbers.push_back(25);
        numbers.push_back(30);
        numbers.push_back(35);
        numbers.push_back(40);
        numbers.push_back(45);
        numbers.push_back(50);

        sp5.addNumber(numbers.begin(), numbers.end());

        std::cout << "Shortest Span (sp5): " << sp5.shortestSpan() << std::endl;  // 5 (10と5の差)
        std::cout << "Longest Span (sp5): " << sp5.longestSpan() << std::endl;    // 45 (50と5の差)

        // テストケース7: 空のSpanに対する操作（shortestSpan, longestSpan）
        Span sp6(0);
        try {
            std::cout << "Longest Span (sp6): " << sp6.longestSpan() << std::endl;  // 例外が発生するはず
        } catch (const std::runtime_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}