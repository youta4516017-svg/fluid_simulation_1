/// 座標とその座標での圧力を計算する関数
#include <iostream>
#include <vector>
#include "field.hpp"

using std::vector;


/// ２次元座標を計算する関数
vector<double> get_position_at_2D(int index, double dx, double dy) {
    int X, Y;
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

/// ３次元座標を計算する関数
vector<double> get_position_at_3D(int index, double dx, double dy, double dz) {
    int X, Y, Z;
    vector<int> index_3D(3);

    X = XMAX;
    Y = YMAX;
    Z = ZMAX;

    index_3D = get_3D_index(index, X, Y, Z);  // 仮のXMAX, YMAX, ZMAXを使用

    std::cout << index_3D[0] << "," << index_3D[1] << "," << index_3D[2] << std::endl;

    vector<double> position(3);
    position[0] = index_3D[0] * dx;  // x座標
    position[1] = index_3D[1] * dy;  // y座標
    position[2] = index_3D[2] * dz;  // z座標
    return position;
}



// テスト関数
int main(void){
    int index = 200;  // テスト用のインデックス
    double dx = 0.1; // x方向の間隔
    double dy = 0.1; // y方向の間隔
    double dz = 0.1; // z方向の間隔

    XMAX = 30, YMAX = 30, ZMAX = 10; // 仮のXMAX, YMAX, ZMAXを設定

    vector<double> position = get_position_at_2D(index, dx, dy);
    std::cout << "Position at index " << index << ": (" 
              << position[0] << ", " << position[1] << ")" << std::endl;

    return 0;
}