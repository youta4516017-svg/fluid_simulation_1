/// make field クラスの実装（計算領域を設定する関数群）
#include <iostream>
#include <vector>
#include "test_field.hpp"
using std::vector;

int XMAX;  // X方向の最大値
int YMAX;  // Y方向の最大値
int ZMAX;  // Z方向の最大値

make_field::make_field(/* args */) {
    // コンストラクタの初期化処理
    // ここで必要な初期化を行う
    std::cout << "Please set field size. (XMAX, YMAX, ZMAX)" << std::endl;
}

void make_field::set_field(int dimension, int test) {
    // フィールドの設定処理
    std::cout << "XMAX = ";
    std::cin >> XMAX;
    std::cout << "XMAX = " << XMAX << std::endl;
    X = XMAX;  // X方向の最大値を設定(プライベート変数に格納)

    std::cout << "YMAX = ";
    std::cin >> YMAX;
    std::cout << "YMAX = " << YMAX << std::endl;
    Y = YMAX;  // Y方向の最大値を設定(プライベート変数に格納)

    // dimension: 2D or 3D
    if (2 == dimension) {
        ZMAX = 1;  // 2Dの場合はZ方向のサイズを1に設定
    } else if (3 == dimension) {
        std::cout << "ZMAX = ";
        std::cin >> ZMAX;
        std::cout << "ZMAX = " << ZMAX << std::endl;
        Z = ZMAX;  // Y方向の最大値を設定(プライベート変数に格納)
    } else {
        std::cerr << "Error: Dimension must be 2 or 3." << std::endl;
        return;
    }
    
    
    // フィールドサイズ・次元のチェック
    if (X <= 0 || Y <= 0 || (dimension == 3 && Z <= 0)) {
        std::cerr << "Error: field size must be positive integers." << std::endl;
        return;
    }

    // デバッグ用の出力
    if (1 == test) {  // test が 1 の場合は、テスト用の値を設定
        std::cout << "Setting field with dimensions: " << XMAX << "x" << YMAX << "x" << ZMAX 
                  << " and dimension: " << dimension << std::endl;
    }
    // 実際のフィールド設定ロジックをここに実装
}