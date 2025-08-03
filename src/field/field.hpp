#include <vector>
#include <iostream>

using std::vector;

enum class FLUID {
    // 流体の種類とIDを定義
    GAS,
    LIQUID
};

enum class BC {
    // 境界条件の種類とIDを定義
    PFIX_BC,     // 圧力固定の境界条件
    VFIX_BC,     // 流速固定の境界条件
    WALL_BC,     // 壁面境界の境界条件
    ON_WALL_BC,  // 境界条件
    ISOLATED_BC, // 孤立壁の境界条件
};

vector<int> get_2D_index(int n, int XMAX, int YMAX);    /// 一次元配列の番号から２次元空間の座標を計算する関数
int reverse_index_2D(int i, int j, int XMAX, int YMAX);  /// ２次元空間の座標から一次元配列のインデックスを返す関数

vector<int> get_3D_index(int n, int XMAX, int YMAX, int ZMAX);  /// 一次元配列の番号から３次元空間の座標を計算する関数
int reverse_index_3D(int i, int j, int k, int XMAX, int YMAX, int ZMAX);  /// ３次元空間の座標から一次元配列のインデックスを返す関数