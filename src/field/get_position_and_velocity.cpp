/// 座標とその座標での圧力を計算する関数
#include <iostream>
#include <vector>
#include "field.hpp"

using std::vector;

//int XMAX;  // X方向の最大値
//int YMAX;  // Y方向の最大値
//int ZMAX;  // Z方向の最大値

/// ２次元座標を計算する関数
vector<double> get_position_at_2D(int index, double dx, double dy) {
    double X, Y;
    vector<int> index_2D(2);

    X = XMAX;
    Y = YMAX;

    index_2D = get_2D_index(index, X, Y);  // 仮のXMAX, YMAXを使用

    std::cout << index_2D[0] << "," << index_2D[1] << "," << std::endl;

    vector<double> position(2);
    position[0] = index_2D[0] * dx;  // x座標
    position[1] = index_2D[1] * dy;  // y座標
    return position;
}

// テスト関数
int main(void){
    int index = 200;  // テスト用のインデックス
    double dx = 0.1; // x方向の間隔
    double dy = 0.1; // y方向の間隔

    XMAX = 30, YMAX = 30; // 仮のXMAX, YMAXを設定

    vector<double> position = get_position_at_2D(index, dx, dy);
    std::cout << "Position at index " << index << ": (" 
              << position[0] << ", " << position[1] << ")" << std::endl;

    return 0;
}