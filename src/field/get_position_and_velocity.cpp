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

/// ２次元座標での速度を計算する関数（スタガード格子）
vector<double> calc_velocity_at_2D(int index, int setting = 3) {
    // 速度を取得する関数 デフォルトではスタガード格子の境界での速度を返す。
    // setting = 0: スタガード格子中心の u 成分を返す
    // setting = 1: スタガード格子中心の v 成分を返す

    int X, Y;   // x, y 方向の格子数の設定を取得
    vector<int> pos(2);
    X = XMAX;
    Y = YMAX;

    pos = get_2D_index(index, X, Y);  // ２次元座標を取得


    vector<double> velocity(2);
    if (setting == 0) {
        // スタガード格子中心での u 成分を返す
        velocity[0] = 1.0;  // 仮の値
        velocity[1] = 0.0;  // 仮の値
    } else if (setting == 1) {
        // スタガード格子中心での v 成分を返す
        velocity[0] = 0.0;  // 仮の値
        velocity[1] = 1.0;  // 仮の値
    } else {
        velocity[0] = 0.5;  // 仮の値
        velocity[1] = 0.0;  // 仮の値
    }

    return velocity;
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