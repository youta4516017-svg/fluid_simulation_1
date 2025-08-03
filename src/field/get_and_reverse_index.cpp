#include <iostream>
#include <vector>
#include "field.hpp"

using std::vector;

int XMAX;  // X方向の最大値
int YMAX;  // Y方向の最大値
int ZMAX;  // Z方向の最大値


/// 一次元配列の番号から２次元空間の座標を計算する関数
vector<int> get_2D_index(int n, int X, int Y){
    /// n は１次元配列のインデックス
    int y = n/X;
    int x = n - y*X;

    /// 座標の計算
    vector<int> position(2);
    position[0] = x;
    position[1] = y;

    return position;
}

/// ２次元空間の座標から一次元配列のインデックスを返す関数
int reverse_index_2D(int i, int j, int X, int Y){
    /// n は１次元配列のインデックス
    int n;
    return n = i + X*j;
}

/// 一次元配列の番号から３次元空間の座標を計算する関数
vector<int> get_3D_index(int n, int X, int Y, int Z){
    /// n は１次元配列のインデックス
    int z = n/(X*Y);
    int y = (n - z*X*Y)/X;
    int x = n - y*X - z*X*Y;

    /// 座標の計算
    vector<int> position(3);
    position[0] = x;
    position[1] = y;
    position[2] = z;

    return position;
}

/// ３次元空間の座標から一次元配列のインデックスを返す関数
int reverse_index_3D(int i, int j, int k, int X, int Y, int Z){
    /// n は１次元配列のインデックス
    int n;
    return n = i + X*j + X*Y*k;
}

/*
/// プログラム検証
int main(void) {
    int n = 69;
    int xmax = 10;
    int ymax = 20;
    vector<int> pos(2);
    int i = 5, j = 8;

    pos = get_2D_index(n, xmax, ymax);  // 座標の取得

    std::cout << "test" << std::endl;
    std::cout << pos[0] <<", "<< pos[1] << std::endl;
    std::cout << reverse_index_2D(pos[0], pos[1], xmax, ymax) << std::endl;

    int m = reverse_index_2D(i, j, xmax, ymax); // 座標から配列のインデックスに変換
    std::cout << m << std::endl;
    pos = get_2D_index(m, xmax, ymax);
    std::cout << pos[0] <<", "<< pos[1] << std::endl;

    int n3 = 550;
    int X = 18, Y = 13, Z = 15;
    int ii = 8, jj = 5, kk= 3;
    vector<int> pos3d(3);

    pos3d = get_3D_index(n3, X, Y, Z);  // 座標の取得
    std::cout << pos3d[0] <<", "<< pos3d[1] <<", "<< pos3d[2] << std::endl;
    std::cout << reverse_index_3D(pos3d[0], pos3d[1], pos3d[2], X, Y, Z) << std::endl;

    int l = reverse_index_3D(ii, jj, kk, X, Y, Z); // 座標から配列のインデックスに変換
    std::cout << l << std::endl;
    pos3d = get_3D_index(l, X, Y, Z);
    std::cout << pos3d[0] <<", "<< pos3d[1] <<", " << pos3d[2] << std::endl;

}
*/