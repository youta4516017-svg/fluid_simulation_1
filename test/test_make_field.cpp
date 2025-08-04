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
    std::cout << "Please set field size. (XMAX, YMAX, ZMAX) and Dimension" << std::endl;
}

// 実際のフィールド設定ロジックをここに実装
void make_field::set_field(int dim, int test) {
    // フィールドの設定処理
    std::cout << "XMAX = ";
    std::cin >> XMAX;
    //std::cout << "XMAX = " << XMAX << std::endl;
    X = XMAX;  // X方向の最大値を設定(プライベート変数に格納)

    std::cout << "YMAX = ";
    std::cin >> YMAX;
    //std::cout << "YMAX = " << YMAX << std::endl;
    Y = YMAX;  // Y方向の最大値を設定(プライベート変数に格納)

    while (1)
    {
        std::cout << "dimension = ";
        std::cin >> dim;
        //std::cout << "dimension = " << dim << std::endl;
        dimension = dim;  // Y方向の最大値を設定(プライベート変数に格納)
        
        // dimension: 2D or 3D
        if (2 == dimension) {
            ZMAX = 1;  // 2Dの場合はZ方向のサイズを1に設定
            break;  // 2Dの場合はループを抜ける
        } else if (3 == dimension) {
            std::cout << "ZMAX = ";
            std::cin >> ZMAX;
            //std::cout << "ZMAX = " << ZMAX << std::endl;
            Z = ZMAX;  // Y方向の最大値を設定(プライベート変数に格納)
            break;  // 3Dの場合はループを抜ける
        } else {
            std::cerr << "Error: Dimension must be 2 or 3." << std::endl;
            std::cout << "Please re-enter the dimension (2 or 3): ";
            continue; 
        }
    }

    // フィールドサイズ・次元のチェック
    while (X <= 0 || Y <= 0 || (dimension == 3 && Z <= 0)) {
        std::cerr << "Error: field size must be positive integers." << std::endl;
        std::cout << "Please re-enter the field size: " << std::endl;

        std::cout << "XMAX = ";
        std::cin >> XMAX;
        X = XMAX;  // X方向の最大値を設定(プライベート変数に格納)

        std::cout << "YMAX = ";
        std::cin >> YMAX;
        Y = YMAX;  // Y方向の最大値を設定(プライベート変数に格納)

        if (3 == dimension) {
            std::cout << "ZMAX = ";
            std::cin >> ZMAX;
            Z = ZMAX;  // Y方向の最大値を設定(プライベート変数に格納)
        } else {
            ZMAX = 1;  // 2Dの場合はZ方向のサイズを1に設定
        }
        
    }
    
    // デバッグ用の出力
    if (1 == test) {  // test が 1 の場合は、テスト用の値を設定
        std::cout << "Setting field with dimensions: " << XMAX << "x" << YMAX << "x" << ZMAX 
                  << " and dimension: " << dimension << std::endl;
    }
}

vector<int> make_field::get_field(int test) {
    vector<int> field_setting(4);  // フィールドの初期化

    field_setting[0] = XMAX;  // X方向の最大値
    field_setting[1] = YMAX;  // Y方向の最大値
    field_setting[2] = ZMAX;  // Z方向の最大値
    field_setting[3] = dimension;  // 次元（2D or 3
    
    return field_setting;  // フィールドの諸元の値を返す
}

make_field::~make_field(/* args */) {
    // デコンストラクタ
    std::cout << "Field size set to X: " << XMAX << ", Y:" << YMAX << ", Z:" << ZMAX 
              << " with dimension: " << dimension << std::endl;
}

/// @brief テストのためのメイン関数
int main() {

    make_field field;  // make_field クラスのインスタンスを作成
    field.set_field();  // フィールドの設定を行う
    vector<int> field_info = field.get_field();  // フィールドの情報を取得

    return 0;  // 正常終了
}